#include <string>
#include "Track.h"
#include <algorithm>
#include <iostream>
using namespace std;

Track::Track(const string tname)
{
    trackName = tname;
    papersHead = NULL;
}

Track::~Track ()
{
    trackName = "";
    destroyTrack();
}

Track::Track( const Track &trackToCopy)
{
    trackName = trackToCopy.trackName;
    if( trackToCopy.papersHead == NULL)
        papersHead = NULL;
    else
    {
        papersHead = new PaperNode;
        papersHead->p = Paper(trackToCopy.papersHead->p);
        PaperNode* mewPtr = papersHead;
        for( PaperNode* cur = trackToCopy.papersHead->next; cur != NULL; cur= cur->next)
        {
            mewPtr->next = new PaperNode;
            mewPtr = mewPtr ->next;
            mewPtr->p = Paper( cur->p);
        }
        mewPtr ->next = NULL;
    }
}

void Track::operator=(const Track &right)
{
    trackName = right.trackName;
    if( right.papersHead == NULL)
    {
        destroyTrack();
    }
    else
    {
        destroyTrack();
        papersHead = new PaperNode;
        papersHead->p = Paper(right.papersHead->p);
        PaperNode* mewPtr = papersHead;
        for( PaperNode* cur = right.papersHead->next; cur != NULL; cur= cur->next)
        {
            mewPtr->next = new PaperNode;
            mewPtr = mewPtr ->next;
            mewPtr->p = Paper( cur->p);
        }
        mewPtr ->next = NULL;
    }
}

string Track::getTrackName()
{
    return trackName;
}

void Track::destroyTrack()
{
    while( papersHead != NULL)
    {
        PaperNode* temp = papersHead;
        papersHead = papersHead->next;
        temp->p.destroyPaper();
    }
}

void Track::addPaper( const string paperName)
{
    Paper mewPaper( paperName);
    if( papersHead == NULL)
    {
        papersHead = new PaperNode;
        papersHead ->next = NULL;
        papersHead->p = mewPaper;

    }
    else if( findPaper( paperName) != NULL)
    {

    }
    else
    {
        for( PaperNode* cur = papersHead; cur != NULL; cur=cur->next)
        {
            if( cur ->next == NULL)
            {
                cur->next = new PaperNode;
                cur = cur->next;
                cur ->next = NULL;
                cur->p =mewPaper;

            }
        }
    }
}
void Track::removePaper( const string paperName)
{
    if( papersHead == NULL) {}
    else if( findPaper( paperName) == NULL){}
    else
    {
        if( papersHead->p.getName() == paperName)
        {
            PaperNode* del = papersHead;
            papersHead = papersHead ->next;
            delete del;
        }
        else
        {
            for( PaperNode* cur = papersHead; cur != NULL; cur=cur->next)
            {
                if( cur->next->p.getName() == paperName)
                {
                    PaperNode* del = cur ->next;
                    cur->next = del ->next;
                    delete del;
                }
            }
        }
    }
}
Track::PaperNode* Track::findPaper(string paperName)
{
    if( papersHead == NULL)
        return NULL;
    else
    {
        std::string data = paperName;
        transform( data.begin(), data.end(), data.begin(), ::tolower);

        for( PaperNode* cur = papersHead; cur != NULL; cur=cur->next)
        {
            string name = cur->p.getName();
            transform( name.begin(), name.end(), name.begin(), ::tolower);
            if( name == data)
                return cur;
        }
        return NULL;
    }
}

void Track::addAuthor( const string pname, const int id, const string name)
{
    PaperNode* temp = findPaper( pname);
    temp->p.addAuthor( id, name);
}

void Track::removeAuthor( const string pname, const int id)
{
    PaperNode* temp = findPaper( pname);
    temp->p.removeAuthor( id);
}

void Track::displayAuthors( const string pname)
{
    PaperNode* temp = findPaper( pname);
    temp->p.displayAuthors();
}

void Track::displayThisTrack()
{
   if( papersHead != NULL)
   {
      PaperNode* cur = papersHead;
      cout << getTrackName() << endl;
      while( cur != NULL)
      {
         cout << cur->p.getName()<< endl;
         cur->p.displayAuthors();
      }
   }
}
