// Author  : Dev Khullar
// Date    : 7 June 2024
// Purpose : A program that takes the coordinates of points and outputs radius, diameter, circumference
//           and area of a circle  

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// Function prototype
void openFile(ifstream &); 
void readFile(ifstream &, double &, double &, double &, double &);
void writeFile(ofstream &, double &, double &, double &, double &);
void closeFile(ifstream &);  
void closeFile(ofstream &);
double distance(double, double, double, double);
double calculateRadius(double, double , double , double );
double calculateCircumference(double);
double calculateArea(double);
void measure(double, double, double, double, double &, double &, double &, double &);

// Global constant
const double PI = 3.14159;

// Main function
int main()
{   double x_1, y_1, x_2, y_2;
    double radius, diameter, circumference, area;
    ifstream in;
    ofstream out;


    openFile(in);
    out.open("output.data");

    readFile(in, x_1, y_1, x_2, y_2 );
    while(!in.eof())
    {
        measure(x_1, y_1, x_2, y_2, radius, diameter, circumference, area);
        writeFile(out, radius, diameter, circumference, area);
        readFile(in, x_1, y_1, x_2, y_2 );
    }


    closeFile(in);
    closeFile(out);
    return 0;

}

// Purpose: Opens a file for reading
// Input: file name 
// Outputs: none
// Return: None
void openFile(ifstream &i)
{
    string fileName;
    do {
        cout << "Enter a filename: ";
        cin >> fileName;
        i.open(fileName.c_str());
    }
    while(!i);
    cout << "You have successfully opened the file!" << endl;
}

// Purpose: read a row from a file
// Input: None
// Output: ifstream i
// double x_0, double y_0
// double x_1, double y_1
// return: None
void readFile(ifstream &i, double &x_1, double &y_1, double &x_2, double &y_2)
{
    i >> x_1 >> y_1 >> x_2 >> y_2;
}

// Purpose: Writing Output in an output file
// Input: result (final output)
//        a (number)
//        b (number)
// Outputs: ofstream file
// Return: None
void writeFile(ofstream &file, double & radius, double & diameter, double & circumference, double & area)
{
    file << fixed << setprecision(2);
    file << "Radius: " << radius << ", " << "Diameter: " << diameter << ", " << "Circumference: " 
    << circumference << ", " << "Area: " << area << ", " << endl;
}

// Purpose: close on opened input file
// Input: None
// Output: ifstream file
//          Return None
void closeFile(ifstream &file)
{
    file.close();
    cout << "Input File has been closed" << endl;
}

// Purpose: Close an opened output file
// Inpute: None
// Output: ofstream file
// Return: None
void closeFile(ofstream &file)
{
    file.close();
    cout << "Output File has been closed" << endl;
}

// Purpose: A function that calculates the distance between two points 
// Input: double &, double &, double &, double &
// Output: distance
// Return: distance
double distance(double x_1, double y_1, double x_2, double y_2)
{
    double x_difference, y_difference;
    x_difference = x_2 - x_1;
    y_difference = y_2 - y_1;
    return sqrt(pow(x_difference, 2) + pow(y_difference, 2));
  
}

// Purpose: A function which calculates the radius of the circle
// Inputs: double, double, double, double -- 4 coordinates
// Return: radius 
double calculateRadius(double x_1, double y_1, double x_2, double y_2)
{
    return distance(x_1, y_1, x_2, y_2);
}

// Purpose: A function which calculates the circumference of the circle
// Inputs: double -- radius 
// Return: circumference of the circle
double calculateCircumference(double radius)
{
    return 2 * PI * radius;
}

// Purpose: A function which calculates the are of the circle
// Inputs: double -- radius 
// Return: circumference of the circle
double calculateArea(double radius)
{
    return PI * pow(radius, 2);
}

// Purpose: A purpose which executes all other necessary functions for the assignment
// Inputs: double, double, double, double : 4 coordinates
//         double &, double &, double &, double &: radius, diameter, circumference, area
void measure(double x_1, double y_1, double x_2, double y_2, double &radius, double &diameter,
         double &circumference, double&area)
{
    radius = calculateRadius(x_1, y_1, x_2, y_2);
    diameter = 2 * radius;
    circumference = calculateCircumference(radius);
    area = calculateArea(radius);
}
