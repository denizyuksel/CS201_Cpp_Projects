#include <iostream>
using namespace std;
#include "SimpleSRS.h"

SRS::SRS(){
   studentNo = 0;
   students = NULL;
}

SRS::~SRS(){
   if( students)
   {
      delete [] students;
      students = NULL;
   }
}

SRS::SRS( const SRS &srsToCopy){
   studentNo = srsToCopy.studentNo;

   if( studentNo > 0){
      students = new Student[ studentNo];
         for( int i = 0; i < studentNo; i++){
            students[i] = srsToCopy.students[i];
         }
      }
      else
         students = NULL;

}

void SRS::operator= ( const SRS &right){
   if( &right != this){
      studentNo = right.studentNo;
      if( studentNo > 0){
         delete[] students;
         students = new Student[ studentNo];
         for( int i = 0; i < studentNo; i++){
            students[i] = right.students[i];
         }
      }
      else
         students = NULL;
   }
}

bool SRS::addStudent( const int studentId, const string studentName){

   Student stud( studentId, studentName);

   if( students == NULL){
      students = new Student[ 1];
      students[ 0] = stud;
      studentNo++;
      return true;
   }

   else if( findStudent( studentId) >= 0){
         return false;
   }

   else{
         Student* temp;
         temp = students;
         students = new Student[ studentNo + 1];

         for( int i = 0; i < studentNo; i ++){
            students[i] = temp[i];
         }
         students[ studentNo] = stud;
         studentNo++;
         delete[] temp;
         return true;
   }
}

bool SRS::removeStudent( const int studentId ){
   int removeIndex;
   removeIndex = findStudent( studentId);

   if( students == NULL){
      return false;
   }
   else if( removeIndex < 0){
      return false;
   }
   else{
         if( studentNo == 1){
            studentNo--;
            delete [] students;
            return true;
         }
         else{
         Student* temp;
         temp = new Student[ studentNo - 1];

         for( int i = 0; i < removeIndex; i++){
            temp[i] = students[i];

         }
         for( int j = removeIndex + 1; j < studentNo; j++){
            temp[j - 1] = students[j];

         }

         delete[] students;
         students = temp;
         studentNo--;
         return true;
      }
   }
}

int SRS::getStudents(Student *&allStudents){
   allStudents = new Student[ studentNo];
   for( int i = 0; i < studentNo; i++){
      allStudents[i] = students[i];
   }
   return studentNo;
}



int SRS::findStudent( int stId){

    int data = stId;

    for( int i = 0; i < studentNo; i++){
      int id = students[i].getStudentId();
      if( id == data){
            return i;
      }
    }
    return -1;
}
