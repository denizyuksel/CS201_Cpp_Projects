#ifndef __AUTHOR_H
#define __AUTHOR_H
#include <string>
using namespace std;
class Author
{
public:
    Author();
    Author(const int id, const string name);
    int getID();
    string getName();
private:
    string name;
    int id;
};
#endif
