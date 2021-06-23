#ifndef ADDCARWIDGET_H
#define ADDCARWIDGET_H

#include <QWidget>

namespace Ui {
class addCarWidget;
}

class addCarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit addCarWidget(QWidget *parent = nullptr);
    ~addCarWidget();

private:
    Ui::addCarWidget *ui;
};

#endif // ADDCARWIDGET_H
