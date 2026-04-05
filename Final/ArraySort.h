#pragma once

class ArraySort {

public:
    void heapSort(int* arr, int n);
    void insertionSort(int* arr, int n);
    int binarySearch(int* arr, int n, int target);

private:
    void heapify(int* arr, int n, int i);
};