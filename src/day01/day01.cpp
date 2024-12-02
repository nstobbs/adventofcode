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
    // --- Part One ---
    // Read In the Input Puzzle List
    std::ifstream inputFile("input.txt");
    if (inputFile)
    {
        int value;
        while (inputFile >> value)
        {
            input.push_back(value);
        }
    }
    // Format list into two different arrays of Ints
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

    // Then go through each item in the list and take away each pair from
    int result = 0;
    for (int i = 0; i < listOne.size(); i++)
    {
        int value = abs(listOne[i] - listTwo[i]);
        // Add the final result into result var
        result += value;
    }
    // return the final result
    std::cout << "Final Result is: " << result << std::endl;

    // --- Part Two ---
    int similarityScore = 0;

    // Go through listOne, check how many times that number appears in listTwo
    for (int i = 0; i < listOne.size(); i++)
    {
        int count = 0;
        int searchNumber = listOne[i];
        for (int j = 0; j < listTwo.size(); j++)
        {
            // If the number appears in list two, increase found counter
            if (listTwo[j] == searchNumber)
                count++;
        }
        // Once we have gone throughout the whole list, times that number by the counter
        similarityScore += searchNumber * count;
    }

    std::cout << "similarityScore is: " << similarityScore << std::endl;
}