#include <iostream>
#include <string>
using namespace std;
#include "SimpleStudent.h"

Student::Student( const int sid, const string sname){
   studentId = sid;
   studentName = sname;
}

Student::~Student(){
   studentId = 0;
   studentName = "";
}

Student::Student( const Student &studentToCopy){
   studentId = studentToCopy.studentId;
   studentName = studentToCopy.studentId;
}

void Student::operator=( const Student &right){
   studentId = right.studentId;
   studentName = right.studentName;
}

int Student::getStudentId(){
   return studentId;
}

string Student::getStudentName(){
   return studentName;
}


