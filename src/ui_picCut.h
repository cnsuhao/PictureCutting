/********************************************************************************
** Form generated from reading UI file 'picCut.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICCUT_H
#define UI_PICCUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *gp_list;
    QPushButton *btn_addfile;
    QPushButton *btn_rmfile;
    QPushButton *btn_rmAllfile;
    QTableView *pic_list;
    QGroupBox *gp_viev;
    QLabel *label_view;
    QGroupBox *gp_format_conf;
    QComboBox *comboBox;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinBox_quality;
    QGroupBox *gp_save_conf;
    QLabel *label_9;
    QLineEdit *lineEdit_path;
    QPushButton *btn_path_select;
    QLabel *label_10;
    QLineEdit *lineEdit_name;
    QPushButton *btn_run;
    QTabWidget *tabW_cut_conf;
    QWidget *bl;
    QSpinBox *spinBox_left;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox_right;
    QSpinBox *spinBox_low;
    QSpinBox *spinBox_up;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *jf;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *spinBox_row;
    QSpinBox *spinBox_col;
    QPushButton *btn_close;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(761, 463);
        gp_list = new QGroupBox(Widget);
        gp_list->setObjectName(QString::fromUtf8("gp_list"));
        gp_list->setGeometry(QRect(10, 10, 481, 341));
        gp_list->setFlat(false);
        btn_addfile = new QPushButton(gp_list);
        btn_addfile->setObjectName(QString::fromUtf8("btn_addfile"));
        btn_addfile->setGeometry(QRect(24, 310, 141, 31));
        btn_addfile->setCursor(QCursor(Qt::ArrowCursor));
        btn_rmfile = new QPushButton(gp_list);
        btn_rmfile->setObjectName(QString::fromUtf8("btn_rmfile"));
        btn_rmfile->setGeometry(QRect(184, 310, 131, 31));
        btn_rmAllfile = new QPushButton(gp_list);
        btn_rmAllfile->setObjectName(QString::fromUtf8("btn_rmAllfile"));
        btn_rmAllfile->setGeometry(QRect(330, 310, 141, 31));
        pic_list = new QTableView(gp_list);
        pic_list->setObjectName(QString::fromUtf8("pic_list"));
        pic_list->setEnabled(true);
        pic_list->setGeometry(QRect(10, 30, 461, 271));
        gp_viev = new QGroupBox(Widget);
        gp_viev->setObjectName(QString::fromUtf8("gp_viev"));
        gp_viev->setGeometry(QRect(500, 10, 251, 201));
        label_view = new QLabel(gp_viev);
        label_view->setObjectName(QString::fromUtf8("label_view"));
        label_view->setGeometry(QRect(0, 30, 241, 171));
        gp_format_conf = new QGroupBox(Widget);
        gp_format_conf->setObjectName(QString::fromUtf8("gp_format_conf"));
        gp_format_conf->setGeometry(QRect(10, 360, 241, 91));
        QFont font;
        font.setPointSize(11);
        gp_format_conf->setFont(font);
        comboBox = new QComboBox(gp_format_conf);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 101, 31));
        label_7 = new QLabel(gp_format_conf);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 20, 101, 21));
        QFont font1;
        font1.setPointSize(12);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(gp_format_conf);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(140, 20, 101, 21));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox_quality = new QSpinBox(gp_format_conf);
        spinBox_quality->setObjectName(QString::fromUtf8("spinBox_quality"));
        spinBox_quality->setGeometry(QRect(140, 50, 81, 31));
        spinBox_quality->setMinimum(75);
        spinBox_quality->setMaximum(100);
        spinBox_quality->setValue(90);
        gp_save_conf = new QGroupBox(Widget);
        gp_save_conf->setObjectName(QString::fromUtf8("gp_save_conf"));
        gp_save_conf->setGeometry(QRect(260, 360, 381, 91));
        gp_save_conf->setFont(font);
        label_9 = new QLabel(gp_save_conf);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 61, 21));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_path = new QLineEdit(gp_save_conf);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));
        lineEdit_path->setGeometry(QRect(70, 19, 261, 31));
        btn_path_select = new QPushButton(gp_save_conf);
        btn_path_select->setObjectName(QString::fromUtf8("btn_path_select"));
        btn_path_select->setGeometry(QRect(340, 20, 31, 31));
        label_10 = new QLabel(gp_save_conf);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 60, 61, 21));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_name = new QLineEdit(gp_save_conf);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(70, 60, 301, 31));
        lineEdit_name->setMaxLength(256);
        btn_run = new QPushButton(Widget);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));
        btn_run->setGeometry(QRect(650, 360, 101, 41));
        tabW_cut_conf = new QTabWidget(Widget);
        tabW_cut_conf->setObjectName(QString::fromUtf8("tabW_cut_conf"));
        tabW_cut_conf->setGeometry(QRect(500, 220, 251, 131));
        bl = new QWidget();
        bl->setObjectName(QString::fromUtf8("bl"));
        spinBox_left = new QSpinBox(bl);
        spinBox_left->setObjectName(QString::fromUtf8("spinBox_left"));
        spinBox_left->setGeometry(QRect(51, 40, 51, 22));
        spinBox_left->setMaximum(99);
        label = new QLabel(bl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 31, 21));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(bl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 40, 41, 21));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(bl);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 10, 31, 21));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(bl);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 70, 31, 21));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_right = new QSpinBox(bl);
        spinBox_right->setObjectName(QString::fromUtf8("spinBox_right"));
        spinBox_right->setGeometry(QRect(140, 40, 51, 22));
        spinBox_right->setMaximum(99);
        spinBox_low = new QSpinBox(bl);
        spinBox_low->setObjectName(QString::fromUtf8("spinBox_low"));
        spinBox_low->setGeometry(QRect(100, 70, 51, 22));
        spinBox_low->setMaximum(99);
        spinBox_up = new QSpinBox(bl);
        spinBox_up->setObjectName(QString::fromUtf8("spinBox_up"));
        spinBox_up->setGeometry(QRect(100, 10, 51, 22));
        spinBox_up->setMaximum(99);
        label_11 = new QLabel(bl);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(150, 10, 31, 21));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12 = new QLabel(bl);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 40, 31, 21));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_13 = new QLabel(bl);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(150, 70, 31, 21));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabW_cut_conf->addTab(bl, QString());
        jf = new QWidget();
        jf->setObjectName(QString::fromUtf8("jf"));
        label_5 = new QLabel(jf);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 121, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(jf);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 50, 121, 31));
        label_6->setFont(font1);
        spinBox_row = new QSpinBox(jf);
        spinBox_row->setObjectName(QString::fromUtf8("spinBox_row"));
        spinBox_row->setGeometry(QRect(150, 20, 51, 22));
        spinBox_row->setMinimum(1);
        spinBox_row->setMaximum(10);
        spinBox_col = new QSpinBox(jf);
        spinBox_col->setObjectName(QString::fromUtf8("spinBox_col"));
        spinBox_col->setGeometry(QRect(150, 60, 51, 22));
        spinBox_col->setMinimum(1);
        spinBox_col->setMaximum(15);
        tabW_cut_conf->addTab(jf, QString());
        btn_close = new QPushButton(Widget);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(650, 410, 101, 41));

        retranslateUi(Widget);
        QObject::connect(btn_close, SIGNAL(clicked()), Widget, SLOT(close()));

        comboBox->setCurrentIndex(-1);
        tabW_cut_conf->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\233\276\347\211\207\350\243\201\345\210\207\346\211\213", 0, QApplication::UnicodeUTF8));
        gp_list->setTitle(QApplication::translate("Widget", "\345\276\205\345\244\204\347\220\206\347\232\204\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        btn_addfile->setText(QApplication::translate("Widget", "+(\346\267\273\345\212\240)", 0, QApplication::UnicodeUTF8));
        btn_rmfile->setText(QApplication::translate("Widget", "-(\347\247\273\351\231\244)", 0, QApplication::UnicodeUTF8));
        btn_rmAllfile->setText(QApplication::translate("Widget", "\347\247\273\351\231\244\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        gp_viev->setTitle(QApplication::translate("Widget", "\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        label_view->setText(QString());
        gp_format_conf->setTitle(QApplication::translate("Widget", "\350\276\223\345\207\272\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        comboBox->setCurrentText(QString());
        label_7->setText(QApplication::translate("Widget", "\350\276\223\345\207\272\346\240\274\345\274\217", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "\350\276\223\345\207\272\350\264\250\351\207\217", 0, QApplication::UnicodeUTF8));
        gp_save_conf->setTitle(QApplication::translate("Widget", "\350\276\223\345\207\272\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "\350\276\223\345\207\272\345\210\260:", 0, QApplication::UnicodeUTF8));
        btn_path_select->setText(QApplication::translate("Widget", "...", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "\350\276\223\345\207\272\345\220\215:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_name->setToolTip(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\276\223\345\207\272\346\226\207\344\273\266\345\220\215\350\256\276\347\275\256</span></p><p><span style=\" font-size:10pt; font-weight:600;\">{InputName}</span><span style=\" font-size:10pt;\">\357\274\232\344\273\243\346\214\207\345\216\237\346\226\207\344\273\266\345\220\215</span></p><p><span style=\" font-size:10pt; font-weight:600;\">{ID}</span><span style=\" font-size:10pt;\">\357\274\232\346\214\207\345\233\276\347\211\207\345\212\240\345\205\245\345\244\204\347\220\206\345\210\227\350\241\250\346\227\266\345\200\231\347\232\204\347\274\226\345\217\267(\351\241\272\345\272\217)</span></p><p><span style=\" font-size:10pt;\">\344\276\213\345\246\202:\346\267\273\345\212\240\344\272\206\344\270\211\345\274\240\345\276\205\345\244\204\347\220\206\347\232\204\345\233\276\347\211\207\357\274\214\346\226\207\344\273\266\345\220\215\346\230\257</span><span style=\" font-size:10pt; font-style:italic;\">&quot;a.jpg/b.jpg/c.jpg&quot;</span><span style=\""
                        " font-size:10pt;\">\357\274\216\350\276\223\345\207\272\346\226\207\344\273\266\345\220\215\346\226\271\345\274\217\344\270\272</span><span style=\" font-size:10pt; font-style:italic;\">&quot;{InputName}-{ID}&quot;</span></p><p><span style=\" font-size:10pt;\">\345\234\250\346\214\211\346\257\224\347\216\207\350\243\201\345\210\207\346\250\241\345\274\217\344\270\213\357\274\214\350\276\223\345\207\272\346\226\207\344\273\266\345\260\206\346\230\257</span><span style=\" font-size:10pt; font-style:italic; text-decoration: underline;\">&quot;a-1.jpg/b-2.jpg/c-3.jpg&quot;</span></p><p><span style=\" font-size:10pt;\">\345\234\250\346\214\211\346\250\252\347\272\265\345\220\221\345\235\207\345\210\207\346\250\241\345\274\217\344\270\213\357\274\214\345\201\207\350\256\276\346\250\252\345\220\221\345\210\206\344\270\272\357\274\222\344\273\275\347\272\265\345\220\221\345\210\206\344\270\272\357\274\223\344\273\275\357\274\214\350\276\223\345\207\272\346\226\207\344\273\266\345\220\215\345\260\206\346\230\257</span>"
                        "<span style=\" font-size:10pt; font-style:italic; text-decoration: underline;\">&quot;a-1-1.jpg/a-1-2.jpg/a-1-3.jpg...a-1-6.jpg/b-2-1.jpg/.../b-2-6.jpg/c-3-1.jpg/.../c-1-6.jpg&quot;</span><span style=\" font-size:10pt;\">\345\205\261</span><span style=\" font-size:10pt; font-weight:600;\">\357\274\221\357\274\230</span><span style=\" font-size:10pt;\">\344\270\252\346\226\207\344\273\266\357\274\216</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_name->setText(QApplication::translate("Widget", "{InputName}-{ID}", 0, QApplication::UnicodeUTF8));
        btn_run->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\345\267\246:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "%:\345\217\263", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\344\270\212:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\344\270\213:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget", "%", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget", "%", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Widget", "%", 0, QApplication::UnicodeUTF8));
        tabW_cut_conf->setTabText(tabW_cut_conf->indexOf(bl), QApplication::translate("Widget", "\346\214\211\346\257\224\344\276\213\350\243\201\345\210\207", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\346\250\252\345\220\221\345\235\207\345\210\206\344\270\272(\344\273\275):", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\347\272\265\345\220\221\345\235\207\345\210\206\344\270\272(\344\273\275):", 0, QApplication::UnicodeUTF8));
        tabW_cut_conf->setTabText(tabW_cut_conf->indexOf(jf), QApplication::translate("Widget", "\346\250\252\347\272\265\345\220\221\345\235\207\345\210\206\350\243\201\345\210\207", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICCUT_H
