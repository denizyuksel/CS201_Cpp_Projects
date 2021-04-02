#ifndef __SIMPLE_STUDENT_H
#define __SIMPLE_STUDENT_H
#include <string>
#include "Course.h"
using namespace std;
class Student {
   public:
      Student( const int sid = 0, const string sname = "");
      ~Student();
      Student( const Student &studentToCopy);
      void operator=( const Student &right);
      int getStudentId();
      string getStudentName();
      double calculateStudentCurrentGPA();
      int getCourseNo();
      int findCourseIndex( int idOfCourse);
      Course* getCourses();
      void addCourse( const int courseId, const string courseGrade, const int courseCredit);
      void removeCourse( const int courseId);

   private:
      int studentId;
      string studentName;
      int courseNo;
      Course* courses;
};
#endif

