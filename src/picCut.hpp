#ifndef PICCUT_HPP
#define PICCUT_HPP

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QImage>

class QStandardItemModel;
class QImage;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btn_addfile_clicked();

    void on_btn_rmAllfile_clicked();

    void on_pic_list_clicked(const QModelIndex &index);

    void draw_cut_line(int);

    void on_btn_run_clicked();

    void on_btn_path_select_clicked();

    void on_btn_rmfile_clicked();

private:
    Ui::Widget *ui;
    QStandardItemModel  *model;
    QImage      preview;
    QString     path;
    QStringList picFiles;
};

#endif // PICCUT_HPP
