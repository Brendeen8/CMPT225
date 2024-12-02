// Write your name and date here
#include "PlayList.h"

// PlayList method implementations go here


PlayList::PlayList() {
  current_Size = 0;
  head = nullptr;
}

PlayList::PlayList(const PlayList& pl) {
  head = nullptr;
  current_Size = 0;

  if(pl.size() == 0) {
    return;
  }

  head = new PlayListNode(pl.head->song);
  PlayListNode* currentSource = pl.head->next;
  PlayListNode* currentDest = head;

  while(currentSource != nullptr) {
    currentDest->next = new PlayListNode(currentSource->song);
    currentDest = currentDest->next;
    currentSource = currentSource->next;
  }
  current_size = pl.current_size;
}

PlayList::~PlayList() {
  
}
