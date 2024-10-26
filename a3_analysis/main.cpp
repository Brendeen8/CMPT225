#include <iostream>
#include "a3.h"

using std::cout;
using std::endl;

void cartesianProductTest();
void triangleTest();
void matrixTest();
void sortTest();
void powTest();

int main(void) 
{
  cartesianProductTest();
  triangleTest();
  matrixTest();
  sortTest();
  powTest();
  return 1;
}

 
void cartesianProductTest()
{
  cout << "CARTESIAN PRODUCT TEST" << endl;
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int n = 9;
  int cost = 0;
  cartesianProduct(arr, n, cost);
  cout << "cost = " << cost << endl;
}


void triangleTest()
{
  cout << "TRIANGLE TEST" << endl;
  int n = 10;
  int cost = 0;
  triangle(n, cost);
  cout << "cost = " << cost << endl;
}


void matrixTest()
{
  cout << "MATRIX TEST" << endl;
  int n = 9;
  int cost = 0;
  int matrix[] = {1,2,3,4};
  matrixSelfMultiply(matrix, n, cost);
  cout << "cost = " << cost << endl;
}

void sortTest()
{
  cout << "SORT TEST" << endl;
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int n = 9;
  int i = 0;
  int cost = 0;
  ssort(arr, n, i, cost);
  cout << "cost = " << cost << endl;
}
void powTest()
{
  cout << "POW TEST" << endl;
  int n = 9;
  int i = 0;
  int cost = 0;
  pow(i, n, cost);
  cout << "cost = " << cost << endl;
}
