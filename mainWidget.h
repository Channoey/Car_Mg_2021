#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QStackedLayout>
#include"menuwidget.h"
#include"addwidget.h"
#include"selectwidget.h"
#include"modifywidget.h"
#include"sortwidget.h"
#include"helpwidget.h"
namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;

    menuWidget *menuwidget;
    addWidget *addwidget;
    selectWidget *selectwidget;
    modifyWidget *modifywidget;
    sortWidget *sortwidget;
    QStackedLayout*stacklayout;
    helpWidget *helpwidget;
};

#endif // MAINWIDGET_H
