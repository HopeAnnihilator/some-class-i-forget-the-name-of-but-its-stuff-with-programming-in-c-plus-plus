#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//define structures
struct subscriberName {string firstName; string lastName; int customerID;};
struct Address {string street; string city; string state; int zipCode;};
struct date {string month; int day; int year;};
struct renewal {int timeLeft; struct date dateOBJ;};
struct subInfo {subscriberName name; Address address; renewal timeInfo;};

//define functions
void OPENINPUT (ifstream& input);
void OPENOUTPUT (ofstream& output);
void FILLFORM(ifstream& input, subInfo& data);
void PROCESSED (int subCount, int expiredCount);
void EXPIRED(ofstream& output, subInfo& data);
void EMPTYERROR (ofstream& output);


int main () {
    //define vars
    int subCount = 0;
    int expiredCount = 0;
    subInfo subData;

    //open and test input file
    ifstream input;
    OPENINPUT(input);

    //open and test output file
    ofstream output;
    OPENOUTPUT (output);


    while (true) {
        //check if end of file
        int c = input.peek();
        if (c == EOF) {
            break;
        }
        //if not end of file read data
        FILLFORM (input, subData);
        //if expired add to counter and write to output
        if (subData.timeInfo.timeLeft < 1) {
            expiredCount ++;
            EXPIRED (output, subData);
        }
        subCount ++;
    }
    //if empty input throw error else exit successfully
    if (subCount == 0) {
        EMPTYERROR (output);
    } else {
        PROCESSED (subCount, expiredCount);
    }
    return 0;
}

void OPENINPUT (ifstream& input) {
    string filename;

    //loop till correct filename entered 
    while (true) {
        cout << endl << "Enter name of input file or Control-C to quit program: ";
        cin >> filename;
        cout << filename << endl << endl;

        input.open(filename.c_str());
        if (input.good()) {
            return;
        } else {
            cout << "*************** File Open Error ***************" << endl;
            cout << "==> Input file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << filename << endl;
            cout << "==> Please try again..." << endl;
            cout << "***********************************************" << endl; 
            input.close(); input.clear();
        }
    }

};

void OPENOUTPUT (ofstream& output) {
    string filename;

    //loop till correct filename entered 
    while (true) {
        cout << "Enter name of output file or Control-C to quit program: ";
        cin >> filename;
        cout << filename << endl << endl;

        output.open(filename.c_str());
        if (output.good()) {
            return;
        } else {
            cout << "*************** File Open Error ***************" << endl;
            cout << "==> Output file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << filename << endl;
            cout << "==> Please try again..." << endl;
            cout << "***********************************************" << endl;
            output.close(); output.clear();
        }
    }
};

void FILLFORM(ifstream& input, subInfo& data) {
    string line;

    //read each line of data and convert to appropariate type
    getline(input, data.name.firstName, '\n');
    getline(input, data.name.lastName, '\n');
    getline(input, line, '\n');
    data.name.customerID = stoi(line);
    cout << "====> Processing Customer ID: " << data.name.customerID << endl;
    getline(input, data.address.street, '\n');
    getline(input, data.address.state, '\n');
    getline(input, data.address.city, '\n');
    getline(input, line, '\n');
    data.address.zipCode = stoi(line);
    getline(input, line, '\n');
    data.timeInfo.timeLeft = stoi(line);
    getline(input, data.timeInfo.dateOBJ.month, '\n');
    getline(input, line, '\n');
    data.timeInfo.dateOBJ.day = stoi(line);
    getline(input, line, '\n');
    data.timeInfo.dateOBJ.year = stoi(line);
}

void PROCESSED (int subCount, int expiredCount) {
    //log expired subscription
    cout << endl << "-----------------------------------------------" << endl;
    cout << "Number of subscribers processed: " << to_string(subCount) << endl;
    cout << "The number of expired subscriptions is: " << to_string(expiredCount) << endl;
    cout << "-----------------------------------------------" << endl << endl;
}

void EXPIRED(ofstream& output, subInfo& data) {
    //write output
    output << "*******************************************************" << endl;
    output << data.name.firstName << " " << data.name.lastName << "(" << data.name.customerID << ")" << endl;
    output << data.address.street << endl;
    output << data.address.state << ", " << data.address.city << " " << to_string(data.address.zipCode) << endl;
    output << "The last renewal notice was sent on " << data.timeInfo.dateOBJ.month << " " << to_string(data.timeInfo.dateOBJ.day) << ", " << to_string(data.timeInfo.dateOBJ.year) << endl;
    output << "*******************************************************" << endl;
}

void EMPTYERROR (ofstream& output) {
    //throw empty file error
    cout << "===> Input file is empty.  Program terminated" << endl;
    output << "----------------------------------------------------" << endl;
    output << "==> The input file does not contain any information." << endl;
    output << "----------------------------------------------------" << endl;
}
