#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>
#include<QtDebug>
#include<QFile>
#include<QMessageBox>
#include"carlist.h"
#include"inputcheck.h"
#pragma execution_character_set(“utf-8”)

namespace Ui {
class selectWidget;
}

class selectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit selectWidget(QWidget *parent = nullptr);
    ~selectWidget();

private:
    Ui::selectWidget *ui;

signals:
    void display(int);

private slots:
    void on_returnButton_clicked();
    void on_selectButton_clicked();
};

#endif // SELECTWIDGET_H
