#pragma once
using namespace std;
#include "Student.h"
class Pedagog : public Person {

private:
		string password;
		int ID; 
		int paga;

public:
	vector<Student> student;
	Pedagog() :Person() {}
	Pedagog(int id, string password, int paga, string name, string surname, string address, int postalcode, string birthday) {
		this->ID = id;
		this->password = password;
		this->paga = paga;
		this->name = name;
		this->surname = surname;
		this->address = address;
		this->postalcode = postalcode;
		this->birthday = birthday;
	
	}
	string showName() {
		return name;
	}
	
	void setID() {
		this->ID = ID;
	}
	int getID() {
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
