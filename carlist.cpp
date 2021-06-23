#include "carlist.h"

carList::carList()
{
    this->head = new car;
    this->head->next = NULL;
    this->size = 0;
}

carList::~carList(){
    car *p = this->head->next;
    car *temp = nullptr;
    while(p!=nullptr){
        temp = p;
        p = p->next;
        delete temp;
    }
    delete head;
}

void carList::addCar(car *input){
    car *p1 = this->head;
    car *p2 = new car;
    double basicFee;
    if(input->getTypeNum() == 1) basicFee = 2000;
    if(input->getTypeNum() == 2) basicFee = 1000;
    if(input->getTypeNum() == 3) basicFee = 1500;
    p2->setBasicFee(basicFee);
    p2->setDate(input->getDate());
    p2->setFrom(input->getFrom());
    p2->setId(input->getId());
    p2->setMileAll(input->getMileAll());
    p2->setMileUnit(input->getMileUnit());
    p2->setModel(input->getModel());
    p2->setRoadFee(input->getRoadFee());
    p2->setType(input->getTypeNum());
    p2->refreshAllFee();
    while(p1->next!=NULL) p1 = p1->next;
    p2->next = NULL;
    p1->next = p2;
    ++size;
}

void carList::deleteCar(int id){
    car *pre = this->head,*p = this->head->next;
    while(p->getId()!=id) p = p->next;
    while(pre->next!=p) pre = pre->next;
    pre->next = p->next;
    delete p;
    --size;
}

int carList::getSize() const{return this->size;}

void carList::deleteLastCar(){
    car* lastCar = this->head;
    car* pre = this->head;
    while(lastCar->next!=NULL) lastCar = lastCar->next;
    while(pre->next!=lastCar) pre = pre->next;
    pre->next = NULL;
    delete lastCar;
    this->size--;
}

void carList::sortByAllFee(){
    int tempLen = this->getSize()-1;
    car* p = this->head->next;
    for(int i=0;i<this->getSize();++i){//冒泡降序
        for(int j=tempLen;j>=1;--j,p = p->next){
            if(p->getAllFee()<p->next->getAllFee()){
                pSwap(p,p->next);
            }
        }
        p = this->head->next;//每次都从头开始冒泡
    }
}

void carList::pSwap(car *c1, car *c2){
    int date,type,id;
    double mileAll,mileUnit,basicFee,roadFee,allFee;
    QString from,model;

    date = c2->getDate();
    c2->setDate(c1->getDate());
    c1->setDate(date);

    type = c2->getTypeNum();
    c2->setType(c1->getTypeNum());
    c1->setType(type);

    id = c2->getId();
    c2->setId(c1->getId());
    c1->setId(id);

    mileAll = c2->getMileAll();
    c2->setMileAll(c1->getMileAll());
    c1->setMileAll(mileAll);

    mileUnit = c2->getMileUnit();
    c2->setDate(c1->getDate());
    c1->setDate(mileUnit);

    basicFee = c2->getBasicFee();
    c2->setBasicFee(c1->getBasicFee());
    c1->setDate(basicFee);

    roadFee = c2->getRoadFee();
    c2->setRoadFee(c1->getRoadFee());
    c1->setRoadFee(roadFee);

    allFee = c2->getAllFee();
    c2->setAllFee(c1->getAllFee());
    c1->setAllFee(allFee);
}
