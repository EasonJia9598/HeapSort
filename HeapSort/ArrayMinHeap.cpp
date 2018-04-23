//
//  ArrayMaxHeap.cpp
//  HeapSort
//
//  Created by WillJia on 08/04/2018.
//  Copyright © 2018 Zesheng Jia A00416452. All rights reserved.
//

#include "ArrayMinHeap.h"

template<class ItemType> int ArrayMinHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 1;
} // end getLeftChildIndex

template<class ItemType> int ArrayMinHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 2;
} // end getLeftChildIndex

template<class ItemType> int ArrayMinHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
    return (nodeIndex - 1) / 2;
} // end getLeftChildIndex

template <class ItemType>
int ArrayMinHeap<ItemType>::getNumberOfNodes() const{
    return itemCount;
}

template<class ItemType> 
void ArrayMinHeap<ItemType>::heapCreate() {
    for (int index = itemCount / 2; index >= 0; index--)
        heapRebuild(index);
    
} // end heapCreate

template<class ItemType>
bool ArrayMinHeap<ItemType>::isLeaf(int nodeIndex) const {
    if (getLeftChildIndex(nodeIndex) >= itemCount && getRightChildIndex(nodeIndex) >= itemCount) {
        return true;
    }else{
        return false;
    }
}// end isLeaf

template <class ItemType>
void ArrayMinHeap<ItemType>::heapRebuild(const int subTreeNodeIndex) {
    if (!isLeaf(subTreeNodeIndex))
    {
        // Find larger child
        int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);
        //left child must exist
        
        int largerChildIndex = leftChildIndex;
        // Make assumption about larger child
        
        int rightChildIndex = getRightChildIndex(subTreeNodeIndex);
        //rightchild might not exits
        
//        if (rightChildIndex < itemCount)
        if (rightChildIndex < itemCount)
            // Check to see whether a right child exists
        {
            // A right child exists; check whether it is larger
//             if (items[rightChildIndex] > items[largerChildIndex]) largerChildIndex = rightChildIndex;
            if (items[rightChildIndex] > items[largerChildIndex]) largerChildIndex = rightChildIndex;
            
            // Asssumption was wrong
        } // end if
    
        // If root value is smaller that the value in the larger child, swap values
//        if (items[subTreeNodeIndex] < items[largerChildIndex])
        if (items[subTreeNodeIndex] < items[largerChildIndex])
        {
            swap(items[largerChildIndex], items[subTreeNodeIndex]);
            // Continue with the recursion at that child
            heapRebuild(largerChildIndex);
        }  // end if
    } // end if
} // end heapRebuild


template <class ItemType>
ArrayMinHeap<ItemType>:: ArrayMinHeap() : itemCount(0) , maxItems(DEFAULT_CAPACITY)
{
    items = new ItemType[DEFAULT_CAPACITY];
}

template <class ItemType>
ArrayMinHeap<ItemType>:: ArrayMinHeap(const ItemType someArray[] , const int arraySize ) : itemCount(arraySize) , maxItems(2 * arraySize)
{
    items = new ItemType[2 * arraySize];
    for (int i = 0 ; i < itemCount; i++) {
        items[i] = someArray[i];
    }
    heapCreate();
}


template <class ItemType>
bool ArrayMinHeap<ItemType>::isEmpty() const{
    return itemCount <= 0;
}

template <class ItemType>
int  ArrayMinHeap<ItemType>:: getHeight() const{
    return (int)log2(itemCount);
}

template <class ItemType>
bool ArrayMinHeap<ItemType>::add(const ItemType& newData) {
    bool isSuccessful = false;
    if (itemCount < maxItems)
    {
        items[itemCount] = newData;
        bool inPlace = false;
        int newDataIndex = itemCount;
        while ((newDataIndex > 0) && !inPlace)
        {
            int parentIndex = getParentIndex(newDataIndex);
            if (items[newDataIndex] < items[parentIndex])
            {
                inPlace = true;
            }
            else
            {
                swap(items[newDataIndex], items[parentIndex]);
                newDataIndex = parentIndex;
            } //endif
        }  // end while
        itemCount++;
        isSuccessful = true;
    } // end if
    return isSuccessful;
}  // end add

template<class ItemType>
ItemType ArrayMinHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
    if (isEmpty()) throw PrecondViolatedExcep("Attempted peek into an empty heap.");
    return items[0];
    
} // end peekTop

template <class ItemType>
bool ArrayMinHeap<ItemType>::remove() {
    
    if (isEmpty()) throw PrecondViolatedExcep("Attempted remove from an empty heap.");
    
    items[0] = items[itemCount-1];
    itemCount--;
    heapRebuild(0);
    return true;
}

template <class ItemType>
bool ArrayMinHeap<ItemType>::clear() {
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
    return true;
}


template <class ItemType>
ArrayMinHeap<ItemType>:: ~ArrayMinHeap(){
    clear();
}

