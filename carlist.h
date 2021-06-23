#ifndef CARLIST_H
#define CARLIST_H
#include"car.h"

class carList
{
public:
    carList();
    ~carList();
    void addCar(car* input);
    void deleteCar(int id);
    void deleteLastCar();
    void sortByAllFee();
    void pSwap(car*,car*);
    int getSize() const;
    car *head;
    private:

    int size;
};

#endif // CARLIST_H
