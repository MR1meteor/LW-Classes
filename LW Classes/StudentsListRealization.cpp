#include "StudentsList.h"

StudentsList::StudentsList()
{
	head = nullptr;
	length = 0;
}

StudentsList::StudentsList(StudentsList& students)
{
	if (students.length == 0)
	{
		head = nullptr; 
		length = 0;
		return;
	}

	StudentElement* el = students.head;
	StudentElement* copiedElement = new StudentElement{ el->FIO, el->Discipline, nullptr };
	head = copiedElement;
	StudentElement* currentElement = head;
	el = el->Next;

	while (el != nullptr)
	{
		copiedElement = new StudentElement{ el->FIO, el->Discipline, nullptr };
		currentElement->Next = copiedElement;
		currentElement = currentElement->Next;
		el = el->Next;
	}

	length = students.length;
}

StudentsList::~StudentsList()
{
	StudentElement* previousElement = nullptr;
	StudentElement* currentElement = head;

	while (currentElement != nullptr)
	{
		previousElement = currentElement;
		currentElement = currentElement->Next;
		delete previousElement;
	}
}

StudentElement StudentsList::GetElement(int index)
{
	if (index >= length || index < 0)
		throw "GetElement: Index out of range";

	StudentElement* el = head;

	for (int i = 1; i <= index; i++)
		el = el->Next;

	return *el;
}

void StudentsList::AddElement(string fio, string discipline, DisciplinesList* disciplines)
{
	if (fio.empty() || discipline.empty())
		throw "AddElement: Fio and discipline can not be empty";

	if (!disciplines->HasElement(discipline))
		throw "AddElement: Discipline not found";

	StudentElement* newElement = new StudentElement{ fio, discipline, nullptr };

	if (length == 0)
	{
		head = newElement;
		length++;
		return;
	}

	StudentElement* currentElement = head;

	for (int i = 1; i < length; i++)
	{
		currentElement = currentElement->Next;
	}

	currentElement->Next = newElement;
	length++;
	return;
}

void StudentsList::DeleteElement(int index)
{
	index = index == -1 ? length - 1 : index;

	if (index >= length || index < 0)
		throw "DeleteElement: Index out of range";

	StudentElement* previousElement = nullptr;
	StudentElement* currentElement = head;

	if (index == 0)
	{
		head = currentElement->Next;
		delete currentElement;
		length--;
		return;
	}

	for (int i = 0; i < index; i++)
	{
		previousElement = currentElement;
		currentElement = currentElement->Next;
	}

	previousElement->Next = currentElement->Next;
	delete currentElement;
	length--;
	return;
}

void StudentsList::PrintStudentsByDiscipline(string discipline)
{
	StudentElement* el = head;

	cout << "Students with discipline '" << discipline << "':" << endl;

	while (el != nullptr)
	{
		if (el->Discipline == discipline)
			cout << *el << endl;
		
		el = el->Next;
	}

	return;
}

void StudentsList::PrintMostPopularDiscipline()
{
	StudentElement* el = head;

	if (length == 0)
	{
		cout << "List is empty" << endl;
		return;
	}

	string disciplines[100];
	int disciplinesCounters[100] = { 0 };

	while (el != nullptr)
	{
		string discipline = el->Discipline;
		int index = 0;
		bool found = false;

		while (!disciplines[index].empty())
		{
			if (disciplines[index] == discipline)
			{
				found = true;
				break;
			}

			index++;
		}

		if (!found)
		{
			disciplines[index] = discipline;
		}

		disciplinesCounters[index]++;

		el = el->Next;
	}

	int maxDisciplineNumber = 0;
	int popularDisciplineIndex = 0;

	for (int i = 0; disciplinesCounters[i] > 0; i++)
	{
		if (disciplinesCounters[i] > maxDisciplineNumber)
		{
			maxDisciplineNumber = disciplinesCounters[i];
			popularDisciplineIndex = i;
		}
	}

	cout << "Most popular discipline is '" << disciplines[popularDisciplineIndex] << "'" << endl;
	
	return;
}

int StudentsList::GetLength() { return length; }