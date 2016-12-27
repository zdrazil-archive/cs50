/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
#include "stdio.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    // return n if n isn't positive 
    if (n <= 0)
    {
        return false;
    }
    
    // binary search
    
    int min = 0;
    int max = n;
    int i = n;
    // while length of list > 0
    while (i > 0)
    {
        // look at middle of list
        int midpoint = (min + max) / 2;
        
        // if number lower, search right
        if (values[midpoint] < value)
        {
            min = midpoint + 1;
            i = i / 2;
        }
        // else if number higher, search left
        else if (values[midpoint] > value)
        {
            max = midpoint - 1;
            i = i / 2;
        }
        else
            // if number found, return true
            return true;
    }
    // return false if value is not in values
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
 
    // implements an O(n^2) sorting algorithm - insertion sort
    for(int i = 1; i < n ; i++)
    {
        int element = values[i];
        int j = i;
        while (j > 0 && values[j - 1] > element)
        {
            values[j] = values[j - 1];
            j = j - 1;
        }
        values[j] = element;
    }
 
    return;
}
