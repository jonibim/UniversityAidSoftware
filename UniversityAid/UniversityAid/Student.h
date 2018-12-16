#pragma once
#include "Person.h"
using namespace std;
class Student:public Person {
private:
	string password;
public:
	Student() :Person() {}
	Student(string name, string surname) :Person(name, surname) {}
	string showName() {
		return name;
	}
	
	void setPassword() {
		this->password = password;
	}

	string getPassword() {
		return password;
	}

	string tesT() {

	}


};
