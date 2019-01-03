#pragma once
using namespace std;
#include "Faculty.h"
#include "Subjects.h"//pse e ke bere include faculty? a nuk na duhet se nuk po e
//perdorim me trazhgimin? 
//ktu tani duhet te krijojme programin e studimit
//si vektor, edhe studentet 
class Departament {
protected:
	int id;
public:
	string nameDepartament;
	vector<Subjects> lendet;
	Departament()
	{
		id = 0;
		nameDepartament = "Unknown";
	}
	Departament( int id, string name, vector<Subjects> lendet)
	{
		this->id = id;
		this->nameDepartament = name;
		this->lendet = lendet; 
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
		for (int j = 0; j < departamentet[i].lendet.size(); i++)
		{
			cout << "Emer: " << departamentet[i].lendet[j].name << endl;
			cout << "Oret: " << departamentet[i].lendet[j].getHours() << endl;
			cout << "Kreditet: " << departamentet[i].lendet[j].getCredits() << endl;
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