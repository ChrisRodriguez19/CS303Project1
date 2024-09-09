#pragma once
// looks for a number you type in
int search(int arr[], int size, int value);

// modifies an index when given
void modify(int arr[], int size, int index, int newValue, int& oldValue);

// adds a number to the end of the array
void add(int arr[], int& size, int value);

// Removes an interger givin the index
void remove(int arr[], int& size, int index);