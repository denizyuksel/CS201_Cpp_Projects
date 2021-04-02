#include <iostream>
using namespace std;
#include "Course.h"

Course::Course()
{
   courseId = 0;
   courseCredit = 0;
   courseGrade = "";

}

Course::~Course(){}


Course::Course(const Course &courseToCopy)
{
   courseId = courseToCopy.courseId;
   courseCredit = courseToCopy.courseCredit;
   courseGrade = courseToCopy.courseGrade;

}

void Course::operator=(const Course &right)
{
   courseId = right.courseId;
   courseCredit = right.courseCredit;
   courseGrade = right.courseGrade;

}

int Course::getCourseId()
{
   return courseId;
}

int Course::getCourseCredit()
{
   return courseCredit;
}

string Course::getCourseGrade()
{
   return courseGrade;
}

void Course::setCourseGrade( string letter)
{
   courseGrade = letter;
}
void Course::setCourseId( int id)
{
   courseId = id;
}

void Course::setCourseCredit( int credit)
{
   courseCredit = credit;
}
