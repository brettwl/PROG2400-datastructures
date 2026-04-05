// Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "ArraySort.h"
#include "LinkedListSort.h"
#include "PerfManager.h"

using namespace std;

string getFileName(int fileChoice);
int loadArray(const string& fileName, int*& arr);
void printArray(int* arr, int count);
void printLinked(LLNode* head);

int main()
{
    ArraySort arraySort;
    LinkedListSort linkedSort;
    PerfManager mgr;

    //int inMenu = 0;
    int choice = 0;
    int value = 0;
    int fileChoice = 0;
    int searchChoice = 0;
    int printChoice = 0;
    int* arrVals = NULL;
    int itemCount = 0;

    string fileName = "";

    //while (inMenu == 0) {
    while (true) {

        //main menu
        cout << "Enter a number" << endl;
        cout << "1. Sort Array with Heapsort " << endl;
        cout << "2. Sort Array with Insertion " << endl;
        cout << "3. Sort Linked List with Heapsort" << endl;
        cout << "4. Sort Linked List with Insertion " << endl;
        cout << "5. Binary search" << endl;
        cout << "6. Print" << endl << "" << endl;
        cin >> choice;
        cout << "" << endl;

        if (choice < 1 || choice > 6) {
            cout << "Invalid entry" << endl << "" << endl;
            //break;
            continue;
        }

        if (choice >= 1 && choice <= 4) {

            //file selection
            cout << "Enter the number matching the file name" << endl;
            cout << "1. Data1000" << endl;
            cout << "2. Data10000" << endl;
            cout << "3. Data100000" << endl;
            cout << "4. Data200000" << endl;
            cout << "5. Data300000" << endl;
            cout << "6. Data400000" << endl;
            cout << "7. Data500000" << endl;
            cout << "8. Data600000" << endl;
            cout << "9. Data700000" << endl;
            cout << "10. Data800000" << endl;
            cout << "11. Data900000" << endl;
            cout << "12. Data1000000" << endl << "" << endl;
            cin >> fileChoice;
            cout << "" << endl;

            fileName = getFileName(fileChoice);

            if (fileName == "") {
                cout << "Invalid entry" << endl << "" << endl;
                //break;
                continue;
            }

            if (arrVals != NULL) {
                delete[] arrVals;
                arrVals = NULL;
            }

            itemCount = loadArray(fileName, arrVals);

            if (itemCount <= 0) {
                continue;
            }
        }

        //switch for sorting choices
        switch (choice) {

        case 1:
            cout << "Running Array Heapsort with " << fileName << endl;
            cout << "" << endl;

            mgr.SetStartTime();
            arraySort.heapSort(arrVals, itemCount);
            mgr.SetEndTime();

            cout << "Times:\n";
            cout << "Seconds     :" << mgr.getSeconds() << "\n";
            cout << "MilliSeconds:" << mgr.getMilliseconds() << "\n";
            cout << "MicroSeconds:" << mgr.getMicroseconds() << "\n";
            cout << "NanoSeconds :" << mgr.getNanoSeconds() << "\n";
            cout << "" << endl;

            break;

        case 2:
            cout << "Running Array Insertion Sort with " << fileName << endl;
            cout << "" << endl;

            mgr.SetStartTime();
            arraySort.insertionSort(arrVals, itemCount);
            mgr.SetEndTime();

            cout << "Times:\n";
            cout << "Seconds     :" << mgr.getSeconds() << "\n";
            cout << "MilliSeconds:" << mgr.getMilliseconds() << "\n";
            cout << "MicroSeconds:" << mgr.getMicroseconds() << "\n";
            cout << "NanoSeconds :" << mgr.getNanoSeconds() << "\n";
            cout << "" << endl;

            break;

        case 3: {
            cout << "Running Linked List Heapsort with " << fileName << endl;
            cout << "" << endl;

            LLNode* head = linkedSort.buildList(arrVals, itemCount);

            mgr.SetStartTime();
            head = linkedSort.heapSort(head, itemCount);
            mgr.SetEndTime();

            cout << "Times:\n";
            cout << "Seconds     :" << mgr.getSeconds() << "\n";
            cout << "MilliSeconds:" << mgr.getMilliseconds() << "\n";
            cout << "MicroSeconds:" << mgr.getMicroseconds() << "\n";
            cout << "NanoSeconds :" << mgr.getNanoSeconds() << "\n";
            cout << "" << endl;

            linkedSort.deleteList(head);

            break;
        }
        case 4: {
            cout << "Running Linked List Insertion Sort with " << fileName << endl;
            cout << "" << endl;

            LLNode* head = linkedSort.buildList(arrVals, itemCount);

            mgr.SetStartTime();
            head = linkedSort.insertionSort(head);
            mgr.SetEndTime();

            cout << "Times:\n";
            cout << "Seconds     :" << mgr.getSeconds() << "\n";
            cout << "MilliSeconds:" << mgr.getMilliseconds() << "\n";
            cout << "MicroSeconds:" << mgr.getMicroseconds() << "\n";
            cout << "NanoSeconds :" << mgr.getNanoSeconds() << "\n";
            cout << "" << endl;

            linkedSort.deleteList(head);

            break;
        }
        case 5:
            cout << "Enter the number to search by" << endl;
            cout << "1. Array" << endl;
            cout << "2. Linked List" << endl << "" << endl;
            cin >> searchChoice;
            cout << "" << endl;

            cout << "Enter value to search for" << endl << "" << endl;
            cin >> value;
            cout << "" << endl;

            if (searchChoice == 1) {

                arraySort.heapSort(arrVals, itemCount);

                int result = arraySort.binarySearch(arrVals, itemCount, value);

                if (result != -1) {
                    cout << "Found" << result << endl << "" << endl;

                }
                else {
                    cout << "Not found" << endl << "" << endl;
                }

            }
            else if (searchChoice == 2) {

                LLNode* head = linkedSort.buildList(arrVals, itemCount);
                head = linkedSort.insertionSort(head);

                bool found = linkedSort.binarySearch(head, value);

                if (found) {
                    cout << "Found" << "" << endl;
                }
                else {
                    cout << "Not found" << "" << endl;
                }

                linkedSort.deleteList(head);
            }
            else {
                cout << "Invalid entry" << "" << endl;
            }

            break;

        case 6:
            cout << "Enter the number to print" << endl;
            cout << "1. Array" << endl;
            cout << "2. Linked List " << endl << "" << endl;
            cin >> printChoice;

            if (printChoice == 1) {
                printArray(arrVals, itemCount);

            }
            else if (printChoice == 2) {
                LLNode* head = linkedSort.buildList(arrVals, itemCount);
                printLinked(head);
                linkedSort.deleteList(head);

            }
            else {
                cout << "Invalid entry" << endl << "" << endl;
            }

            break;

        default:
            cout << "Invalid entry" << endl << "" << endl;
            break;
        }
    }

    if (arrVals != NULL) {
        delete[] arrVals;
    }
}

