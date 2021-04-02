#include <iostream>
#include <string>
using namespace std;
#include "Paper.h"

Paper::Paper()
{
    name = "";
    head = NULL;
}
Paper::Paper( const string name )
{
    this->name = name;
    head = NULL;
}
Paper::~Paper()
{
    destroyPaper();
}
Paper::Paper( const Paper& paperToCopy )
{
    name = paperToCopy.name;
    if( paperToCopy.head == NULL)
        head = NULL;
    else
    {
        head = new AuthorNode;
        head->a = paperToCopy.head->a;

        AuthorNode* mewPtr = head;
        for( AuthorNode* origPtr = paperToCopy.head ->next; origPtr != NULL; origPtr = origPtr ->next)
        {
            mewPtr->next = new AuthorNode;
            mewPtr = mewPtr->next;
            mewPtr->a = origPtr->a;
        }
        mewPtr ->next = NULL;
    }
}
void Paper::operator=( const Paper& right )
{
    name = right.name;
    if( right.head == NULL)
    {
        head = NULL;
        destroyPaper();
    }
    else
    {
        while( head != NULL)
        {
            AuthorNode* temp = head;
            head = head->next;
            delete temp;
        }
        head = new AuthorNode;
        head->a = right.head->a;

        AuthorNode* mewPtr = head;
        for( AuthorNode* origPtr = right.head ->next; origPtr != NULL; origPtr = origPtr ->next)
        {
            mewPtr->next = new AuthorNode;
            mewPtr = mewPtr->next;
            mewPtr->a = origPtr->a;
        }
        mewPtr ->next = NULL;
    }
}
string Paper::getName()
{
    return name;
}

bool Paper::addAuthor( const int id, const string name )
{
    Author mewAuthor( id, name);
    if( head == NULL)
    {
        head = new AuthorNode;
        head ->next = NULL;
        head->a = mewAuthor;
        return true;
    }
    else if( findAuthor( id) != NULL)
    {
        return false;
    }
    else
    {
        for( AuthorNode* cur = head; cur != NULL; cur=cur->next)
        {
            if( cur ->next == NULL)
            {
                cur->next = new AuthorNode;
                cur = cur->next;
                cur ->next = NULL;
                cur->a =mewAuthor;
                return true;
            }
        }
    }
}
bool Paper::removeAuthor ( const int id )
{
   if( head == NULL)
        return false;
    else if( findAuthor( id) == NULL)
    {
        return false;
    }
    else
    {
        if( head->a.getID() == id)
        {
            AuthorNode* del = head;
            head = head ->next;
            delete del;
        }
        else
        {
            for( AuthorNode* cur = head; cur != NULL; cur=cur->next)
            {
                if( cur->next->a.getID() == id)
                {
                    AuthorNode* del = cur ->next;
                    cur->next = del ->next;
                    delete del;
                    return true;
                }
            }
        }
    }
}
void Paper::displayAuthors()
{
   if( head == NULL)
    {
        cout << "--EMPTY--" << endl;
    }
    else
    {
        for( AuthorNode* cur = head; cur != NULL; cur=cur->next)
        {
            cout << "\t" <<cur->a.getID() << "," << cur->a.getName() << endl;
        }
    }
}
Paper::AuthorNode* Paper::findAuthor(int id)
{
   if( head == NULL)
        return NULL;
    else
    {
        for( AuthorNode* cur = head; cur != NULL; cur=cur->next)
        {
            if( id == cur->a.getID())
                return cur;
        }
        return NULL;
    }
}
void Paper::destroyPaper()
{
    while( head != NULL)
    {
        AuthorNode* temp = head;
        head = head->next;
        delete temp;
    }
}
