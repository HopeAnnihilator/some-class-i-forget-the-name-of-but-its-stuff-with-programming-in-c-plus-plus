#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <climits>
#include <cstdlib>


using namespace std;

int main(int argc, char * argv[]) {
    
    // Check if proper amount of arguments
    if (argc != 3) {
        cout << "\n********* Command Line Argument Error *********" << endl;
        cout << "==> Incorrect number of Command Line Arguments!" << endl;
        cout << "==> Command for running the program is:" << endl;
        cout << "==> ./Project_06 inputFileName outputFileName" << endl;
        cout << "***********************************************\n" << endl;
        return 0;
    }

    // Define Filestreams
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    ifstream inputFile;
    ofstream outputFile;

    // Test input file
    cout << "\nOpening input file: " << inputFileName << endl << endl;
    inputFile.open(inputFileName.c_str());
    if (inputFile.fail()) {
        while (true) {
            inputFile.close();
            cout << "*************** File Open Error ***************" << endl;
            cout << "==> Input file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << inputFileName << endl;
            cout << "==> Try Again" << endl;
            cout << "***********************************************" << endl << endl;
            cout << "Enter in the name of the input file: "; 
            cin >> inputFileName;
            cout << inputFileName << endl << endl;
            inputFile.open(inputFileName.c_str());
            if (inputFile.good()) {
                break;
            }
        };
    }

    // Test output file
    cout << "Opening output file: " << outputFileName << endl << endl;
    outputFile.open(outputFileName.c_str());
    if (outputFile.fail()) {
        while (true) {
            outputFile.close();
            cout << "*************** File Open Error ***************" << endl;
            cout << "==> Output file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << outputFileName << endl;
            cout << "==> Try Again" << endl;
            cout << "***********************************************" << endl << endl;
            cout << "Enter in the name of the output file: "; 
            cin >> outputFileName;
            cout << outputFileName << endl << endl;
            outputFile.open(outputFileName.c_str());
            if (outputFile.good()) {
                break;
            }
        };
    }

    // Test for proper amount of lines
    int uwu = 0;
    string asdf;
    while(getline(inputFile, asdf)) {
        uwu += 1;
    };
    inputFile.close();
    if (uwu != 3) {
        cout << "*************** File Read Error ***************" << endl;
        cout << "==> Reading of the information line failed." << endl;
        cout << "==> Input stream is in the fail state mode." << endl;
        cout << "==> There is an error in the input file." << endl;
        cout << "==> Program Terminated." << endl;
        cout << "***********************************************" << endl;

        outputFile << "*************** File Read Error ***************" << endl;
        outputFile << "==> Reading of the information line failed." << endl;
        outputFile << "==> Input stream is in the fail state mode." << endl;
        outputFile << "==> There is an error in the input file." << endl;
        outputFile << "==> Program Terminated." << endl;
        outputFile << "***********************************************" << endl;
        outputFile.close();
        return 1;
    }
    inputFile.open(inputFileName.c_str());


    // Find scores and test info
    char int9963[9963];
    string scores;
    int score1, score2, score3, score4;
    string sectionNumber;
    int flip = 0;

    for (int i = 1; i < 3 + 1; i ++){
        inputFile.getline(int9963, 9963); 
        if (i == 2) {
            string scoresold;
            scores = int9963;
            int space = scores.find(" ");
            score1 = stoi(scores.substr(0, space));
            scoresold = scores;
            scores = scores.substr(space + 1, 9963);
            if (scores == scoresold) flip = 1; 
            space = scores.find(" ");
            score2 = stoi(scores.substr(0, space));
            scoresold = scores;
            scores = scores.substr(space + 1, 9963);
            if (scores == scoresold) flip = 1; 
            space = scores.find(" ");
            score3 = stoi(scores.substr(0, space));
            scoresold = scores;
            scores = scores.substr(space + 1, 9963);
            if (scores == scoresold) flip = 1; 
            space = scores.find(" ");
            score4 = stoi(scores.substr(0, space));
            scores = int9963;
        }
        if (i == 3) {
            sectionNumber = int9963;
        }
    }
    
    // if not 4 scores print error
    if (flip == 1){
        cout << "*************** File Read Error ***************" << endl;
        cout << "==> Reading of the 4 test scores failed." << endl;
        cout << "==> The input stream is in the fail state mode." << endl;
        cout << "==> There is an error in the input file." << endl;
        cout << "==> Program Terminated." << endl;
        cout << "***********************************************" << endl;

        outputFile << "*************** File Read Error ***************" << endl;
        outputFile << "==> Reading of the 4 test scores failed." << endl;
        outputFile << "==> The input stream is in the fail state mode." << endl;
        outputFile << "==> There is an error in the input file." << endl;
        outputFile << "==> Program Terminated." << endl;
        outputFile << "***********************************************" << endl;
        inputFile.close();
        outputFile.close();
        return 1;
        
    }

    // verify all scores > 0
    if (score1 < 0 || score2 < 0 || score3 < 0 || score4 <0){
        cout << "*************** File Read Error ***************" << endl;
        cout << "==> Test scores read are: ";
        cout << score1 << setw(6) << score2;
        cout << setw(6) << score3 << setw(6) << score4 << endl;
        cout << "==> One or more of the scores is negative!" << endl;
        cout << "==> Program Terminated." << endl;
        cout << "***********************************************" << endl;
        outputFile << "*************** File Read Error ***************" << endl;
        outputFile << "==> Test scores read are: ";
        outputFile << score1 << setw(6) << score2;
        outputFile << setw(6) << score3 << setw(6) << score4 << endl;
        outputFile << "==> One or more of the scores is negative!" << endl;
        outputFile << "==> Program Terminated." << endl;
        outputFile << "***********************************************" << endl;
        inputFile.close();
        outputFile.close();
        return 1;
    }
    
    // calculate output
    float sum = score1 + score2 + score3 + score4;
    float average = sum / 4;
    char letterGrade;
    if (average >= 90) letterGrade = 'A'; 
    else if (average >= 80) letterGrade = 'B';
    else if (average >= 70) letterGrade = 'C';
    else if (average >= 60) letterGrade = 'D';
    else letterGrade = 'F';

    // calculate variance thingy and standard deviation
    float thingy = pow(score1 - average, 2);
    thingy += pow(score2 - average, 2);
    thingy += pow(score3 - average, 2);
    thingy += pow(score4 - average, 2);
    float variance =  thingy / 4;
    float deviation = pow(variance, 0.5);

    // output data
    outputFile << left;
    outputFile << "*****************   Statistics   *****************" << endl;
    outputFile << setw(32) << sectionNumber;
    outputFile << setw(6) << score1 << setw(6) << score2 << setw(6) << score3 << setw(6) << score4 << endl;
    outputFile << setw(32) << "The sum of the scores is:       ";
    outputFile << setprecision(2) << fixed << sum << endl;
    outputFile << setw(32) << "The average of the scores is:   ";
    outputFile << setprecision(2) << fixed << average << endl;
    outputFile << setw(32) << "Letter grade equivalent:        " << letterGrade << endl;
    outputFile << setw(32) << "The variance of the scores is:  ";
    outputFile << setprecision(2) << fixed << variance << endl;
    outputFile << setw(32) << "The standard deviation is:      ";
    outputFile << setprecision(2) << fixed << deviation << endl;
    outputFile << "**************************************************" << endl;

    //exit successfully
    inputFile.close();
    outputFile.close();
    return 0;
}
