#include "picCut.hpp"
#include "ui_picCut.h"

#include <QStandardItemModel>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QPushButton>
#include <QHeaderView>

#include <QProgressDialog>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QMessageBox>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    path(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)),
    picFiles()
{
    ui->setupUi(this);

    if(path.isEmpty()){
        path.append(".");
    }


    //添加图片列表区表头
    model = new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,QString("图片名"));
    model->setHeaderData(1,Qt::Horizontal,QString("分辨率"));
    //设置model到tableView
    ui->pic_list->setModel(model);
    //设置表头左对齐
    ui->pic_list->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //设置充满表宽度(现有列占据整个表格)
    ui->pic_list->horizontalHeader()->setStretchLastSection(true);
    // 均分列宽
    ui->pic_list->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);

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
    //connect(ui->spinBox_up,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    //connect(ui->spinBox_low,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    //connect(ui->spinBox_right,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    //connect(ui->spinBox_left,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    //connect(ui->spinBox_row,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));
    //connect(ui->spinBox_col,SIGNAL(valueChanged(int)),this,SLOT(draw_cut_line(int)));

    void (QSpinBox::*vc)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox_up,   vc,this,&Widget::draw_cut_line);
    connect(ui->spinBox_low,  vc,this,&Widget::draw_cut_line);
    connect(ui->spinBox_right,vc,this,&Widget::draw_cut_line);
    connect(ui->spinBox_left, vc,this,&Widget::draw_cut_line);
    connect(ui->spinBox_row,  vc,this,&Widget::draw_cut_line);
    connect(ui->spinBox_col,  vc,this,&Widget::draw_cut_line);
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
    QImage image; //用于获取图片分辨率
    for(auto & it:selFiles){
        if(this->picFiles.indexOf(it) >= 0){
            qDebug()<<"重复了";
            continue;
        }
        this->picFiles.append(it);//将添加的文件添加到picFiles变量中
        image.load(it);    //加载图片
        //it.remove(0,pathLen);   //移除路径(不能移除，避免文件路径不一致)
        this->model->setItem(row,0,new QStandardItem(it.mid(pathLen)));
        this->model->setItem(row++,1,new QStandardItem(
                                 QString("%1 x %2").arg(image.width()).arg(image.height())));
    }
    qDebug()<<this->picFiles;

    // 预览第一张图像
    on_pic_list_clicked(this->model->index(0,0));

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
    //static QPixmap viewPixmap(ui->label_view->size());  //用于绘制到label

    static QImage image;    //用于加载图片
    static QString picPath; //图片的路径
    if(picPath == this->picFiles[index.row()]){
        return; // 没有改变，直接跳过
    }else{
        picPath = this->picFiles[index.row()];
    }

    image.load(picPath);    //加载图片

    //a/b>c/d --> a*d > b*c
    if(image.width() * ui->label_view->height() >
            ui->label_view->width()*image.height()){
        //缩放image到与label同宽(图片的宽高比大于label的宽高比，即等高下图片较宽)
        preview = image.scaledToWidth(ui->label_view->width());
        //viewPixmap.convertFromImage(image.scaledToWidth(ui->label_view->width()));

    }else{
        //缩放image到与label同高
        //viewPixmap.convertFromImage(image.scaledToHeight(ui->label_view->height()));
        preview = image.scaledToHeight(ui->label_view->height());
    }

    // 预览图保存
    //preview = viewPixmap.toImage();

    draw_cut_line(0);
    //ui->label_view->setPixmap(viewPixmap);
}
/*==============================================================*
 *          预览label绘制裁切辅助线                                *
 *--------------------------------------------------------------*/
