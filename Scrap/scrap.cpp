Node* copy_list() {
  Node* newHead;
  Node* newTail;
  Node* temp = head;
  while(temp != nullptr) {
    Node* newNode = new Node(temp->data, nullptr);
    if(newHead == nullptr) {
      newHead = newNode;
      newTail = newNode;
  }
  else {
      newTail->next = newNode;
      newTail = newTail->next;
    }
    return newHead;
  }
}

int remove_last() {
  Node* temp = head;

  if(head->next == nullptr) {
    result = head->data;
    delete head;
    head = nullptr;
    return result;
  }

  while(temp->next->next != nullptr) {
    temp = temp->next;
  }
  int result = temp->next->data;
  delete temp->next;
  temp->next = nullptr;
  return result;
}

int negate_biggest() {
  Node* temp = head;

  Node* biggest = temp;

  while(temp != nullptr) {
    if(temp->data > biggest->data) {
      biggest = temp;
    } 
    temp = temp->next;
  }
  result = biggest->data;
  biggest->data *= -1;
  return result;
}

remove_max() {
  Stack S;
  Stack T;

  int biggest = T.peek();

  while(!S.empty) {
    T.push(S.pop());
    if(T.peek > biggest) {
      biggest = T.peek;
    }
  }
  while(!T.empty) {
    if(T.peek != biggest) {
      S.push(T.pop());
    }
    else {
      T.pop;
    }
  }

}
