// Author : Dev Khullar
// Date: 24 May 2024
// A program which converts a person's weight in kilograms to pounds

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    const double CONVERSION = 2.2;
    double weight_in_kilograms, weight_in_pounds;

    // Taking input from the user for their weight in kg
    cout << "Enter your weight in kilograms: " << endl;
    cin >> weight_in_kilograms;

    // calculating and assigning weight_in_pounds
    weight_in_pounds = weight_in_kilograms * CONVERSION;
    cout << fixed << setprecision(2); 

    cout << "Your weight in pounds is " << weight_in_pounds << endl;     

    return 0;
}