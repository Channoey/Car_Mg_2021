#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>
#include<QFile>
#include<QMessageBox>
#include<QtDebug>
#include<QButtonGroup>
#include"carlist.h"
#include"inputcheck.h"

namespace Ui {
class modifyWidget;
}

class modifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit modifyWidget(QWidget *parent = nullptr);
    ~modifyWidget();

private:
    Ui::modifyWidget *ui;
    QButtonGroup *typeButtonGroup;

signals:
    void display(int);

private slots:
    void on_returnButton_clicked();
    void on_deleteButton_clicked();
    void on_modifyButton_clicked();
};

#endif // MODIFYWIDGET_H
