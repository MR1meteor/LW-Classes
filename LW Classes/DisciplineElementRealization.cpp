#include "DisciplineElement.h"

ostream& operator << (ostream& os, const DisciplineElement& el)
{
	os << "Discipline: " << el.Name;
	return os;
}