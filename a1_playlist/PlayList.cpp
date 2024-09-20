// Author: Brendan Lim
// Date: September 2024
#include "PlayList.h"
#include <iostream>
using std::cout;
using std::endl;

// Default Contructor
PlayList::PlayList()
{
  head = nullptr;
  current_size = 0;
}

//Creates Deep Copy of pl
PlayList::PlayList(const PlayList& pl)
{
  head = nullptr;
  current_size = 0;

  // check if play list is empty
  if(pl.size() == 0) {
    return; 
  }

  // copy first node
  head = new PlayListNode(pl.head->song);
  PlayListNode* currentSource = pl.head->next;
  PlayListNode* currentDest = head;

  // copy rest of nodes
  while(currentSource != nullptr) {
    currentDest->next = new PlayListNode(currentSource->song);
    currentDest = currentDest->next;
    currentSource = currentSource->next;
  }
  
  current_size = pl.current_size;

}

PlayList::~PlayList()
{
  PlayListNode* temp = head;
  while(head != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
  }
}

PlayList& PlayList::operator=(const PlayList& pl) {
    // Check for self-assignment
    if (this == &pl) {
        return *this;  // Return *this to allow chained assignments
    }

    // Clear current resources
    this->~PlayList();  // Call the destructor to free existing nodes

    // Initialize new playlist
    head = nullptr;
    current_size = 0;

    // Check if the source playlist is empty
    if (pl.head == nullptr) {
        return *this;  // Nothing to copy
    }

    // Copy the first node
    head = new PlayListNode(pl.head->song);
    current_size = 1;

    PlayListNode* currentSource = pl.head->next;
    PlayListNode* currentDest = head;

    // Copy the rest of the nodes
    while (currentSource != nullptr) {
        currentDest->next = new PlayListNode(currentSource->song);
        currentDest = currentDest->next;
        currentSource = currentSource->next;
        current_size++;
    }

    return *this;  // Return *this to allow chained assignments
}

void PlayList::insert(Song sng, unsigned int pos)
{
  if(pos > current_size) {
    cout << "INVALID POSTION" << endl;
    return;
  }
  PlayListNode* mysong = new PlayListNode(sng);
  
  if(pos == 0) {
    mysong->next = head;
    head = mysong;
    current_size += 1;
    return;
  }
  PlayListNode* temp = head;
  for(unsigned int i = 0; i < pos - 1; i++) {
    temp = temp->next;
  }

  mysong->next = temp->next;
  temp->next = mysong;
  current_size += 1;
  return;
}

Song PlayList::remove(unsigned int pos) {
    if (pos == 0) {  // Adjust this to check for the head node
        if (head == nullptr) {
            cout << "INVALID POSITION" << endl;
            return Song("Invalid", "Invalid", 0);
        }
        // Handle removing the head node
        Song removedSong = head->song;
        PlayListNode* temp = head;
        head = head->next;
        delete temp;
        current_size--;
        return removedSong;
    }
    
    if (pos >= current_size) {
        cout << "INVALID POSITION" << endl;
        return Song("Invalid", "Invalid", 0);
    }

    // Traverse to the node just before the one to remove
    PlayListNode* temp = head;
    for (unsigned int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    // Ensure node to delete exists
    PlayListNode* nodeToDelete = temp->next;
    if (!nodeToDelete) {
        cout << "INVALID POSITION" << endl;
        return Song("Invalid", "Invalid", 0);
    }

    Song removedSong = nodeToDelete->song; 
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    current_size--;
    return removedSong;
}

void PlayList::swap(unsigned int pos1, unsigned int pos2)
{
    if (pos1 >= current_size || pos2 >= current_size) {
        return;  // Invalid positions
    }

    if (pos1 == pos2) {
        return;  // No need to swap the same position
    }

    PlayListNode* node1 = head;
    PlayListNode* node2 = head;
    PlayListNode* prev1 = nullptr;
    PlayListNode* prev2 = nullptr;

    // Find node1 and its previous node
    for (unsigned int i = 0; i < pos1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    // Find node2 and its previous node
    for (unsigned int i = 0; i < pos2; i++) {
        prev2 = node2;
        node2 = node2->next;
    }

    // If node1 is the head
    if (prev1 == nullptr) {
        head = node2;  // Update head to node2
    } else {
        prev1->next = node2;  // Link prev1 to node2
    }

    // If node2 is the head
    if (prev2 == nullptr) {
        head = node1;  // Update head to node1
    } else {
        prev2->next = node1;  // Link prev2 to node1
    }

    // Swap the next pointers
    PlayListNode* temp = node1->next; // <-- Keep this line
    node1->next = node2->next; // <-- Keep this line
    node2->next = temp; // <-- Keep this line
}

Song PlayList::get(unsigned int pos) const
{
  if(pos >= current_size) {
    cout << "INVALID POSTION" << endl;
    return Song("INVALID", "INVALID", 0);
  }
  PlayListNode* temp = head;

  for(unsigned int i = 0; i < pos; i++) {
    temp = temp->next;
  }
 return temp->song; 

}

unsigned int PlayList::size() const 
{
  return current_size;
}
