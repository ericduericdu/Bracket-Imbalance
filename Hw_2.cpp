/**~*~*
  This program demonstrates two basic stack operations:
  push and pop
*~**/

//Name: Eric Du
//IDE: CodeBlocks
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Stack.h"
using namespace std;

void  openFile(ifstream &inputFile);
void closeFile(ifstream &inputFile);

void displayText(int &line, string text);
void pushItem(char character, Stack<char> *stack);
bool validateAndPopItem(char character, Stack<char> *stack);
bool isBalanced(char currentCharacter, Stack<char> *stack);

void displayErrorMessage(int lineNumber);
void displayOkayMessage();

int main()
{
    ifstream inputFile;

    openFile(inputFile);

    Stack<char> *stack = new Stack<char>;
    bool balancedSoFar = true;
    int lineNumber = 1;
    string readString;


//**********First 2 lines just display what each source********//
//**********demonstrates; doesn't effect testing***************//
    getline(inputFile, readString);
    displayText(lineNumber, readString);
    cout << endl;

    getline(inputFile, readString);
    displayText(lineNumber, readString);
    cout << endl;
//************************************************************//

    while(getline(inputFile, readString) && balancedSoFar)
    {
        displayText(lineNumber, readString);

        //convert read in string into C-String
        char line[readString.length()];
        strcpy(line, readString.c_str());

        //traverses through each character of string to find braces
        for(int i = 0; line[i] != NULL && balancedSoFar; i++)
        {
            //push or pops, depending on the brace type
            switch (line[i])
            {
                case '{':
                case '(':
                case '[': pushItem(line[i], stack);
                          break;

                case '}':
                case ')':
                case ']': if(!validateAndPopItem(line[i], stack))
                              balancedSoFar = false;
            }

        }
        cout << endl;
    }

    //since an extra left brace won't be detected until the end
    //if it is still "Balanced" and not empty, it displays an error
    if(balancedSoFar && stack->isEmpty())
        displayOkayMessage();
    else
        displayErrorMessage(lineNumber);

    delete stack;
    closeFile(inputFile);
}

//************************************
//opens the text file it will read from
//************************************
void openFile(ifstream &inputFile)
{
    inputFile.open("Source2.cpp");

    if(!inputFile)
    {
        cout << "\ncannot obtain file\n";
        exit(EXIT_FAILURE);
    }

}

//************************************
//closes the text file it used to read
//************************************
void closeFile(ifstream &inputFile)
{
    inputFile.close();
}

//************************************
//displays the line of text, as its reading.
//it will continue t display as long as
//there is no imbalance
//************************************
void displayText(int &line, string text)
{
    cout << line << "   " << text;
    line++;
}

//************************************
//The pushItem function gets an item from the
//user and pushes it onto the stack.
//************************************
void pushItem(char item, Stack<char> *stack)
{
     stack->push(item);
     //cout << "*" << stack->getCount() << stack->getTop() << "*";
}

//************************************
//The popItem function pops an item from the stack
//************************************
bool validateAndPopItem(char character, Stack<char> *stack)
{
     bool status;
     char poppedItem = ' ';

     if(status = isBalanced(character, stack))
        stack->pop(poppedItem);

     return status;
}

//************************************
//Function checks if the item that is gonna be
//popped is a valid item, if not, it won't
//pop, and display an error
//************************************
bool isBalanced ( char currentCharacter, Stack<char> *stack)
{
    if(!stack->isEmpty())
    {
        switch (currentCharacter)
        {
            case '}': if(stack->getTop() == '{')
                        return true;
                    else
                        return false;

            case ')': if(stack->getTop() == '(')
                        return true;
                    else
                        return false;

            case ']': if(stack->getTop() == '[')
                        return true;
                    else
                        return false;
        }
    }
    return false;

}

//************************************
//this function displays an error message
//when there is an imbalance
//************************************
void displayErrorMessage(int lineNumber)
{
    cout << "\n*********************************************************************************\n"
         << "*                   Detected imbalance of braces on line " << lineNumber-1 << "                      *\n"
         << "*                         please fix before proceeding                          *\n"
         << "*********************************************************************************\n";
}

//************************************
//this message displays if it goes through the whole
//program and does not find an error in braces
//************************************
void displayOkayMessage()
{
    cout << "*********************************************************************************\n"
         << "*                      All braces balanced, good job!!!                         *\n"
         << "*********************************************************************************\n";
}

/**Source 1**/
/*
1   //This Source demonstrates that it can
2   //correctly detect balanced braces in a program
3
4   #include <iostream>
5
6   using namespace std;
7
8   int main ()
9   {
10       int id[SIZE], students;
11       double avg[SIZE], classAvg1, classAvg2, overallAvg;
12
13       welcome();
14
15       ifstream inputFile;
16       inputFile.open("midterm_scores.txt");
17
18       ofstream outputFile;
19       outputFile.open("sorted.txt");
20
21       if(!inputFile)
22       {
23           cout << "(Reading data from INCORRECT file)\n\n";
24           return 1;
25       }
26       cout << "(Reading data from CORRECT file)\n\n";
27
28       if(!outputFile)
29       {
30           cout << "(Recording data to INCORRECT file)\n\n";
31           return 2;
32       }
33       cout << "(Recording data to CORRECT file)\n\n";
34
35       students = getData(inputFile, id, avg, SIZE, classAvg1, classAvg2, overallAvg);
36
37       selectionSort(outputFile, id, avg, students);
38
39       writeData(id, avg, students, classAvg1, classAvg2, overallAvg);
40
41       searchList(id, avg, students);
42
43       farwell();
44
45       inputFile.close();
46       outputFile.close();
47   }
*********************************************************************************
*                      All braces balanced, good job!!!                         *
*********************************************************************************
*/

