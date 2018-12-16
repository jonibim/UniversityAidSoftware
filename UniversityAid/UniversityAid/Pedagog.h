#pragma once
using namespace std;
#include "Student.h"
class Pedagog : public Person {

private:
		string password;

public:
	Pedagog() :Person() {}
	Pedagog(string name, string surname) :Person(name, surname) {}
	string showName() {
		return name;
	}

	void setPassword() {
		this->password = password;
	}

	string getPassword() {
		return password;
	}

};
