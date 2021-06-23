#include "inputcheck.h"

bool idCheck(QString input){

    //有字符不是数字就返回false
    for(int i=0;i<input.length();++i){
        if(!input[i].isNumber()) return false;
    }

    //第一个数字不能是0
    if(input[0]=='0') return false;

    return true;
}

bool modelCheck(QString input){

    for(int i=0;i<input.length();++i){
        if((!input[i].isNumber())&&(!input[i].isLetter())&&(input[i]!=" ")) return false;
    }

    return true;
}

bool fromCheck(QString input){

    for(int i=0;i<input.length();++i){
        if((!input[i].isNumber())&&(!input[i].isLetter())&&(input[i]!=" ")) return false;
    }

    return true;
}

bool feeCheck(QString input){

    for(int i=0;i<input.length();++i){
        if(!(input[i].isNumber())&&(input[i]!='.')) return false;
    }

    return true;

}

bool dateCheck(QString input){

    if(input.length()!=8) return false;

    for(int i=0;i<input.length();++i){
        if(!input[i].isNumber()) return false;
    }

    //年月日合法性判断
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int rdays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int year,month,day,dayss;
    year = input.mid(0,4).toInt();
    month = input.mid(4,2).toInt();
    day = input.mid(6,2).toInt();

    if(year<1900||year>2100) return false;//年

    if(month==0||month>=13) return false;//月

    if(((year%4==0)&&(year%100!=0))||(year%400==0))//日
    {
        dayss = rdays[month-1];
    }
    else{
        dayss = days[month-1];
    }


    if(day<=dayss&&day>0) return true;
    else return false;

}

bool idRepeatCheck(int id){
    QFile file("car.txt");//打开文件
    file.open(QIODevice::Text|QIODevice::ReadOnly);//以只读方式打开文件
    if(file.isOpen()){
        return true;
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
    if(cl.head->next==NULL){
        return true;
    }
    else cl.deleteLastCar();

    file.close();

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
        QMessageBox::about(NULL,"ERROR","The id is existed!");
        return false;
    }

    return true;
}

