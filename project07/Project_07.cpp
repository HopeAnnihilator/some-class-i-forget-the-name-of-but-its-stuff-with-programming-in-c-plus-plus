#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Define functions
void mEnU ();
int cHoIcE ();
void eXiT ();
string fIlEnAmE (string openType);
void oPeNiNpUt (ifstream& input, string filename);
void oPeNoUtPuT (ofstream& output, string filename);
void fIlEoPeNeRrOr (string filename, string filetype);
void cOmPrEsStExT (ifstream& input, ofstream& output);
void dEcOmPrEsStExT (ifstream& input, ofstream& output);
void cLoSeSuCcEsSfUlLy (ifstream& input, ofstream& output, string closeType);
void fAiLeD (ifstream& input, ofstream& output);

int main () {
    // loop program
    while (true) {
        // print menu
        mEnU ();
        // allow input
        int choice = cHoIcE ();
        // check input
        if (choice == 0) {
            eXiT ();
            return 0;
        }
        else if (choice == 1 || choice == 2) {
            // if input 1 or 2 open files
            string inputFilename = fIlEnAmE ("input");
            ifstream input;
            oPeNiNpUt (input, inputFilename);
            if (input.fail()) {
                fIlEoPeNeRrOr (inputFilename, "Input");
                continue;
            }

            string outputFilename = fIlEnAmE ("output");
            ofstream output;
            oPeNoUtPuT (output, outputFilename);
            if (output.fail()) {
                fIlEoPeNeRrOr (outputFilename, "Output");
                continue;
            }

            //operate according to integer entered
            if (choice == 1 && !(input.peek() == ifstream::traits_type::eof())) {
                cOmPrEsStExT (input, output);
                cLoSeSuCcEsSfUlLy (input, output, "Compressed");
            }
            else if (choice == 2 && !(input.peek() == ifstream::traits_type::eof())) {
                dEcOmPrEsStExT (input, output);
                cLoSeSuCcEsSfUlLy (input, output, "Decompressed");
            }
            else {
                // if file empty fail
                fAiLeD (input, output);
            }
        }
    }
    return 0;
}

// print menu
void mEnU () { 
    cout << endl << "**********  Compression Menu  **********" << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Compress File" << endl;
    cout << "2. Uncompress File" << endl;
    cout << "****************************************" << endl << endl;
    cout << "Input your selection now: ";
    return;
}

// allow input
int cHoIcE () {
    while (true) {
        string item;
        cin >> item;
        int isInt;
        if (isdigit(item.at(0)) || (item.at(0) == '-' && isdigit(item.at(1)))) {
            isInt = stoi(item);
            cout << isInt << endl << endl;
            if (isInt == 0 || isInt == 1 || isInt == 2) {
                return isInt;
            } else {
                cout << "************** Invalid Selection **************" << endl;
                cout << "==> Invalid integer value entered" << endl;
                cout << "==> Please enter 0, 1 or 2" << endl;
                cout << "***********************************************" << endl;
                return 99;
            }
        } else {
            cout << item.at(0) << endl << endl;
            cout << "************** Invalid Selection **************" << endl;
            cout << "==> Invalid character entered!!" << endl;
            cout << "==> Please enter 0, 1 or 2" << endl;
            cout << "***********************************************" << endl;
            return 99;
        }
    }
}

// exit 
void eXiT () {
    cout << "Quit selected.  Terminating program now..." << endl << endl;
    return;
}

// input filename
string fIlEnAmE (string openType) {
    string filename;
    cout << "Enter the name of the " << openType << " file: ";
    cin >> filename;
    cout << filename << endl << endl;
    return filename;
}

// open file
void oPeNiNpUt (ifstream& input, string filename) {
    input.open(filename.c_str());
    return;
}

// open file
void oPeNoUtPuT (ofstream& output, string filename) {
    output.open(filename.c_str());
    return;
}

// output error on file fail
void fIlEoPeNeRrOr (string filename, string filetype) {
    cout << "*************** File Open Error ***************" << endl;
    cout << "==> " << filetype << " file failed to open properly!!" << endl;
    cout << "==> Attempted to open file: " << filename << endl;
    cout << "==> Selected operation has been canceled" << endl;
    cout << "***********************************************" << endl << endl;
    return;
}

// compress input
void cOmPrEsStExT (ifstream& input, ofstream& output) {
    string line;
    getline(input, line, '*');

    char current;
    char previous = line.at(0);
    int count = 1;
    string outLine;

    for (int spot = 1; spot < line.length(); spot++) {
        current = line.at(spot);
        if (current == previous) {
            count += 1;
        }
        else {
            outLine = outLine + to_string(count) + previous;
            count = 1;
        }
        previous = current;
    }
    outLine = outLine + to_string(count) + previous;
    output << outLine;
    return;
}

// decompress input
void dEcOmPrEsStExT (ifstream& input, ofstream& output) {
    string line;
    getline(input, line, '*');
    string defNotAnInt;
    for (int i = 0; i < line.length(); i++) {
        char current = line.at(i);
        if (isdigit(current)) {
            defNotAnInt = defNotAnInt + current;
        }
        else {
            output << string(stoi(defNotAnInt), current);
            defNotAnInt = "";
        }
    }
    return;
}

// exit successfully
void cLoSeSuCcEsSfUlLy (ifstream& input, ofstream& output, string closeType) {
    cout << "==> File has been "<< closeType << endl;
    input.close();
    input.clear();
    output.close();
    output.clear();
    return;
}

// fail successfully 
void fAiLeD (ifstream& input, ofstream& output) {
    cout << "*************** Empty Input File **************" << endl;
    cout << "==> Empty file for Compression" << endl;
    cout << "==> Nothing written to the output file" << endl;
    cout << "***********************************************" << endl;
    input.close();
    input.clear();
    output.close();
    output.clear();
    return;
}
