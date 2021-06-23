#include "carmodifywidget.h"
#include "ui_carmodifywidget.h"

carModifyWidget::carModifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carModifyWidget)
{
    ui->setupUi(this);
}

carModifyWidget::~carModifyWidget()
{
    delete ui;
}
