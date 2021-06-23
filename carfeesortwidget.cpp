#include "carfeesortwidget.h"
#include "ui_carfeesortwidget.h"

carFeeSortWidget::carFeeSortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carFeeSortWidget)
{
    ui->setupUi(this);
}

carFeeSortWidget::~carFeeSortWidget()
{
    delete ui;
}
