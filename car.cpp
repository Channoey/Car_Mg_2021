#include "car.h"
#include<QString>

car::car()
{
    this->id = -1;
    this->roadFee = 0;
    this->mileAll = 0;
    this->date = 0;
    this->allFee = 0;
    this->basicFee = 0;
    this->from = "";
    this->mileUnit = 0;
    this->model = "";
    this->type = 0;
}
car::car(int id,int date,double mileAll,double mileUnit,double roadFee,
         QString from,int type,QString model){

    if(type == 1) this->basicFee = 2000;
    else if(type == 2) this->basicFee = 1000;
    else if(type == 3) this->basicFee = 1500;
    this->id = id;
    this->roadFee = roadFee;
    this->mileAll = mileAll;
    this->date = date;
    this->allFee = allFee;
    this->from = from;
    this->mileUnit = mileUnit;
    this->model = model;
    this->type = type;
    this->refreshAllFee();
}
car::~car(){}

int car::getDate() const { return this->date; }
void car::setDate(int date_input) { this->date = date_input; }

int car::getId() const { return this->id; }
void car::setId(int id_input) { this->id = id_input; }

double car::getMileAll() const { return this->mileAll; }
void car::setMileAll(double mileAllInput) { this->mileAll = mileAllInput; }

double car::getMileUnit() const { return this->mileUnit; }
void car::setMileUnit(double mileUnitInput) { this->mileUnit = mileUnitInput; }

double car::getBasicFee() const{ return this->basicFee; }
void car::setBasicFee(double basicFeeInput) { this->basicFee = basicFeeInput; }

double car::getRoadFee() const { return this->roadFee; }
void car::setRoadFee(double roadFeeInput) { this->roadFee = roadFeeInput; }

double car::getAllFee() const { return this->allFee; }
void car::setAllFee(double allFeeInput){this->allFee = allFeeInput;}
void car::refreshAllFee() { this->allFee = this->basicFee + this->roadFee + (this->mileUnit) * (this->mileAll); }

QString car::getFrom() const { return this->from; }
void car::setFrom(QString fromInput) { this->from = fromInput; }

QString car::getModel() const { return this->model; }
void car::setModel(QString modelInput) { this->model = modelInput; }

QString car::getType() {
    QString s1 = "bus";
    QString s2 = "car";
    QString s3 = "truck";
    if (this->type == 1) return s1;
    else if (this->type == 2) return s2;
    else if (this->type == 3) return s3;
}
void car::setType(int typeCodeInput) { this->type = typeCodeInput; }
int car::getTypeNum() const{ return this->type; }

car car::operator=(car & input){
    car temp;
    temp.setId(input.getId());
    temp.setBasicFee(input.getBasicFee());
    temp.setDate(input.getDate());
    temp.setFrom(input.getFrom());
    temp.setMileUnit(input.getMileUnit());
    temp.setModel(input.getModel());
    temp.setRoadFee(input.getRoadFee());
    temp.setType(input.getTypeNum());
    temp.refreshAllFee();
    return temp;
}

QString numToType(int type){
    QString s1 = "bus";
    QString s2 = "car";
    QString s3 = "truck";
    if (type == 1) return s1;
    else if (type == 2) return s2;
    else if (type == 3) return s3;
}
