#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex; // index of last student in the roster
	int capacity; // max size of the roster
	Student** classRosterArray; //array of pointers to Student

	Roster(); //empty constructor
	Roster(int capacity); 

	void parseAdd(std::string datarow);
	void print_All();
	bool remove(std::string studentID);
	void printAverageDays(std::string studentID);
	void printInvalidEmails();
	void printByDegreeType(DegreeType d);

	~Roster(); //deconstructor
};



