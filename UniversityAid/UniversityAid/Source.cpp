#include "Student.h"
#include "Faculty.h"
#include "S_Program.h"
#include "Departament.h"
using namespace std;

vector<Faculty> faculties;
void welcomeScreen(void);
void mainMenu();
void addDepartament();
void addFaculty();
void addStudy();
void addSubject();
void addStudentstoSubject();
void addPedagoge(int,int,int,int);
void addStudent(int,int,int,int);
void deregisterStudent();
void deleteStudy();
void deleteDepartment();
void deleteFaculty();
void checkPedagogue();
void overwritePedagogue(int, int, int, int);
void createDirectories();
void addMarks();
void cls(void);

int main() {

	int ProgramExit = 0;
	while (ProgramExit !=1) {
		welcomeScreen();
		mainMenu();
		int choice;
		cout << "Enter option: (0-12): " << endl;
		cin >> choice;
		verifyInt(choice);
		cls();
		if (choice == 1) {
			addFaculty();
		}

		if (choice == 2) {
			addDepartament();
		}
		if (choice == 3) {
			addStudy();
		}

		if (choice == 4) {
			addSubject();
		}

		if (choice == 5) {
			addStudentstoSubject();
		}

		if (choice == 6) {
			deregisterStudent();
		}

		if (choice == 7) {
			addMarks();
		}

		if (choice == 8) {
			deleteStudy();
		}

		if (choice == 9) {
			deleteDepartment();
		}

		if (choice == 10) {
			deleteFaculty();
		}

		if (choice == 11) {
			checkPedagogue();
		}

		if (choice == 13) {
			cout << "Debug Vector Size" << endl;
			DebugSize(faculties);
			cin.ignore();
			cin.ignore();
		}

		if (choice == 14) {
			createDirectories();
		}

		if (choice <= 0) {
			cout << "Select an option using numbers from 1 - 12" << endl;
		}

		if (choice == 12) {
			if (faculties.size() != 0) {
				cout << R"(
+------------------------------------+
| Do you want to save current state? |
+------------------------------------+
)";
				cout << "Y/N: ";
				char input;
				cin >> input;
				if (input == 'Y' || input == 'y') {
					createDirectories();
				}
			}
			return 0;
		}

	}






}

