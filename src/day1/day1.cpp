#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

std::vector<int> input;
std::vector<int> listOne;
std::vector<int> listTwo;

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
    std::sort(listOne.begin(), listOne.end());
    std::sort(listTwo.begin(), listTwo.end());

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