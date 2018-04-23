//
//  ArrayMaxHeap.hpp
//  HeapSort
//
//  Created by WillJia on 08/04/2018.
//  Copyright © 2018 Zesheng Jia A00416452. All rights reserved.
//

#ifndef ArrayMaxHeap_hpp
#define ArrayMaxHeap_hpp

#include <stdio.h>
#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"
#include <math.h>
template <class ItemType>
class ArrayMinHeap : public HeapInterface<ItemType> {
private:
    static const int ROOT_INDEX = 0;
    static const int DEFAULT_CAPACITY = 21;
    ItemType* items;
    int itemCount;
    int maxItems;
    
    int getLeftChildIndex(const int nodeIndex) const;
    int getRightChildIndex(int nodeIndex) const;
    int getParentIndex(int nodeIndex) const;
    int getNumberOfNodes() const;
    bool isLeaf(int nodeIndex) const;
    void heapRebuild(int subTreeRootIndex);
    void heapCreate();
public:
    ArrayMinHeap();
    ArrayMinHeap(const ItemType someArray[] , const int arraySize);
    virtual ~ArrayMinHeap();
    
    bool isEmpty() const;
    int getNumberofNodes() const;
    int getHeight() const;
    ItemType peekTop() const throw (PrecondViolatedExcep);
    bool add(const ItemType& newData);
    bool remove();
    bool clear();
    
    
}; // end ArrayMinHeap

#include "ArrayMinHeap.cpp"


#endif /* ArrayMaxHeap_hpp */
