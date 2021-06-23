#include "selectwidget.h"
#include "ui_selectwidget.h"
#pragma execution_character_set(“utf-8”)

selectWidget::selectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectWidget)
{
    ui->setupUi(this);
}

selectWidget::~selectWidget()
{
    delete ui;
}

void selectWidget::on_returnButton_clicked(){
    ui->showBasicFeelabel->clear();
    ui->showDateLabel->clear();
    ui->showFromLabel->clear();
    ui->showMileAllLabel->clear();
    ui->showMileUnitLabel->clear();
    ui->showModelLabel->clear();
    ui->showRoadFeeLabel->clear();
    ui->showTypeLabel->clear();
    ui->idEdit->clear();
    ui->showAllFeeLabel->clear();
    emit display(0);
}

//id判断
void selectWidget::on_selectButton_clicked(){

    if(ui->idEdit->text()==""){
        QMessageBox::about(NULL,"Car Management System","Id is null!");
        return;
    }


    if(!idCheck(ui->idEdit->text())){
       QMessageBox::about(NULL,"Input Error","The id you input isn't valid!");
       return;
    }

    QFile file("car.txt");//打开文件
    file.open(QIODevice::ReadOnly|QIODevice::Text);//以只读方式打开文件
    if(!file.isOpen()){
        QMessageBox::about(NULL,"Car Managemrnt","File open error!");
        return;
    }

    carList cl;//创建链表
    QTextStream in(&file);//QT文本流读文件
    while(!in.atEnd()){//读到结尾
        int date,type,id;
        double mileAll,mileUnit,basicFee,roadFee,allFee;
        QString from,model;
        in>>id>>type>>model>>from>>basicFee>>
              roadFee>>mileUnit>>mileAll>>date>>allFee;
        car c(id,date,mileAll,mileUnit,roadFee,from.replace("_"," "),type,model.replace("_"," "));
        cl.addCar(&c);
    }
    cl.deleteLastCar();
    file.close();

    int id = ui->idEdit->text().toInt();
    car *p = cl.head->next;
    bool flag = false;
    for(int i=0;i<cl.getSize();++i){
        if(p->getId()==id){
            flag = true;
            break;
        }
        else if(p==NULL) break;
        else p = p->next;
    }

    if(flag){
        QString  unit1("yuan"),unit2("km");
        ui->showBasicFeelabel->setText(QString::number(p->getBasicFee())+"   "+unit1);
        ui->showDateLabel->setText(QString::number(p->getDate()));
        ui->showFromLabel->setText(p->getFrom().replace("_"," "));
        ui->showMileAllLabel->setText(QString::number(p->getMileAll())+"   "+unit1);
        ui->showMileUnitLabel->setText(QString::number(p->getMileUnit())+"   "+unit1+"/"+unit2);
        ui->showModelLabel->setText(p->getModel().replace("_"," "));
        ui->showRoadFeeLabel->setText(QString::number(p->getRoadFee())+"   "+unit1);
        ui->showTypeLabel->setText(p->getType());
        ui->showAllFeeLabel->setText(QString::number(p->getAllFee())+"   "+unit1);
    }
    else{
        QMessageBox::about(NULL,"Car Management System","You must have input a wrong number!!");
        return;
    }
}
