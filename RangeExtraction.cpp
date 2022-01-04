// RangeExtraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    A format for expressing an ordered list of integers is to use a comma separated list of either

    individual integers
    or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"
    Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

    Example:

    range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
//  returns "-6,-3-1,3-5,7-11,14,15,17-20"
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string range_extraction(vector<int>args)
{
    string returnSolution = ""; //  return string

    args.push_back(0);          //  add help elements to vector args

    int min_element = 0;        //  min_element jest first element in sequence, example 1,2,3,4 
                                //  min_element is equel id first element that is 0

    int counterNumber = 1;      //  how many elements have in sequence, that is counter

    for (int i = 1; i < args.size(); i++)   //  loop start id second elements to id last elements
    {
        if (args.size() == 1)               //  example maybe we have vector with one element
        {
            returnSolution += to_string(args[0]);   //  add element to return string with char 
            return returnSolution;                  //  return this string
        }
        else if ((args[i - 1] + 1) != args[i])      //  if have example element one plus 1 is different from second 
        {                                           //  elements
        
            if (counterNumber >= 3)                 //  option when we have sequence 3-5, 7-10
                returnSolution += to_string(args[min_element]) + "-" + to_string(args[i - 1]);
            else if (counterNumber == 2)            //  optiny when we have two following number
                returnSolution += to_string(args[min_element]) + "," + to_string(args[i - 1]);
            else                                    //  when we have one elements
                returnSolution += to_string(args[min_element]);

            if (i != args.size() - 1)               //  if we have element other that last we add in end string char ','
                returnSolution += ",";

            min_element = i;                        //  we change min_element on id next element
            counterNumber = 1;                      //  change value counterNumber to value started
        }
        else                                        //  in last case we add to counterNumber one
            counterNumber++;    
    }

    return returnSolution;
}

int main()
{
    string String = range_extraction({ -3,-2,-1,2,10,15,16,18,19,20 });

    cout << String << endl;
}

