#pragma once
#include "StudentElement.h"
#include "DisciplinesList.h"

class StudentsList
{
private:
	StudentElement* head;
	int length;

public:
	StudentsList();
	StudentsList(StudentsList&);
	~StudentsList();

	StudentElement GetElement(int);
	void AddElement(string, string, DisciplinesList*);
	void DeleteElement(int = -1);

	void PrintStudentsByDiscipline(string);
	void PrintMostPopularDiscipline();

	int GetLength();

	friend ostream& operator << (ostream& os, const StudentsList& el)
	{
		StudentElement* currentElement = el.head;

		os << "Length: " << el.length << endl << "Students: " << endl;

		for (int i = 0; i < el.length; i++)
		{
			os << i << " | " << *currentElement << endl;
			currentElement = currentElement->Next;
		}

		return os;
	}
};