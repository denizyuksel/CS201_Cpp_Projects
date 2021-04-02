#ifndef __PAPER_H
#define __PAPER_H
#include <string>
using namespace std;
#include "Author.h"
class Paper
{
public:
    Paper();
    Paper( const string name );
    ~Paper();
    Paper( const Paper& paperToCopy );
    void operator=( const Paper& right );
    string getName();
    bool addAuthor( const int id, const string name);
    bool removeAuthor ( const int id );
    void displayAuthors();
    void destroyPaper();

private:
    struct AuthorNode
    {
        Author a;
        AuthorNode* next;
    };
    AuthorNode *head;
    string name;
    AuthorNode* findAuthor(int id);
};
#endif
