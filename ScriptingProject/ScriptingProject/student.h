#pragma once
#include "degree.h"
#include <string>

class Student
{
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string studentAge;
	int* daysToComplete;
	DegreeType dType;
public:

	const static int daysToCompleteSize = 3;
	
	Student();												//empty constructor

	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, std::string studentAge, int daysToComplete[], DegreeType type); //full constructor

	std::string getStudentID();								//Accessor
	std::string getFirstName();								//Accessor
	std::string getLastName();								//Accessor
	std::string getStudentAge();							//Accessor
	std::string getEmailAddress();							//Accessor
	int* getDaysToComplete();								//Accessor
	DegreeType getDegreeType();								//Accessor

	void setStudentID(std::string studentID);				//Mutator
	void setFirstName(std::string firstName);				//Mutator
	void setLastName(std::string lastName);					//Mutator
	void setEmailAddress(std::string emailAddress);			//Mutator
	void setStudentAge(std::string studentAge);				//Mutator
	void setDaysToComplete(int daysToComplete[]);			//Mutator
	void setDegreeType(DegreeType d);

	void print();
		 
	 ~Student();											//deconstructor
};

