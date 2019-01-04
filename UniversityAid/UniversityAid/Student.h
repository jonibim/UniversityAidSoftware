#pragma once
#include "Person.h"
using namespace std;
class Student:public Person {
private:
	string password;
	int id;
public:
	Student() :Person() {}
	Student(string name, string surname, string password, int age, string address, int postalcode, string birthday) {
		this->name = name;
		this->surname = surname;
		this->password = password;
		this->age = age;
		this->address = address;
		this->postalcode = postalcode;
		this->birthday = birthday;
	}
	string showName() {
		return name;
	}
	
	void setPassword(string password) {
		this->password = password;
	}

	string getPassword() {
		return password;
	}


};
