#ifndef __COURSE_H
#define __COURSE_H
#include <string>
using namespace std;
class Course
{
public:
    Course();
    ~Course();
    Course(const Course &courseToCopy);
    void operator=(const Course &right);
    int getCourseId();
    int getCourseCredit();
    string getCourseGrade();
    void setCourseGrade( string letter);
    void setCourseId( int id);
    void setCourseCredit( int credit);

private:
    int courseId;
    int courseCredit;
    string courseGrade;

};
#endif
