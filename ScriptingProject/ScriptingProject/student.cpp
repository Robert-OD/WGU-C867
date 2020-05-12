#include "student.h"
#include <iomanip>
// full constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, std::string studentAge, int daysToComplete[], DegreeType type)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysToComplete = new int[daysToCompleteSize];
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->dType = type;
};

// empty constructor 
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = "";
	this->daysToComplete = new int[daysToCompleteSize];
	for (int i = 0; i < daysToCompleteSize; i++) this->daysToComplete[i] = 0;
	this->dType = DegreeType::UNDECIDED;
};

//getters
std::string Student::getStudentID()
{
	return studentID;
}

std::string Student::getFirstName()
{
	return firstName;
}

std::string Student::getLastName()
{
	return lastName;
}

std::string Student::getEmailAddress()
{
	return emailAddress;
}

std::string Student::getStudentAge()
{
	return studentAge;
}

int* Student::getDaysToComplete()
{
	return daysToComplete;
}

inline DegreeType Student::getDegreeType()
{
	return dType;
}

//setters
void Student::setStudentID(std::string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setStudentAge(std::string studentAge)
{
	this->studentAge = studentAge;
}

void Student::setDaysToComplete(int daysToComplete[])
{
	
	this->daysToComplete = new int[daysToCompleteSize];
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	
}

void Student::setDegreeType(DegreeType d)
{
	this->dType = d;
}



void Student::print()
{
	std::cout << std::left << "Student ID: " <<  std::setw(1) << std::left << studentID << "   ";
	std::cout << std::left << " First Name: " << std::setw(5) << std::left << firstName << "   ";
	std::cout << std::left << " Last Name: " << std::setw(5) << std::left << lastName << "   ";
	std::cout << std::left << " Email: " << std::setw(5) << std::left << emailAddress << "   ";
	std::cout << std::left << " Age: " << std::setw(5) << std::left << studentAge << std::endl;
	std::cout << std::left << std::setw(5) << "Days In Course: {" << daysToComplete[0] << ", ";
	std::cout << std::left << daysToComplete[1] << ", ";
	std::cout << std::left << daysToComplete[2] << "}" << "             ";
	std::cout << std::left << " Degree Program: " << std::setw(5) << std::left << DegreeTypeStrings[getDegreeType()] << std::endl << std::endl << std::endl;
}

Student::~Student()
{
	if (daysToComplete != nullptr)
	{
		delete[] daysToComplete;
		daysToComplete = nullptr;
	}
}