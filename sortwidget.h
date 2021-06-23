#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include<QButtonGroup>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include"carlist.h"

namespace Ui {
class sortWidget;
}

class sortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sortWidget(QWidget *parent = nullptr);
    ~sortWidget();

private:
    Ui::sortWidget *ui;
    QButtonGroup *sortButtonGroup;

signals:
    void display(int);

private slots:
    void on_returnButton_clicked();
    void on_sortButton_clicked();
};

#endif // SORTWIDGET_H
