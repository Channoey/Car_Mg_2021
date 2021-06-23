#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

namespace Ui {
class menuWidget;
}

class menuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit menuWidget(QWidget *parent = nullptr);
    ~menuWidget();

private:
    Ui::menuWidget *ui;

signals:
    void display(int);

private slots:
    void on_addButton_clicked();
    void on_selectButton_clicked();
    void on_modifyButton_clicked();
    void on_sortButton_clicked();
    void on_exitButton_clicked();

};

#endif // MENUWIDGET_H
