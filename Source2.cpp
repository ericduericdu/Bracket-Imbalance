//This Source demonstrates that it can correctly
//detect an extra right brace. Ex: [{}])

#include <iostream>

using namespace std;

int main ()

{
    int caseNumber[CASES] = {1 , 10, 100, 1000, 10000, 100000, 1000000};
    int again;
    string name;

    welcome(caseNumber, CASES);

    ofstream outputFile;
    outputFile.open ("players.txt");

    if (!outputFile)
    {
        cout << "(Saving to incorrect file.)";

        return 1;
    }

    cout << "(Saving data to file.)\n";

    outputFile << setw(12) << "NAME" << setw(16) << "WON\n";
    outputFile << "-------------------- -----------\n";

    do
    {
        name = recordName(outputFile);

        shuffleValue(caseNumber, CASES);

        pickCase(outputFile, caseNumber, CASES, name);

        gameOver(name);

        again = playAgain();

    } while(again);
    )

    outputFile.close();

   return 0;
}

