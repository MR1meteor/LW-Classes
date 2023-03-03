#include "DisciplinesList.h"

DisciplinesList::DisciplinesList()
{
	head = nullptr;
	length = 0;
}

DisciplinesList::DisciplinesList(DisciplinesList& disciplines)
{
	DisciplineElement* el = disciplines.head;
	DisciplineElement* copiedElement = new DisciplineElement{ el->Name, nullptr };
	head = copiedElement;
	DisciplineElement* currentElement = head;
	el = el->Next;

	while (el != nullptr)
	{
		copiedElement = new DisciplineElement{ el->Name, nullptr };
		currentElement->Next = copiedElement;
		currentElement = currentElement->Next;
		el = el->Next;
	}

	length = disciplines.length;
}

DisciplinesList::~DisciplinesList()
{
	DisciplineElement* previousElement;
	DisciplineElement* currentElement = head;

	while (currentElement != nullptr)
	{
		previousElement = currentElement;
		currentElement = currentElement->Next;
		delete previousElement;
	}
}

DisciplineElement DisciplinesList::GetElement(int index)
{
	if (index >= length || index < 0)
		throw "GetElement: Index out of range";

	DisciplineElement* el = head;

	for (int i = 1; i <= index; i++)
		el = el->Next;

	return *el;
}

void DisciplinesList::AddElement(string name)
{
	if (name.empty())
		throw "AddElement: Name can not be empty";

	DisciplineElement* newElement = new DisciplineElement { name, nullptr };

	if (length == 0)
	{
		head = newElement;
		length++;
		return;
	}

	DisciplineElement* currentElement = head;

	for (int i = 1; i < length; i++)
	{
		currentElement = currentElement->Next;
	}

	currentElement->Next = newElement;
	length++;
	return;
}

void DisciplinesList::DeleteElement(int index)
{
	index = index == -1 ? length - 1 : index;

	if (index >= length || index < 0)
		throw "DeleteElement: Index out of range";

	DisciplineElement* previousElement = nullptr;
	DisciplineElement* currentElement = head;
	
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

bool DisciplinesList::HasElement(string name)
{
	DisciplineElement* el = head;

	while (el != nullptr)
	{
		if (el->Name == name)
			return true;

		el = el->Next;
	}

	return false;
}

int DisciplinesList::GetLength() { return length; }