string getFileName(int fileChoice)
{
    switch (fileChoice) {

    case 1:
        return "Data1000.txt";
    case 2:
        return "Data10000.txt";
    case 3:
        return "Data100000.txt";
    case 4:
        return "Data200000.txt";
    case 5:
        return "Data300000.txt";
    case 6:
        return "Data400000.txt";
    case 7:
        return "Data500000.txt";
    case 8:
        return "Data600000.txt";
    case 9:
        return "Data700000.txt";
    case 10:
        return "Data800000.txt";
    case 11:
        return "Data900000.txt";
    case 12:
        return "Data1000000.txt";
    default:
        return "";
    }
}

int loadArray(const string& fileName, int*& arr)
{
    ifstream dataFile;
    dataFile.open(fileName);

    if (!dataFile.is_open()) {
        cerr << "File Open Error" << endl;
        return -1;
    }
    else
    {
        int count = 0;
        int value = 0;

        while (dataFile >> value) {
            count++;
        }

        dataFile.close();

        if (count == 0) {
            return 0;
        }

        arr = new int[count];

        dataFile.open(fileName);

        if (!dataFile.is_open()) {
            cerr << "File Open Error" << endl;
            delete[] arr;
            arr = NULL;
            return -1;
        }

        int index = 0;

        while (dataFile >> value) {
            arr[index] = value;
            index++;
        }

        dataFile.close();
        return count;
    }
}

void printArray(int* arr, int count)
{
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printLinked(LLNode* head)
{
    LLNode* current = head;

    while (current != NULL) {
        cout << current->getData() << " ";
        current = current->getNext();
    }

    cout << endl;
}


/*
// Load Data From File.
ifstream dataFile;
//dataFile.open(R"(fileName)");
dataFile.open(fileName);
if (!dataFile.is_open()) {
    cerr << "File Open Error";
    exit(1);
}
else
{
    int value;

    while (dataFile >> value) {
        //data.insert(value, value);
    }
    dataFile.close();
}

*/