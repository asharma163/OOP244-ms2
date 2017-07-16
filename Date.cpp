/* NAME- ANSHUL SHARMA
   SENECA ID- 136530169
   E-MAIL- asharma163@myseneca.ca
*/
#include<iostream>
#include "Date.h"
#include "general.h"
namespace sict {
	Date::Date()
	{
		year_,mon_,day_ = 0;
		readErrorCode_ = NO_ERROR;
	}
	Date::Date(int m_year, int m_month, int m_day)
	{
		year_ = m_year;
		mon_ = m_month;
		day_ = m_day;
		readErrorCode_ = NO_ERROR;
	}
	bool Date::operator==(const Date& D) const
	{
		if (this->value() == D.value())
			return true;
		else
			return false;
	}
	bool Date::operator!=(const Date& D) const
	{
		if (this->value() != D.value())
			return true;
		else
			return false;
	}
	bool Date::operator<(const Date& D) const
	{
		if (this->value() < D.value())
			return true;
		else
			return false;
	}
	bool Date::operator>(const Date& D) const
	{
		if (this->value() > D.value())
			return true;
		else
			return false;
	}
	bool Date::operator<=(const Date& D) const
	{
		if (this->value() <= D.value())	
			return true;
		else
			return false;
	}
	bool Date::operator>=(const Date& D) const
	{
		if (this->value() >= D.value())
			return true;
		else
			return false;
	}
	bool Date::bad() const
	{
		return readErrorCode_ != NO_ERROR; //could have been represented with 'if' statement but done to reduce code.
	}

	void Date::errCode(int errorCode)
	{
		readErrorCode_ = errorCode;
	}
	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}
	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
	int Date::errCode() const
	{
		return readErrorCode_;
	}

	std::istream& Date::read(std::istream& istr)
	{
		istr >> year_;std::cin.ignore();
		istr >> mon_;std::cin.ignore();
		istr >> day_;
		if (istr.fail())
			readErrorCode_ = CIN_FAILED;
		else
		{
			if (year_ >= MIN_YEAR && year_ <= MAX_YEAR)
			{
				if (mon_ >= 1 && mon_ <= 12)
				{
					if (day_ <= mdays() && day_ >= 1)
					{
						errCode(NO_ERROR);
					}
					else
						errCode(DAY_ERROR);
				}
				else
					errCode(MON_ERROR);
			}
			else errCode(YEAR_ERROR);
		}
		return istr;
	}
	std::ostream& Date::write(std::ostream& ostr) const
	{
		ostr << year_ << "/";
		ostr.width(2);
		ostr.fill('0');   //if month is 7 it will be represented as 07 because of this function to make format yyyy/mm/dd.
		ostr << mon_;
		ostr << "/";
		ostr.width(2);
		ostr.fill('0');    //if day is 9 it will be represented as 09 because of this function to make format yyyy/mm/dd
		ostr << day_;
		return ostr;
	}
	std::istream& operator >> (std::istream& istr, Date& D)
	{
		D.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& istr, const Date& D)
	{
		D.write(istr);
		return istr;
	}
}