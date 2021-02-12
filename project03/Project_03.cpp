#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// create variables
string stockName;
int stockAmount;
float buyPrice;
float sellPrice;
float brokerFeeBuy;
float brokerFeeSell;
float totalCost;
float returnValue;
float netProfit;
float taxCost;

int main()
{
  //Output header
  cout << "\n*************************" << endl;
  cout << "Stock Calculations" << endl;
  cout << "*************************" << endl;
  cout << "\n";

  // Input stock name
  cout << "Enter the name of the stock: ";
  cin >> stockName;
  cout << stockName << endl;

  // Input stock volume
  cout << "Enter the number of shares purchased: ";
  cin >> stockAmount;        
  cout << stockAmount << endl;
  
  // Input buy price
  cout << "Enter the buy price per share: ";
  cin >> buyPrice;   
  cout << setprecision(2) << fixed << buyPrice << endl;   

  // Input sell price
  cout << "Enter the sell price per share: ";
  cin >> sellPrice;        
  cout << setprecision(2) << fixed << sellPrice << endl;


  // Calculate 2% trading fee for buying
  brokerFeeBuy = (stockAmount * buyPrice) * 0.020;

  //Calculate total cost of buying
  totalCost = brokerFeeBuy + stockAmount * buyPrice;

  //Calculate total broker fee for selling
  brokerFeeSell = (stockAmount * sellPrice) * 0.015; 

  //Calculate return on sell
  returnValue =  (stockAmount * sellPrice) - brokerFeeSell;

  //Calculate net profit 
  netProfit = returnValue - totalCost; 
  
  //Calculate taxes
  taxCost = netProfit * 0.25;



  //Output name and number of shares
  cout << "\nResults for "<< stockAmount << " shares of " << stockName << ":" << endl;
  cout << "-----------------------------------" << endl;

  //Output commission from buying
  cout << "Buy Commission......$" << setprecision(2) << fixed << brokerFeeBuy  << endl;

  //Output total cost of buying
  cout << "Total Cost..........$" << setprecision(2) << fixed << totalCost  << endl;

  //Output commission from selling
  cout << "Sell Commission.....$" << setprecision(2) << fixed << brokerFeeSell  << endl;

  //Output the total return of sell
  cout << "Total Return........$" << setprecision(2) << fixed << returnValue  << endl;

  //Output netprofit
  cout << "Net Profit/Loss.....$" << setprecision(2) << fixed << netProfit  << endl;

  //Output taxes               
  cout << "Tax/Credit..........$" << setprecision(2) << fixed << taxCost << endl;


  cout << "\n";
  return 0; 
}

