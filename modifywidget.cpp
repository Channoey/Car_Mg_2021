#include "modifywidget.h"
#include "ui_modifywidget.h"

modifyWidget::modifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifyWidget)
{
    ui->setupUi(this);
    typeButtonGroup = new QButtonGroup();
    typeButtonGroup->addButton(ui->busRadioButton,1);
    typeButtonGroup->addButton(ui->carRadioButton,2);
    typeButtonGroup->addButton(ui->truckRadioButton,3);
    ui->carRadioButton->setChecked(true);//默认为car
}

modifyWidget::~modifyWidget()
{
    delete ui;
}

void modifyWidget::on_returnButton_clicked(){
    ui->basicFee->clear();
    ui->dateEdit->clear();
    ui->fromEdit->clear();
    ui->mileAllEdit->clear();
    ui->mileUnitEdit->clear();
    ui->modelEdit->clear();
    ui->roadFee->clear();
    ui->idEdit->clear();
    emit display(0);
}

//删除
void modifyWidget::on_deleteButton_clicked(){

//空判断
    if(ui->idEdit->text()==""){
        QMessageBox::about(NULL,"Car Management System","ID cannot be null!");
        return;
    }

//id判断
        if(!idCheck(ui->idEdit->text())){
            QMessageBox::about(NULL,"Input Error","The id you input isn't valid!");
            return;
        }

    QFile file("car.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);//以只读方式打开文件
    if(!file.isOpen()){
        QMessageBox::about(NULL,"ERROR!",file.errorString());//反馈问题
        return;
    }

    carList cl;
    QTextStream in(&file);//创建文本流
    while(!in.atEnd()){
        int date,type,id;
        double mileAll,mileUnit,basicFee,roadFee,allFee;
        QString from,model;
        in>>id>>type>>model>>from>>basicFee>>
              roadFee>>mileUnit>>mileAll>>date>>allFee;
        car c(id,date,mileAll,mileUnit,roadFee,from.replace("_"," "),type,model.replace("_"," "));
        cl.addCar(&c);
    }
    cl.deleteLastCar();//删除最后一行多读的垃圾数据
    file.close();


    int id = ui->idEdit->text().toInt();//拿文本框里的id
    bool flag = false;//记录是否删除
    car *p = cl.head->next;
    for(int i=0;i<cl.getSize();++i){
        if(p->getId()==id){
            QMessageBox msgBox;//新建一个对话框提示要删除的对象的信息
            msgBox.setText("The car will be deleted:\n\nType:   "
                            +p->getType()+"\nModel:   "
                            +p->getModel().replace("_"," ")+"\nFrom:   "
                            +p->getFrom().replace("_"," ")+"\nBasic Fee:   "
                            +QString::number(p->getBasicFee())+" yuan\nRoad Fee:   "
                            +QString::number(p->getRoadFee())+" yuan\nUnit Fee:   "
                            +QString::number(p->getMileUnit())+" yuan/km\nAll Mile:   "
                            +QString::number(p->getMileAll())+" km\nDate:   "
                            +QString::number(p->getDate())+"\n");
             msgBox.setInformativeText("Do you want to save the change?");
             msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard);
             msgBox.setDefaultButton(QMessageBox::Save);
             int res = msgBox.exec();
             switch(res){
             case QMessageBox::Save:
                flag = true;
                cl.deleteCar(id);
                break;
             case QMessageBox::Discard:
                 return;
                 break;
             default:
                 break;
            }
        }
        else if(p==NULL) break;
        else p = p->next;
    }

    if(flag){
        QMessageBox::about(NULL,"Car Management System","Delete Success!");
        file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);//以只写覆盖方式打开文本文件
        if(!file.isOpen()){
            QMessageBox::about(NULL,"ERROR!",file.errorString());//反馈问题
            return;
        }

        QTextStream out(&file);
        p = cl.head->next;
        while(p!=NULL){
            out<<p->getId()<<" "<<p->getTypeNum()<<" "<<p->getModel().replace("_"," ")<<" "<<p->getFrom().replace("_"," ")<<" "<<p->getBasicFee()<<" "<<p->getRoadFee()<<" "<<p->getMileUnit()<<" "<<p->getMileAll()<<" "<<p->getDate()<<" "<<p->getAllFee()<<endl;
            p = p->next;
        }
            file.close();
    }else{
        QMessageBox::about(NULL,"Car Management System","You must have input a wrong id!");
    }

    ui->idEdit->clear();
}

