// Реализовать класс Date, хранящий в себе информацию о дате 
//(год, месяц, число, час, минута, секунда, эра). За эру отвечает поле isOurEra типа bool 
//(true – наша эра, false – до нашей эры).В классе Date должны быть реализованы методы со
// следующей сигнатурой: add/subtract(year, month, day, hour, minute, second), 
//которые должны возвращать новый объект класса Date.
// В классе Date должны быть перегружены следующие операторы: 
//оператор копирования =, 
//Датой инициализации по умолчанию должна быть 1 января 1960 года, 00 часов, 00 минут, 00 секунд.
// Должно учитываться, что год может быть високосным.Нарисовать UML диаграмму.
// Проверять работоспособность программы будем лично на паре!



#include<iostream>
using namespace std;

class Date{

private:
     unsigned int year;
     unsigned int month;
     unsigned int day;
     unsigned int hour;
     unsigned int minute;
     unsigned int second;
    bool isOurEra;

public:
//default initialization
Date() {year = 1960 ; month = 1 ; day = 1 ; hour = 0 ; minute = 0 ; second = 0 ; isOurEra = true;}
//initialization
Date( short int y,  short int m,  short int d , short int h, short int mm, short int s,bool isOE ) {
           year = y;
           month = m;
           day = d;
           hour = h;
           minute = mm;
           second = s;
           isOurEra = isOE; 
        }
//method for add date
Date add(short int y,short int m ,short int d,short int h, short int min ,short int s){
 Date dat;
 if (isOurEra) year += y ; 
    else year -= y;
  dat.year = year;  
  month += m;
  dat.month = m;
  day += d;
  dat.day = d;
  hour += h;
  dat.hour = h;
  minute += min;
  dat.minute = min;
  second += s;
  dat.second = s;
    return dat;
}
//method for substract date
Date subtract(short int y,short int m ,short int d,short int h, short int min ,short int s){
    Date dat;
 if (isOurEra) year -= y ; 
    else year += y;
  dat.year = year;  
  month -= m;
  dat.month = m;
  day -= d;
  dat.day = d;
  hour -= h;
  dat.hour = h;
  minute -= min;
  dat.minute = min;
  second -= s;
  dat.second = s;
    return dat;
}
//overload for "<<"
friend ostream& operator<<(ostream& os,const Date& data){
os << "Date: ["<<data.year<<" year, "<<data.month<<" month, "<<data.day<<" day, ";
os <<data.hour<<" hours, "<<data.minute<<" minutes, "<<data.second<<" sec., ";
if(data.isOurEra) os<<"Our Era]"; 
    else os<<"Previous Era";
    return os;
}
//overload for "<"
 bool operator < ( const Date& d2 ){
   if((isOurEra == false) and (d2.isOurEra == true)){
    return true;
   }

   if((isOurEra == true) and (d2.isOurEra == false)){
    return false;
   }

   if(!isOurEra){
        if(year<d2.year) return true; 
            else if(year>d2.year) return false;
        if(month<d2.month) return true; 
            else if(month>d2.month) return false;
        if(day<d2.day) return true; 
            else if(day>d2.day) return false;
        if(hour<d2.hour) return true; 
            else if(hour>d2.hour) return false;
        if(minute<d2.minute) return true; 
            else if(minute>d2.minute) return false;  
        if(second<d2.second) return true; 
            else if(second>d2.second) return false;      
        return false;
        
   } else {
         if(year>d2.year) return true; 
            else if(year<d2.year) return false;
        if(month>d2.month) return true; 
            else if(month<d2.month) return false;
        if(day>d2.day) return true; 
            else if(day<d2.day) return false;
        if(hour>d2.hour) return true; 
            else if(hour<d2.hour) return false;
        if(minute>d2.minute) return true; 
            else if(minute<d2.minute) return false;  
        if(second>d2.second) return true; 
            else if(second<d2.second) return false;      
        return false;
   }

}
//overload for ">"
bool operator > (const Date& d2 ){
   if((isOurEra == true) and (d2.isOurEra == false)){
    return true;
   }

   if((isOurEra == false) and (d2.isOurEra == true)){
    return false;
   }

   if(!isOurEra){
        if(year<d2.year) return true; 
            else if(year>d2.year) return false;
        if(month<d2.month) return true; 
            else if(month>d2.month) return false;
        if(day<d2.day) return true; 
            else if(day>d2.day) return false;
        if(hour<d2.hour) return true; 
            else if(hour>d2.hour) return false;
        if(minute<d2.minute) return true; 
            else if(minute>d2.minute) return false;  
        if(second<d2.second) return true; 
            else if(second>d2.second) return false;      
        return false;
        
   } else {
         if(year>d2.year) return true; 
            else if(year<d2.year) return false;
        if(month>d2.month) return true; 
            else if(month<d2.month) return false;
        if(day>d2.day) return true; 
            else if(day<d2.day) return false;
        if(hour>d2.hour) return true; 
            else if(hour<d2.hour) return false;
        if(minute>d2.minute) return true; 
            else if(minute<d2.minute) return false;  
        if(second>d2.second) return true; 
            else if(second<d2.second) return false;      
        return false;
   }

}
//overload operator "=="
 bool operator == ( const Date& d2){
    if(isOurEra!=d2.isOurEra) return false;
    if((year==d2.year) and (month==d2.month) and (day==d2.day) and (hour==d2.hour) and (minute==d2.minute) and (second==d2.second) ){
       return true; 
    } else return false;
}

//overload operator "+"
Date operator + (const Date& d){
    if(isOurEra==d.isOurEra){
        second+=d.second;
        if(second>60){
            second-=60;
            minute+=1;
        }  
        minute+=d.minute;
        if(minute>60){
            minute-=60;
            hour+=1;
        }
        hour+=d.hour;
        if(hour>24){
            hour-=24;
            day+=1;
        }
        day+=d.day;
        if(day>30){
            day-=30;
            month+=1;
        }
        month+=d.month;
        if(month>12){
            year+=1;
            month-=12;
        }
        year+=d.year;
        

    } 
   return *this; 
}

//overload operator "+="
 void operator += (const Date& d){
   *this = *this + d;
}

//overload operator "-"
Date operator - (const Date& d){
    if(isOurEra==d.isOurEra){
        second-=d.second;
        if(second<0){
            second+=60;
            minute-=1;
        }  
        minute-=d.minute;
        if(minute<0){
            minute+=60;
            hour-=1;
        }
        hour-=d.hour;
        if(hour<0){
            hour+=24;
            day-=1;
        }
        day-=d.day;
        if(day<0){
            day+=30;
            month-=1;
        }
        month-=d.month;
        if(month<0){
            year-=1;
            month+=12;
        }
        year-=d.year;
    } 
    return *this;
}


//overload operator "-="
void operator -= (const Date& d){
   *this = *this - d;
}
//overload operator "="
void operator = (const Date& d){
   isOurEra = d.isOurEra;
   year = d.year;
   month = d.month;
   day = d.day;
   hour = d.hour;
   minute = d.minute;
   second = d.second;
}

void getDate(){
    cout<<year<<" "<<month<<" "<<day<<" "<<hour<<" "<<minute<<" "<<second<<endl;
}

bool isVis(Date data){
    if(!(data.year%100)){
        if(!(data.year%400)) return true;
    }
    if(!(data.year%4)) return true;
        else return false;
}

};




int main(){
Date data ;
Date data1(1960,1,1,0,0,5,true);
data.getDate();
data1.getDate();
data.add(1,2,12,12,12,45);
data.getDate();
data.subtract(1,2,12,12,12,45);
data.getDate();
data1.getDate();
cout<<(data1==data)<<endl;
Date data3;
data3 = data1+data1; 
data = data3;
cout<<data;

}