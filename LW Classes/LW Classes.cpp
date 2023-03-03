#include <iostream>
#include "DisciplinesList.h"
#include "StudentsList.h"

int main()
{
	try
	{
		DisciplinesList disciplines;
		disciplines.AddElement("Math");
		disciplines.AddElement("Physic");
		disciplines.AddElement("Language");

		DisciplinesList disciplines2 = disciplines;

		cout << disciplines << endl;
		cout << disciplines2 << endl;

		disciplines.DeleteElement();

		cout << disciplines << endl;
		cout << disciplines2 << endl;

		while (true)
		{
			DisciplinesList testDestruct;
			testDestruct.AddElement("1");
			testDestruct.AddElement("2");
			testDestruct.AddElement("3");

			break;
		}
		
		cout << disciplines << endl;

		StudentsList students;

		students.AddElement("Student 1", "Math", &disciplines);
		students.AddElement("Student 2", "Physic", &disciplines);
		students.AddElement("Student 3", "Math", &disciplines);
		students.AddElement("student 4", "Physic", &disciplines);

		StudentsList students2 = students;

		cout << students << endl;
		cout << students2 << endl;

		students.DeleteElement(2);

		cout << students << endl;
		cout << students2 << endl;

		students.PrintMostPopularDiscipline();

		students.PrintStudentsByDiscipline("Physic");
	}
	catch (const char* msg)
	{
		cout << "Exception: " << msg;
	}
}