#include"RomanNumbers.h"
int main()
{
	std::cout << "Enter Arabic number: ";
	int n;
	do { std::cin >> n; } while (n < 0);

	RomanNumber ob(n);

	std::cout<<ob.toRoman();
	std::cout << std::endl;
	return 0;
}