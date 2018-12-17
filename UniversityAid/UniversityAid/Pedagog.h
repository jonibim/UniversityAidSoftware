#pragma once
using namespace std;
#include "Student.h"
class Pedagog : public Person {

private:
		string password;
		string ID; 
		int paga;

public:
	Pedagog() :Person() {}
	Pedagog(string name, string surname) :Person(name, surname) {}
	string showName() {
		return name;
	}
	
	void setID() {
		this->ID = ID;
	}
	string getID() {
		return ID;
	}
	
	void setPaga() {
		this->paga = paga;
	}
	int getPaga() {
		return paga;
	}
	
	void setPassword() {
		this->password = password;
	}

	string getPassword() {
		return password;
	}

};
