#pragma once
#include "DisciplineElement.h"

class DisciplinesList
{
private:
	DisciplineElement* head;
	int length;

public:
	DisciplinesList();
	DisciplinesList(DisciplinesList&);
	~DisciplinesList();

	DisciplineElement GetElement(int);
	void AddElement(string);
	void DeleteElement(int = -1);
	bool HasElement(string);

	int GetLength();

	friend ostream& operator << (ostream& os, const DisciplinesList& el)
	{
		DisciplineElement* currentElement = el.head;

		os << "Length: " << el.length << endl << "Disciplines: " << endl;

		for (int i = 0; i < el.length; i++)
		{
			os << i << " | " << *currentElement << endl;
			currentElement = currentElement->Next;
		}

		return os;
	}
};