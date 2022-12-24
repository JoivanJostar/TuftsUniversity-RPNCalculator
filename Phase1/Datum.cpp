#define _CRT_SECURE_NO_WARNINGS
#include "Datum.h"
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
using namespace std;
//Datum(const Datum& d);


Datum::Datum(const Datum& d){
	this->bdata = d.bdata;
	this->idata = d.idata;
	this->sdata = d.sdata;
	this->ty = d.ty;
}
//explicit Datum(int i);
//explicit Datum(bool b);
//explicit Datum(const char* s);
//explicit Datum(std::string s);
Datum::Datum(int i) {
	this->idata = i;
	this->ty = this->D_INT;
}
Datum::Datum(bool b) {
	this->bdata = b;
	this->ty = this->D_BOOL;
}
Datum::Datum(const char* s) :Datum(string(s)){
	
}
Datum::Datum(string s) {
	this->sdata = s;
	this->ty = this->D_RSTRING;
}
//
//bool isInt()     const;
//bool isBool()    const;
//bool isRString() const;
bool Datum::isInt() const {
	return this->ty == this->D_INT;
}
bool Datum::isBool() const {
	return this->ty == this->D_BOOL;
}
bool Datum::isRString() const {
	return this->ty == this->D_RSTRING;
}
//
//Datum& operator= (const Datum& d);
Datum& Datum:: operator= (const Datum& d) {
	this->bdata = d.bdata;
	this->idata = d.idata;
	this->sdata = d.sdata;
	this->ty = d.ty;
	return *this;
}
//bool   operator==(Datum& d) const;
bool Datum:: operator==(Datum& d) const {
	bool ret = false;
	if (this->ty == d.ty) {
		if (this->ty == Datum::D_INT) {
			ret = this->idata == d.idata;
		}
		else if(this->ty==Datum::D_BOOL) {
			ret = this->bdata == d.bdata;
		}
		else {
			ret = this->sdata == d.sdata;
		}
	}
	return ret;
}
//bool   operator< (Datum& d) const;
bool Datum:: operator< (Datum& d) const {
	bool ret = false;
	if (this->ty != Datum::D_INT || d.ty != Datum::D_INT)
		throw runtime_error("datum_not_int");
	else
		ret = this->idata < d.idata;
	return ret;
}
//int         getInt()     const;
int  Datum::getInt() const {
	if (this->ty != Datum::D_INT)
		throw runtime_error("datum_not_int");
	else
		return this->idata;
}
//bool        getBool()    const;
bool   Datum::getBool() const {
	if (this->ty != Datum::D_BOOL)
		throw runtime_error("datum_not_bool");
	else
		return this->bdata;
}
//std::string getRString() const;
std::string  Datum::getRString() const {
	if (this->ty != Datum::D_RSTRING)
		throw runtime_error("datum_not_rstring");
	else
		return this->sdata;
}

//std::string toString()   const;
std::string  Datum::toString()   const {
	string ret = "";
	if (this->ty == Datum::D_INT) {
		stringstream ss;
		ss << this->idata;
		ret = ss.str();
	}
	else if (this->ty == Datum::D_BOOL) {
		string s = this->bdata ? "#t" : "#f";
		ret = s;
	}
	else {
		ret = this->sdata;
	}
	return ret;
}