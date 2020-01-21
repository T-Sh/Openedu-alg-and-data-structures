#include "edx-io.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int first(long arr[], int low, int high, long x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int last(long arr[], int low, int high, long x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int main()
{
    int elements_quantity;
    io >> elements_quantity;
    long *elements = new long[elements_quantity];
    for (int i = 0; i < elements_quantity; i++) {
        io >> elements[i];
    }
    int commands_quantity;
    io >> commands_quantity;
    long curr_elem;
    for (int i = 0; i < commands_quantity; i++) {
        io >> curr_elem;
        int first_occurance = first(elements, 0, elements_quantity - 1, curr_elem, elements_quantity);
        if (first_occurance != -1)
            first_occurance++;
        int last_occurance = last(elements, 0, elements_quantity - 1, curr_elem, elements_quantity);
        if (last_occurance != -1)
            last_occurance++;
        io << first_occurance << " " << last_occurance << "\n";

    }
    return 0;
}