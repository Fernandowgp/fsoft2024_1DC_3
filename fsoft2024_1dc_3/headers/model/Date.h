//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_DATE_H
#define FSOFT2024_1DC_3_DATE_H

class Date  {
private:
    int day;
    int month; //  [1 to 12]
    int year;
    bool isLeapYear(int year);
    bool isValid(int day, int month, int year);
    void setDate(int day, int month, int year);
public:
    Date(); //Use only constructor
    std::string getDate();
    bool operator == (const Date& obj) const;
    bool operator > (const Date& obj)const;
    bool operator < (const Date& obj) const;

};

#endif //FSOFT2024_1DC_3_DATE_H
