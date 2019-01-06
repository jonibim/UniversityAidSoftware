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
void cls(void);

int main() {

	int ProgramExit = 0;
	while (ProgramExit !=1) {
		welcomeScreen();
		mainMenu();
		int choice;
		cout << "Enter option: (0-12): " << endl;
		cin >> choice;
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

		}

		if (choice == 8) {

		}

		if (choice == 9) {

		}

		if (choice == 10) {

		}

		if (choice == 11) {

		}

		if (choice == 11) {
		}

		if (choice == 15) {
			cout << "Debug Size" << endl;
			DebugSize(faculties);
			string temp;
			cin >> temp;
		}

		if (choice <= 0) {
			cout << "Select an option using numbers from 1 - 12" << endl;
		}

		if (choice == 12) {
			return 0;
		}

	}






}

void welcomeScreen(void){
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
	cout << R"(
+---------------------+
| Adding a Department |
|                     |
+---------------------+
)" << endl;

	cout << "Add ID dhe Departmanet's name" << endl;
	int id;
	string name;
	cout << "ID: ";
	cin >> id;
	verifyInt(id);
	//noZeroInt(id);
	cout << "Name: " << endl;
	cin >> name;
	Departament departamentIRi(id, name); 
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
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
};
void addFaculty() {
	cout << R"(
+------------------+
| Adding a Faculty |
|                  |
+------------------+
)" << endl;
	string adresa, emer;
	cout << "Vendosni emrin dhe adresen e Fakultetit" << endl;
	cin >> emer;
	cin >> adresa;
	Faculty fakultetIRi;
	fakultetIRi.name = emer;
	fakultetIRi.address = adresa;
	faculties.push_back(fakultetIRi);
};
void addStudy() {
	cout << R"(
+------------------------+
| Adding a Study Program |
|                        |
+------------------------+
)" << endl;
	int id;
	string name;
	cout << "Add Study Program ID, name and years:" << endl;
	cout << "ID: ";
	cin >> id;
	verifyInt(id);
	//noZeroInt(id);
	cin >> name;
	int years;
	cout << "Years: ";
	cin >> years;
	verifyInt(years);
	//noZeroInt(years);
	S_Program newProgram(id, name, years);
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
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
	cout << "Cilit departament do i perkasi?" << endl;
	cin >> fName;
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


	

};
void addSubject() {
	cout << R"(
+------------------+
| Adding a Subject |
|                  |
+------------------+
)" << endl;
	int credits, hours;
	string name;
	cout << "Add Subject name, credits and hours:" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Credits: ";
	cin >> credits;
	verifyInt(credits);
	cout << "Hours: ";
	cin >> hours;
	verifyInt(hours);
	Subjects newSubjects(name, hours, credits);
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
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
	cout << "Cilit departament do i perkasi?" << endl;
	cin >> fName;
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
	cout << "Cilit program do i perkasi?" << endl;
	cin >> fName;
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

}

void addStudentstoSubject() {
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
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
	cout << "Cilit departament do i perkasi?" << endl;
	cin >> fName;
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
	cout << "Cilit program do i perkasi?" << endl;
	cin >> fName;
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
	cout << "Cilit mesim do i perkasi?" << endl;
	cin >> fName;
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
+------------------------------------------------+)";
		cout << "Do you want to assign a pedagogue to " << faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].name << " ? (Y/N)";
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
		cout << R"(
+--------------------+
| Adding a Pedagogue |
|                    |
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
		cout << "Salary";
		cin >> salary;
		verifyInt(salary);
		cout << "Address: ";
		cin >> address;
		cout << " Postal Code: ";
		cin >> postalcode;
		verifyInt(postalcode);
		cout << "Birthday: ";
		cin >> birthday;
		Pedagog newPedagogue(id,password,salary,name,surname,address,postalcode,birthday);
		faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.push_back(newPedagogue);

	}

	void addStudent(int poz, int poz2, int poz3, int poz4) {
		cout << R"(
+------------------+
| Adding a Student |
|                  |
+------------------+
)";
		cout << "Cilit pedagog?" << endl;
		string fName;
		cin >> fName;
		int poz5 = -1;
		for (int i = 0; i < faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog.size(); i++)
		{
			if (faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[i].name == fName)
			{
				poz5 = i;
				break;
			}
		}
		if (poz5 == -1)
		{
			cout << "This pedagoge cannot be found" << endl;
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
		cin >> address;
		cout << " Postal Code: ";
		cin >> postalcode;
		verifyInt(postalcode);
		cout << "Birthday: ";
		cin >> birthday;
		Student newStudent(name, surname,password,age,address,postalcode,birthday);
		faculties[poz].departamentet[poz2].programet[poz3].sub[poz4].pedagog[poz5].student.push_back(newStudent);
	}

	void deregisterStudent() {
		cout << R"(
+----------------------+
| Searching Student... |
|                      |
+----------------------+
)";
		cout << "Enter First Name: ";
		string fName;
		string sName;
		cout << "Enter Second Name (Surname): ";
		cin >> fName;
		cin >> sName;
		cls();

		int count = 0;
		for (int i = 0; i < faculties.size(); i++)
			for (int j = 0; j < faculties[i].departamentet.size(); j++)
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
		if (count == 0) {
			cls();
			cout << R"(
+--------------------------+
| Cannot find this Student |
|   Returning to Menu...   |
+--------------------------+
)";
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
		if (i > faculties.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		int j;
		cout << "Enter Second Number shown afrer Department's name: ";
		cin >> j;
		if (j > faculties[i].departamentet.size()) {
			cout << "The input is not correct" << endl;
			cin.ignore();
			cin.ignore();
			return;
		}
		int k;
		cout << "Enter Third Number shown after Program's name: ";
		cin >> k;
		if (k > faculties[i].departamentet.size()) {
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
|                 |
+-----------------+
)";
			Sleep(4000);
			return;
		}
	}