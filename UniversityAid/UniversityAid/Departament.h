#pragma once
using namespace std;
#include "S_Program.h"
#include "Pedagog.h"//pse e ke bere include faculty? a nuk na duhet se nuk po e
//perdorim me trazhgimin? 
class Departament {
protected:
	int id;
public:
	string nameDepartament;
	vector<S_Program> programet;
	vector<Pedagog> pedagog;
	vector<Student> student; 
	Departament()
	{
		id = 0;
		nameDepartament = "Unknown";
	}
	Departament( int id, string name, vector<S_Program> programet, vector<Pedagog> pedagog, 
		vector<Student> student)
	{
		this->id = id;
		this->nameDepartament = name;
		this->programet = programet;
		this->pedagog = pedagog;
		this->student = student;
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
		cout << "Programet jane: " << endl;
		for (int j = 0; j < departamentet[i].programet.size(); i++)
		{
			cout << "ID: " << departamentet[i].programet[j].getId() << endl;
			cout << "Emer: " << departamentet[i].programet[j].nameProgram << endl;
			cout << "Vitet: " << departamentet[i].programet[j].programYears << endl;
		}
		for (int s = 0; s < departamentet[i].pedagog.size(); i++) {
			cout << "Emri: " << departamentet[i].pedagog[s].name << endl;
			cout << "Mbiemri: " << departamentet[i].pedagog[s].surname << endl;
			cout << "Password:" << departamentet[i].pedagog[s].getPassword() << endl;
			cout << "ID:" << departamentet[i].pedagog[s].getID() << endl;
			cout << "Paga:" << departamentet[i].pedagog[s].getPaga() << endl;
			}
		for (int u = 0; u < departamentet[i].student.size(); i++) {
			cout << "Emri: " << departamentet[i].student[u].name << endl;
			cout << "Mbiemri: " << departamentet[i].student[u].surname << endl;
			cout << "Password:" << departamentet[i].student[u].getPassword() << endl;
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