#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void mEnU ();
void bAdInPuT ();
int cHoIcE ();
void eXiT ();
string fIlEnAmE (string openType);
bool iNpUtFiLe (ifstream& checkFile);
bool oUtPuTfIlE (ofstream& checkFile);
void fIlEoPeNeRrOr (string filename, string filetype);
void cOmPrEsStExT (ifstream& input, ofstream& output);
void dEcOmPrEsStExT (ifstream& input, ofstream& output);
void cLoSeSuCcEsSfUlLy (ifstream& input, ofstream& output, string closeType);

int main () {
    while (true) {
        mEnU ();
        int choice = cHoIcE ();
        if (choice == 0) {
            eXiT ();
            return 0;
        }
        else if (choice == 1) {
            ifstream input;
            string inputFilename = fIlEnAmE ("input");
            input.open(inputFilename.c_str());
            bool inputFileOpen = iNpUtFiLe (ref(input));
            if (!inputFileOpen) {
                fIlEoPeNeRrOr (inputFilename, "Input");
                continue;
            }

            ofstream output;
            string outputFilename = fIlEnAmE ("output");
            output.open(outputFilename.c_str());
            bool outputFileOpen = oUtPuTfIlE (ref(output));
            if (!outputFileOpen) {
                fIlEoPeNeRrOr (outputFilename, "Output");
                continue;
            }

            cOmPrEsStExT (ref(input), ref(output));
            cLoSeSuCcEsSfUlLy (ref(input), ref(output), "Compressed");
        }
        else if (choice == 2) { 
            ifstream input;
            string inputFilename = fIlEnAmE ("input");
            input.open(inputFilename.c_str());
            bool inputFileOpen = iNpUtFiLe (ref(input));
            if (!inputFileOpen) {
                fIlEoPeNeRrOr (inputFilename, "Input");
                continue;
            }

            ofstream output;
            string outputFilename = fIlEnAmE ("output");
            output.open(outputFilename.c_str());
            bool outputFileOpen = oUtPuTfIlE (ref(output));
            if (!outputFileOpen) {
                fIlEoPeNeRrOr (outputFilename, "Output");
                continue;    
            }
            dEcOmPrEsStExT (ref(input), ref(output));
            cLoSeSuCcEsSfUlLy (ref(input), ref(output), "Decompressed"); 
        }

        else {
            bAdInPuT ();
        }
    }
    return 0;
}

void mEnU () { 
    cout << endl << "**********  Compression Menu  **********" << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Compress File" << endl;
    cout << "2. Uncompress File" << endl;
    cout << "****************************************" << endl << endl;
    cout << "Input your selection now: ";
}

void bAdInPuT () { 
    cout << "************** Invalid Selection **************" << endl;
    cout << "==> Invalid character entered!!" << endl;
    cout << "==> Please enter 0, 1 or 2" << endl;
    cout << "***********************************************" << endl;
}

int cHoIcE () {
    int item;
    cin >> item;
    cout << item << endl << endl;
    return item;
}

void eXiT () {
    cout << "Quit selected.  Terminating program now..." << endl << endl;
}

string fIlEnAmE (string openType) {
    string filename;
    cout << "Enter the name of the " << openType << " file: ";
    cin >> filename;
    cout << filename << endl << endl;
    return filename;
}

bool iNpUtFiLe (ifstream& checkFile) {
    if (checkFile.fail()) {
        return false;
    }
    return true;
}

bool oUtPuTfIlE (ofstream& checkFile) {
    if (checkFile.fail()) {
        return false;
    }
    return true;
}

void fIlEoPeNeRrOr (string filename, string filetype) {
    cout << "*************** File Open Error ***************" << endl;
    cout << "==> " << filetype << " file failed to open properly!!" << endl;
    cout << "==> Attempted to open file: " << filename << endl;
    cout << "==> Selected operation has been canceled" << endl;
    cout << "***********************************************" << endl << endl;
    return;
}

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

void dEcOmPrEsStExT (ifstream& input, ofstream& output) {
    string line;
    getline(input, line, '*');
    char current = line.at(0);

    
    cout << line << endl;
    
}


void cLoSeSuCcEsSfUlLy (ifstream& input, ofstream& output, string closeType) {
    cout << "==> File has been "<< closeType << endl;
    input.close();
    input.clear();
    output.close();
    output.clear();
    return;
}
