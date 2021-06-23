#include "sortwidget.h"
#include "ui_sortwidget.h"
#include<algorithm>

sortWidget::sortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sortWidget)
{
    ui->setupUi(this);
    sortButtonGroup = new QButtonGroup();
    sortButtonGroup->addButton(ui->busRadioButton,1);
    sortButtonGroup->addButton(ui->carRadioButton,2);
    sortButtonGroup->addButton(ui->truckRadioButton,3);//保证与getTypeNum()里的数字相对应
    ui->tableWidget->setColumnCount(2);

    QStringList headerLabels;//表头信息
    headerLabels<<tr("ID")<<tr("All Fee");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);//设置水平表头标签
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//根据总宽度调整列宽
    ui->busRadioButton->setChecked(true);
}

sortWidget::~sortWidget(){
    delete ui;
}

void sortWidget::on_returnButton_clicked(){
    emit display(0);
}

void sortWidget::on_sortButton_clicked(){
    ui->tableWidget->clearContents();
    carList cl;

    QFile file("car.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);//只读方式打开文件
    if(!file.isOpen()){
        QMessageBox::about(NULL,"ERROR",file.errorString());
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        int date,type,id;
        double mileAll,mileUnit,basicFee,roadFee,allFee;
        QString from,model;
        in>>id>>type>>model>>from>>basicFee>>
              roadFee>>mileUnit>>mileAll>>date>>allFee;
        car c(id,date,mileAll,mileUnit,roadFee,from,type,model);
        cl.addCar(&c);
    }
    cl.deleteLastCar();
    file.close();

    carList cls;//筛选后的链表
    int sortTag = sortButtonGroup->checkedId();//取选择选项的id
    car* p =cl.head->next;
    while(p!=NULL){//筛选
        if(p->getTypeNum()==sortTag){
           car c(p->getId(),p->getDate(),p->getMileAll(),p->getMileUnit(),p->getRoadFee(),p->getFrom().replace("_"," "),p->getTypeNum(),p->getModel().replace("_"," "));
            cls.addCar(&c);
        }
        p = p->next;
    }

    if(cls.head->next == NULL){
        QMessageBox::about(NULL,"Car Management System","No information!");
        return;
    }

    cls.sortByAllFee();

    ui->tableWidget->setRowCount(cls.getSize());//将表格行数调成和车辆数相等

    p = cls.head->next;
    for(int i = 0;i < cls.getSize();++i,p = p->next){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(p->getId())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(p->getAllFee())));
    }

}
