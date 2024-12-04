// Author : Dev Khullar
// Date: 24 May 2024
// A program which reads data from a file and displays the result

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ifstream infile;
    string firstName1, lastName1, firstName2, lastName2, firstName3, lastName3;
    double currentSalary1, payIncrease1, updatedSalary1;
    double currentSalary2, payIncrease2, updatedSalary2;
    double currentSalary3, payIncrease3, updatedSalary3;
    infile.open("employee.data");

    
    if(!infile)
    {
      cout <<"The file does not exist";
      exit(0);
    }

   infile >> lastName1 >> firstName1 >> currentSalary1 >> payIncrease1;
   infile >> lastName2 >> firstName2 >> currentSalary2 >> payIncrease2;
   infile >> lastName3 >> firstName3 >> currentSalary3 >> payIncrease3;

    cout << endl<< endl;
    cout << setfill('*') << setw(45) <<""<< endl;
    cout << setfill(' ') << setw(30) << "Employee Salary" << setw(20) << endl;
    cout << setfill('-') << setw(45) <<""<< endl;
    cout << left <<  setfill(' ') << setw(20) << "Employee Name"  << "|" << setfill(' ') << setw(7) << "" << "Updated Salary" <<endl;
    cout << setfill('-') << setw(45) <<""<< endl;

    updatedSalary1 = currentSalary1 + (payIncrease1/100 *currentSalary1 );
    updatedSalary2 = currentSalary2 + (payIncrease2/100 *currentSalary2 );
    updatedSalary3 = currentSalary3 + (payIncrease3/100 *currentSalary3 );

    cout << fixed << setprecision(2);
    cout << setfill(' ') << setw(19) << (firstName1 + " " + lastName1) << " | " 
    << right << setw(20) << updatedSalary1 << endl;
    cout << setfill(' ') << setw(19) << (firstName2 + " " + lastName2) << " | " 
    << right << setw(20) << updatedSalary2 << endl;
    cout << setfill(' ') << setw(15) << (firstName3 + " " + lastName3) << setfill(' ') << setw(7) << " | " 
    << right << setw(20) << updatedSalary3 << endl;

    cout << setfill('*') << setw(45) <<""<< endl;


    infile.close();
    return 0;
}

