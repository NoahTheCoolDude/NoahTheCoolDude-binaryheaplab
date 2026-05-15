// heap.cpp
// Diba Mirza
// Noah Ruderman

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
//heapify algorithim is to copy all values from start to end into vdata
//then starting at last non leaf node at index vdata.size()/2 -1, bubble down working backwards
  for (auto it = start; it != end; it++) {
    vdata.push_back(*it);
  }

  for (int i = (vdata.size()/2 -1 ); i >= 0; i--) {
    int indexi = i; //modify not the iterator itself but the index we are at

    while (indexi < vdata.size() / 2) {
    //if the left child is smaller than the right child...
    // or there isn't a right child at all, swap with left child
    if (2*indexi+2 >= vdata.size() || vdata[2 * indexi + 1] < vdata[2 * indexi + 2]) {
      if(vdata[indexi] <= vdata[2* indexi + 1]) break; //if heap property satisfied, we are done
      
      int tempforswap = vdata[indexi];

      vdata[indexi] = vdata[2 * indexi + 1];

      vdata[2 * indexi + 1] = tempforswap;

      indexi = 2 * indexi + 1; // update the index
    } else {
      if(vdata[indexi] <= vdata[2* indexi + 2]) break; //if heap property satisfied, we are done


      int tempforswap = vdata[indexi];

      vdata[indexi] = vdata[2 * indexi + 2];

      vdata[2 * indexi + 2] = tempforswap;

      indexi = 2 * indexi + 2;

    }

  }


  }



}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
// logic is supposed to be, push at the end, swap if it's less than parent
void Heap::push(int value){
  vdata.push_back(value); // add it to the end\

  //while the parent is greater than, swap as it is a min heap

  int indexi = vdata.size() - 1; //this is the index of the new pushed value

  //stop when the condition fails or if we become the root

  while (indexi > 0 && vdata[(indexi-1) / 2] > vdata[indexi]) { 

    vdata[indexi] = vdata[(indexi-1) / 2]; //put the parent where the kid is
    vdata[(indexi-1) / 2] = value; //set it to the kid

    indexi = ((indexi-1) / 2); //update index to be the parent index
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  //swap root with last element
  int temp = vdata[vdata.size() - 1]; //temp variable as final element

  vdata[vdata.size()-1] = vdata[0]; //set final value to root

  vdata[0] = temp; //set root to final element, now they are swapped

  vdata.pop_back(); //last element removed

  //bubble down the top element, min heap so only swap when we are greater than
  int indexi = 0;

  //bubble down while we aren't a leaf node

  while (indexi < vdata.size() / 2) {
    //if the left child is smaller than the right child...
    // or there isn't a right child at all, swap with left child
    if (2*indexi+2 >= vdata.size() || vdata[2 * indexi + 1] < vdata[2 * indexi + 2]) {
      if(vdata[indexi] <= vdata[2* indexi + 1]) break; //if heap property satisfied, we are done
      
      int tempforswap = vdata[indexi];

      vdata[indexi] = vdata[2 * indexi + 1];

      vdata[2 * indexi + 1] = tempforswap;

      indexi = 2 * indexi + 1; // update the index
    } else {
      if(vdata[indexi] <= vdata[2* indexi + 2]) break; //if heap property satisfied, we are done


      int tempforswap = vdata[indexi];

      vdata[indexi] = vdata[2 * indexi + 2];

      vdata[2 * indexi + 2] = tempforswap;

      indexi = 2 * indexi + 2;

    }

  }

}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0]; //by definition always the top value
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty(); //.empty already exists for a vector so just call that
}
    