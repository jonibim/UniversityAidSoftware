#pragma once
#include "Libraries.h"
using namespace std;
class Person {

protected:
	string address;
	int postalcode;
	string birthday;

public:
	string name;
	string surname;
	int age;

	Person() {
		name = "";
		surname = "";
	}

	Person(string name, string surname) {
		this->name = name;
		this->surname = surname;
	}

	void setAddressAndPostalCode(string address, int postalcode) {
		this->address = address;
		this->postalcode = postalcode;
	}

	void setAge(int age) {
		this->age = age;
	}

	bool validateBirthday() {

	}

	void setBirthday(string birthday) {
		this->birthday = birthday;
	}

	string getNameSurname() {
		return name, surname;
	}

	string getAddress() {
		return address;
	}

	int getPS() {
		return postalcode;
	}

	string getBirthday() {
		return birthday;
	}

	int getAge() {
		return age;
	}

	
};