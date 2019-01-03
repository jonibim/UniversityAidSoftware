#pragma once
using namespace std;
#include "Libraries.h"
class S_Program {

private:
	int id;

public:
	int programYears;
	string nameProgram;

	S_Program() {
		id = 0;
		nameProgram = "Unknown";
		programYears = 0;

	}

	S_Program(int id, string name, int programYears) {
		this->id = id;
		this->nameProgram = name;
		this->programYears = programYears;
		
		
	}

	int getId()
	{
		return id;
	}
	void setId(int Id)
	{
		this->id = Id;
	}


};
