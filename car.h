#ifndef CAR_H
#define CAR_H

#include<QString>
#include<iostream>

class car
{
public:
    car();
    car(int id,int date,double mileAll,double mileUnit,double roadFee,
        QString from,int type,QString model);
    ~car();

    int getDate() const;
    void setDate(int);

    int getId() const;
    void setId(int);

    double getMileAll() const;
    void setMileAll(double);

    double getMileUnit() const;
    void setMileUnit(double);

    double getBasicFee() const;
    void setBasicFee(double);

    double getRoadFee() const;
    void setRoadFee(double);

    double getAllFee() const;
    void setAllFee(double);
    void refreshAllFee();

    QString getFrom() const;
    void setFrom(QString);

    QString getModel() const;
    void setModel(QString);

    QString getType();
    void setType(int);
    int getTypeNum() const;

    car *next;

    car operator=(car&);//车赋值重载

private:
    int date,type,id;
    double mileAll,mileUnit,basicFee,roadFee,allFee;
    QString from,model;
};

QString numToType(int type);

#endif // CAR_H
