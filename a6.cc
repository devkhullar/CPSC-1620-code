// Name   : Dev Khullar
// Date   : 14 June 2024
// Purpose: A program which tabulates an input data file in descending order of the total number of sales. 

#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// global variable 
const int MAX_SELLERS = 100;  

// Function prototype
void openFile(ifstream &);
void getData(ifstream &, string[], int[], int &);
void computePercentages(int[], double[], int &);
void sortSeller(string[], int[], double[], int &);
void display(const string[], const int[], const double[], int);
void displayTopSeller(const string[], const int[], int);
  
int main()
{
    ifstream input;
    string names[MAX_SELLERS];
    int sales[MAX_SELLERS];
    double percentage[MAX_SELLERS];
    int count = 0;

    openFile(input);
    getData(input, names, sales, count);
    computePercentages(sales, percentage, count);
    sortSeller(names, sales, percentage, count);
    display(names, sales, percentage, count);
    displayTopSeller(names, sales, count);

    return 0;
}

// Purpose  : A function which opens the file 
// Input    : ifstream 
// Output   : None
// Return   : None
void openFile(ifstream &i)
{
    string fileName;
    do {
        cout << "Enter the filename: ";
        cin >> fileName;
        i.open(fileName.c_str());
    }
    while(!i);
    cout << "You have successfully opened the file!" << endl;
}

// Purpose  : A function that reads the data from the opened file 
// Input    : (1) ifstream (2) Names of the Sellers [array], 
//            (3) Number of Sales [array], (4) total number [integer]
// Output   : Reads the data
// Return   : None
void getData(ifstream & i, string sellerName[], int  numOfSales[], int & totNum)
{
    totNum = 0;
    while (i >> sellerName[totNum] >> numOfSales[totNum])
    {
        totNum++;
    }
}

// Purpose  : A function which converts the number of sales made
//            by a salesperson into percentage of the total sales
// Input    : (1) Number of Sales [array], (2) Percentage [array] and total number (integer)
// Output   : Computed Percentage
// Return   : None
void computePercentages(int numOfSales[], double percentage[], int & totNum)
{
    int totalSales = 0;
    for (int i = 0; i < totNum; i++)
    {
        totalSales = totalSales + numOfSales[i];
    }

    for (int i = 0; i < totNum; i++) 
    {
        percentage[i] = (static_cast<double>(numOfSales[i]) / totalSales) * 100;
    }
}

// Purpose  : A function which sorts the order of sales in a descending order. 
// Inputs   : (1) Names of the Seller [array], (2) Number of Sales [array]
//            (3) Percentage of Sales [array], (4) total Number [integer]
// Output   : A sorted list 
// Return   : None
void sortSeller(string sellerName[],  int numOfSales[],  double percentage[], int & totNum)
{
    for (int i = 0; i < totNum - 1; i++)
        for (int j = i + 1; j < totNum; j++)
        {
            if (numOfSales[j] > numOfSales[i])
               {
                string temp;
                temp = sellerName[i];
                sellerName[i] = sellerName[j];
                sellerName[j] = temp;

                int t;
                t = percentage[i];
                percentage[i] = percentage[j];
                percentage[j] = t;

                int lem;
                lem = numOfSales[i];
                numOfSales[i] = numOfSales[j];
                numOfSales[j] = lem;
               }
                
        }
        
}

// Purpose :  A function which displays the output (see output)
// Input   : (1) Name of the Seller [array], (2) Number of Sales [array]
//           (3) Percentage of Sales [array], (4) Total number (integer)
// Output  : (1) Names of the seller, (2) Number of Sales, (3) Percentage of Sales
//           (4) Total number of Sales
// Return  : Output
void display(const string sellerName[], const int numOfSales[], const double percentage[], int totNum)
{
    cout << left << setw(10) << "Seller" << setw(10) << "# of sales" << " % of total sales" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    for (int i = 0; i < totNum; i++)
    {   cout << fixed << setprecision(2);
        cout << left << setw(10) << sellerName[i] << setw(10) << numOfSales[i] << percentage[i] << endl;
    }

    int totSales = 0;
    for (int i = 0; i < totNum; i++)
    {
        totSales = totSales + numOfSales[i];
    }

    cout << "Total: " << right << setw(7) << totSales << endl;

}

// Purpose  : A function which displays the top seller 
// Input    : (1) Name of the seller [array], (2) Number of Sales [array],
//            (3) Total Number [integer]
// Output   : outputs the seller(s) with the highest sales. 
// Return   : Top Seller
void displayTopSeller(const string sellerName[], const int numOfSales[], int totNum)
{
    int highestSale = numOfSales[0];
    cout << "Name of the highest seller(s): ";
    for (int i = 0; i < totNum; i++)
    {
        if (numOfSales[i] == highestSale)
            cout << sellerName[i] << " ";
        else
            break;
    }
    cout << endl;
}