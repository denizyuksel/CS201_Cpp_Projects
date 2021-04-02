#include <iostream>
using namespace std;
#include "SRS.h"

SRS::SRS()
{
    studentNo = 0;
    students = NULL;
}

SRS::~SRS()
{
    if( students)
    {
        delete [] students;
        students = NULL;
    }
}

SRS::SRS( const SRS &srsToCopy)
{
    studentNo = srsToCopy.studentNo;

    if( studentNo > 0)
    {
        students = new Student[ studentNo];
        for( int i = 0; i < studentNo; i++)
        {
            students[i] = srsToCopy.students[i];
        }
    }
    else
        students = NULL;
}

void SRS::operator= ( const SRS &right)
{
    if( &right != this)
    {
        studentNo = right.studentNo;
        if( studentNo > 0)
        {
            delete[] students;
            students = new Student[ studentNo];
            for( int i = 0; i < studentNo; i++)
            {
                students[i] = right.students[i];
            }
        }
        else
            students = NULL;
    }
}

bool SRS::addStudent( const int studentId, const string studentName)
{

    Student stud( studentId, studentName);

    if( students == NULL)
    {
        students = new Student[ 1];
        students[ 0] = stud;
        studentNo++;
        return true;
    }

    else if( findStudent( studentId) >= 0)
    {
        return false;
    }

    else
    {
        Student* temp;
        temp = students;
        students = new Student[ studentNo + 1];

        for( int i = 0; i < studentNo; i ++)
        {
            students[i] = temp[i];
        }
        students[ studentNo] = stud;
        studentNo++;
        delete[] temp;
        return true;
    }
}

bool SRS::removeStudent( const int studentId )
{
    int removeIndex;
    removeIndex = findStudent( studentId);

    if( students == NULL)
    {
        return false;
    }
    else if( removeIndex < 0)
    {
        return false;
    }
    else
    {
        if( studentNo == 1)
        {
            studentNo--;
            delete [] students;
            return true;
        }
        else
        {
            Student* temp;
            temp = new Student[ studentNo - 1];

            for( int i = 0; i < removeIndex; i++)
            {
                temp[i] = students[i];

            }
            for( int j = removeIndex + 1; j < studentNo; j++)
            {
                temp[j - 1] = students[j];

            }

            delete[] students;
            students = temp;
            studentNo--;
            return true;
        }
    }
}

int SRS::getStudents(Student *&allStudents)
{
    allStudents = new Student[ studentNo];
    for( int i = 0; i < studentNo; i++)
    {
        allStudents[i] = students[i];
    }
    return studentNo;
}

int SRS::findStudent( int stId)
{

    int data = stId;

    for( int i = 0; i < studentNo; i++)
    {
        int id = students[i].getStudentId();
        if( id == data)
        {
            return i;
        }
    }
    return -1;
}

bool SRS::addCourse(const int studentId, const int courseId,
                    const string courseGrade, const int courseCredit)
{
    int k = findStudent( studentId); // course insert index.
    if( k >= 0)
    {
        students[ k].addCourse( courseId, courseGrade, courseCredit);
        return true;
    }
    return false;
}


bool SRS::removeCourse(const int studentId, const int courseId)
{
    int k = findStudent( studentId);

    if( k >= 0)
    {
        students[k].removeCourse( courseId);
        return true;
    }
    return false;
}

double SRS::calculateCourseGPA(const int courseId)
{
    double totalGPA = 0.0;
    int totalStudentNo = 0;

    for( int i = 0; i < studentNo; i++)
    {
        int courseIndex = students[i].findCourseIndex( courseId);
        if( courseIndex >= 0)
        {
            string courseGrade = students[i].getCourses()[courseIndex].getCourseGrade();
            if( courseGrade == "A+" || courseGrade == "A")
            {
                totalGPA = totalGPA + 4.0;
                totalStudentNo++;
            }
            else if( courseGrade == "A-")
            {
                totalGPA = totalGPA + 3.7;
                totalStudentNo++;
            }
            else if( courseGrade == "B+")
            {
                totalGPA = totalGPA + 3.3;
                totalStudentNo++;
            }
            else if( courseGrade == "B")
            {
                totalGPA = totalGPA + 3.0;
                totalStudentNo++;
            }
            else if( courseGrade == "B-")
            {
                totalGPA = totalGPA + 2.7;
                totalStudentNo++;
            }
            else if( courseGrade == "C+")
            {
                totalGPA = totalGPA + 2.3;
                totalStudentNo++;
            }
            else if( courseGrade == "C")
            {
                totalGPA = totalGPA + 2.0;
                totalStudentNo++;
            }
            else if( courseGrade == "C-")
            {
                totalGPA = totalGPA + 1.7;
                totalStudentNo++;
            }
            else if( courseGrade == "D+")
            {
                totalGPA = totalGPA + 1.3;
                totalStudentNo++;
            }
            else if( courseGrade == "D")
            {
                totalGPA = totalGPA + 1.0;
                totalStudentNo++;
            }
            else if( courseGrade == "F")
            {
                totalStudentNo++;
            }
            else if( courseGrade == "W" || courseGrade == "FZ" || courseGrade == "FX")
            {
            }

        }
    }
    return totalGPA / totalStudentNo;
}
