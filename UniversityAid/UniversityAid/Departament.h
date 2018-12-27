#pragma once
using namespace std;
#include "Faculty.h"
class Departament/*:public Faculty*/ {
//protected:
//    string clubs;
//public:
//	Departament() :Faculty() {}
//	Departament(int classes,int labs,int secretary,int library):Faculty(classes, labs, secretary, library) {}
//
//	
//	void setClubs(string clubs) {
//		this->clubs = clubs;
//	}
//	string getClubs() {
//		return clubs; 
//	}
//
//

private:
	int id;
public:
	string nameDepartament;
	Departament()
	{
		id = 0;
		nameDepartament = "Unknown";
	}
	Departament(int id, string name)
	{
		this->id = id;
		this->nameDepartament = name;
	}
	int getId()
	{
		return id;
	}
	void setId(int id)
	{
		this->id = id;
	}

};
