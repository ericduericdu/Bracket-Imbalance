//This Source demonstrates that it can
//correctly detect balanced braces in a program

#include <iostream>

using namespace std;

int main ()
{
    int id[SIZE], students;
    double avg[SIZE], classAvg1, classAvg2, overallAvg;

    welcome();

    ifstream inputFile;
    inputFile.open("midterm_scores.txt");

    ofstream outputFile;
    outputFile.open("sorted.txt");

    if(!inputFile)
    {
        cout << "(Reading data from INCORRECT file)\n\n";
        return 1;
    }
    cout << "(Reading data from CORRECT file)\n\n";

    if(!outputFile)
    {
        cout << "(Recording data to INCORRECT file)\n\n";
        return 2;
    }
    cout << "(Recording data to CORRECT file)\n\n";

    students = getData(inputFile, id, avg, SIZE, classAvg1, classAvg2, overallAvg);

    selectionSort(outputFile, id, avg, students);

    writeData(id, avg, students, classAvg1, classAvg2, overallAvg);

    searchList(id, avg, students);

    farwell();

    inputFile.close();
    outputFile.close();
}
