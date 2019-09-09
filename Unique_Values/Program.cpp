// This program reads in numbers from the user and prints out only the
// unique values.
//
// Author: Kelvin Tay
// Version: 1.0
#include <iostream>
#include <array>
using namespace std;

const int MIN_NUMBER = 10;
const int MAX_NUMBER = 100;
const int ARRAY_SIZE = 20;

template <size_t SIZE>
void getInput(array<int, SIZE>&);

template <size_t SIZE>
bool isUnique(const array<int, SIZE>&, const int&);

template <size_t SIZE>
void displayUnique(const array<int, SIZE>&);

int main() {
	array<int, ARRAY_SIZE> arr = { 0 };

	getInput(arr);
	displayUnique(arr);

	system("pause");
}

// Prompt and get input from the user. Each input must be in the
// valid range from 10 - 100 inclusive.
// If the input is unique, add the input into the array.
template <size_t SIZE>
void getInput(array<int, SIZE>& a) {
	int input;

	for (int count = 1; count <= a.size(); ++count) {
		cout << "\nEnter # " << count << " : ";
		cin >> input;

		while (input < MIN_NUMBER || input > MAX_NUMBER) {
			cerr << "The number entered is not in the valid range of "
				<< MIN_NUMBER << " to " << MAX_NUMBER << "\n" << endl;

			cout << "Enter # " << count << " : ";
			cin >> input;
		}

		if (isUnique(a, input)) {
			static int index = 0;
			cout << "The number: " << input << " is unique" << endl;
			a[index] = input;
			++index;
		}
	}
}

// Return true if the given number input is not already in the array,
// otherwise return false.
template <size_t SIZE>
bool isUnique(const array<int, SIZE>& a, const int& number) {
	
	for (int i = 0; a[i] != 0; ++i) {
		if (number == a[i]) {
			return false;
		}
	}

	return true;
}

// Display the unique numbers in the given array.
template <size_t SIZE>
void displayUnique(const array<int, SIZE>& a) {

	cout << "\n\nThe unique numbers are:\n" << endl;
	
	for (int i = 0; a[i] != 0; ++i) {

		if (i > 0 && 0 == (i % 5)) {
			cout << "\n";
		}

		cout << "    " << a[i];
	}

	cout << endl << endl;
}