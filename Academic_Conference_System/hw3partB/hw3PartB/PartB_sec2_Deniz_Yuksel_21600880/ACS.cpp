#include <string>
#include <iostream>
#include "ACS.h"
#include <algorithm>
using namespace std;

ACS::ACS()
{
    head = NULL;
    trackCount = 0;

}
ACS::~ACS()
{
    destroyACS();
    trackCount = 0;
}
ACS::ACS( const ACS& systemToCopy )
{
    trackCount = systemToCopy.trackCount;
    if( systemToCopy.head == NULL)
        head = NULL;
    else
    {
        head = new Node;
        head->t = Track(systemToCopy.head->t);
        Node* mewPtr = head;
        for( Node* cur = systemToCopy.head->next; cur != NULL; cur= cur->next)
        {
            mewPtr->next = new Node;
            mewPtr = mewPtr ->next;
            mewPtr->t = Track( cur->t);
        }
        mewPtr ->next = NULL;
    }
}
void ACS::operator=( const ACS& right )
{
    trackCount = right.trackCount;
    if( right.head == NULL)
    {
        destroyACS();
    }
    else
    {
        destroyACS();
        head = new Node;
        head->t = Track(right.head->t);
        Node* mewPtr = head;
        for( Node* cur = right.head->next; cur != NULL; cur= cur->next)
        {
            mewPtr->next = new Node;
            mewPtr = mewPtr ->next;
            mewPtr->t = Track( cur->t);
        }
        mewPtr ->next = NULL;
    }
}
void ACS::addTrack( string trackName )
{
    Track mewTrack( trackName);
    if( head == NULL)
    {
        head = new Node;
        head ->next = NULL;
        head->t = mewTrack;
        trackCount++;
    }
    else if( findTrack( trackName) != NULL)
    {}
    else
    {
        for( Node* cur = head; cur != NULL; cur=cur->next)
        {
            if( cur ->next == NULL)
            {
                cur->next = new Node;
                cur = cur->next;
                cur ->next = NULL;
                cur->t =mewTrack;
                trackCount++;
            }
        }
    }
}
void ACS::removeTrack( string trackName )
{
    if( head == NULL) {}
    else if( findTrack( trackName) == NULL){}
    else
    {
        if( head->t.getTrackName() == trackName)
        {
            Node* del = head;
            head = head ->next;
            delete del;
            trackCount--;
        }
        else
        {
            for( Node* cur = head; cur != NULL; cur=cur->next)
            {
                if( cur->next->t.getTrackName() == trackName)
                {
                    Node* del = cur ->next;
                    cur->next = del ->next;
                    delete del;
                    trackCount--;
                }
            }
        }
    }
}
void ACS::displayAllTracks()
{
    if( head == NULL)
    {
        cout << "--EMPTY--" << endl;
    }
    else
    {
        for( Node* cur = head; cur != NULL; cur=cur->next)
        {
            cout << cur->t.getTrackName() << "," << endl;
        }
    }
}

void ACS::addPaper( string trackName, string paperName )
{
   if( findTrack( trackName) != NULL)
   {
      Node* datTrack = findTrack( trackName);
      datTrack->t.addPaper( paperName);
   }
}
void ACS::removePaper( string trackName, string paperName )
{
   if( findTrack( trackName) != NULL)
   {
      Node* datTrack = findTrack( trackName);
      datTrack->t.removePaper( paperName);
   }
}
void ACS::addAuthor( string trackName, string paperName, int authorID, string
                     authorName )
{
   Node* temp = findTrack( trackName);
   temp->t.addAuthor( paperName, authorID, authorName);
}
void ACS::removeAuthor(string trackName, string paperName, int authorID )
{
   Node* temp = findTrack( trackName);
   temp->t.removeAuthor( paperName, authorID);
}
void ACS::displayTrack( string trackName )
{
   Node* temp = findTrack( trackName);
   temp->t.displayThisTrack();
}
void ACS::displayAuthor( int authorID )
{
   // Too overwhelming.

}
void ACS::destroyACS()
{
    while( head != NULL)
    {
        Node* cur = head;
        head = head->next;
        cur->t.destroyTrack();
    }
}
ACS::Node* ACS::findTrack(string trackName)
{
    if( head == NULL)
        return NULL;
    else
    {
        std::string data = trackName;
        transform( data.begin(), data.end(), data.begin(), ::tolower);

        for( Node* cur = head; cur != NULL; cur=cur->next)
        {
            string name = cur->t.getTrackName();
            transform( name.begin(), name.end(), name.begin(), ::tolower);
            if( name == data)
                return cur;
        }
        return NULL;
    }
}
