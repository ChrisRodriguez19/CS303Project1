#include "Header.h"
#include <iostream>
using namespace std;

int search(int arr[], int size, int value) {
    //goes through the whole index and findes the value
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i; // Return the index if found
        }
    }
    return -1;
}

void modify(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds!");
    }
    oldValue = arr[index]; // Store old value to print out
    arr[index] = newValue; // Modify the index with new value
}

void add(int arr[], int& size, int value) {
    if (size >= 100) { 
        throw length_error("Array size exceeded!");
    }
    arr[size++] = value; // Add the new value and add one to the size if it doesn't go above 100
}

void remove(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds!");
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1]; // Shift numbers to left
    }
    --size; // Reduce the size of the array
}