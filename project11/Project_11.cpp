#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

int main () {
    // declare vars
    ifstream input; 
    int lineNum = 0;
    string line;
    int totalDig = 0, totalUp = 0, totalLow = 0, totalPun = 0, totalSpace = 0, totalOther = 0, totalAll = 0;

    //open input file
    while (true) {
        //get filename
        string filename;
        cout << endl << "Enter in the name of the input file: ";
        cin >> filename;
        cout << filename << endl << endl;

        //open input 
        input.open(filename.c_str());

        //check valid file
        if (!input.good()) {
            cout << "*************** File Open Error ***************" << endl;
            cout << "==> Input file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << filename << endl;
            cout << "==> Please try again..." << endl;
            cout << "***********************************************" << endl;
            input.close(); input.clear();
        } else {
            break;
        }
    }

    //check if input file empty
    if (input.peek() == ifstream::traits_type::eof()) {
        cout << "************* Input File Is Empty *************" << endl;
        cout << "==> The input file is empty." << endl;
        cout << "==> Terminating the program." << endl;
        cout << "***********************************************" << endl << endl;
        return 1;
    }

    //print header for output
    cout << left << setw(15) << "Line number" << setw(10) << "Upper" << setw(10) << "Lower" << setw(10) << "Digits" << setw(10) << "Punct" << setw(10) << "Spaces" << setw(10) << "Other" << setw(10) << "Total" << endl;
    cout << left << setw(15) << "-----------" << setw(10) << "-----" << setw(10) << "-----" << setw(10) << "------" << setw(10) << "-----" << setw(10) << "------" << setw(10) << "-----" << setw(10) << "-----" << endl;
    
    //read each line of input
    while (getline(input, line)) {
        lineNum += 1;
        //declare vars to count chars
        int digits = 0, upper = 0, lower = 0, punct = 0, space = 0, other = 0;
        //loop through chars
        for (int i = 0; i < line.length(); i++) {
            //identify char type
            char uwu = line.at(i);
            if (isdigit(uwu)) {
                digits += 1;
            } 
            else if (isalpha(uwu)) {
                if (isupper(uwu)) {
                    upper += 1;
                } else {
                    lower += 1;
                }
            } 
            else if (ispunct(uwu)) {
                punct += 1;
            }
            else if (isspace(uwu)) {
                space += 1;
            }
            else {
                other += 1;
            }
        }
        //add 1 to other for newline character 
        other += 1;
        //find total 
        int total = space + lower + upper + digits + punct + other;
        //output totals for each char type
        cout << left << setw(15) << lineNum << setw(10) << upper << setw(10) << lower << setw(10) << digits << setw(10) << punct << setw(10) << space << setw(10) << other << setw(10) << total << endl;
        //add current totals to overall total
        totalSpace += space; totalDig += digits; totalLow += lower; totalUp += upper; totalPun += punct; totalOther += other;
        totalAll += total;
    }
    
    //a line
    cout << "--------------------------------------------------------------------------------" << endl;

    //output totals
    cout << left << setw(15) << "Totals" << setw(10) << totalUp << setw(10) << totalLow << setw(10) << totalDig << setw(10) << totalPun << setw(10) << totalSpace << setw(10) << totalOther << setw(10) << totalAll << endl;
    
    //calculate percents
    float percentUp =  (float(totalUp) / float(totalAll)) * 100;
    float percentLow =  (float(totalLow) / float(totalAll)) * 100;
    float percentDig =  (float(totalDig) / float(totalAll)) * 100;
    float percentPunct =  (float(totalPun) / float(totalAll)) * 100;
    float percentSpace =  (float(totalSpace) / float(totalAll)) * 100;
    float percentOther =  (float(totalOther) / float(totalAll)) * 100;
    //output percents
    cout << left << setw(15) << "Percent" << fixed << setprecision(2) << setw(10) << percentUp << setw(10) << percentLow << setw(10) << percentDig << setw(10) << percentPunct << setw(10) << percentSpace << setw(10) << percentOther << endl << endl;

    //exit successfully
    return 0;
};
