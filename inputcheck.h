#ifndef INPUTCHECK_H
#define INPUTCHECK_H
#include<QString>
#include<QFile>
#include"carlist.h"
#include"QTextStream"
#include"QMessageBox"

bool idCheck(QString input);
bool modelCheck(QString input);
bool fromCheck(QString input);
bool feeCheck(QString input);
bool dateCheck(QString input);
bool idRepeatCheck(int input);

#endif // INPUTCHECK_H
