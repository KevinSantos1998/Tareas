
#include "Byte.h"
#include <cmath>

Byte::Byte(void)
{
	for (int i = 0; i < 8; i++)
	{
		bits[i] = 0;
	}
}

// "10011101", "00000001"
Byte::Byte(const char* _bits)
{
	for (int i = 0; i < 8; i++)
	{
		bits[i] = (int)_bits[i] - 48;
	}
}

std::ostream& operator<<(std::ostream& out, const Byte& _b)
{

	for (int i = 0; i < 8; i++)
	{
		out << _b.bits[i];
	}

	return out;

}

Byte operator&(const Byte& b1, const Byte& b2)
{
	Byte nuevo;
	for (int i = 8-1; i >= 0; i--)
	{
		if(b1.bits[i] == 1 && b2.bits[i] == 1)
		{
			nuevo.bits[i] = 1;
		}
		else
		{
			nuevo.bits[i] = 0;
		}
	}
	return nuevo;
}

Byte operator|(const Byte& b1, const Byte& b2)
{
	Byte nuevo;
	for (int i = 8 - 1; i >= 0; i--)
	{
		if (b1.bits[i] == 1 || b2.bits[i]==1)
		{
			nuevo.bits[i] = 1;
		}
		else
		{
			nuevo.bits[i] = 0;
		}
	}
	return nuevo;
}

Byte operator^(const Byte& b1, const Byte& b2)
{
	Byte nuevo;
	for (int i = 8 - 1; i >= 0; i--)
	{
		if (b1.bits[i] == 1 && b2.bits[i] == 1)
		{
			nuevo.bits[i] = 0;
		}
		else if (b1.bits[i] == 0 && b2.bits[i] == 0)
		{
			nuevo.bits[i] = 0;
		}
		else
		{
			nuevo.bits[i] = 1;
		}
	}
	return nuevo;
}

Byte operator+(const Byte& b1, const Byte& b2)
{
	Byte nuevo;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--)
	{
		int resultado = 0;
		if (acarreo == 1)
		{
			if (b1.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}
			else
			{
				resultado = 1;
				acarreo = 0;
			}

			if (resultado == 0 && b2.bits[i] == 0)
			{
				resultado = 0;
			}
			else if (resultado == 0 && b2.bits[i] == 1)
			{
				resultado = 1;
			}
			else if (resultado == 1 && b2.bits[i] == 0)
			{
				resultado = 1;
				acarreo = 0;
			}
			else if (resultado == 1 && b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}

		}//fin de if acarreo
		else
		{
			if (b1.bits[i] == 0 && b2.bits[i] == 0)
			{
				resultado = 0;
				acarreo = 0;
			}
			else if (b1.bits[i] == 1 && b2.bits[i] == 0 || b1.bits[i] == 0 && b2.bits[i] == 1)
			{
				resultado = 1;
				acarreo = 0;
			}
			else if (b1.bits[i] == 1 && b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}
		}

		nuevo.bits[i] = resultado;

	}

	return nuevo;

}

Byte operator-(const Byte& b1, const Byte& b2)
{
	Byte nuevo;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--)
	{
		int resultado = 0;
		if(acarreo == 1)
		{
			if (b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo=1;
			}
			if(b2.bits[i] == 0)
			{
				resultado = 0;
				acarreo = 0;
			}
		}else
		{
			if (b1.bits[i] == 1 && b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 0;
			}
			if (b1.bits[i] == 1 && b2.bits[i] == 0)
			{
				resultado = 1;
				acarreo = 0;
			}
			if (b1.bits[i] == 0 && b2.bits[i] == 1)
			{
				resultado = 1;
				acarreo = 1;
			}
		}
		

		nuevo.bits[i] = resultado;

	}

	return nuevo;

}

Byte operator*(const Byte& b1, const Byte& b2)
{
	Byte nuevo;
	Byte op1, op2, op3, op4, op5, op6, op7, op8;
	

	for (int i = 8 - 1; i >= 0; i--)
	{
		int resultado = 0;
		if (b2.bits[i]==1 && i == 7)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 1 < 0)
					break;
				op1.bits[f] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 6)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 1 < 0)
					break;
				op2.bits[f-1] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 5)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 2 < 0)
					break;
				op3.bits[f-2] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 4)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 3 < 0)
					break;
				op4.bits[f-4] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 3)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 5 < 0)
					break;
				op5.bits[f-5] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 2)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 6 < 0)
					break;
				op6.bits[f-6] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 1)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 7 < 0)
					break;
				op7.bits[f-7] = b1.bits[f];
			}
		}
		if (b2.bits[i] == 1 && i == 0)
		{
			for (int f = 8 - 1; f >= 0; f--)
			{
				if (f - 1 < 0)
					break;
				op8.bits[f-1] = b1.bits[f];
			}
		}

	}
	
	nuevo = op1 + op2;
	nuevo = nuevo + op3;
	nuevo = nuevo + op4;
	nuevo = nuevo + op5;
	nuevo = nuevo + op6;
	nuevo = nuevo + op7;
	nuevo = nuevo + op8;
	return nuevo;

}

Byte Byte::operator~(void)
{

	for (int i = 0; i < 8; i++)
	{
		this->bits[i] = this->bits[i] == 1 ? 0 : 1;
	}

	return *this;

}

int Byte::obtenerDecimal() 
{
	int resultado = 0;
	int exp = 0;
	for (int i = 8 - 1; i >= 0; i--)
	{
		if (bits[i] == 1) 
		{
			resultado = resultado + (pow(2, exp));
		}
		exp++;
	}
	return resultado;
}