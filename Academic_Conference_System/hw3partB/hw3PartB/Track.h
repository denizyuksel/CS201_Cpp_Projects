#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED
#include <string>
#include "Paper.h"
using namespace std;
class Track
{
public:
    Track(const string tname = "");
    ~Track();
    Track (const Track &trackToCopy);
    void operator=(const Track &right);
    string getTrackName();
    void destroyTrack();
    void addPaper( const string pname);
    void removePaper( const string pname);
    void addAuthor( const string pname, const int id, const string name);
    void removeAuthor( const string pname, const int id);
    void displayAuthors(const string pname);
    void displayThisTrack();
private:
   struct PaperNode
    {
        Paper p;
        PaperNode* next;
    };
    string trackName;
    PaperNode* papersHead;
    PaperNode* findPaper(string pname);
};
#endif // TRACK_H_INCLUDED
