#include <iostream>
using namespace std;
#include "SimpleTrack.h"

Track::Track( const string trName)
{
   trackName = trName;
}

Track::~Track( ){}

Track::Track( const Track &trackToCopy)
{
   trackName = trackToCopy.trackName;
}

void Track::operator=( const Track & right)
{
   trackName = right.trackName;
}

string Track::getTrackName()
{
   return trackName;
}

