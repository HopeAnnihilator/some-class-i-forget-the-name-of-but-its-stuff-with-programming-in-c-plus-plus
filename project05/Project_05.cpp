#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
    // Check if proper amount of system arguments
    if (argc != 3) {
        cout << "\n********* Command Line Argument Error *********" << endl;
        cout << "==> Incorrect number of Command Line Arguments!" << endl;
        cout << "==> Command for running the program is:" << endl;
        cout << "==> ./Project_05 inputFileName  outputFileName" << endl;
        cout << "***********************************************\n" << endl;
        return 0;
    }

    // Define Filestreams
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    ifstream inputFile;
    ofstream outputFile;

    // Test input file
    cout << "\nOpening Input File: " << inputFileName << endl << endl;
    inputFile.open(inputFileName.c_str());
    if (inputFile.fail()) {
        cout << "*************** File Open Error ***************" << endl;
        cout << "==> Input file failed to open properly!!" << endl;
        cout << "==> Attempted to open file: " << inputFileName << endl;
        cout << "==> Terminating program!!!" << endl;
        cout << "***********************************************" << endl << endl;
        return 1;
    }

    // Test output file
    cout << "Opening Output File: " << outputFileName << endl << endl;
    outputFile.open(outputFileName.c_str());
    if (outputFile.fail()) {
        cout << "*************** File Open Error ***************" << endl;
        cout << "==> Output file failed to open properly!!" << endl;
        cout << "==> Attempted to open file: "<< outputFileName << endl;
        cout << "==> Terminating program!!!" << endl;
        cout << "***********************************************" << endl << endl;
        return 1;
    }

    // Define variables
    char ch;
    string line;
    int space;
    float A;
    float B;
    float C;
    float average;
    string magnitude;

    // Find numbers in each file
    inputFile.get(ch);
    getline(inputFile, line, '*');
    A = line.find("A");
    space = line.substr(A + 1).find(" ");
    A = stof(line.substr(A + 1, space));
    B = line.find("B");
    space = line.substr(B + 1).find(" ");
    if (space == 0) {
        B = B + 3;
        space = line.substr(B + 1).find(" ");
    }
    B = stof(line.substr(B + 1, space));
    C = line.find("C");
    space = line.substr(C + 1).find(" ");
    C = stof(line.substr(C + 1, space));

    // Make sure no numbers are negative
    if (A < 0 or B < 0 or C < 0) {
    cout << "*************** Negative Number ***************" << endl;
    if (A < 0) {
    cout << "==> First number is less than 0" << endl;
    }
    if (B < 0) {
    cout << "==> Second number is less than 0" << endl;
    }
    if (C < 0) {
    cout << "==> Third number is less than 0" << endl;
    }
    cout << "==> All numbers should be positive" << endl;
    cout << "==> Terminating program!!!" << endl;
    cout << "***********************************************"  << endl << endl;
    return 1;
    }

    // Find average and output to file
    average = (A + B + C) / 3;
    outputFile << "***********************************************" << endl;
    outputFile << "The numbers read are:              " << A << " " << B << " " << C << endl;
    outputFile << "The sum of the numbers is:         " << A + B + C << endl;
    outputFile << "The average of these numbers is:   " << setprecision(2) << fixed << average << endl;
    if (average > 75) {
        magnitude = "High";
    }
    else if (average >= 25) {
        magnitude = "Medium";
    }
    else {
        magnitude = "Low";
    }
    outputFile << "This average is:                   " << magnitude << endl;
    outputFile << "***********************************************" << endl;

    return 0;
}
