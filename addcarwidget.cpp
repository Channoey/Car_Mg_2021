#include "addcarwidget.h"
#include "ui_addcarwidget.h"

addCarWidget::addCarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addCarWidget)
{
    ui->setupUi(this);
}

addCarWidget::~addCarWidget()
{
    delete ui;
}
