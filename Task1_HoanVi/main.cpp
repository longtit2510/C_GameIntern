#include <iostream>

using namespace std;

//Swap function using Reference
void swapRef(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

//Swap function using Pointer
void swapPoi(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//Input data function
void input(int &a, int &b) {
	cout << "Please enter the value of a: ";
	cin >> a;
	cout << "Please enter the value of b: ";
	cin >> b;
}

//Output data function
void output(int a, int b) {
	cout << "RESULT: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main() {

	//Declares Variables
	int a = 0;
	int b = 0;

	//SWAP NUMBERS USING REFERENCE
	cout << "*** SWAP NUMBERS USING REFERENCE ***\n\n";

	input(a, b);

	cout << endl << "Calculating...\n\n";

	swapRef(a, b);
	output(a, b);

	//SWAP NUMBERS USING POINTERS
	cout << "\n\n*** SWAP NUMBERS USING POINTERS ***\n\n";

	input(a, b);

	cout << endl << "Calculating...\n\n";

	swapPoi(&a, &b);
	output(a, b);

	system("PAUSE");
	return 0;
}
