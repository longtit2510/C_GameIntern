#include <iostream>
#include <crtdbg.h>

//FUNCTION THAT ENTER A POSITIVE INTEGER FROM KEYBOARD
int input(int& n) {
	std::cout << "Enter your number: ";
	std::cin >> n;
	while (n <= 0) {
		std::cout << "Please enter a positive one: ";
		std::cin >> n;
	}
	return n;
}

//FUNCTION THAT CALCULATE FACTORIAL OF A NUMBER USING LONG LONG INT
void factorialByLong(int n) {
	long long int t=1;
	for (int i = 1; i <= n; i++) {
		t = t * i;
	}
	std::cout << "Function 1: Factorial of " << n << " equals: " << t << std::endl;
}

//2 FUNCTION THAT CALCULATE FACTORIAL OF A NUMBER USING ARRAY
//FUNCTION THAT UPDATE ARRAY SIZE AND MUTIPLY NUMBER
int multiply(int x, int a[], int size) {
	int carry = 0;

	for (int i = 0; i < size; i++) {
		int p = a[i] * x + carry;
		a[i] = p % 10;
		carry = p / 10;
	}
	while (carry) {
		a[size] = carry % 10;
		carry = carry / 10;
		size++;
	}
	return size;
}
//FUNCTION THAT TAKE INPUT AND RETURN THE FACTORIAL
void factorialByArray(int n) {
	int a[500];

	a[0] = 1;
	int size = 1;

	for (int x = 2; x <= n; x++) {
		size = multiply(x, a, size);
	}
	std::cout << "Function 2: Factorial of " << n << " equals: ";
	for (int i = size - 1; i >= 0; i--) {
		std::cout << a[i];
	}
}


int main() {
	int n = 2;
	long long int t;

	std::cout << "*** TASK 2 ***\n\n";
	
	//ENTER A POSITIVE INTEGER FROM KEYBOARD
	input(n);

	std::cout << "Calculating...\n\n";

	//CALCULATE FACTORIAL OF n USING LONG LONG INT TYPE
	factorialByLong(n);

	//CALCULATE FACTORIAL OF n USING ARRAY
	factorialByArray(n);

	return 0;
}