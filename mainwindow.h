#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"carlist.h"
#include<QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

private slots:

private:
    Ui::MainWindow *ui;
    carList *neList;

};
#endif // MAINWINDOW_H
