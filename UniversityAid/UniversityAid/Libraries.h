#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include <windows.h>
//#include<ifstream>
//#include<ofstream>

using namespace std;
//Extra Functions
void verifyInt(int);
void noZeroInt(int);
void cls(void);

void noZeroInt(int a) { //WIP!
	if (a <= 0) {
		while (a <= 0) {
			cout << "ID cannot be zero or a negative number" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input: ";
			cin >> a;

		}
	}
}


void verifyInt(int a) {
	while (cin.fail()) {
		cout << "Wrong input. Please input your data again" <<endl;
		cin.clear();
		cin.ignore(256, '\n'); //Shiko parametrat tek http://www.cplusplus.com/reference/istream/istream/ignore/ //Parandalon perseritjen e errorit
		cout << "Input: ";
		cin >> a;
	}
}

void cls() {
	system("CLS");
}






