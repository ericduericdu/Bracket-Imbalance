//This Source demonstrates that it can correctly detect
//a set of braces opening before closing the previous one. Ex: [{]}

#include <iostream>
using namespace std;

int main ()
{
    string name;
    int customers;
    char gasOptions, washOptions;
    double gallons, gasTotal, gasType, washTotal, washCost, totalTotal;

    ifstream inputFile;
    inputFile.open("customers.txt");

    ofstream outputFile;
    outputFile.open("gas_bill.txt");

    inputFile >> customers;

    for (int i = 1; i <= customers; i++)
    {
        inputFile >> name;
        inputFile >> gasOptions;
        inputFile >> gallons;
        inputFile >> washOptions;

        switch (gasOptions)
        {
            case 'R':
            case 'r': gasType = REGULAR;
                      break;

            case 'U':
            case 'u': gasType = UNLEADED;
                      break;

            case 'P':
            case 'p': gasType = PREMIUM;
                      break;

            case 'N':
            case 'n': gasType = 0;
                      break;
        }

        gasTotal = gasType * gallons;

        outputFile << setprecision(2) << fixed << showpoint
                   << "*************************************\n"
                   << "* Best Gas and Wash Service Station *\n"
                   << "*************************************\n"
                   << setw(5) << " " << "Customer: " << name << endl << endl;


        if (gasOptions == 'N' || gasOptions == 'n')
        {
            //blank
        }
        else
        {
            outputFile << setw(5) << " " << "Gallons purchased:" << setw(8) << gallons << endl
                       << setw(5) << " " << "Price per gallon :" << setw(8) << gasType << endl << endl
                       << setw(5) << " " << "Total gasoline cost:" << setw(6) << gasTotal << endl;
        }

        if (washOptions == 'N' || washOptions == 'n')
        {
            washCost = 0;
        }
        else
        {
            if (gasTotal >= WASHPARAMETER)
                washCost = WASHDISCOUNTED;
                washCost = WASHFULL;

            outputFile << setw(5) << " " << "Car wash cost:" << setw(12) << washCost << endl;
        }

        totalTotal = gasTotal + washCost;

        outputFile << setw([32) << "------\n"
                    ]
                   << setw(12) << " " << "Total due: " << setw(8) << totalTotal << endl << endl
                   << "*************************************\n"
                   << "  *    Thank you for stopping!    *  \n"
                   << "    *    Have a nice day and    *    \n"
                   << "       *    come again!       *       \n"
                   << "          ******************          \n\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