//修改
void modifyWidget::on_modifyButton_clicked(){

    int typeInput = typeButtonGroup->checkedId();

//空判断
    if(ui->idEdit->text()==""||ui->modelEdit->text()==""||
            ui->fromEdit->text()==""||ui->basicFee->text()==""||ui->roadFee->text()==""||ui->mileUnitEdit->text()==""||
            ui->mileAllEdit->text()==""||ui->dateEdit->text()==""){
        QMessageBox::about(NULL,"Car Management System","Something is null!");
        return;
    }
//id判断
        if(!idCheck(ui->idEdit->text())){
            QMessageBox::about(NULL,"Input Error","The id you input isn't valid!");
            return;
        }

//model判断
        if(!modelCheck(ui->modelEdit->text())){
            QMessageBox::about(NULL,"Input Error","The model you input isn't valid!");
            return;
        }

//from判断
        if(!fromCheck(ui->fromEdit->text())){
            QMessageBox::about(NULL,"Input Error","The from you input isn't valid!");
            return;
        }

//roadfee判断
        if(!feeCheck(ui->roadFee->text())){
            QMessageBox::about(NULL,"Input Error","The road fee you input isn't valid!");
            return;
        }

//unitfee判断
        if(!feeCheck(ui->mileUnitEdit->text())){
            QMessageBox::about(NULL,"Input Error","The unit fee you input isn't valid!");
            return;
        }

//mileall判断
        if(!feeCheck(ui->mileAllEdit->text())){
            QMessageBox::about(NULL,"Input Error","The all mile you input isn't valid!");
            return;
        }

//buydate判断
        if(!dateCheck(ui->dateEdit->text())){
            QMessageBox::about(NULL,"Input Error","The date you input isn't valid!");
            return;
        }


//读文件
    QFile file("car.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen()){
        QMessageBox::about(NULL,"ERROR",file.errorString());
        return;
    }

//存链表
    carList cl;
    QTextStream in(&file);
    while(!in.atEnd()){
        int date,type,id;
        double mileAll,mileUnit,basicFee,roadFee,allFee;
        QString from,model;
        in>>id>>type>>model>>from>>basicFee>>
              roadFee>>mileUnit>>mileAll>>date>>allFee;
        car c(id,date,mileAll,mileUnit,roadFee,from.replace("_"," "),type,model.replace("_"," "));
        cl.addCar(&c);
    }
    cl.deleteLastCar();//删除最后一行多读的垃圾数据
    file.close();

//修改车辆信息
    int id = ui->idEdit->text().toInt();
    car *p = cl.head->next;
    bool flag = false,flag2 = true;


//先判断能否找到车辆，并返回车辆信息
    for(int i=0;i<cl.getSize();++i){
        if(p->getId()==id){

            flag = true;

            QMessageBox msgBox;//新建一个对话框判断是否要保存修改信息
            msgBox.setText("The car will be modified:\n\nType:   "
                            +p->getType()+" -> "+numToType(typeInput)+"\nModel:   "
                            +p->getModel().replace("_"," ")+" -> "+ui->modelEdit->text()+"\nFrom:   "
                            +p->getFrom().replace("_"," ")+" -> "+ui->fromEdit->text()+"\nBasic Fee:   "
                            +QString::number(p->getBasicFee())+" -> "+ui->basicFee->text()+" yuan\nRoad Fee:   "
                            +QString::number(p->getRoadFee())+" -> "+ui->roadFee->text()+" yuan\nUnit Fee:   "
                            +QString::number(p->getMileUnit())+" -> "+ui->mileUnitEdit->text()+" yuan/km\nAll Mile:   "
                            +QString::number(p->getMileAll())+" -> "+ui->mileAllEdit->text()+" km\nDate:   "
                            +QString::number(p->getDate())+" -> "+ui->dateEdit->text()+"\n");
             msgBox.setInformativeText("Do you want to save the changes?");
             msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard);
             msgBox.setDefaultButton(QMessageBox::Save);
             int res = msgBox.exec();
             switch(res){
                case QMessageBox::Save:

                    p->setBasicFee(ui->basicFee->text().toDouble());
                    p->setDate(ui->dateEdit->text().toDouble());
                    p->setFrom(ui->fromEdit->text().replace(" ","_"));
                    p->setMileAll(ui->mileAllEdit->text().toDouble());
                    p->setMileUnit(ui->mileUnitEdit->text().toDouble());
                    p->setModel(ui->modelEdit->text().replace(" ","_"));
                    p->setRoadFee(ui->roadFee->text().toDouble());
                    p->setType(typeInput);
                    p->refreshAllFee();
                    break;
                 case QMessageBox::Discard:
                    flag2 = false;
                    return;
                 default:
                    break;
             }
        }else p = p->next;
    }

    if(flag&&flag2){//若找到对应的车并且是否修改对话框选择修改，则改文件

        file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);//以只读覆盖方式打开文件
        if(!file.isOpen()){
            QMessageBox::about(NULL,"ERROR",file.errorString());
            return;
        }
        QTextStream out(&file);
        p = cl.head->next;
        while(p!=NULL){
            out<<p->getId()<<" "<<p->getTypeNum()<<" "<<p->getModel()<<" "<<p->getFrom()<<" "<<p->getBasicFee()<<" "<<p->getRoadFee()<<" "<<p->getMileUnit()<<" "<<p->getMileAll()<<" "<<p->getDate()<<" "<<p->getAllFee()<<endl;
            p = p->next;
        }
        file.close();
        QMessageBox::about(NULL,"Car Management System","Modify success！！");
        ui->basicFee->clear();
        ui->dateEdit->clear();
        ui->fromEdit->clear();
        ui->mileAllEdit->clear();
        ui->mileUnitEdit->clear();
        ui->modelEdit->clear();
        ui->roadFee->clear();
        ui->idEdit->clear();
    }
    else if(flag==false){
        QMessageBox::about(NULL,"ERROR","You must have input a wrong ID!");
        return;
    }
}
