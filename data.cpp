// Реализовать класс Date, хранящий в себе информацию о дате 
//(год, месяц, число, час, минута, секунда, эра). За эру отвечает поле isOurEra типа bool 
//(true – наша эра, false – до нашей эры).В классе Date должны быть реализованы методы со
// следующей сигнатурой: add/subtract(year, month, day, hour, minute, second), 
//которые должны возвращать новый объект класса Date.
//Датой инициализации по умолчанию должна быть 1 января 1960 года, 00 часов, 00 минут, 00 секунд.
// Должно учитываться, что год может быть високосным.Нарисовать UML диаграмму.
// Проверять работоспособность программы будем лично на паре!



#include<iostream>
#include <cmath>
using namespace std;

class Date {

private:
    int year;
    short int month;
    short int day;
    short int hour;
    short int minute;
    short int second;
    bool isOurEra;

public:

    int dayInM[13] = { 0,31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //default initialization
    Date() { year = 1960; month = 1; day = 1; hour = 0; minute = 0; second = 0; isOurEra = true; }
    //initialization
    Date(int y, short int m, short int d, short int h, short int mm, short int s, bool isOE) {
        year = abs(y);
        month = abs(m);
        day = abs(d);
        hour = abs(h);
        minute = abs(mm);
        second = abs(s);
        isOurEra = isOE;
    }
    //method for add date
    Date add(int y, short int m, short int d, short int h, short int min, short int s, bool isE) {
        Date fdata{ y,m,d,h,min,s,isE };
        *this = *this + fdata;
        return *this;
    }
    //method for substract date
    Date subtract(int y, short int m, short int d, short int h, short int min, short int s, bool isE) {
        Date fdata{ y,m,d,h,min,s,isE };
        *this = *this - fdata;
        return *this;
    }
    //overload for "<<"
    friend ostream& operator<<(ostream& os, const Date& data) {
        os << "Date: [" << data.year << " year, " << data.month << " month, " << data.day << " day, ";
        os << data.hour << " hours, " << data.minute << " minutes, " << data.second << " sec., ";
        if (data.isOurEra) os << "Our Era]";
        else os << "Previous Era";
        return os;
    }
    //overload for "<"
    bool operator < (const Date& d2) {
        if ((isOurEra == false) and (d2.isOurEra == true)) {
            return true;
        }

        if ((isOurEra == true) and (d2.isOurEra == false)) {
            return false;
        }

        if (!isOurEra) {
            if (year < d2.year) return true;
            else if (year > d2.year) return false;
            if (month < d2.month) return true;
            else if (month > d2.month) return false;
            if (day < d2.day) return true;
            else if (day > d2.day) return false;
            if (hour < d2.hour) return true;
            else if (hour > d2.hour) return false;
            if (minute < d2.minute) return true;
            else if (minute > d2.minute) return false;
            if (second < d2.second) return true;
            else if (second > d2.second) return false;
            return false;

        }
        else {
            if (year > d2.year) return true;
            else if (year < d2.year) return false;
            if (month > d2.month) return true;
            else if (month < d2.month) return false;
            if (day > d2.day) return true;
            else if (day < d2.day) return false;
            if (hour > d2.hour) return true;
            else if (hour < d2.hour) return false;
            if (minute > d2.minute) return true;
            else if (minute < d2.minute) return false;
            if (second > d2.second) return true;
            else if (second < d2.second) return false;
            return false;
        }

    }
    //overload for ">"
    bool operator > (const Date& d2) {
        if ((isOurEra == true) and (d2.isOurEra == false)) {
            return true;
        }

        if ((isOurEra == false) and (d2.isOurEra == true)) {
            return false;
        }

        if (!isOurEra) {
            if (year < d2.year) return true;
            else if (year > d2.year) return false;
            if (month < d2.month) return true;
            else if (month > d2.month) return false;
            if (day < d2.day) return true;
            else if (day > d2.day) return false;
            if (hour < d2.hour) return true;
            else if (hour > d2.hour) return false;
            if (minute < d2.minute) return true;
            else if (minute > d2.minute) return false;
            if (second < d2.second) return true;
            else if (second > d2.second) return false;
            return false;

        }
        else {
            if (year > d2.year) return true;
            else if (year < d2.year) return false;
            if (month > d2.month) return true;
            else if (month < d2.month) return false;
            if (day > d2.day) return true;
            else if (day < d2.day) return false;
            if (hour > d2.hour) return true;
            else if (hour < d2.hour) return false;
            if (minute > d2.minute) return true;
            else if (minute < d2.minute) return false;
            if (second > d2.second) return true;
            else if (second < d2.second) return false;
            return false;
        }

    }
    //overload operator "=="
    bool operator == (const Date& d2) {
        if (isOurEra != d2.isOurEra) return false;
        if ((year == d2.year) and (month == d2.month) and (day == d2.day) and (hour == d2.hour) and (minute == d2.minute) and (second == d2.second)) {
            return true;
        }
        else return false;
    }

    //overload operator "+"
    Date operator + (const Date& d) {
        if (isOurEra == d.isOurEra) {
            second += d.second;
            if (second > 60) {
                second -= 60;
                minute += 1;
            }
            minute += d.minute;
            if (minute >= 60) {
                minute -= 60;
                hour += 1;
            }
            hour += d.hour;
            if (hour >= 24) {
                hour -= 24;
                day += 1;
            }
            day += d.day;
            if (isVis(*this)) {
                dayInM[2] += 1;
                if (day > dayInM[month]) {
                    day -= dayInM[month];
                    month += 1;
                }
                dayInM[2] -= 1;
            }
            else if (day > dayInM[month]) {
                month += 1;
                day -= dayInM[month];
            }
            month += d.month;
            if (month > 12) {
                year += 1;
                month -= 12;
            }
            year += d.year;


        }
        return *this;
    }

    //overload operator "+="
    void operator += (const Date& d) {
        *this = *this + d;
    }

    //overload operator "-"
    Date operator - (const Date& d) {
        if (isOurEra == d.isOurEra) {
            second -= d.second;
            if (second < 0) {
                second += 60;
                minute -= 1;
            }
            minute -= d.minute;
            if (minute < 0) {
                minute += 60;
                hour -= 1;
            }
            hour -= d.hour;
            if (hour < 0) {
                hour += 24;
                day -= 1;
            }
            day -= d.day;
            if (isVis(*this)) {
                dayInM[2]+=1;
                if (day < 0) {
                    month -= 1;
                    day += dayInM[month];
                    if (month == 0) month = 12;
              
                }
                dayInM[2]-= 1;
                if (day == 0) day = dayInM[month];
            }
            else if (day < 0) {
                day -= dayInM[month];
                month += 1;
            }
            month -= d.month;
            if (month < 0) {
                year -= 1;
                month += 12;
            }
            year -= d.year;
            if (year < 0) {
                abs(year);
                isOurEra = !isOurEra;
            }
        }
        return *this;
    }


    //overload operator "-="
    void operator -= (const Date& d) {
        *this = *this - d;
    }
    //overload operator "="
    void operator = (const Date& d) {
        isOurEra = d.isOurEra;
        year = d.year;
        month = d.month;
        day = d.day;
        hour = d.hour;
        minute = d.minute;
        second = d.second;
    }

    void getDate() {
        cout << year << " " << month << " " << day << " " << hour << " " << minute << " " << second << endl;
    }

    bool isVis(Date data) {
        if (!(data.year % 100)) {
            if (!(data.year % 400)) return true;
        }
        if (!(data.year % 4)) return true;
        else return false;
    }

};




int main() {
    Date data;
    Date data1(1960, 2, 29, 0, 0, 5, true);
    cout << data << endl;
    cout << data1 << endl;
    data1.subtract(1, 2, 29, 12, 12, 45, true);
    cout << data1 << endl;
    data1.add(1, 2, 29, 12, 12, 45, true);
    cout << data1 << endl;
}
