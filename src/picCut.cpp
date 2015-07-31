#include "picCut.hpp"
#include "ui_picCut.h"

#include <QStandardItemModel>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    path("."),picFiles()
{
    ui->setupUi(this);

    //添加图片列表区表头
    model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString("图片名"));
    model->setHeaderData(1,Qt::Horizontal,QString("分辨率"));
    //设置model到tableView
    ui->pic_list->setModel(model);
    //设置表头左对齐
    ui->pic_list->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    //设置首列列宽不可变
    ui->pic_list->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Custom);
    //设置各列列宽
    ui->pic_list->setColumnWidth(0,ui->pic_list->width()-128);
    ui->pic_list->setColumnWidth(1,128);
    //单选模式
    ui->pic_list->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    //行选择模式
    ui->pic_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    //支持输出的图片格式
    ui->comboBox->addItem("JPEG");
    ui->comboBox->addItem("PNG");
    ui->comboBox->addItem("BMP");
    ui->comboBox->addItem("XBM");
    ui->comboBox->addItem("PPM");

    //对上下左右比例的控制
    connect(ui->spinBox_up,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    connect(ui->spinBox_low,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    connect(ui->spinBox_right,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    connect(ui->spinBox_left,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    connect(ui->spinBox_row,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    connect(ui->spinBox_col,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
}

Widget::~Widget()
{
    delete ui;
}

/*==============================================================*
 *          添加文件到待处理列表                                *
 *--------------------------------------------------------------*/
void Widget::on_btn_addfile_clicked()
{
    //弹出文件选择对话框
    QStringList selFiles;
    selFiles =  QFileDialog::getOpenFileNames(this,"选择待裁切图片",
                              this->path,"图片文件 (*.png *.jpg *.bmp)");
    //判断是否选择了图片
    if(selFiles.isEmpty()){return;}
    //保存原路径
    path = QFileInfo(selFiles[0]).path();
    path += '/';    //QT下不需要区分是linux还是windows '\\'
    ui->lineEdit_path->setText(path+"outputPicture/");
    //添加文件名到列表中
    int pathLen=path.length();
    int row = this->model->rowCount();  //当前行数
    QPixmap pixmap; //用于获取图片分辨率
    char buf[128];
    for(auto & it:selFiles){
        if(this->picFiles.indexOf(it) >= 0){
            qDebug()<<"重复了";
            continue;
        }
        this->picFiles.append(it);//将添加的文件添加到picFiles变量中
        pixmap.load(it);    //加载图片
        //it.remove(0,pathLen);   //移除路径(不能移除，避免文件路径不一致)
        this->model->setItem(row,0,new QStandardItem(it.mid(pathLen)));
        sprintf(buf,"%4d x %d",pixmap.width(),pixmap.height());
        this->model->setItem(row++,1,new QStandardItem(buf));
    }
    qDebug()<<this->picFiles;
}


/*==============================================================*
 *          清空待处理图片列表                                  *
 *--------------------------------------------------------------*/
void Widget::on_btn_rmAllfile_clicked()
{
    this->model->removeRows(0,this->model->rowCount());   //清空model
    this->picFiles.clear(); //清空
}

/*==============================================================*
 *          图片列表中选择图片                                     *
 *--------------------------------------------------------------*/
void Widget::on_pic_list_clicked(const QModelIndex &index)
{
    qDebug()<<this->picFiles[index.row()];
    //viewPixmap必须给一个能够容纳image传给它的大小，不然会崩掉
    static QPixmap viewPixmap(ui->label_view->size());  //用于绘制到label
    static QImage image;    //用于加载图片
    image.load(this->picFiles[index.row()]);    //加载图片

    //a/b>c/d --> a*d > b*c
    if(viewPixmap.width() * ui->label_view->height() >
            ui->label_view->width()*viewPixmap.height()){
        //缩放image到与label同宽(图片的宽高比大于label的宽高比，即等高下图片较宽)
        viewPixmap.convertFromImage(image.scaledToWidth(ui->label_view->width()));
    }else{
        //缩放image到与label同高
        viewPixmap.convertFromImage(image.scaledToHeight(ui->label_view->height()));
    }
    ui->label_view->setPixmap(viewPixmap);
}
/*==============================================================*
 *          预览label绘制裁切辅助线                                *
 *--------------------------------------------------------------*/
void Widget::draw_cut_line(int a)
{
    //还未完成
    //qDebug()<<ui->tabW_cut_conf->currentIndex();
    //qDebug()<<a;

    int left,right,up,low;
    left	= ui->spinBox_left->value();
    right	= ui->spinBox_right->value();
    up		= ui->spinBox_up->value();
    low		= ui->spinBox_low->value();



    if(left + right > 95){
        ui->spinBox_left->setValue(left-1);
        ui->spinBox_right->setValue(right-1);
    }
    if(up + low > 95){
        ui->spinBox_up->setValue(up -1);
        ui->spinBox_low->setValue(low - 1);
    }
}
/*==============================================================*
 *          开始裁切图片并保存到指定文件夹                           *
 *--------------------------------------------------------------*/
void Widget::on_btn_run_clicked()
{
    if(picFiles.isEmpty()){return;} //没有加载图片

    if(ui->tabW_cut_conf->currentIndex()==0){
        //按比例裁切
        //获取上下左右占比
        int left,right,up,low;
        left	= ui->spinBox_left->value();
        right	= ui->spinBox_right->value();
        up		= ui->spinBox_up->value();
        low		= ui->spinBox_low->value();

        QString fileName;
        QString OutputPath = ui->lineEdit_path->text();
        QString PicFmt = ui->comboBox->currentText();
        int quality = ui->spinBox_quality->value();

        QDir dir(OutputPath);   //获取输出目录信息
        if(!dir.exists()){
            dir.mkpath(OutputPath); //输出目录不存在的时候创建
        }

        for(int i = 0;i<picFiles.count();++i){
            fileName = picFiles[i];
            QImage image(fileName); //加载要裁切的图片
            QRect rect = image.rect(); //获取大小
            //设置裁切矩形
            rect.setRect(rect.width()*left/100,rect.height()*up/100,
                         rect.width()*(100-left-right)/100,rect.height()*(100-up-low)/100);
            if(rect.width()==0 || rect.height() == 0){
                qDebug()<<"to width or height is zero";
                continue;   //直接下一个
            }

            QFileInfo fileinfo(fileName);
            fileName = ui->lineEdit_name->text();
            fileName.replace("{InputName}",fileinfo.baseName());
            fileName.replace("{ID}",QString().setNum(i));
            //输出裁切图片到指定目录
            image.copy(rect).save(OutputPath+fileName+'.'+PicFmt,
                                  PicFmt.toStdString().c_str(),quality);
            //qDebug()<<OutputPath+fileName+'.'+PicFmt;
        }
    }
    else{
        //横纵向等分裁切为多个图片
        int row,col;
        row = ui->spinBox_row->value();
        col = ui->spinBox_col->value();

        QString fileName;
        QString OutputPath = ui->lineEdit_path->text();
        QString PicFmt = ui->comboBox->currentText();
        int quality = ui->spinBox_quality->value();

        QDir dir(OutputPath);
        if(!dir.exists()){
            dir.mkpath(OutputPath);
        }

        for(int i = 0;i<picFiles.count();++i){
            fileName = picFiles[i];
            QImage image(fileName);
            QRect rect = image.rect();
            int x,y,w,h;
            w = rect.width()/col;
            h = rect.height()/row;
            if(w < 2 || h < 2){continue;}

            QFileInfo fileinfo(fileName);
            fileName = ui->lineEdit_name->text();
            fileName.replace("{InputName}",fileinfo.baseName());
            fileName.replace("{ID}",QString().setNum(i));
            int index = 0;
            for(x = 0;x < rect.width() ; x+=w){
                for(y = 0;y < rect.height(); y+=h){
                    ++index;
                    //qDebug()<<OutputPath+fileName+(QString().setNum(index))+'.'+PicFmt;
                   image.copy(x,y,w,h).save(OutputPath+fileName+(QString().setNum(index))+'.'+PicFmt,
                                            PicFmt.toStdString().c_str(),quality);
                }
            }
        }

    }
}

/*==============================================================*
 *          选择裁切输出文件夹                                     *
 *--------------------------------------------------------------*/
void Widget::on_btn_path_select_clicked()
{
    ui->lineEdit_path->setText(
                QFileDialog::getExistingDirectory(this,"select Output Path",ui->lineEdit_path->text()).append('/')
                );
}
/*==============================================================*
 *          从待处理列表中移除选中项                                *
 *--------------------------------------------------------------*/
void Widget::on_btn_rmfile_clicked()
{
    if(picFiles.isEmpty()){return;}
    int curow = ui->pic_list->currentIndex().row();
    picFiles.removeAt(curow);
    this->model->removeRow(curow);

}
