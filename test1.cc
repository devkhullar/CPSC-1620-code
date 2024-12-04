// Author: Dev Khullar
// Date: 29 May 2024
// A program which reads input from a file and displays the output in another file
// from the selected options

#include <iostream> 
#include <fstream>
using namespace std;

int main()
{   
    // Declaring variables
    ifstream infile;
    ofstream outfile;
    int n, option;

    // Opening the files 
    infile.open("input.data");
    outfile.open("output.data");

    if (infile)
        cout << "File read was successful" << endl;
    else
        cout << "Could not open the file" << endl;


    // Inputing the data from the file
    infile >> n >> option;    

    // Purpose: source code reads all of the input
    while (!infile.eof())
    {
        // Declaring the options 
        switch(option)
        {
            case 1: // Even
                for (int i = 1; i <= n; i++)
                {
                    outfile << 2 * i << " ";
                }  
                outfile << endl;
                break;

            case 2: // odd
                for (int j = 0; j <=n ; j++)
                {
                    outfile << 2 * j + 1 << " ";
                }
                outfile << endl;
                break;

            case 3: // fibonnaci 
                int counter, prev1, prev2, cur;
                 prev1 = 1, prev2 = 1;
                 if (n == 1)
                 {
                    outfile << "1";
                 }
                else
                {
                  outfile << "1 1 ";
                }
                counter = 3;

                while (counter <= n)
                {
                    cur = prev1 + prev2;
                    outfile << cur << " " ;
                
                    prev1 = prev2;
                    prev2 = cur;

                    counter++;
            
                }
                outfile << endl;
                break;

            default:
                outfile << "You may have not selected either an option or a value for n" << endl;
        }

        infile >> n >> option;
    }
    

    // Closing the files
    infile.close();
    outfile.close();

    return 0;
}
/*Problems that I am facing 
1. The code is not reading my input properly -- it does not read all of my input
2. How do I break line after every output? */