void Widget::draw_cut_line(int delta)
{
    if(this->picFiles.isEmpty()){
        return;
    }
    // 获取当前显示的图像
    QPixmap viewPixmap = QPixmap::fromImage(preview);
    // 获取当前的分割方式
    if(ui->tabW_cut_conf->currentIndex()==0){
        //按比例裁切

        int left,right,up,low;
        left	= ui->spinBox_left->value();
        right	= ui->spinBox_right->value();
        up		= ui->spinBox_up->value();
        low		= ui->spinBox_low->value();

        // 不知道所有图的大小，暂时先控制裁切出部分必须大于5%
        // 若新的value和旧的一致，不会触发valueChange信号
        if(left + right > 95){
            if(sender() == ui->spinBox_left){
                left -= delta;
                ui->spinBox_left->setValue(left);
            }else{
                right -= delta;
                ui->spinBox_right->setValue(right);
            }
        }
        if(up + low > 95){
            if(sender() == ui->spinBox_up){
                up -= delta;
                ui->spinBox_up->setValue(up);
            }else{
                low -= delta;
                ui->spinBox_low->setValue(low);
            }
        }
        // 计算左右上下线在缩略图上的位置
        left = preview.width() * float(left*0.01f);
        right = preview.width() * float(1.0f - right*0.01f);
        up = preview.height() * float(up*0.01f);
        low = preview.height() * float(1.0f - low*0.01f);

        // 缩略图上画线
        QPainter painter;
        painter.begin(&viewPixmap);
        painter.setPen(QColor(255,0,0));
        painter.drawRect(left,up,right-left,low-up);
        painter.end();
        // 替换到viewlabel
        ui->label_view->setPixmap(viewPixmap);

    }
    else{
        // 获取分割的行高和列宽
        int w = preview.width();
        int h = preview.height();
        int ncol = ui->spinBox_col->value();
        int nrow = ui->spinBox_row->value();

        // 缩略图上画线
        QPainter painter;
        painter.begin(&viewPixmap);
        painter.setPen(QColor(255,0,0));
        for(int col = 1; col < ncol; ++col){
            int x = float(col * w)/float(ncol) + 0.5f;
            painter.drawLine(x,0,x,h);
        }
        for(int row = 1; row < nrow; ++row){
            int y = float(row * h)/float(nrow) + 0.5f;
            painter.drawLine(0,y,w,y);
        }
        painter.end();
        // 替换到viewlabel
        ui->label_view->setPixmap(viewPixmap);
    }
}
/*==============================================================*
 *          开始裁切图片并保存到指定文件夹                           *
 *--------------------------------------------------------------*/
void Widget::on_btn_run_clicked()
{
    if(picFiles.isEmpty()){return;} //没有加载图片
    //使开始按钮不可用
    ui->btn_run->setEnabled(false);
    int picCount = picFiles.count();
    //创建进度指示对话框
    QProgressDialog process;
    process.setWindowTitle("处理进度");
    process.setLabelText(tr("裁切处理中..."));
    process.setRange(0,picCount);
    process.setCancelButtonText(tr("取消"));
    process.showNormal();   //显示进度指示对话框

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

        for(int i = 0;i<picCount;++i){
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
            //更新进度条
            process.setValue(i);
            // 处理其他事件
            QApplication::processEvents();
            // 上面需要确保本槽函数不会被再次出发，否则可能不断递归
            if(process.wasCanceled()){
                //按下取消键
                break;
            }
        }//end for
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

        for(int i = 0;i<picCount;++i){
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
                }//end for y
            }//end for x
            //更新进度条
            process.setValue(i);
            // 处理其他事件
            QApplication::processEvents();
            // 上面需要确保本槽函数不会被再次出发，否则可能不断递归
            if(process.wasCanceled()){
                //按下取消键
                break;
            }
        }//end for i
    }//end if

    // 处理完成，询问是否打开输出文件夹
    int btn = QMessageBox::question(this,QString("提示信息"),
                          QString("全部处理完成，是否打开输出目录？"),
                          QMessageBox::Ok,QMessageBox::Close);
    if(btn == QMessageBox::Ok){
        // 打开输出文件夹
        QDesktopServices::openUrl(ui->lineEdit_path->text());
    }

    //使开始按钮可用
    ui->btn_run->setEnabled(true);
}

/*==============================================================*
 *          选择裁切输出文件夹                                     *
 *--------------------------------------------------------------*/
void Widget::on_btn_path_select_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"select Output Path",ui->lineEdit_path->text());
    if(!dir.isEmpty()){
        ui->lineEdit_path->setText(dir.append('/'));
    }
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
