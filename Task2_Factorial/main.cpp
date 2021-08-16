#include <iostream>

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
	long long int t = 1;
	for (int i = 1; i <= n; i++) {
		t = t * i;
	}
	std::cout << "Function 1: Factorial of " << n << " equals: " << t << std::endl;
}

int main() {
	int n;

	std::cout << "*** TASK 2 ***\n\n";

	//ENTER A POSITIVE INTEGER FROM KEYBOARD
	input(n);

	std::cout << "Calculating...\n\n";

	//CALCULATE FACTORIAL OF n USING LONG LONG INT TYPE
	factorialByLong(n);

	return 0;
}