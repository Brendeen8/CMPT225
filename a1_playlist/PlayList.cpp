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

// Copy Contructor
PlayList::PlayList(const PlayList& pl)
{
  head = nullptr;
  current_size = 0;

  // Check if playlist is empty
  if(pl.size() == 0) {
    return; 
  }

  //Copy first node
  head = new PlayListNode(pl.head->song);
  PlayListNode* currentSource = pl.head->next;
  PlayListNode* currentDest = head;

  // Copy rest of nodes
  while(currentSource != nullptr) {
  currentDest->next = new PlayListNode(currentSource->song);
    currentDest = currentDest->next;
    currentSource = currentSource->next;
  }
  // Copy size
  current_size = pl.current_size;
}

// Destructor
PlayList::~PlayList()
{
  PlayListNode* temp = head;
  while(head != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
  }
}

// Overloaded Assignemnt Operator
PlayList& PlayList::operator=(const PlayList& pl) {
    // Check if pl is the same as this
    if (this == &pl) {
        return *this;  
    }

    // Clear current resources
    this->~PlayList();

    // Create new playlist
    head = nullptr;
    current_size = 0;

    // Check if the source playlist is empty
    if (pl.head == nullptr) {
        return *this;  
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

    return *this;
}

// Insert Function
void PlayList::insert(Song sng, unsigned int pos)
{
  // Check if parameter is valid
  if(pos > current_size) {
    cout << "INVALID POSTION" << endl;
    return;
  }
  // Create a new song
  PlayListNode* mysong = new PlayListNode(sng);
  
  // If position is at the front, add to head
  if(pos == 0) {
    mysong->next = head;
    head = mysong;
    current_size += 1;
    return;
  }
  // If position is not at front, go through elements until node before pos
  PlayListNode* temp = head;
  for(unsigned int i = 0; i < pos - 1; i++) {
    temp = temp->next;
  }
  // Insert node to the next
  mysong->next = temp->next;
  temp->next = mysong;
  current_size += 1;
  return;
}
// Remove Function
Song PlayList::remove(unsigned int pos) {
  // Check if position is first
  if (pos == 0) {  
      // Check if list is emtpy
      if (head == nullptr) {
          cout << "INVALID POSITION" << endl;
          return Song("Invalid", "Invalid", 0);
      }
      // Remove the head node
      Song removedSong = head->song;
      PlayListNode* temp = head;
      head = head->next;
      delete temp;
      current_size--;
      return removedSong;
  }
  // Check if position is valid
  if (pos >= current_size) {
      cout << "INVALID POSITION" << endl;
      return Song("Invalid", "Invalid", 0);
  }

  // Go through elements until one before position is chosen
  PlayListNode* temp = head;
  for (unsigned int i = 0; i < pos - 1; i++) {
      temp = temp->next;
  }

  // Check if node to delete exists
  PlayListNode* nodeToDelete = temp->next;
  if (!nodeToDelete) {
      cout << "INVALID POSITION" << endl;
      return Song("Invalid", "Invalid", 0);
  }
  // Remove the song
  Song removedSong = nodeToDelete->song; 
  temp->next = nodeToDelete->next;
  delete nodeToDelete;
  current_size--;
  return removedSong;
}
// Swap Function
void PlayList::swap(unsigned int pos1, unsigned int pos2)
{
  // Check if positions are valid
  if (pos1 >= current_size || pos2 >= current_size) {
      return;  
  }
  if (pos1 == pos2) {
      return;  
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

  // Swap the songs
  PlayListNode* temp = node1->next; 
  node1->next = node2->next; 
  node2->next = temp; 
}

// Get Function
Song PlayList::get(unsigned int pos) const
{
  // Check if positions are valid
  if(pos > current_size) { 
    cout << "INVALID POSTION" << endl;
    return Song("INVALID", "INVALID", 0);
  }
  PlayListNode* temp = head;
  
  // Find the node
  for(unsigned int i = 0; i < pos; i++) {
    temp = temp->next;
  }
 return temp->song; 

}

// Size Function
unsigned int PlayList::size() const 
{
  return current_size;
}
