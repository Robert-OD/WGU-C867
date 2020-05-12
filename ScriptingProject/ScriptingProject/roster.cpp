#include "roster.h"

const int numStudents = 5;
std::string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Robert,O'Donnell,odonnellrob21@gmail.com,20,1,2,3,SOFTWARE"
};

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::parseAdd(std::string row)
{
	if (lastIndex < capacity)
	{
		lastIndex++;

		int dArray[Student::daysToCompleteSize];

		if (row.back() == 'Y')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeType(DegreeType::SECURITY);
		}
		else if (row.back() == 'K')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeType(DegreeType::NETWORK);
		}
		else if (row.back() == 'E')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeType(DegreeType::SOFTWARE);
		}
		else if (row.back() == 'D')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeType(DegreeType::UNDECIDED);
		}
		else
		{
			std::cerr << "Invalid degree type, exiting now...\n";
			exit(-1);
		}

		//Set ID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

		//Set First Name
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set Last Name
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set Email Address
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set Age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setStudentAge(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set Days to Complete
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set Days to Complete
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set Days to Complete
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set all of the Days
		classRosterArray[lastIndex]->setDaysToComplete(dArray);
	}
	else
	{
		std::cerr << "Error, list has exceeded cpacity.\n Exiting now...";
		exit(-1);
	}
	
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
	}
}

bool Roster::remove(std::string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
		else
		{
			std::cout << "There is no student with the ID: " << studentID << std::endl;
			return found;
		}
	}
	return found;
}


void Roster::printAverageDays(std::string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* days = classRosterArray[i]->getDaysToComplete();
			std::cout << "Average number of days of student " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << "." << std::endl;			
		}
	}
	if (!found) std::cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	std::cout << "Displaying invalid email addresses: \n" << std::endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		bool any = false;
		std::string iEmail = classRosterArray[i]->getEmailAddress();
		for (int j = 0; j < classRosterArray[i]->getEmailAddress().length(); j++)
		{
			if (iEmail[j] == ' ')
			{
				std::cout << '"' << iEmail << '"' << " is an invalid email!\n";
			}
		}
		if (iEmail.find("@") == std::string::npos)
		{
			std::cout << '"' << classRosterArray[i]->getEmailAddress() << '"' << " is an invalid email!\n";
		}
		else if (iEmail.find(".") == std::string::npos)
		{
			std::cout << '"' << classRosterArray[i]->getEmailAddress() << '"' << " is an invalid email!\n";
		}		
	}
}

void Roster::printByDegreeType(DegreeType d)
{
	std::cout << "Printing students with degree type: " << DegreeTypeStrings[d] << std::endl << std::endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i]->getDegreeType() == d)
		{
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}



