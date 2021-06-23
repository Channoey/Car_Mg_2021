#ifndef CARDELWIDGET_H
#define CARDELWIDGET_H

#include <QWidget>

namespace Ui {
class carDelWidget;
}

class carDelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit carDelWidget(QWidget *parent = nullptr);
    ~carDelWidget();

private:
    Ui::carDelWidget *ui;
};

#endif // CARDELWIDGET_H
