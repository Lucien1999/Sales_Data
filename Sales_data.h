#pragma once
#include<string>
#include<iostream>

struct Sales_data
{
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, Sales_data &);
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend std::ostream &operator<<(std::ostream &, Sales_data &);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
private:
	std::string bookno;
	double price = 0;
	double units_sold = 0;
	double revenue = 0;
public:
	Sales_data() :
		bookno(), units_sold(0), revenue(0){}
	Sales_data(const std::string &s) :
		bookno(s), units_sold(0), revenue(0) {}
	Sales_data(const Sales_data &tmp) :
		Sales_data(tmp.bookno, tmp.price, tmp.units_sold) {}
	Sales_data(const std::string &s, double n, double p) :
		bookno(s), price(p), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream &);
	Sales_data combine(const Sales_data &rhs);
	std::string isbn()const;
	Sales_data &operator+=(const Sales_data&);
	double avg_price()const;
	Sales_data &operator-=(const Sales_data&);
	Sales_data &operator=(const std::string);
};