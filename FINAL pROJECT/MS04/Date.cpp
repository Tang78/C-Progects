

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "Utils.h"
#include <ctime>
#include <iomanip>
using namespace std;
namespace sdds {
    int Date::MonthDays(int year, int month) const 
    {
        const int daysinmonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int monthIn = (month >= 1 && month <= 12) ? month - 1 : 12;
        int daysinthis = daysinmonth[monthIn];
        if (monthIn == 1) {
            bool leapyear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
            if (leapyear) {
                daysinthis++;
            }
        }
        return daysinthis;
    }
    Date::Date() {
        getSysDate(year_, month_, day_, hour_, minute_, false);
        dateOnly_ = false;
        Datecheck();
    }

    void Date::Datecheck() {
        errorMessage.clear();
        const int minimumyear = 1900;
        const int maximumyear = 2100;

        if (year_ <  minimumyear|| year_ > maximumyear) {
            errorMessage = "Invalid Year";
        }
        else {
            const int minmonth = 1;
            const int maxmonth = 12;
            if (month_ < minmonth || month_ > maxmonth) {
                errorMessage = "Invalid Month";
            }
            else {
                int maxday = MonthDays(year_, month_);
                const int minday = 1;
                if (day_ < minday || day_ > maxday) {
                    errorMessage = "Invalid Day";
                }
                else if (!dateOnly_) {
                    const int minHour = 0;
                    const int maxHour = 23;
                    if (hour_ < minHour || hour_ > maxHour) {
                        errorMessage = "Invalid Hour";
                    }
                    else {
                        const int minMinute = 0;
                        const int maxMinute = 59;
                        if (minute_ < minMinute || minute_ > maxMinute) {
                            errorMessage = "Invalid Minute";
                        }
                    }
                }
            }
        }
    }

    
    Date::Date(bool Flag) {
        getSysDate(year_, month_, day_, hour_, minute_, dateOnly_);
        dateOnly_ = Flag;
        Datecheck();
    }

    Date::Date(int year, int month, int day)
        : year_(year), month_(month), day_(day), hour_(0), minute_(0) {
        dateOnly_ = true;
        Datecheck();
    }
    Date::Date(int year, int month, int day, int hour)
        : year_(year), month_(month), day_(day), hour_(hour), minute_(0) {
        dateOnly_ = false;
       Datecheck();
    }


    Date::Date(int year, int month, int day, int hour, int minute)
        : year_(year), month_(month), day_(day), hour_(hour), minute_(minute) {
        dateOnly_= false;
       Datecheck();
    }

    bool Date::operator==(const Date& D) const {
        if (year_ != D.year_ || month_ != D.month_ || day_ != D.day_)
            return false;

        if (dateOnly_ || (hour_ == D.hour_ && minute_ == D.minute_))
            return true;

        return false;
    }


    bool Date::operator!=(const Date& D) const {
        return (*this != D);
    }

    bool Date::operator<(const Date& D) const {
        bool isList = false;

        if (year_ != D.year_) {
            isList = year_ < D.year_;
        }
        else if (month_ != D.month_) {
             isList= month_ < D.month_;
        }
        else if (day_ != D.day_) {
            isList = day_ < D.day_;
        }
        else if (!dateOnly_) {
            if (hour_!= D.hour_) {
                isList = hour_ < D.hour_;
            }
            else {
                isList= minute_ < D.minute_;
            }
        }

        return isList;
    }


    bool Date::operator>(const Date& D) const {
        return D < *this;
    }

    bool Date::operator<=(const Date& D) const {
        return !(*this > D);
    }

    bool Date::operator>=(const Date& D) const {
        return !(*this < D);
    }

    Date& Date::dateOnly(bool date) {
        dateOnly_ = date;
        if (date) {
            hour_ = minute_ = 0;
        }
        return *this;
    }

    Date::operator bool() const {
        return !errorMessage;
    }

    const Error& Date::error() const {
        return errorMessage;
    }

    std::ostream& operator<<(std::ostream& ostr, const Date& D) {
        if (!D) {
            ostr << D.error() << "(";
        }
        ostr << D.year_ << '/';
        ostr << std::setw(1) << '0' << D.month_ << '/'
            << std::setw(2) << D.day_;
        if (!D.dateOnly_) {
            ostr << ", " << std::setw(2) << D.hour_ << ':'
                << std::setw(2) << D.minute_;
        }
        if (!D) {
            ostr << ")";
        }
        return ostr;
    }



    std::istream& operator>>(std::istream& istr, Date& D) {
        D.errorMessage.clear();
        D.year_ = D.month_ = D.day_= D.hour_ = D.minute_ = 0;

        if (!(istr >> D.year_)) {
            D.errorMessage = "Cannot read year entry";
            return istr;
        }
        istr.ignore();

        if (!(istr >> D.month_)) {
            D.errorMessage = "Cannot read month entry";
            return istr;
        }
        istr.ignore();

        if (!(istr >> D.day_)) {
            D.errorMessage = "Cannot read day entry";
            return istr;
        }

        if (!D.dateOnly_) {
            istr.ignore();
            if (!(istr >> D.hour_)) {
                D.errorMessage = "Cannot read hour entry";
                return istr;
            }
            istr.ignore();

            if (!(istr >> D.minute_)) {
                D.errorMessage = "Cannot read minute entry";
                return istr;
            }
        }

        D.Datecheck();
        return istr;
    }




}
