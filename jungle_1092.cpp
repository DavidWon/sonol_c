#include <iostream>
#include <stdio.h>
#define MOD 20091024

using namespace std;

unsigned long long int X, Y;

unsigned long long int modular_exponentiation(unsigned long long int base, unsigned long long int exp, unsigned long long int n);

unsigned long long int result;

int main(void)
{
	cin >> X >> Y;

	cout << modular_exponentiation(X, Y, MOD) << endl;

	return 0;
}

unsigned long long int modular_exponentiation(unsigned long long int base, unsigned long long int exp, unsigned long long int n)
{
	//큰 지수승 나머지 구하는 함수 base^exp mod n
	base %= n;

	if (exp == 0) return 1;
	else if (exp == 1) return base;
	else if (exp & 1 == 0) return modular_exponentiation(base * base % n, exp / 2, n);
	else return base * modular_exponentiation(base, exp - 1, n) % n;
}
