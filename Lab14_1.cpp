// Chad Huntebrinker
// crh92d@umsystem.edu
// Lab-Week 14
// CS 201L

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
T add(T variable1, T variable2);

template <class T>
void findTotal(vector<T> vector);

int main()
{
    int userInput1, userInput2;
    double input1, input2;
    string user1, user2;
    vector<int> vectorInt;
    vector<double> vectorDouble;
    vector<string> vectorString;
    ifstream fin1, fin2, fin3;

    /* Part A is when the user enters in two integers, two decimals, and two strings first.
    Then, the program add allows the two variables to be combined together, starting with the
    integers, then the decimals, and finally the strings. Then they are all outputted to the screen.
    */
    cout << "Part A" << endl << endl;
    
    //User enters in the information
    cout << "Enter first integer number: ";
    cin >> userInput1;
    cout << "Enter second integer number: ";
    cin >> userInput2;
    cout << endl;

    cout << "Enter first decimal number: ";
    cin >> input1;
    cout << "Enter second decimal number: ";
    cin >> input2;
    cout << endl;

    cout << "Enter first string: ";
    cin >> user1;
    cout << "Enter second string: ";
    cin >> user2;
    cout << endl;

    //The function add is called and the two variables are added together.
    cout << "Addition of integers = " << add(userInput1, userInput2) << endl;
    cout << "Addition of deciamls = " << add(input1, input2) << endl;
    cout << "Addition of strings = " << add(user1, user2) << endl << endl << endl;

    /* Part B is when the three files are opened, one has integers, one has doubles, and one has strings.
    The files are opened and all the integers, doubles, and strings are read into their own vector.
    Then, the function called findTotal is called.  This function is used to find the total number
    of occurrences of each integer, double, or string in each vector.
    */
    cout << "Part B" << endl << endl;

    fin1.open("integers.txt");
    fin2.open("doubles.txt");
    fin3.open("strings.txt");

    while (fin1 >> userInput1) {
        vectorInt.push_back(userInput1);
    }
    while (fin2 >> input1) {
        vectorDouble.push_back(input1);
    }
    while (fin3 >> user1) {
        vectorString.push_back(user1);
    }

    cout << "Integers -- Count" << endl;
    findTotal(vectorInt);
    cout << "Double -- Count" << endl;
    findTotal(vectorDouble);
    cout << "String -- Count" << endl;
    findTotal(vectorString);

    return 0;
}

//The two variables are added together and then returned.
template <class T>
T add(T variable1, T variable2) {
    T temp;
    
        temp = variable1 + variable2;

    return temp;
}

/*
This function first takes all the numbers or strings in the fileVector and puts them in tempVector,
not counting the repeats (there is only one 1 in tempVector, one 2 in tempVector,
one 3 in tempVector, etc.) Then, the function finds the number of occurences of the 
number or string in fileVector and outputs that to the screen.
*/
template <class T>
void findTotal(vector<T> fileVector) {
    
    T temp;
    vector<T> tempVector;
    int location = -1, occur = 0;
    bool status = false;

    //This loop finds all the unique numbers or strings in fileVector and puts them in 
    //tempVector, not counting repeats.  The first number or string is automatically put
    //in the tempVector first.
    for (int i = 0; i < fileVector.size(); ++i) {
        if (i == 0) {
            temp = fileVector.at(0);
            tempVector.push_back(temp);
        }
        else if (i > 0) {
            for (int j = 0; j < tempVector.size(); ++j) {
                //If tempVector doesn't have the number or string.
                if (tempVector.at(j) != fileVector.at(i)) {
                    status = true;
                    location = i;
                }
                //If tempVector already has the number or string (no repeats).
                else {
                    status = false;
                    location = -1;
                    break;
                }
            }
            //If tempVector doesn't have the number, then it is put into the tempVector.
            if (status == true) {
                temp = fileVector.at(location);
                tempVector.push_back(temp);
                status = false;
                location = -1;
            }
        }
    }

    //This for loop finds the number of occurences of each number or string in
    //tempVector.  It is then outputted to the screen and the variable occur
    //is reset to 0.
    for (int i = 0; i < tempVector.size(); ++i) {
        for (int j = 0; j < fileVector.size(); ++j) {
            if (tempVector.at(i) == fileVector.at(j)) {
                ++occur;
            }
        }
        cout << tempVector.at(i) << " = " << occur << endl;
        occur = 0;
    }

    cout << endl;
}
