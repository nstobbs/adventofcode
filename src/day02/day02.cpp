#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

const int MAX_REPORTS = 1000;

int main()
{
    // --- Part One ---
    // Read the File For Every Line and add it to a Vector Called Reports;
    //std::ifstream inputFile("../../src/day02/input.txt");
    std::ifstream inputFile("../../src/day02/inputTestCase.txt");
    std::string line;
    std::vector<std::vector<int>> reports;
    int safeReports = 0;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            std::istringstream stream(line);
            std::string string;
            std::vector<int> levels;
            while (stream >> string)
            {
                levels.push_back(std::stoi(string));
            }
            // This Report will be a Vector of ints as levels
            reports.push_back(levels);
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }

    // Check each Report within the Reports
    for (int i = 0; i < reports.size(); i++)
    {
         // And Check if the levels are Safe
         for (int k = 0; k < (reports[i].size()); k++)
        {
            std::cout << reports[i][k] << " ";
        }
        std::cout << std::endl;
        bool isIncreasing = false;
        bool locked = false;
        bool safe = true;
        for (int j = 0; j < (reports[i].size()-1); j++)
        {  
           int left = reports[i][j];
           int right = reports[i][j+1];
           std::cout << "LEFT: " << left << " RIGHT: " << right << std::endl;
         // Check if we are increasing or not
           if (left < right && locked == false)
           {
                isIncreasing = true;
                locked = true;
           } else {
                isIncreasing = false;
                locked = true;
           }
           // Check distance 
           int d = left - right;
           std::cout << "Distance was: " << d << std::endl;
            if (d > 3 || d < -3)
            {
                std::cout << "Distance is too big: Not Safe" << std::endl;
                safe = false;
            }
           if (left > right && locked == true && isIncreasing == true)
           {
                std::cout << "Levels are Decreasing: Not Safe" << std::endl;
                safe = false;
           } 
            if (left < right && locked == true && isIncreasing == false) {
            
                std::cout << "Levels are Increating: Not Safe" << std::endl;
                safe = false;
           }
            // If the levels are safe then we increase the safe counter
            if(safe == true && (j+1) == (reports[i].size()-1))
            {
                std::cout << "This report is safe!" << std::endl;
                safeReports = safeReports + 1;
            }
        }
    }
    std::cout << "Counted " << safeReports << " Safe Reports..." << std::endl;
    return 0;
}