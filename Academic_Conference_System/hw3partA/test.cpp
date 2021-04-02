#include <iostream>
#include "SimpleACS.h"
using namespace std;

int main(){

   ACS myACS;
   /*
   bool addTrack(const string trackName);
    bool removeTrack (const string trackName);
    void displayTracks();
   */
   cout << " INITIALLY" << endl;
   myACS.removeTrack( " biyoloji");
   myACS.displayTracks();
   cout << " Adding tracks... \n" << endl;
   myACS.addTrack( " Biyoloji");
   myACS.addTrack( " CS");
   myACS.addTrack( " Tenis");
   myACS.addTrack( " Jazz");
   myACS.addTrack( " Jazz");
   myACS.addTrack( " Jazz");
   myACS.addTrack( " Jazz");
   //myACS.removeTrack( " Jazz");




   myACS.displayTracks();


   myACS.addTrack( " Montaigne");

   cout << " \n Displaying tracks... \n" << endl;
   myACS.displayTracks();


   cout << " \n Removing a track which is not in the ACS... \n" << endl;
   myACS.removeTrack( " BOKTAN");
   myACS.removeTrack( " Noobs");

   cout << " \n Displaying tracks again... \n" << endl;
   myACS.displayTracks();

   cout << " \n Removing tracks... \n " << endl;
   myACS.removeTrack( " Tenis");
   myACS.displayTracks();
   myACS.removeTrack(" CS");

   myACS.removeTrack(" Jazz");

   myACS.removeTrack( " Biyoloji");
   myACS.displayTracks();

   cout << " WOOOOW STOP RIGHT THERE " << endl;
   myACS.removeTrack(" BÝyoloji");
   myACS.removeTrack(" BÝyoloji");
   myACS.removeTrack(" BÝyoloji");
   myACS.removeTrack(" Montaigne");
   myACS.removeTrack(" Montaigne");

   myACS.displayTracks();

   cout << " Adding tracks again... \n" << endl;
   myACS.addTrack( " Tenis");
   myACS.addTrack( " CS");
   myACS.addTrack( " Tenis");
   myACS.addTrack( " Biyoloji");
   myACS.displayTracks();

   ACS mySecondACS;

   cout << " Copy constructor..." << endl;
   mySecondACS.displayTracks();
   mySecondACS = myACS;
   mySecondACS.displayTracks();

   cout << " Assignment operator..."<<endl;
   ACS myThirdACS = myACS;
   myThirdACS.displayTracks();

   cout << " Empty Assignment operator..." << endl;
   ACS myFourthACS;
   mySecondACS = myFourthACS;
   mySecondACS.displayTracks();

   return 0;
}
