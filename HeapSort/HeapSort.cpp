#include <iostream>
#include <string>
#include "ArrayMinHeap.h"
#include <sstream>
using namespace std;

template <class ItemType>
void displayArray(ItemType array[] , int size , string words){
    for (int i = 0; i < size; i++){
        cout <<array[i] << " " ;
    }
    if (words.size() != 0) {
        cout << words << endl;
    }

}
int getLeftChildIndex(const int nodeIndex)
{
    return (2 * nodeIndex) + 1;
} // end getLeftChildIndex

int getRightChildIndex(const int nodeIndex)
{
    return (2 * nodeIndex) + 2;
} // end getLeftChildIndex

bool isLeaf(int nodeIndex , int itemCount) {
    if (getLeftChildIndex(nodeIndex) >= itemCount && getRightChildIndex(nodeIndex) >= itemCount) {
        return true;
    }else{
        return false;
    }
}// end isLeaf

template <class ItemType>
void heapRebuild(int index , ItemType anArray[] , int itemCount) {
    if (!isLeaf(index, itemCount))
    {
        // Find larger child
        int leftChildIndex = getLeftChildIndex(index);
        //left child must exist
        
        int largerChildIndex = leftChildIndex;
        // Make assumption about larger child
        
        int rightChildIndex = getRightChildIndex(index);
        //rightchild might not exits
        
        //        if (rightChildIndex < itemCount)
        if (rightChildIndex < itemCount)
            // Check to see whether a right child exists
        {
            // A right child exists; check whether it is larger
            if (anArray[rightChildIndex] > anArray[largerChildIndex]) largerChildIndex = rightChildIndex;
            
            // Asssumption was wrong
        } // end if
        
        // If root value is smaller that the value in the larger child, swap values
        if (anArray[index] <  anArray[largerChildIndex])
        {
            swap(anArray[largerChildIndex], anArray[index]);
            // Continue with the recursion at that child
            heapRebuild(largerChildIndex, anArray ,itemCount);
        }  // end if
    } // end if
} // end heapRebuild

template <class ItemType>
void heapSort(ItemType anArray[] , int n){

    // Build initial heap
    for (int i = n / 2 ; i >= 0 ; i--)
    {
        // Assertion: The tree rooted at index is a semiheap
        heapRebuild(i, anArray, n);
    // Assertion: The tree rooted at index is a heap
    }
    // display
    displayArray(anArray , n , "Initial rebuild to form a heap" );
    
    // Assertion: anArray[0] is the largest item in heap anArray[0..n-1]
    // Move the largest item in the Heap region—the root anArray[0]—to the beginning
    // of the Sorted region by swapping items and then adjusting the size of the regions
    swap(anArray[0], anArray[n-1]);
    
    //display
    std::ostringstream oss;
    oss << "After swapping " << anArray[0] << " and " << anArray[n-1];
    string a = oss.str();
    
    displayArray(anArray , n , a);
    
    int heapSize = n - 1;
    // Decrease the size of the Heap region, expand the Sorted region
    
    while (heapSize > 1) { // Make the Heap region a heap again
        
        heapRebuild(0, anArray, heapSize);
      
        
        displayArray(anArray, n, "");
        cout << "rebuild(" << 0 << ", anArray," << heapSize << ")" << endl;
        
        // Move the largest item in the Heap region—the root anArray[0]—to the beginning
        // of the Sorted region by swapping items and then adjusting the size of the regions
        swap(anArray[0], anArray[heapSize - 1]);
        std::ostringstream oss2;
        oss2 << "After swapping " << anArray[0] << " and " << anArray[heapSize-1];
        string a2 = oss2.str();
        displayArray(anArray , n , a2);
        
        heapSize --;
        // Decrease the size of the Heap region, expand the Sorted region
    }
}
        
int main()
{
    cout << "Driver program to test your implementation of HeapSort" << endl << endl;
    
    cout << "Test1: array of Stings\n" << endl;
    
    string a[6] = {"Zavier", "Brandon", "Adam", "Chelsey", "Fabio", "Emily"};
    
    ArrayMinHeap<string>(a, 6);
    
    for (int i = 0; i < 6; i++){
        cout <<a[i] << " " ;
    }
    cout << "Original array" << endl;
    
    heapSort(a, 6);
    displayArray(a, 6, "");
    cout << "Sorted array" << endl << endl;
    
    cout << "Test2: array of Integers\n" << endl;
    // Example in Figure 17.8
    // The trace should correspond to the trace in Figure 17.11
    
    int b[6] = {6, 3, 5, 9, 2, 10};
    
    for (int i = 0; i < 6; i++){
        cout <<b[i] << " " ;
    }
    cout << "Original array" << endl;

    heapSort(b, 6);
    for (int i = 0; i < 6; i++)
        cout << b[i] << " ";
    cout << "Sorted array" << endl;
    
}  // end main


