#pragma once
#include <iostream>

using namespace std;

struct DisciplineElement
{
	string Name = "";
	DisciplineElement* Next;
};

ostream& operator << (ostream&, const DisciplineElement&);