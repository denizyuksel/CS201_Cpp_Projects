#ifndef __SIMPLE_SRS_H
#define __SIMPLE_SRS_H
#include <string>
using namespace std;
#include "Student.h"
class SRS
{
public:
    SRS();
    ~SRS();
    SRS(const SRS &srsToCopy);
    void operator=(const SRS &right);
    bool addStudent(const int studentId, const string studentName);
    bool removeStudent(const int studentId);
    int getStudents(Student *&allStudents);
    int findStudent( int stId);
    bool addCourse(const int studentId, const int courseId,
                   const string courseGrade, const int courseCredit);
    bool removeCourse(const int studentId, const int courseId);
    double calculateCourseGPA(const int courseId);
private:
    Student *students;
    int studentNo;
};
#endif
