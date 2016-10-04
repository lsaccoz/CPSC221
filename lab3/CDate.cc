// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <map>
#include <cstring>
#include "CDate.h"

using namespace std;

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num
    setDate( year, monthStr2Num(month), day);
}

bool CDate::isValidDate(int year, int month, int day){
    return isValidDay(year, month, day);
}

bool CDate::isValidDate(int year, std::string month, int day){
    return isValidDay(year, monthStr2Num(month), day);
}

int CDate::monthStr2Num(string month){
    map<string, int> months
            {
                    { "January", 1 },
                    { "February", 2 },
                    { "March", 3 },
                    { "April", 4 },
                    { "May", 5 },
                    { "June", 6 },
                    { "July", 7 },
                    { "August", 8 },
                    { "September", 9 },
                    { "October", 10 },
                    { "November", 11 },
                    { "December", 12 }
            };

    const auto iter = months.find( month );

    if( iter != months.cend() )
        return iter->second;
    return -1;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31) || year < 1752){
            return false;
        }
        
	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
                    valid = (day <= 31);
                    break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
                    valid = (day <= 30);
                    break;
		default:
                    valid = false;
                    break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
    setDate(year, monthStr2Num(month), day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