/**Source 2**/
/*
1   //This Source demonstrates that it can correctly
2   //detect an extra right brace. Ex: [{}])
3
4   #include <iostream>
5
6   using namespace std;
7
8   int main ()
9
10   {
11       int caseNumber[CASES] = {1 , 10, 100, 1000, 10000, 100000, 1000000};
12       int again;
13       string name;
14
15       welcome(caseNumber, CASES);
16
17       ofstream outputFile;
18       outputFile.open ("players.txt");
19
20       if (!outputFile)
21       {
22           cout << "(Saving to incorrect file.)";
23
24           return 1;
25       }
26
27       cout << "(Saving data to file.)\n";
28
29       outputFile << setw(12) << "NAME" << setw(16) << "WON\n";
30       outputFile << "-------------------- -----------\n";
31
32       do
33       {
34           name = recordName(outputFile);
35
36           shuffleValue(caseNumber, CASES);
37
38           pickCase(outputFile, caseNumber, CASES, name);
39
40           gameOver(name);
41
42           again = playAgain();
43
44       } while(again);
45       )

*********************************************************************************
*                   Detected imbalance of braces on line 45                      *
*                         please fix before proceeding                          *
*********************************************************************************
*/

/**Source 3**/
/*
1   //This Source demonstrates that it can correctly
2   //detect an extra left brace. Ex: ([{}]
3
4   #include <iostream>
5
6   using namespace std;
7
8   int main ()
9   {
10   {
11       string name, winner;
12       double score1, score2, score3, score4, score5, overallScore, winningScore = 0.0;
13       int participants = 0;
14
15       welcome();
16
17       ifstream inputFile;
18       inputFile.open ("performers.txt");
19
20       if (!inputFile)
21       {
22           cout << "Failed to obtain data from correct file";
23
24           return 1;
25       }
26
27       cout << "Now reading data from file...\n\n";
28
29       ofstream outputFile;
30       outputFile.open ("results.txt");
31
32       if (!outputFile)
33       {
34           cout << "Failed to output data to correct file";
35
36           return 1;
37       }
38
39       cout << "Now storing data to text file...\n\n";
40
41       outputFile << "NAME" << setw(10) << "SCORE\n" << "-------------\n";
42
43       while (getScores(inputFile, name, score1, score2, score3, score4, score5))
44       {
45           overallScore = calcScore(score1, score2, score3, score4, score5);
46
47           participants++;
48
49           if (overallScore > winningScore)
50           {
51               winningScore = overallScore;
52               winner = name;
53           }
54
55           writeScore(outputFile, name, overallScore);
56       }
57
58       inputFile.close();
59
60       outputFile.close();
61
62      cout << "In this event there are " << participants << " participants.\n\n";
63
64      cout << "With a score of " << setprecision(2) << fixed << winningScore
65           << " the winner is......\n.\n.\n.\n" << winner << endl << endl;
66
67      farewell();
68
69      return 0;
70   }

*********************************************************************************
*                   Detected imbalance of braces on line 70                      *
*                         please fix before proceeding                          *
*********************************************************************************
*/

/**Source 4**/
/*
1   //This Source demonstrates that it can correctly detect
2   //a set of braces opening before closing the previous one. Ex: [{]}
3
4   #include <iostream>
5   using namespace std;
6
7   int main ()
8   {
9       string name;
10       int customers;
11       char gasOptions, washOptions;
12       double gallons, gasTotal, gasType, washTotal, washCost, totalTotal;
13
14       ifstream inputFile;
15       inputFile.open("customers.txt");
16
17       ofstream outputFile;
18       outputFile.open("gas_bill.txt");
19
20       inputFile >> customers;
21
22       for (int i = 1; i <= customers; i++)
23       {
24           inputFile >> name;
25           inputFile >> gasOptions;
26           inputFile >> gallons;
27           inputFile >> washOptions;
28
29           switch (gasOptions)
30           {
31               case 'R':
32               case 'r': gasType = REGULAR;
33                         break;
34
35               case 'U':
36               case 'u': gasType = UNLEADED;
37                         break;
38
39               case 'P':
40               case 'p': gasType = PREMIUM;
41                         break;
42
43               case 'N':
44               case 'n': gasType = 0;
45                         break;
46           }
47
48           gasTotal = gasType * gallons;
49
50           outputFile << setprecision(2) << fixed << showpoint
51                      << "*************************************\n"
52                      << "* Best Gas and Wash Service Station *\n"
53                      << "*************************************\n"
54                      << setw(5) << " " << "Customer: " << name << endl << endl;
55
56
57           if (gasOptions == 'N' || gasOptions == 'n')
58           {
59               //blank
60           }
61           else
62           {
63               outputFile << setw(5) << " " << "Gallons purchased:" << setw(8) << gallons << endl
64                          << setw(5) << " " << "Price per gallon :" << setw(8) << gasType << endl << endl
65                          << setw(5) << " " << "Total gasoline cost:" << setw(6) << gasTotal << endl;
66           }
67
68           if (washOptions == 'N' || washOptions == 'n')
69           {
70               washCost = 0;
71           }
72           else
73           {
74               if (gasTotal >= WASHPARAMETER)
75                   washCost = WASHDISCOUNTED;
76                   washCost = WASHFULL;
77
78               outputFile << setw(5) << " " << "Car wash cost:" << setw(12) << washCost << endl;
79           }
80
81           totalTotal = gasTotal + washCost;
82
83           outputFile << setw([32) << "------\n"

*********************************************************************************
*                   Detected imbalance of braces on line 83                      *
*                         please fix before proceeding                          *
*********************************************************************************
*/
