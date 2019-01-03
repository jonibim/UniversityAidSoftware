#pragma once
using namespace std;
#include "Libraries.h"
#include "Subjects.h"
class S_Program {

private:
	int Id;

public:
	int programYears;
	string nameProgram;
	vector<Subjects> lendet;


	S_Program() {
		Id = 0;
		nameProgram = "Unknown";
		programYears = 0;

	}

	S_Program(int Id, string nameProgram, int programYears, vector<Subjects> lendet) {
		this->Id = Id;
		this->nameProgram = nameProgram;
		this->programYears = programYears;
		this->lendet = lendet;
		
		
	}
	int getId()
	{
		return Id;
	}
	void setId(int Id)
	{
		this->Id = Id;
	}
	void checkPrograms(vector<S_Program> programet) {
		for (int i = 0; i < programet.size(); i++)
		{
			cout << "Te dhenat e programit " << i + 1 << endl;
			cout << programet[i].Id << endl;
			cout << programet[i].nameProgram << endl;
			cout << programet[i].programYears << endl;
			cout << "Lendet jane: " << endl;
			for (int j = 0; j < programet[i].lendet.size(); j++)
			{
				cout << "Emer: " << programet[i].lendet[j].name<< endl;
				cout << "Oret: " << programet[i].lendet[j].getHours() << endl;
				cout << "Kreditet: " << programet[i].lendet[j].getCredits() << endl;
			}
		}
	};


};
