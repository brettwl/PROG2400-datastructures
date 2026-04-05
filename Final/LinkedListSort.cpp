#include "LinkedListSort.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
    load list from file
*/
LLNode* LinkedListSort::getListData(const string& fileName, int& count) {

    ifstream dataFile(fileName);

    if (!dataFile.is_open()) {
        count = 0;
        return NULL;
    }

    LLNode* head = NULL;
    LLNode* tail = NULL;
    count = 0;
    int value = 0;

    while (dataFile >> value) {

        LLNode* newNode = new LLNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    dataFile.close();
    return head;
}

/*
    build list
*/

LLNode* LinkedListSort::buildList(int* arr, int count) 
{
    if (arr == NULL || count <= 0) {
        return NULL;
    }

    LLNode* head = NULL;
    LLNode* tail = NULL;

    for (int i = 0; i < count; i++) {
        LLNode* newNode = new LLNode(arr[i]);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

/*
    delete list
*/

void LinkedListSort::deleteList(LLNode* head) {

    while (head != NULL) {
        LLNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/*
    print list
*/

void LinkedListSort::printLinked(LLNode* head) {

    LLNode* current = head;

    while (current != NULL) { 
        cout << current->data << " "; current = current->next; 
    }

    cout << endl;
}

/*
    Heapsort
*/

void LinkedListSort::heapify(LLNode** arr, int n, int i) {

    int largest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;

    if (left < n && arr[left]->data > arr[largest]->data) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {

        LLNode* temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

LLNode* LinkedListSort::heapSort(LLNode* head, int count) {

    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        return head;
    }

    LLNode* current = head;
    int i = 0;

    LLNode** arr = new LLNode* [count];

    while (current != NULL) {
        arr[i] = current;
        i++;
        current = current->next;
    }

    for (int i = count / 2 - 1; i >= 0; i--) {
        heapify(arr, count, i);
    }

    for (int i = count - 1; i > 0; i--) {
        LLNode* temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    for (int i = 0; i < count - 1; i++) {
        arr[i]->next = arr[i + 1];
    }

    arr[count - 1]->next = NULL;
    head = arr[0];

    delete[] arr;
    return head;
}

/*
    Insertion Sort
*/

LLNode* LinkedListSort::insertionSort(LLNode* head) {

    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        return head;
    }

    LLNode* sorted = NULL;
    LLNode* current = head;

    while (current != NULL) {
        LLNode* next = current->next;

        if (sorted == NULL || current->data <= sorted->data) {

            current->next = sorted;
            sorted = current;

        }
        else {

            LLNode* temp = sorted;

            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sorted;
}

/*
    Binary Search
*/

LLNode* LinkedListSort::getMiddle(LLNode* start, LLNode* last) {

    if (start == NULL) {
        return NULL;
    }

    if (start == last) {
        return start;
    }

    LLNode* slow = start;
    LLNode* fast = start->next;

    while (fast != last) {

        fast = fast->next;
        slow = slow->next;

        if (fast != last) {
            fast = fast->next;
        }
    }

    return slow;
}

bool LinkedListSort::binarySearch(LLNode* head, int value) {

    LLNode* start = head;
    LLNode* last = NULL;

    while (true) {

        LLNode* mid = getMiddle(start, last);

        if (mid == NULL) {
            return false;
        }

        if (mid->data == value) {
            return true;
        }
        else if (start == last) {
            break;
        }
        else if (mid->data < value) {
            start = mid->next;
        }
        else if (mid->data > value) {
            last = mid;
        }
    }

    return false;
}