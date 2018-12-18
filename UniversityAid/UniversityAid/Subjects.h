#pragma once
#include "Libraries.h"
using namespace std;
class Subjects {
protected:
	int hours;
	int credits;

public:
	string name;
	Subjects() {
		name = "";
	}

	Subjects(string name) {
		this->name = name;
	}
	void setHours(int hours) {
		this->hours = hours;
	}

	int getHours() {
		return hours;
	}
	void setCredits(int credits) {
		this->credits = credits;
	}

	int getCredits() {
		return credits;
	}

};