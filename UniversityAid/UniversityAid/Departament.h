#pragma once
using namespace std;
#include "Faculty.h"
#include "S_Program.h"
class Departament {
private:
	int id;
public:
	string nameDepartament;
	vector<S_Program> programet;
	Departament()
	{
		id = 0;
		nameDepartament = "Unknown";
	}
	Departament(int id, string name)
	{
		this->id = id;
		this->nameDepartament = name;
		//this->programet = program;
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

void checkDepartments(vector<Departament> departamentet) {
	for (int i = 0; i < departamentet.size(); i++)
	{
		cout << "Te dhenat e departamentit " << i + 1 << endl;
		cout << departamentet[i].nameDepartament << endl;
		cout << "Lendet jane: " << endl;
		for (int j = 0; j < departamentet[i].programet.size(); i++)
		{
			cout << "ID: " << departamentet[i].programet[j].getId() << endl;
			cout << "Emer: " << departamentet[i].programet[j].nameProgram << endl;
			cout << "Vitet: " << departamentet[i].programet[j].programYears << endl;
		}
	}
};


//leftover code

/*:public Faculty*/ 
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