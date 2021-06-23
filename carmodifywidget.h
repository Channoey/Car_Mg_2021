#ifndef CARMODIFYWIDGET_H
#define CARMODIFYWIDGET_H

#include <QWidget>

namespace Ui {
class carModifyWidget;
}

class carModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit carModifyWidget(QWidget *parent = nullptr);
    ~carModifyWidget();

private:
    Ui::carModifyWidget *ui;
};

#endif // CARMODIFYWIDGET_H
