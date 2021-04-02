#include <iostream>
#include "Author.h"
using namespace std;

Author::Author()
{
   name = "";
   id = 0;
}
Author::Author(const int id, const string name)
{
   this->name = name;
   this->id = id;
}
int Author::getID()
{
   return id;
}
string Author::getName()
{
   return name;
}
