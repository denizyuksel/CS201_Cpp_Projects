#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

Student::Student( const int sid, const string sname)
{
    studentId = sid;
    studentName = sname;
    courses = NULL;
    courseNo = 0;
}

Student::~Student()
{
    studentId = 0;
    studentName = "";

    if( courses)
    {
        delete[] courses;
    }
    courses = NULL;
}

Student::Student( const Student &studentToCopy)
{
    studentId = studentToCopy.studentId;
    studentName = studentToCopy.studentId;
    courseNo = studentToCopy.courseNo;

    if( studentToCopy.courseNo > 0)
    {
        courses = new Course[ courseNo];
        for( int i = 0; i < courseNo; i++)
        {
            courses[i] = studentToCopy.courses[i];
        }
    }
    else
    {
        courses = NULL;
    }
}

void Student::operator=( const Student &right)
{
    studentId = right.studentId;
    studentName = right.studentName;
    courseNo = right.courseNo;

    if( right.courseNo > 0)
        courses = new Course[ courseNo];
    for( int i = 0; i < courseNo; i++)
    {
        courses[i] = right.courses[i];
    }

}

int Student::getStudentId()
{
    return studentId;
}

string Student::getStudentName()
{
    return studentName;
}

int Student::getCourseNo()
{
    return courseNo;
}

Course* Student::getCourses()
{
    return courses;
}

int Student::findCourseIndex(int idOfCourse)
{
    for( int i = 0; i < courseNo; i++)
    {
        if( courses[i].getCourseId() == idOfCourse)
            return i;
    }
    return -1;

}

double Student::calculateStudentCurrentGPA()
{
    double total = 0.0;
    int credit = 0;

    for( int i = 0; i < courseNo; i++)
    {
        if( courses[i].getCourseGrade() == "A+")
        {
            total = total + courses[i].getCourseCredit() * 4;
            credit = credit + courses[i].getCourseCredit();
        }

        else if( courses[i].getCourseGrade() == "A")
        {
            total = total + courses[i].getCourseCredit() * 4;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "A-")
        {
            total = total + courses[i].getCourseCredit() * 3.7;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "B+")
        {
            total = total + courses[i].getCourseCredit() * 3.3;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "B")
        {
            total = total + courses[i].getCourseCredit() * 3.0;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "B-")
        {
            total = total + courses[i].getCourseCredit() * 2.7;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "C+")
        {
            total = total + courses[i].getCourseCredit() * 2.3;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "C")
        {
            total = total + courses[i].getCourseCredit() * 2.0;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "C-")
        {
            total = total + courses[i].getCourseCredit() * 1.7;
           credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "D+")
        {
            total = total + courses[i].getCourseCredit() * 1.3;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "D")
        {
            total = total + courses[i].getCourseCredit() * 1.0;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "F" || courses[i].getCourseGrade() == "FZ" || courses[i].getCourseGrade() == "FX")
        {
            total = total + courses[i].getCourseCredit() * 0;
            credit = credit + courses[i].getCourseCredit();
        }
        else if( courses[i].getCourseGrade() == "W")
        {

        }
        else
        {

        }

    }
    return total / credit;
}
void Student::addCourse( const int courseId, const string courseGrade, const int courseCredit)
{
    Course anyCourse;
    anyCourse.setCourseCredit( courseCredit);
    anyCourse.setCourseGrade( courseGrade);
    anyCourse.setCourseId( courseId);
    if( courseNo == 0)
    {
        courses = new Course[1];
        courses[0] = anyCourse;
        courseNo++;
    }

    else if( findCourseIndex( courseId) >= 0)
    {

    }
    else
    {
        Course* temp = courses;
        courses = new Course[ courseNo + 1];
        for( int i = 0; i < courseNo; i++)
        {
            courses[i] = temp[i];
        }
        courses[ courseNo] = anyCourse;
        delete [] temp;
        courseNo++;
    }
}

void Student::removeCourse( const int courseId)
{
    int removeIndex;
    removeIndex = findCourseIndex( courseId);

    if( courseNo == 0)
    {
        // THERE ARE NO COURSES.
    }
    else if( removeIndex < 0)
    {
        // STUDENT DOESN'T TAKE THE COURSE.
    }
    else
    {
        if( courseNo == 1)
        {
            delete[] courses;
            courses = NULL;
            courseNo--;
        }
        else
        {
            Course* temp;
            temp = new Course[ courseNo - 1];

            for( int i = 0; i < removeIndex; i++)
                temp[i] = courses[i];

            for( int i = removeIndex + 1; i < courseNo; i++)
                temp[ i - 1] = courses[i];

            delete[] courses;
            courses = temp;
            courseNo--;
        }
    }
}

