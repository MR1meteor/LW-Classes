#include "StudentElement.h"

ostream& operator << (ostream& os, const StudentElement& el)
{
	os << "FIO: " << el.FIO << " | Discipline: " << el.Discipline;

	return os;
}