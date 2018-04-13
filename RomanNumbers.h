#include <string>
#include <iostream>
#include <math.h>
class RomanNumber
{
public:RomanNumber(int);
	   std::string toRoman() const;
private:
	int m_number ;
	const std::string m_roman[13] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	const int m_arabic[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    int length() const;
	int index(int) const;


};
RomanNumber::RomanNumber(int number)
{
	m_number = number;
}
int RomanNumber::length() const 
{
	if (m_number == 0) return 1;
	int size = 0;
	int tempNum = m_number;
	while (tempNum)
	{
		tempNum /= 10;
		++size;
	}
	return size;

}
int RomanNumber::index(int number)const
{
	int index = 0;
	
	for (int i = 0;i < 13;++i)
	{
		if (number == m_arabic[i])
		{
	 		index = i;
			return index;
	    }
		else
		{
			if (number > m_arabic[i])
			{
				index = i;
			}
		}
	}
	return index;
}
std::string RomanNumber::toRoman() const 
{
	int size = length();
	std::string roman="";
	if (m_number == 0)
	{
		return "0";
	}

	int number = m_number;
	

	
		while (number)
		{

			size--;
			int temp1 = number / pow(10, size);
			int temp = temp1*pow(10, size);
			number -= temp;
			while (temp)
			{
				int i = index(temp);
				roman += m_roman[i];
				temp -= m_arabic[i];
			}

		}
	
	return roman;
}