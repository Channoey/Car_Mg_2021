#ifndef CARFEESORTWIDGET_H
#define CARFEESORTWIDGET_H

#include <QWidget>

namespace Ui {
class carFeeSortWidget;
}

class carFeeSortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit carFeeSortWidget(QWidget *parent = nullptr);
    ~carFeeSortWidget();

private:
    Ui::carFeeSortWidget *ui;
};

#endif // CARFEESORTWIDGET_H
