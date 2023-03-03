#pragma once
#include <iostream>;

using namespace std;

struct StudentElement
{
	string FIO = "";
	string Discipline = "";
	StudentElement* Next = nullptr;
};

ostream& operator << (ostream& os, const StudentElement& el);