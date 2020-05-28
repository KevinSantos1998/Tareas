#include "Conjunto.h"
#include <iostream>
using namespace std;

Conjunto::Conjunto() 
{
	for (int i = 0; i < 10; i++)
	{
		num[i] = 0;
	}
}

Conjunto::Conjunto(const char* _num)
{
	for (int i = 0; i < 10; i++)
	{
		num[i] = (int)_num[i] - 48;
	}
}

std::ostream& operator<<(std::ostream& out, const Conjunto& _num)
{

	for (int i = 0; i < 10; i++)
	{
		out << _num.num[i];
	}

	return out;

}

Conjunto operator+(const Conjunto& c1, const Conjunto& c2)
{	
	Conjunto resultado;
	int pos;
	for (int i = 0; i < 10; i++)
	{
		if(c1.num[i]!=0)
		{
			resultado.num[i] = c1.num[i];
			pos = i;
		}
	}
	pos++;
	for (int i = 0; i < 10; i++)
	{
		if (c2.num[i] != 0)
		{
			resultado.num[pos] = c2.num[i];
			pos++;
		}
	}
	
	return resultado;
}

Conjunto operator&(const Conjunto& c1, const Conjunto& c2) 
{
	Conjunto resultado;
	for (int i = 0; i < 10; i++)
	{
		for (int f = 0; f < 10; f++)
		{
			if (c1.num[i] == c2.num[f])
			{
				for (int k = 0; k < 10; k++)
				{
					if (c1.num[i] == resultado.num[k])
					{
						break;
					}
					else
					{
						resultado.num[i] = c1.num[i];
					}
				}
			}
		}
	}
	return resultado;
}