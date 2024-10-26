// Lab on Testing
// Author: John Edgar
// Date: June 2022
//

#include <iostream>
using std::cout;
using std::endl;

int remove(int arr[], unsigned n, int target);
void removeTest(int input[], unsigned nInput, int target, int result[], unsigned nResult);
void printArray(int arr[], int n);
void test1();

int main()
{
    test1();

    return 0;
}

// PARAM: arr - input array to be changed
//        n - number of values in arr
//        target - value to be removed
// POST: removes *all* incidences of target from arr and returns the new count
//       of the values in arr (i.e. n - # of incidences of target)
int remove(int arr[], unsigned n, int target)
{
  if(n == 0) {
    return n;
  }
  // Scan array for element 
  for(int i = 0; i < n; i++) {
    if(target == arr[i]) {
      for(int remIndex = i; remIndex < n-1; remIndex++) {
        arr[remIndex] = arr[remIndex+1];
      }
      n--;
    }
  }
  
    return n;
}

// Tests removal of a single element from the interior of the array
void test1()
{
    int test1[] = { :class MyClass : public QObject {
      Q_OBJECT;
    public:

    explicit MyClass(QObject *parent = nullptr);
      
    signals:

    public slots:
    };
    };
    int correct1[] = { };
    unsigned nInput = 0;
    unsigned nResult = 7;
    int target = 5;
    removeTest(test1, nInput, target, correct1, nResult);
}

// Simple test function for removing values from an array
// PARAM: input - input array to be changed
//        n - number of values in input
//        target - value to be removed from input
//        result - expected result of calling remove
//        nResult - expected number of values in result
// POST: prints results of calling remove(target) on input
void removeTest(int input[], unsigned nInput, int target, int result[], unsigned nResult)
{
    cout << "remove " << target << ": ";
    printArray(input, nInput);
    nInput = remove(input, nInput, target);
    cout << endl << "result:   ";
    printArray(input, nInput);
    cout << endl << "expected: ";
    printArray(result, nResult);
    cout << endl << endl;
}

// PARAM: arr - array to be printed
//        n - number of values in arr
// POST: prints arr to standard output on one line with no terminating line feed
void printArray(int arr[], int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << ",";
        }
    }
    cout << " }";
}
