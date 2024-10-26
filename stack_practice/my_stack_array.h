class MyStackArray {
  
  public:
    // Default
    MyStackArray();

    // Constructor
    MyStackArray(int capacity);

    // Destructor
    ~MyStackArray();

    // Stack Commands
    void push(int val);
    int pop();
    int size();
    void print();
  
  private:
    int capacity;
    int* container;
    int top;
    
    void increaseSize();
};
