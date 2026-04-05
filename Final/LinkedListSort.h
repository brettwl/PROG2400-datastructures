#pragma once
#include <string>

class LLNode {
    int data;
    LLNode* next;

    LLNode(int value) {
        data = value;
        next = NULL;
    }
    
    friend class LinkedListSort;

public:
    int getData() const { return data; }
    LLNode* getNext() const { return next; }
};

class LinkedListSort {

public:
    LLNode* heapSort(LLNode* head, int count);
    LLNode* insertionSort(LLNode* head);
    bool binarySearch(LLNode* head, int value);
    LLNode* getListData(const std::string& fileName, int& count);
    LLNode* buildList(int* arr, int count);
    void deleteList(LLNode* head);
    void printLinked(LLNode* head);

private:
    void heapify(LLNode** arr, int n, int i);
    LLNode* getMiddle(LLNode* start, LLNode* last);
};