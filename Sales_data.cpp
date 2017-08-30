#include"Sales_data.h"
#include<iostream>
#include<string>
using namespace std;
Sales_data Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	return *this;
}

inline double Sales_data::avg_price()const
{
	if (units_sold)return revenue / units_sold;
	else return 0;

}
Sales_data & Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}
string Sales_data::isbn()const
{
	return this->bookno;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookno >> item.units_sold >> price;
	if(is)
		item.revenue = price * item.units_sold;
	else item = Sales_data();
	return is;
}
ostream &print(ostream &os, Sales_data &item)
{
	os << item.isbn() << ends << item.units_sold << ends << item.revenue << ends;
	return os;
}
std::istream & operator>>(std::istream &is, Sales_data &item)
{
	return read(is, item);
}

std::ostream & operator<<(std::ostream &os, Sales_data &item)
{
	return print(os, item);
}
Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(istream &is)
{
	is >> this->bookno >> this->price >> this->units_sold;
	revenue = units_sold * price;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}
Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum -= rhs;
	return sum;
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.revenue == rhs.revenue&&
		lhs.units_sold == rhs.units_sold;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
Sales_data &Sales_data::operator=(const std::string isbn)
{
	bookno = isbn;
	return *this;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data ret(lhs);
	ret += rhs;
	return ret;
}