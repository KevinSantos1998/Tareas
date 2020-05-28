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
		if(_num.num[i]!=0)
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

Conjunto operator-(const Conjunto& c1, const Conjunto& c2)
{
	Conjunto resultado;
	resultado = c1 + c2;
	Conjunto un;
	un = c1 & c2;
	for (int i = 0; i < 10; i++)
	{
		for (int h = 0; h < 10; h++)
		{
			if (resultado.num[i] == un.num[h]) 
			{
				resultado.num[i] = 0;
			}
		}
	}
	return resultado;
}

bool operator==(const Conjunto& c1, const Conjunto& c2)
{
	bool verdadero[10];
	for (int i = 0; i < 10; i++)
	{
		verdadero[i] = false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (c1.num[i] == c2.num[1])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[2])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[3])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[4])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[5])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[6])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[7])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[8])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[9])
			verdadero[i] == true;
		if (c1.num[i] == c2.num[0])
			verdadero[i] == true;
	}
	if(verdadero[0]==true&& verdadero[1] == true && verdadero[2] == true && verdadero[3] == true && verdadero[4] == true && verdadero[5] == true && verdadero[6] == true && verdadero[7] == true &&
		verdadero[8] == true && verdadero[9] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
