#include "cardelwidget.h"
#include "ui_cardelwidget.h"

carDelWidget::carDelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carDelWidget)
{
    ui->setupUi(this);
}

carDelWidget::~carDelWidget()
{
    delete ui;
}
