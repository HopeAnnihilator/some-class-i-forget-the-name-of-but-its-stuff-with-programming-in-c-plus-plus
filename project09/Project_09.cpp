#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//define struct to store data in 
struct fullData {
    int height;
    int width;
    //allocate memory for arrays
    int andArray[500][500];
    int xorArray[500][500];
    int orArray[500][500];
    int arrayOne[500][500];
    int arrayTwo[500][500];
};


//define functions
void OPENINPUT (ifstream& input);
void READDATA (ifstream& input, fullData& array);
void ANALYZEDATA (fullData& array);
void PRINTINPUT (fullData &array);
void PRINTOUTPUT (fullData& array);
void PRINTINT (fullData& array);


int main () {
    //define variables and struct object
    fullData array;
    ifstream input;

    //open input
    OPENINPUT (input);

    //read input
    READDATA (input, array);

    //create and, or, and xor data
    ANALYZEDATA (array);

    //print output
    PRINTINPUT (array);
    PRINTOUTPUT (array);
    PRINTINT (array);

    //exit successfully
    return 0;
}


void OPENINPUT (ifstream& input) {

    string filename;

    //loop till correct filename entered 
    while (true) {
        cout << endl << "Enter the name of the input file: ";
        cin >> filename;
        cout << filename << endl << endl;

        input.open(filename.c_str());
        if (input.good()) {
            //if input opened return
            return;
        } else {
            //print error on failed filename input
            cout << "*************** File Open Error ***************" << endl;
            cout << "==> Input file failed to open properly!!" << endl;
            cout << "==> Attempted to open file: " << filename << endl;
            cout << "==> Please try again..." << endl;
            cout << "***********************************************" << endl; 
            //clear filestream
            input.close(); input.clear();
        }
    }
};



void READDATA(ifstream& input, fullData& array) {
    //define vars
    string line;
    string a;
    input >> a;
    //store array height
    array.height = stoi(a);
    getline(input, line, '\n');
    input >> a;
    //store array width
    array.width = stoi(a);
    getline(input, line, '\n');
    getline(input, line, '\n');
    //read lines for array one and store in struct
    for (int row = 0; row < array.height; row++) {
        getline(input, line, '\n');
        for (int col = 0; col < array.width; col++) {
            array.arrayOne[row][col] =  stoi(line.substr(col * 2, 1));
        }
    }

    getline(input, line, '\n');
    //read lines for array two and store in struct
    for (int row = 0; row < array.height; row++) {
        getline(input, line, '\n');
        for (int col = 0; col < array.width; col++) {
            array.arrayTwo[row][col] =  stoi(line.substr(col * 2, 1));
        }
    }
};

void ANALYZEDATA (fullData& array) {
    //create and, or, xor data
    for (int row = 0; row < array.height; row++) {
        for (int col = 0; col < array.width; col++) {
            //check and data
            if (array.arrayOne[row][col] + array.arrayTwo[row][col] == 2){
                array.andArray[row][col] = 1;
            } else {
                array.andArray[row][col] = 0;
            }
            //check or data
            if (array.arrayOne[row][col] + array.arrayTwo[row][col] >= 1){
                array.orArray[row][col] = 1;
            } else {
                array.orArray[row][col] = 0;
            }
            //check xor data
            if (array.arrayOne[row][col] + array.arrayTwo[row][col] == 1){
                array.xorArray[row][col] = 1;
            } else {
                array.xorArray[row][col] = 0;
            }
        }
    }
};
void PRINTINPUT (fullData &array) {
    //print input file information
    cout << "Initial values of the arrays processed" << endl;
    cout << "--------------------------------------" << endl;
    cout << left << setw(array.width * 3 - 1) << "Array 1" << setw(array.width * 3 - 1) << "Array 2" << endl;
    cout << left << setw(array.width * 3 - 1) << "-------" << setw(array.width * 3 - 1) << "-------" << endl;
    for (int row = 0; row < array.height; row++) {
        for (int col = 0; col < array.width; col++) {
            cout << array.arrayOne[row][col] << " ";
        }
        cout << left << setw(array.width - 1) << " ";
        for (int col = 0; col < array.width; col++) {
            cout << array.arrayTwo[row][col] << " ";
        }
        cout << endl;
    }
};
void PRINTOUTPUT (fullData& array) {
    //print and, or, xor output
    cout << endl << "OR, AND and XOR results" << endl;
    cout << "-----------------------" << endl;
    cout << left << setw(array.width * 3 - 1) <<  "OR" << setw(array.width * 3 - 1) << "AND" << setw(array.width * 3 - 1) << "XOR" << endl;
    cout << left << setw(array.width * 3 - 1) << "--" << setw(array.width * 3 - 1) << "---" << setw(array.width * 3 - 1) << "---" << endl;
    for (int row = 0; row < array.height; row++) {
        for (int col = 0; col < array.width; col++) {
            cout << array.orArray[row][col] << " ";
        }
        cout << left << setw(array.width - 1) << " ";
        for (int col = 0; col < array.width; col++) {
            cout << array.andArray[row][col] << " ";
        }
        cout << left << setw(array.width - 1) << " ";
        for (int col = 0; col < array.width; col++) {
            cout << array.xorArray[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
};

void PRINTINT (fullData& array) {
    //print decimal output
    cout << "Integer Equivalents for the rows" << endl;
    cout << "of the OR, AND and XOR arrays" << endl;
    cout << "--------------------------------" << endl;
    cout << "OR      AND     XOR" << endl;
    cout << "--      ---     --- " << endl;
    for (int row = 0; row < array.height; row++) {
        int totalOR = 0;
        int totalAND = 0;
        int totalXOR = 0;
        for (int col = 0; col < array.width; col++) {
            if (array.xorArray[row][col] == 1) {
                totalXOR += pow(2, array.width - col - 1);
            }
            if (array.orArray[row][col] == 1) {
                totalOR += pow(2, array.width - col - 1);
            }
            if (array.andArray[row][col] == 1) {
                totalAND += pow(2, array.width - col - 1);
            }
        }
        cout << left << setw(8) << totalOR << setw(8) << totalAND << setw(8) << totalXOR << endl;
    }
};
