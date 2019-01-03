#pragma once
#include "Libraries.h"
#include "Pedagog.h"
using namespace std;
class Subjects {
private:
	int hours;
	int credits;

public:
	string name;
	vector<Pedagog> pedagog;
	Subjects() {
		name = "";
	}

	Subjects(string name, int hours, int credits) {
		this->name = name;
		this->hours = hours;
		this->credits = credits;
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