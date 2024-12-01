#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

std::vector<int> input;
std::vector<int> listOne;
std::vector<int> listTwo;

// Merge Sort From https://www.geeksforgeeks.org/merge-sort/
void merge(std::vector<int> &array, int left, int mid, int right)
{
    int number1 = mid - left + 1;
    int number2 = right - mid;

    std::vector<int> L(number1), R(number2);
    for (int i = 0; i < number1; i++)
    {
        L[i] = array[left + i];
    }
    for (int j = 0; j < number2; j++)
    {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < number1 && j < number2)
    {
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < number1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < number2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &array, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main()
{
    // Read In the Input Puzzle List
    // Format list into two different arrays of Ints
    std::ifstream inputFile("input.txt");
    if (inputFile)
    {
        int value;
        while (inputFile >> value)
        {
            input.push_back(value);
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (i % 2 == 0)
        {
            listTwo.push_back(input[i]);
        } else {
            listOne.push_back(input[i]);
        }
    }
    // Sort both list of Array
    mergeSort(listOne, 0, int(listOne.size())-1);
    mergeSort(listTwo, 0, int(listTwo.size())-1);

    // Then go throught each item in the list and take away each pair from
    // Add the final result into result var
    // return the final result
    int result = 0;
    for (int i = 0; i < listOne.size(); i++)
    {
        int value = abs(listOne[i] - listTwo[i]);
        result = result + value;
    }
    std::cout << "Final Result is: " << result << std::endl;

    // --- Part Two ---
    // Go throght listOne, check how many times that number apperas in listTwo
    // If the number apperas in list two, increase found counter
    // Once we have go throught the whole list, times that number by the counter
    int similarityScore = 0;
    for (int i = 0; i < listOne.size(); i++)
    {
        int count = 0;
        int searchNumber = listOne[i];
        for (int j = 0; j < listTwo.size(); j++)
        {
            if (listTwo[j] == searchNumber)
                count++;
        }
        similarityScore = similarityScore + (searchNumber * count);
    }

    std::cout << "similarityScore is: " << similarityScore << std::endl;
}