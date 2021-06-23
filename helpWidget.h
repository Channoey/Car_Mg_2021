#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>

namespace Ui {
class helpWidget;
}

class helpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit helpWidget(QWidget *parent = nullptr);
    ~helpWidget();

private:
    Ui::helpWidget *ui;

signals:
    void display(int);
};

#endif // HELPWIDGET_H
