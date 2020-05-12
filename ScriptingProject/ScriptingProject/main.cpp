
#include "roster.h"

const int numStudents = 5;
static std::string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Robert,O'Donnell,odonnellrob21@gmail.com,20,1,2,3,SOFTWARE"
};
int main()
{
	std::cout << "WGU Scripting and Programming-Applications - C867\nWritten in C++ on Visual Studio \nWGU Student ID: #001349867 \n Robert O'Donnell\n\n\n";


	Roster* classRoster = new Roster(numStudents);


	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseAdd(studentData[i]);
	}

	
	std::cout << "Print all:\n\n";
	classRoster->print_All();

	std::cout << "\n\n";
	classRoster->printInvalidEmails();

	std::cout << "\n\n";
	std::cout << "Print all student's average days\n";

	for (int i = 1; i <= numStudents; i++)
	{
		classRoster->printAverageDays("A" + std::to_string(i));
		std::cout << "\n";
	}

	std::cout << "\n\n";
	classRoster->printByDegreeType(SOFTWARE);

	std::cout << "\n\n";
	std::cout << "Removing A3\n";
	classRoster->remove("A3");

	std::cout << "\n\n";
	std::cout << "Print all without A3\n";

	std::cout << "\n\n";
	classRoster->print_All();

	std::cout << "\n\n";
	std::cout << "Trying to remove A3 again:\n\n";
	classRoster->remove("A3");
	classRoster->~Roster();
}
