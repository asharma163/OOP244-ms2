/* NAME- ANSHUL SHARMA
SENECA ID- 136530169
E-MAIL- asharma163@myseneca.ca
*/
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include<iostream>
namespace sict {
#define NO_ERROR   0  
#define CIN_FAILED 1  
#define YEAR_ERROR 2  
#define MON_ERROR  3  
#define DAY_ERROR  4

	class Date {
	private:
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;
		int value()const;
		void errCode(int errorCode);
	public:
		Date();
		Date(int m_year, int m_month, int m_day);
		
		bool operator==(const Date& D) const;
		bool operator!=(const Date& D) const;
		bool operator<(const Date& D) const;
		bool operator>(const Date& D) const;
		bool operator<=(const Date& D) const;
		bool operator>=(const Date& D) const;
		int errCode() const;
		bool bad() const;
		
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

		int mdays()const;
	};
	std::istream& operator >> (std::istream&, Date&); // not declared friend because its not good practice to do so and it accesses 'istr' which is object of method.
	std::ostream& operator<<(std::ostream&, const Date&);




}
#endif