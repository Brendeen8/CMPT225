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
   
  cout << "***Welcome to PlayList!***\n" 
       << "Enter Option Number:\n"
       << "1: Enter a song in the playlist at a given position\n"
       << "2: Remove a song from the playlist at a given position\n"
       << "3: Swap 2 songs in the playlist\n"
       << "4: Print all songs in the playlist\n"
       << "5: Quit"
       << endl;

  int choice;
  PlayList myPlaylist;

  while(true) {
    cout << "Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) 5 (quit): ";
    cin >> choice;

    // Clears buffer so that \n doesn't mess up getline input
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(choice == 1) {
      string songName;
      string artist;
      int length;
      unsigned int position;

      cout << "Song Name: ";
      getline(cin, songName);
      cout << "Artist: ";
      getline(cin, artist);
      cout << "Length: ";
      cin >> length;
      cout << "Position: ";
      cin >> position;

      Song addSong(songName, artist, length);

      myPlaylist.insert(addSong, position);

    }

    else if(choice == 2) {
      unsigned int theSize = myPlaylist.size();
      unsigned int position = 0;
      if(theSize == 0) {
        cout << "Nothing to remove" << endl;
      }
      else {
        cout << "Postion (1-" << theSize << "):";
        cin >> position;
        myPlaylist.remove(position - 1);

      }
    }
    else if(choice == 4) {
      unsigned int theSize = myPlaylist.size();
      
      for(unsigned int i = 0; i < theSize; i++) {
       Song retrievedsong = myPlaylist.get(i);
       cout << "Song: " << retrievedsong.getName() << " by "
            << retrievedsong.getArtist() << " (Duration: "
            << retrievedsong.getLength() << " seconds)" << endl;
      }
      cout << "There are " << theSize << " songs in the playlist" << endl;
    }

    else if(choice == 5) {
      break;
      }

    else {
      cout << "INVALID INPUT" << endl;
    }
  }
  return 0;
}