void welcomeScreen(void){
	cls();
	cout << R"(
##############################################################################

 _   _      _                _ _            _   _    _   _____         _ 
| | | |_ _ (_)_ _____ _ _ __(_) |_ _  _    /_\ (_)__| | |_   _|__  ___| |___
| |_| | ' \| \ V / -_) '_(_-< |  _| || |  / _ \| / _` |   | |/ _ \/ _ \ (_-<
 \___/|_||_|_|\_/\___|_| /__/_|\__|\_, | /_/ \_\_\__,_|   |_|\___/\___/_/__/
                                   |__/                                     

##############################################################################
)";
}

void mainMenu() {
	cout << R"(
+----------------------------------------+-------------------------------------------+
|              Add a Faculty             |              Add a Department             |
|                   01                   |                     02                    |
+----------------------------------------+-------------------------------------------+
|           Add a Study Program          |               Add a Subject               |
|                   03                   |                     04                    |
+----------------------------------------+-------------------------------------------+
| Register a Student  in a Study program | Deregister a Student from a Study program |
|                   05                   |                     06                    |
+----------------------------------------+-------------------------------------------+
|            Add Student Marks           |           Delete a Study Program          |
|                   07                   |                     08                    |
+----------------------------------------+-------------------------------------------+
|           Delete a Department          |              Delete a Faculty             |
|                   09                   |                     10                    |
+----------------------------------------+-------------------------------------------+
|             Add a Pedagogue            |                    Exit                   |
|                   11                   |                     12                    |
+----------------------------------------+-------------------------------------------+
)";

}


void addDepartament() {
	checkFaculties(faculties);
	cout << R"(
+---------------------+
| Adding a Department |
+---------------------+
)" << endl;

	cout << "Add ID dhe Departmanet's name" << endl;
	int id;
	string name;
	cout << "ID: ";
	cin >> id;
	verifyInt(id);
	cin.ignore();
	//noZeroInt(id);
	cout << "Name: ";
	getline(cin, name);
	Departament departamentIRi(id, name); 
	cout << "Which faculty will it belong to?" << endl;
	string fName;
	getline(cin, fName);
	int poz = -1; 
	for (int i = 0; i < faculties.size(); i++) 	{
		if (faculties[i].name == fName)
		{
			poz = i; 
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl; 
		promptocheck(faculties);
		return;
	}
	faculties[poz].departamentet.push_back(departamentIRi);
	cls();
};

void addFaculty() {
	checkFaculties(faculties);
	cout << R"(
+------------------+
| Adding a Faculty |
+------------------+
)" << endl;
	string adresa, emer;
	cout << "Add Faculty's name and address" << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, emer);
	cout << "Address: ";
	getline(cin, adresa);
	Faculty fakultetIRi;
	fakultetIRi.name = emer;
	fakultetIRi.address = adresa;
	faculties.push_back(fakultetIRi);
	cls();
};

void addStudy() {
	checkFaculties(faculties);
	cout << R"(
+------------------------+
| Adding a Study Program |
+------------------------+
)" << endl;
	int id;
	string name;
	cout << "Add Study Program's ID, name and years:" << endl;
	cout << "ID: ";
	cin >> id;
	verifyInt(id);
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	int years;
	cout << "Years: ";
	cin >> years;
	verifyInt(years);
	S_Program newProgram(id, name, years);
	cout << "Which faculty will it belong to?" << endl;
	string fName;
	cin.ignore();
	getline(cin, fName);
	int poz = -1; 
	for (int i = 0; i < faculties.size(); i++) 
	{
		if (faculties[i].name == fName)
		{
			poz = i; 
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	cout << "Which department will it be attached to?" << endl;
	getline(cin, fName);
	int poz2 = -1;
	for (int i = 0; i < faculties[poz].departamentet.size(); i++)
	{
		if (faculties[poz].departamentet[i].nameDepartament == fName)
		{
			poz2 = i;
			break;
		}
	}
	if (poz2 == -1)
	{
		cout << "This departament cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	faculties[poz].departamentet[poz2].programet.push_back(newProgram);
	cls();


	

};

void addSubject() {
	checkFaculties(faculties);
	cout << R"(
+------------------+
| Adding a Subject |
+------------------+
)" << endl;
	int credits, hours;
	string name;
	cout << "Type Subject's name, credits and hours:" << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Credits: ";
	cin >> credits;
	verifyInt(credits);
	cout << "Hours: ";
	cin >> hours;
	verifyInt(hours);
	Subjects newSubjects(name, hours, credits);
	cout << "To which faculty will it belong?" << endl;
	string fName;
	cin.ignore();
	getline(cin, fName);
	int poz = -1;
	for (int i = 0; i < faculties.size(); i++)
	{
		if (faculties[i].name == fName)
		{
			poz = i;
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	cout << "To which department will it be added?" << endl;
	getline(cin, fName);
	int poz2 = -1;
	for (int i = 0; i < faculties[poz].departamentet.size(); i++)
	{
		if (faculties[poz].departamentet[i].nameDepartament == fName)
		{
			poz2 = i;
			break;
		}
	}
	if (poz2 == -1)
	{
		cout << "This department cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	cout << "To which programe will it be attached?" << endl;
	getline(cin, fName);
	int poz3 = -1;
	for (int i = 0; i < faculties[poz].departamentet[poz2].programet.size(); i++)
	{
		if (faculties[poz].departamentet[poz2].programet[i].nameProgram == fName)
		{
			poz3 = i;
			break;
		}
	}
	if (poz3 == -1)
	{
		cout << "This program cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	faculties[poz].departamentet[poz2].programet[poz3].sub.push_back(newSubjects);
	cls();

}

void addStudentstoSubject() {
	checkFaculties(faculties);
	cout << "To which faculty will he/she belong?" << endl;
	string fName;
	cin.ignore();
	getline(cin, fName);
	int poz = -1;
	for (int i = 0; i < faculties.size(); i++)
	{
		if (faculties[i].name == fName)
		{
			poz = i;
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	cout << "To which department will he/she belong?" << endl;
	getline(cin, fName);
	int poz2 = -1;
	for (int i = 0; i < faculties[poz].departamentet.size(); i++)
	{
		if (faculties[poz].departamentet[i].nameDepartament == fName)
		{
			poz2 = i;
			break;
		}
	}
	if (poz2 == -1)
	{
		cout << "This departament cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	cout << "Which programe will he/she belong to?" << endl;
	getline(cin, fName);
	int poz3 = -1;
	for (int i = 0; i < faculties[poz].departamentet[poz2].programet.size(); i++)
	{
		if (faculties[poz].departamentet[poz2].programet[i].nameProgram == fName)
		{
			poz3 = i;
			break;
		}
	}
	if (poz3 == -1)
	{
		cout << "This program cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}
	cout << "Which subject will he/she belong to?" << endl;
	getline(cin, fName);
	int poz4 = -1;
	for (int i = 0; i < faculties[poz].departamentet[poz2].programet[poz3].sub.size(); i++)
	{
		if (faculties[poz].departamentet[poz2].programet[poz3].sub[i].name == fName)
		{
			poz4 = i;
			break;
		}
	}
	if (poz4 == -1)
	{
		cout << "This subject cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl;
		promptocheck(faculties);
		return;
	}

	if (faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.size() == 0) {
		cout << R"(
+------------------------------------------------+
| This subject doesn't have a pedagogue assigned |
|                                                |
+------------------------------------------------+
)";
		cout << "You need to add a pedagogue first!" << endl;
		cout << "Do you want to assign a pedagogue to " << faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].name <<" now? (Y/N)";
		char input;
		cin >> input;
		if (input == 'y' || input == 'Y') {
			cls();
			addPedagoge(poz, poz2, poz3, poz4);
		}
		else {
			cls();
			cout << R"(
+-------------------------------------------------------+
| Cannot add a Student to a Subject without a Pedagogue |
|                  Returning to Menu...                 |
+-------------------------------------------------------+
)";
			Sleep(900);
			return;
		}
	}

	else
	{
		addStudent(poz, poz2, poz3, poz4);
		}
	}

void addPedagoge(int poz, int poz2, int poz3, int poz4) {
		cls();
		checkFaculties(faculties);
		cout << R"(
+--------------------+
| Adding a Pedagogue |
+--------------------+
)";
		cout << "Add Pedagogue ID, name, surname, salary, address, postalcode and birthday:" << endl;
		cout << "ID:  ";
		int id, salary, postalcode;
		cin >> id;
		verifyInt(id);
		string name, surname, address, birthday, password;
		cout << "Name: ";
		cin >> name;
		cout << "Surname: ";
		cin >> surname;
		cout << "Password: ";
		cin >> password;
		cout << "Salary: ";
		cin >> salary;
		verifyInt(salary);
		cout << "Address: ";
		cin.ignore();
		getline(cin, address);
		cout << " Postal Code: ";
		cin >> postalcode;
		verifyInt(postalcode);
		cout << "Birthday: ";
		cin.ignore();
		getline(cin, birthday);
		Pedagog newPedagogue(id,password,salary,name,surname,address,postalcode,birthday);
		faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.push_back(newPedagogue);

	}

void addStudent(int poz, int poz2, int poz3, int poz4) {
		cls();
		checkFaculties(faculties);
		cout << endl;
		cout << R"(
+------------------+
| Adding a Student |
+------------------+
)";
		cout << endl;
		cout << "To which PEDAGOGUE will he/she be assigned?" << endl;
		string fName;
		string sName;
		cout << "Name: ";
		cin >> fName;
		cout << "Surname: ";
		cin >> sName;
		int poz5 = -1;
		for (int i = 0; i < faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.size(); i++)
		{
			if (faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[i].name == fName && faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[i].surname == sName)
			{
				poz5 = i;
				break;
			}
		}
		if (poz5 == -1)
		{
			cout << "This pedagogue cannot be found" << endl;
			cout << "Check all the exsisiting faculties? (Y/N)" << endl;
			promptocheck(faculties);
			return;
		}
		cout << "Add Student ID, name, surname, salary, address, postalcode and birthday:" << endl;
		cout << "ID:  ";
		int id, postalcode, age;
		cin >> id;
		verifyInt(id);
		string name, surname, address, birthday, password;
		cout << "Name: ";
		cin >> name;
		cout << "Surname: ";
		cin >> surname;
		cout << "Password: ";
		cin >> password;
		cout << "Age: ";
		cin >> age;
		verifyInt(age);
		cout << "Address: ";
		cin.ignore();
		getline(cin, address);
		cout << "Postal Code: ";
		cin >> postalcode;
		verifyInt(postalcode);
		cout << "Birthday: ";
		cin.ignore();
		getline(cin, birthday);
		Student newStudent(name, surname,password,age,address,postalcode,birthday);
		faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[poz5].student.push_back(newStudent);
	}

void deregisterStudent() {
		cls();
		checkFaculties(faculties);
		cout << R"(
+----------------------+
| Searching Student... |
+----------------------+
)"; 
		string fName;
		cout << "Enter First Name: ";
		cin >> fName;
		string sName;
		cout << "Enter Second Name (Surname): ";
		cin >> sName;
		cls();

		int count = 0;
		for (int i = 0; i < faculties.size(); i++) {
			for (int j = 0; j < faculties[i].departamentet.size(); j++) {
				for (int k = 0; k < faculties[i].departamentet[j].programet.size(); k++) {
					for (int l = 0; l < faculties[i].departamentet[j].programet[k].sub.size(); l++) {
						for (int m = 0; m < faculties[i].departamentet[j].programet[k].sub[l].pedagog.size(); m++) {
							for (int n = 0; n < faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.size(); n++) {
								if (faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].name == fName && faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].surname == sName) {
									cout << "This student is registered in:" << endl;
									cout << "Faculty: " << faculties[i].name << " [" << i << "]" << endl;
									cout << "Departament: " << faculties[i].departamentet[j].nameDepartament << " [" << j << "]" << endl;
									cout << faculties[i].departamentet[j].programet[k].nameProgram << " [" << k << "]" << endl;
									count++;
								}
							}
						}
					}
				}
			}
		
				}
		if (count == 0) {
			cls();
			cout << R"(
+--------------------------+
| Cannot find this Student |
|   Returning to Menu...   |
+--------------------------+
)";
			Sleep(4000);
			return;
		}

		cout << R"(
+---------------------------------------------------------------------------------+
|                 Choose where you want to deregister this student                |
| Use the number displayed in [] after the faculty, department and program name   |
+---------------------------------------------------------------------------------+
)";
		int i;
		cout << "Enter First Number shown after Faculty's name: ";
		cin >> i;
		verifyInt(i);
		if (i > faculties.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		int j;
		cout << "Enter Second Number shown after Department's name: ";
		cin >> j;
		verifyInt(j);
		if (j > faculties[i].departamentet.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		int k;
		cout << "Enter Third Number shown after Program's name: ";
		cin >> k;
		verifyInt(k);
		if (k > faculties[i].departamentet[j].programet.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		count = 0;
		for (int l = 0; l < faculties[i].departamentet[j].programet[k].sub.size(); l++) {
			for (int m = 0; m < faculties[i].departamentet[j].programet[k].sub[l].pedagog.size(); m++) {
				for (int n = 0; n < faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.size(); n++) {
					if (faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].name == fName && faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].surname == sName) {
						faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.erase(faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.begin() + n);
						count++;
					}
				}
			}
		}

		if (count != 0) {
			cout << R"(
+-----------------+
| Student Deleted |
+-----------------+
)";
			Sleep(4000);
			return;
		}
	}

void deleteStudy() {
		checkFaculties(faculties);
		cout << R"(
+----------------------------+
| Searching Study Program... |
+----------------------------+
)";
		string fName;
		cout << "Enter Program name: ";
		cin.ignore();
		getline(cin, fName);
		cls();
		int count = 0;
		for (int i = 0; i < faculties.size(); i++) {
			for (int j = 0; j < faculties[i].departamentet.size(); j++) {
				for (int k = 0; k < faculties[i].departamentet[j].programet.size(); k++) {
					if (faculties[i].departamentet[j].programet[k].nameProgram == fName) {
						cout << "This program can be found in:" << endl;
						cout << "Faculty: " << faculties[i].name << " [" << i << "]" << endl;
						cout << "Department: " << faculties[i].departamentet[j].nameDepartament << " [" << j << "]" << endl;
						count++;
					}
				}
			}
		}
		if (count == 0) {
			cout << R"(
+--------------------------------+
| Cannot find this Study Program |
|      Returning to Menu...      |
+--------------------------------+
)";
			Sleep(4000);
			return;
		}

		cout << R"(
+----------------------------------------------------------------------+
|              Which study program do you want to delete?              |
| Use the number displayed in [] after the faculty and department name |
+----------------------------------------------------------------------+
)";
		int i;
		cout << "Enter First Number shown after Faculty's name: ";
		cin >> i;
		verifyInt(i);
		if (i > faculties.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		int j;
		cout << "Enter Second Number shown after Department's name: ";
		cin >> j;
		verifyInt(j);
		if (j > faculties[i].departamentet.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}

		count = 0;
		for (int k = 0; k < faculties[i].departamentet[j].programet.size(); k++) {
			if (faculties[i].departamentet[j].programet[k].nameProgram == fName) {
				faculties[i].departamentet[j].programet.erase(faculties[i].departamentet[j].programet.begin() + k);
				count++;
			}
		}

		if (count != 0) {
			cout << R"(
+-----------------------+
| Study Program Deleted |
+-----------------------+
)";
			Sleep(4000);
			cls();
			return;
		}
	}

void deleteDepartment() {
		cls();
		checkFaculties(faculties);
		cout<<R"(
+-------------------------+
| Searching Department... |
+-------------------------+
)";
		string fName;
		cout << "Enter Department name: ";
		cin.ignore();
		getline(cin, fName);
		cls();
		int count = 0;
		for (int i = 0; i < faculties.size(); i++) {
			for (int j = 0; j < faculties[i].departamentet.size(); j++) {
				if (faculties[i].departamentet[j].nameDepartament == fName) {
					cout << "This department can be found in:" << endl;
					cout << "Faculty: " << faculties[i].name << " [" << i << "]" << endl;
					count++;
				}
			}
		}

		if (count == 0) {
			cout << R"(
+-----------------------------+
| Cannot find this Department |
|     Returning to Menu...    |
+-----------------------------+
)";
			Sleep(4000);
			return;
		}

		cout << R"(
+---------------------------------------------------------+
|         Which department do you want to delete?         |
| Use the number displayed in [] after the faculty's name |
+---------------------------------------------------------+
)";
		int i;
		cout << "Enter First Number shown after Faculty's name: ";
		cin >> i;
		verifyInt(i);
		if (i > faculties.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		count = 0;
		for (int j = 0; j < faculties[i].departamentet.size(); j++) {
			if (faculties[i].departamentet[j].nameDepartament == fName) {
				faculties[i].departamentet.erase(faculties[i].departamentet.begin() + j);
				count++;
			}
		}

		if (count != 0) {
			cout << R"(
+--------------------+
| Department Deleted |
+--------------------+
)";
			Sleep(4000);
			cls();
			return;
		}
	}

void deleteFaculty() {
		cls();	
		checkFaculties(faculties);
		cout << R"(
+----------------------+
| Searching Faculty... |
+----------------------+
)";
		for (int i = 0; i < faculties.size(); i++) {
			cout << "[" << i << "] Name: " << faculties[i].name << endl;
		}

		cout << R"(
+--------------------------------------+
| Which Faculty do you want to delete? |
|    Use the number displayed in []    |
+--------------------------------------+
)";
		int i;
		cout << "Enter Number: ";
		cin >> i;
		verifyInt(i);
		if (i > faculties.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}

		faculties.erase(faculties.begin() + i);
		cout << R"(
+-----------------+
| Faculty Deleted |
+-----------------+
)";
		Sleep(4000);
		cls();

	}

void checkPedagogue() {
		cls();
		checkFaculties(faculties);
		cout << "Which faculty will he/she be assigned to?" << endl;
		string fName;
		cin.ignore();
		getline(cin, fName);
		int poz = -1;
		for (int i = 0; i < faculties.size(); i++)
		{
			if (faculties[i].name == fName)
			{
				poz = i;
				break;
			}
		}
		if (poz == -1)
		{
			cout << "This faculty cannot be found" << endl;
			cout << "Check all the exsisiting faculties? (Y/N)" << endl;
			promptocheck(faculties);
			return;
		}
		cout << "Which department will he/she be assigned to?" << endl;
		getline(cin, fName);
		int poz2 = -1;
		for (int i = 0; i < faculties[poz].departamentet.size(); i++)
		{
			if (faculties[poz].departamentet[i].nameDepartament == fName)
			{
				poz2 = i;
				break;
			}
		}
		if (poz2 == -1)
		{
			cout << "This departament cannot be found" << endl;
			cout << "Check all the exsisiting faculties? (Y/N)" << endl;
			promptocheck(faculties);
			return;
		}
		cout << "Which programe will he/she be assigned to?" << endl;
		getline(cin, fName);
		int poz3 = -1;
		for (int i = 0; i < faculties[poz].departamentet[poz2].programet.size(); i++)
		{
			if (faculties[poz].departamentet[poz2].programet[i].nameProgram == fName)
			{
				poz3 = i;
				break;
			}
		}
		if (poz3 == -1)
		{
			cout << "This program cannot be found" << endl;
			cout << "Check all the exsisiting faculties? (Y/N)" << endl;
			promptocheck(faculties);
			return;
		}
		cout << "Which subject will he/she be assigned to?" << endl;
		getline(cin, fName);
		int poz4 = -1;
		for (int i = 0; i < faculties[poz].departamentet[poz2].programet[poz3].sub.size(); i++)
		{
			if (faculties[poz].departamentet[poz2].programet[poz3].sub[i].name == fName)
			{
				poz4 = i;
				break;
			}
		}
		if (poz4 == -1)
		{
			cout << "This subject cannot be found" << endl;
			cout << "Check all the exsisiting faculties? (Y/N)" << endl;
			promptocheck(faculties);
			return;
		}

		if (faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.size() != 0) {
			cout << R"(
+---------------------------------------------+
| This subject does have a pedagogue assigned |
|    Do you want to add another pedagogue     |
|                      or                     |
|    Do you want to overwrite a pedagogue?    |
+---------------------------------------------+)";
			cout << R"(
+----------------------------------------------------------------------------------+
| Enter A to add || Enter O to Overwrite || Enter Any Othery Key to Return to Menu |
+----------------------------------------------------------------------------------+
)";
			char input;
			cin >> input;
			if (input == 'a' || input == 'A') {
				cls();
				addPedagoge(poz, poz2, poz3, poz4);
			}

			else if (input == 'o' || input == 'O') {
				cls();
				overwritePedagogue(poz, poz2, poz3, poz4);

			}
		}
	}

void createDirectories() {
		for (int i = 0; i < faculties.size(); i++) {
			string temp;
			temp = faculties[i].name;
			LPTSTR dirName = new TCHAR[temp.size() + 1];
			strcpy(dirName, temp.c_str());
			if (CreateDirectory(dirName, NULL))
			{
				string temp2 = temp;
				temp2 += "/information.txt";
				ofstream write(temp2);
				writeFaculties(faculties, i, write);

			}
			else if (ERROR_ALREADY_EXISTS == GetLastError())
			{
				cout << R"(
+-------------------------------------+
|       Directory already exists      |
| Do you want to overwrite the files? |
|                (Y/N)                |
+-------------------------------------+
)";
				char input;
				cin >> input;
				if (input == 'y' || input == 'Y') {
					string temp2 = temp;
					temp2 += "/information.txt";
					ofstream write(temp2);
					writeFaculties(faculties, i, write);
				}


			}
			else
			{
				throw exception();
			}
		}
	}

void addMarks() {
	cls();
	checkFaculties(faculties);
	cout << R"(
+-----------------------------------+
| Searching Student to add Marks... |
+-----------------------------------+
)";
	string fName;
	cout << "Enter First Name: ";
	cin >> fName;
	string sName;
	cout << "Enter Second Name (Surname): ";
	cin >> sName;
	cls();

	int count = 0;
	for (int i = 0; i < faculties.size(); i++) {
		for (int j = 0; j < faculties[i].departamentet.size(); j++) {
			for (int k = 0; k < faculties[i].departamentet[j].programet.size(); k++) {
				for (int l = 0; l < faculties[i].departamentet[j].programet[k].sub.size(); l++) {
					for (int m = 0; m < faculties[i].departamentet[j].programet[k].sub[l].pedagog.size(); m++) {
						for (int n = 0; n < faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.size(); n++) {
							if (faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].name == fName && faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].surname == sName) {
								cout << "This student is registered in:" << endl;
								cout << "Faculty: " << faculties[i].name << " [" << i << "]" << endl;
								cout << "Departament: " << faculties[i].departamentet[j].nameDepartament << " [" << j << "]" << endl;
								cout << "Program Name: " << faculties[i].departamentet[j].programet[k].nameProgram << " [" << k << "]" << endl;
								cout << "Subject: " << faculties[i].departamentet[j].programet[k].sub[l].name << " [" << l << "]" << endl;
								cout << "Pedagogue: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].name << " [" << m << "]" << endl;
								cout << "Student: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].name << " " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].surname << endl;
								count++;

								if (faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.size() != 0) {
									for (int o = 0; o < faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.size(); o++) {
										cout << "Marks: ";
										cout << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks[o] << " ";
									}
								}
								else{
									cout << "Marks: This student doesn't have a mark";
								}
							}
						}
					}
				}
			}
		}
	}

	
	if (count == 0) {
		cls();
		cout << R"(
+--------------------------+
| Cannot find this Student |
|   Returning to Menu...   |
+--------------------------+
)";
		Sleep(4000);
		return;
	}

	cout << R"(
+----------------------------------------------------+
|              To add marks to a student             |
|     Select the belonging numbers of each entity    |
|                Which are shown in []               |
| Start by Faculty until you reach Student's number  |
+----------------------------------------------------+
)";
	int i;
	cout << "Enter First Number shown after Faculty's name: ";
	cin >> i;
	verifyInt(i);
	if (i > faculties.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}
	int j;
	cout << "Enter Second Number shown after Department's name: ";
	cin >> j;
	verifyInt(j);
	if (j > faculties[i].departamentet.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}
	int k;
	cout << "Enter Third Number shown after Program's name: ";
	cin >> k;
	verifyInt(k);
	if (k > faculties[i].departamentet[j].programet.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}

	int l;
	cout << "Enter Fourth Number shown after Subject's name: ";
	cin >> l;
	verifyInt(l);
	if (l > faculties[i].departamentet[j].programet[k].sub.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}

	int m;
	cout << "Enter Fifth Number shown after Pedagogue's name: ";
	cin >> m;
	verifyInt(m);
	if (m > faculties[i].departamentet[j].programet[k].sub[l].pedagog.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}

	int n;
	cout << "Enter Sixth Number shown after Student's name: ";
	cin >> n;
	verifyInt(n);
	if (n > faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}

	if (faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.size() != 0){
		cout << R"(
+----------------------------------------------------+
| There appears to be existing marks on this student |
+----------------------------------------------------+
)";
		cout << R"(
+---------------+--------------+--------------+
| [O] Overwrite | [A] Add      | [D] Delete   |
+---------------+--------------+--------------+
)";
		char input;
		cin >> input;
		if (input == 'O' || input == 'o') {
			cout << R"(
+-----------------------+
| Overwriting a Mark... |
+-----------------------+
)";
			int o;
			cout << "Enter the Sevnth Number shown after Mark: ";
			cin >> o;
			verifyInt(o);
			if (o > faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.size()) {
				cout << "The input is not correct" << endl;
				cin.ignore();
				cin.ignore();
				return;
			}
			cout << " Enter desired mark: ";
			int mark;
			cin >> mark;
			verifyInt(mark);
			faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks[o] = mark;
			cls();
			cout << R"(
+------------------+
| Mark Overwritten |
+------------------+
)";
			Sleep(4000);
			return;
		}

		if (input == 'D' || input == 'd') {
			cout << R"(
+--------------------+
| Deleting a Mark... |
+--------------------+
)";
			int o;
			cout << "Enter the Sevnth Number shown after Mark: ";
			cin >> o;
			verifyInt(o);
			if (o > faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.size()) {
				cout << "The input is not correct" << endl;
				cin.ignore();
				cin.ignore();
				return;
			}

			faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.erase(faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.begin() + o);
			cls();
			cout << R"(
+--------------+
| Mark Deleted |
+--------------+
)";
			Sleep(4000);
			cls();
			return;


		}

		if (input != 'A' || input != 'a') {
			cls();
			cout << R"(
+----------------------+
|     Invalid input    |
| Returning to Menu... |
+----------------------+
)";
			Sleep(4000);
			cls();
			return;
		}
	}

	cout << R"(
+------------------+
| Adding a Mark... |
+------------------+
)";
	cout << " Enter desired mark: ";
	int mark;
	cin >> mark;
	verifyInt(mark);
	faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].marks.push_back(mark);
	cls();
	cout << R"(
+------------+
| Mark Added |
+------------+
)";
	Sleep(4000);
	cls();
}

void overwritePedagogue(int poz, int poz2, int poz3, int poz4){
	cls();
	checkFaculties(faculties);
	cout << R"(
+----------------------------+
| Overwriting a Pedagogue... |
+----------------------------+
)";

	cout << "Which pedagogue you want to overwrite in " << faculties[poz].name << " " << faculties[poz].departamentet[poz2].nameDepartament << " " << faculties[poz].departamentet[poz2].programet[poz3].nameProgram << " " << faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].name << " ?"<< endl;
	for (int m = 0; m < faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.size(); m++) {
	
		cout << faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[m].name << " " << faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[m].surname << " [" << m << "] " << endl;
	}

	cout << R"(
+--------------------------------------------------------------+
|                   To overwrite a Pedagogue                   |
| Select the number displayed after the name Pedagogue's name  |
+--------------------------------------------------------------+
)";
	int m;
	cout << "Enter the number of the pedagogue you want to overwrite: ";
	cin>>m;
	verifyInt(m);
	if (m > faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.size()) {
		cout << "The input is not correct" << endl;
		cin.ignore();
		cin.ignore();
		return;
	}
	cout << "Add Pedagogue ID, name, surname, salary, address, postalcode and birthday:" << endl;
	cout << "ID:  ";
	int id, salary, postalcode;
	cin >> id;
	verifyInt(id);
	string name, surname, address, birthday, password;
	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Password: ";
	cin >> password;
	cout << "Salary: ";
	cin >> salary;
	verifyInt(salary);
	cout << "Address: ";
	cin.ignore();
	getline(cin, address);
	cout << " Postal Code: ";
	cin >> postalcode;
	verifyInt(postalcode);
	cout << "Birthday: ";
	cin.ignore();
	getline(cin, birthday);
	Pedagog newPedagogue(id, password, salary, name, surname, address, postalcode, birthday);
	faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[m] = newPedagogue;

	cls();
	cout << R"(
+---------------------+
| Overwrite completed |
+---------------------+
)";
	Sleep(4000);
	cls();


}