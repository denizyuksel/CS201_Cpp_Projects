#include <iostream>
#include "SimpleACS.h"
#include <algorithm>
using namespace std;

ACS::ACS()
{
    head = NULL;
    name = "";
    topic = "";
    trackCount = 0;
}

ACS::~ACS()
{
    while( head != NULL)
    {
        TrackNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ACS::ACS( const ACS& acsToCopy)
{
    name = acsToCopy.name;
    topic = acsToCopy.topic;
    trackCount = acsToCopy.trackCount;
    if( acsToCopy.head == NULL)
        head = NULL;
    else
    {
        head = new TrackNode;
        head->t = acsToCopy.head->t;

        TrackNode* mewPtr = head;
        for( TrackNode* origPtr = acsToCopy.head ->next; origPtr != NULL; origPtr = origPtr ->next)
        {
            mewPtr->next = new TrackNode;
            mewPtr = mewPtr->next;
            mewPtr->t = origPtr->t;
        }
        mewPtr ->next = NULL;
    }
}

void ACS::operator=(const ACS& right)
{
    name = right.name;
    topic = right.topic;
    trackCount = right.trackCount;
    if( right.head == NULL)
    {	   
        while( head != NULL)
        {
            TrackNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    else
    {
        while( head != NULL)
        {
            TrackNode* temp = head;
            head = head->next;
            delete temp;
        }
        head = new TrackNode;
        head->t = right.head->t;

        TrackNode* mewPtr = head;
        for( TrackNode* origPtr = right.head ->next; origPtr != NULL; origPtr = origPtr ->next)
        {
            mewPtr->next = new TrackNode;
            mewPtr = mewPtr->next;
            mewPtr->t = origPtr->t;
        }
        mewPtr ->next = NULL;
    }
}
bool ACS::addTrack(const string trackName)
{
    Track mewTrack( trackName);
    if( head == NULL)
    {
        head = new TrackNode;
        head ->next = NULL;
        head->t = mewTrack;
        trackCount++;
        return true;
    }
    else if( findTrack(trackName) != NULL)
    {
        return false;
    }
    else
    {
        for( TrackNode* cur = head; cur != NULL; cur=cur->next)
        {
            if( cur ->next == NULL)
            {
                cur->next = new TrackNode;
                cur = cur->next;
                cur ->next = NULL;
                cur->t =mewTrack;
                trackCount++;
                return true;
            }
        }

    }
}
bool ACS::removeTrack(const string trackName)
{
    if( head == NULL)
        return false;
    else if( findTrack( trackName) == NULL)
    {
        return false;
    }
    else
    {
        if( head->t.getTrackName() == trackName)
        {
            TrackNode* del = head;
            head = head ->next;
            delete del;
        }
        else
        {
            for( TrackNode* cur = head; cur != NULL; cur=cur->next)
            {
                if( cur->next->t.getTrackName() == trackName)
                {
                    TrackNode* del = cur ->next;
                    cur->next = del ->next;
                    delete del;
                    trackCount--;
                    return true;
                }
            }
        }

    }
}

ACS::TrackNode* ACS::findTrack(string trackName)
{
    if( head == NULL)
        return NULL;
    else
    {
        std::string data = trackName;
        transform( data.begin(), data.end(), data.begin(), ::tolower);

        for( TrackNode* cur = head; cur != NULL; cur=cur->next)
        {
            string name = cur->t.getTrackName();
            transform( name.begin(), name.end(), name.begin(), ::tolower);
            if( name == data)
                return cur;
        }
        return NULL;
    }
}

void ACS::displayTracks()
{
    if( head == NULL)
    {
        cout << "--EMPTY--" << endl;
    }
    else
    {
        for( TrackNode* cur = head; cur != NULL; cur=cur->next)
        {
            cout << cur->t.getTrackName() << "," << endl;
        }
    }
}
