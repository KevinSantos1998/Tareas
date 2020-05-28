#pragma once
#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
using namespace std;

class Conjunto
{

public:
	Conjunto();
	Conjunto(const char*);


	friend ostream& operator<<(ostream&, const Conjunto&);
	friend Conjunto operator+(const Conjunto&, const Conjunto&);
	friend Conjunto operator-(const Conjunto&, const Conjunto&);
	friend Conjunto operator&(const Conjunto&, const Conjunto&);
	friend Conjunto operator==(const Conjunto&, const Conjunto&);

private:
	int num[10];
};


#endif // CONJUNTO_H