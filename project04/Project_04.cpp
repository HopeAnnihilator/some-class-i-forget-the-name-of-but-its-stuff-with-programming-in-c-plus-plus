#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  // Declare Variables
  string username;
  string word1;
  string word2;
  string word3;
  string password;
  string initials;
  float  average;
  int    space;

  // Print header
  cout << "\n" << string(60, '*') << endl;
  cout << "                      Password Generator\n";
  cout << string(60, '*') << endl;

  // Input username
  cout << "Enter user's first and last names separated by a space: ";
  getline(cin, username);
  cout << "\nname = " + username << endl;
  
  // Input first word
  cout << "\nEnter the first word: ";
  cin >> word1;
  cout << "\nfirst word = " << word1 << endl;

  // Input second word
  cout << "\nEnter the second word: ";
  cin >> word2;
  cout << "\nsecond word = " << word2 << endl;

  // Input third word
  cout << "\nEnter the third word: ";
  cin >> word3;
  cout << "\nthird word = " << word3 << endl << "\n";

  // Print columns 
  cout << left;
  cout << string(60, '*') << endl;
  cout << setw(8) << "Word#";
  cout << setw(10) << "Length";
  cout << setw(20) << "Word" << endl;
  cout << setw(8) << "-----";
  cout << setw(10) << "------";
  cout << setw(20) << "----" << endl;

  // Print data for first word in columns
  cout << setw(8) << "1" << setw(10);
  cout << word1.length();
  cout << setw(20) << word1 << endl;

  // Print data	for second word in columns
  cout << setw(8) << "2" << setw(10);
  cout << word2.length();
  cout << setw(20) << word2 << endl;

  // Print data for third word in columns
  cout << setw(8) << "3" << setw(10);
  cout << word3.length();
  cout << setw(20) << word3 << endl;

  // Print end of columns
  cout << setw(8) << "-----";
  cout << setw(10) << "------";
  cout << setw(20) << "----" << endl;

  // Print average
  average = (float(word1.length()) + float(word2.length()) + float(word3.length())) / 3.0;
  cout << "\nAverage word length = " << fixed << setprecision(2) << average << endl;

  // Create and print password
  space = username.find(" ");
  initials = username.substr(0, 1) + username.at(space + 1);
  password = initials + to_string(username.length());
  password = password + word1.at(0) + word1.back() + to_string(word1.length());
  password = password + word2.at(0) + word2.back() + to_string(word2.length());
  password = password + word3.at(0) + word3.back() + to_string(word3.length());
  cout << "\npassword = " << password << endl;
  cout << string(60, '*') << endl << "\n";
  
  // Successfully exit function
  return 0;
}
