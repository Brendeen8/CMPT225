/*
Time Complexity:

    Default constructor
      O(1) - only 2 variables in constant time
    Destructor
      O(n) - dependent on n nodes in while loop
    Copy constructor
      O(n) - dependent on n nodes in while loop 
    Overloaded assignment operator
      O(n) - dependent on n nodes in while loop
    Insert
      O(n) - dependent on n nodes in for loop
    Remove
      O(n) - dependent on n nodes in for loop
    Get
      O(n) - dependent on n nodes in for loop
    Swap
      O(n) - dependent on n nodes in for loop
      even though there are 2 for loops, they
      are not nested and we only account for max time 
    Size
      O(1) - return is in constant time

    Enter a song
      O(n) - dependent on valid input while loop
    Remove a song
      O(n) - dependent on valid input while loop
    Swap two songs
      O(1) - no loops and all lines are in constant time
    Print all the songs
      O(n) - dependent on for loop of playlist size

*/
#include <iostream>
#include <string>
#include <limits>
    
#include "PlayList.h"
#include "Song.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

int main(){
  
  // Menu
  cout << "***Welcome to PlayList!***\n" 
       << "\nEnter Option Number:\n"
       << "1: Enter a song in the playlist at a given position\n"
       << "2: Remove a song from the playlist at a given position\n"
       << "3: Swap 2 songs in the playlist\n"
       << "4: Print all songs in the playlist\n"
       << "5: Quit"
       << endl;
  
  // Initialize the choice variable and create a new playlist
  int choice;
  PlayList myPlaylist;

  // Loop that will continue until user prompts to
  while(true) {
    // Sub Menu
    cout << "\nEnter 1 (insert), 2 (remove), 3 (swap), 4 (print) 5 (quit): ";
    cin >> choice;

    // Clears buffer so that \n doesn't mess up getline input
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Insert Command
    if(choice == 1) {
      string songName;
      string artist;
      int length;
      unsigned int position;
      unsigned int theSize = myPlaylist.size() + 1;
      
      // Ask user for each song attribute
      cout << "Song Name: ";
      getline(cin, songName);
      cout << "Artist: ";
      getline(cin, artist);
      cout << "Length: ";
      cin >> length;

      // Loop that asks for position until user enters valid number
      while(true) {
        
        // Prompts user and checks if Position is 1 or greater
        if(theSize == 1) {
          cout << "Position(1): ";
        }
        else {
         cout << "Position (1-" << theSize << "): ";
        }
        cin >> position;

        if(position < theSize+1){ // Condition if position is valid
          break;
        }
        cout << "INVALID POSITION, TRY AGAIN" << endl;  
      }
      // Create song and insert to list
      Song addSong(songName, artist, length);
      myPlaylist.insert(addSong, position-1);
      
      // Summary of inserted song
      cout << "You added " << songName << " at position "
           << position << " in the playlist" << endl;
    }

    // Remove command
    else if(choice == 2) {
      unsigned int theSize = myPlaylist.size();
      unsigned int position = 0;
    
      if(theSize == 0) { // Case if list is empty
        cout << "Nothing to remove" << endl;
      }
      else {
        // Loop that continues until user enters valid position
        while(true) {
          
          // Prompts user and checks if position is 1 or greater
          if(theSize == 1) {
            cout << "Position(1): ";
          }
          else {
            cout << "Position (1-" << theSize << "):";
          }
          cin >> position;

          if(position < theSize+1){ // Condition if position is valid
           break;
          }
        cout << "INVALID POSITION, TRY AGAIN" << endl; // Output if position is invalid  
        }
        // Get the song at position
        Song theSong = myPlaylist.get(position-1);

        // Summary of removed song
        cout << "You removed " << theSong.getName() << " from the playlist" << endl;
        myPlaylist.remove(position - 1);

      }
    }
    // Swap Command
    else if(choice == 3) {
      unsigned int theSize = myPlaylist.size();
      unsigned int position1 = 0;
      unsigned int position2 = 0;

      if(theSize == 0 || theSize == 1) { // Condition if list is empty or only 1 song
        cout << "Nothing to swap" << endl;
      }
      else {
        // Prompt user to enter swapped positions
        cout << "Swap song at position (1-" << theSize << "): "; 
        cin >> position1;
        cout << "with the song at position (1-" << theSize << "): ";
        cin >> position2;

        if(position1 > theSize || position2 > theSize) { // Condition if user enters invalid position
          cout << "POSITION INVALID, NOTHING SWAPPED" << endl;
        }
        else {
          // Switch positions in list
          myPlaylist.swap(position1 -1, position2 -1);
          
          // Summary of swapped positions
          cout << "You swapped the songs at position " << position1
               << " and " << position2 << endl;
        }
      }
    }
    // Print Command
    else if(choice == 4) {
      unsigned int theSize = myPlaylist.size();
      
      // Print all the songs in the list
      for(unsigned int i = 0; i < theSize; i++) {
       Song retrievedsong = myPlaylist.get(i);
       cout << "Song: " << retrievedsong.getName() << " by "
            << retrievedsong.getArtist() << " (Duration: "
            << retrievedsong.getLength() << " seconds)" << endl;
      }
      // Summary of number of songs in the list
      cout << "There are " << theSize << " songs in the playlist" << endl;
    }

    // Exit command
    else if(choice == 5) {
      break;
      }

    // Case if user doens't enter between 1 and 5
    else {
      cout << "INVALID INPUT. TRY AGAIN" << endl;
    }
  }
  // End Prompt
  cout << "You have chosen to quit the program" << endl;
  return 0;
}
