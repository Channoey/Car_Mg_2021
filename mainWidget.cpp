#include "mainWidget.h"
#include "ui_mainwidget.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    menuwidget = new menuWidget;
    addwidget = new addWidget;
    selectwidget = new selectWidget;
    modifywidget = new modifyWidget;
    sortwidget = new sortWidget;
    stacklayout = new QStackedLayout;

    stacklayout->addWidget(menuwidget);
    stacklayout->addWidget(addwidget);
    stacklayout->addWidget(selectwidget);
    stacklayout->addWidget(modifywidget);
    stacklayout->addWidget(sortwidget);

    setLayout(stacklayout);
    //连接各个界面的返回按钮和menu以及menu上各个界面的button
    connect(menuwidget,&menuWidget::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(addwidget,&addWidget::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(selectwidget,&selectWidget::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(modifywidget,&modifyWidget::display,stacklayout,&QStackedLayout::setCurrentIndex);
    connect(sortwidget,&sortWidget::display,stacklayout,&QStackedLayout::setCurrentIndex);

}

mainWidget::~mainWidget()
{
    delete ui;
}
