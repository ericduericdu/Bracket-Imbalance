//This Source demonstrates that it can correctly
//detect an extra left brace. Ex: ([{}]

#include <iostream>

using namespace std;

int main ()
{
{
    string name, winner;
    double score1, score2, score3, score4, score5, overallScore, winningScore = 0.0;
    int participants = 0;

    welcome();

    ifstream inputFile;
    inputFile.open ("performers.txt");

    if (!inputFile)
    {
        cout << "Failed to obtain data from correct file";

        return 1;
    }

    cout << "Now reading data from file...\n\n";

    ofstream outputFile;
    outputFile.open ("results.txt");

    if (!outputFile)
    {
        cout << "Failed to output data to correct file";

        return 1;
    }

    cout << "Now storing data to text file...\n\n";

    outputFile << "NAME" << setw(10) << "SCORE\n" << "-------------\n";

    while (getScores(inputFile, name, score1, score2, score3, score4, score5))
    {
        overallScore = calcScore(score1, score2, score3, score4, score5);

        participants++;

        if (overallScore > winningScore)
        {
            winningScore = overallScore;
            winner = name;
        }

        writeScore(outputFile, name, overallScore);
    }

    inputFile.close();

    outputFile.close();

   cout << "In this event there are " << participants << " participants.\n\n";

   cout << "With a score of " << setprecision(2) << fixed << winningScore
        << " the winner is......\n.\n.\n.\n" << winner << endl << endl;

   farewell();

   return 0;
}
