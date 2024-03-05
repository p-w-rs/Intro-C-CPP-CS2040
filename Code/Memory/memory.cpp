#include <iostream>
using namespace std;

int global_var = 10;

int main() {
  int local_var = 20;
  int *ptr = &local_var;
  int *heap_var = new int;

  *heap_var = 30;

  cout << "Address of global variable: " << &global_var << endl;
  cout << "Address of local variable: " << &local_var << endl;
  cout << "Value of local variable: " << local_var << endl;
  cout << "Value of pointer to local variable: " << *ptr << endl;
  cout << "Address of pointer to local variable: " << &ptr << endl;
  cout << "Address of heap variable: " << heap_var << endl;
  cout << "Value of heap variable: " << *heap_var << endl;
  cout << "Address of the heap variable: " << &heap_var << endl;

  delete heap_var;

  return 0;
}
