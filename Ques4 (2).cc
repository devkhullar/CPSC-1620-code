//Author: Dev Khullar
//Date: 15-05-2024
//Solution of Question 4, Assignment 2 

#include <iostream>
using namespace std;

int main() {
    // Declaring the dimensions 
    double door_length, door_width;
    double window1_length, window1_width;
    double window2_length, window2_width;
    double bookshelf_length, bookshelf_width;
    double room_length, room_width, room_height;
    double total_area_of_room;
    double door_area, window1_area, window2_area, bookshelf_area;
    double total_area_to_be_painted, total_paint_needed;

   // Dimensions of the door 
    cout << "Enter the length of the door (in feet): ";
    cin >> door_length;
    cout << "Enter the width of the door (in feet): ";
    cin >> door_width;

    // dimensions of window 1
    cout << "Enter the length of the first window (in feet): ";
    cin >> window1_length;
    cout << "Enter the width of the first window (in feet): ";
    cin >> window1_width;

    // dimensions of window 2
    cout << "Enter the length of the second window (in feet): ";
    cin >> window2_length;
    cout << "Enter the width of the second window (in feet): ";
    cin >> window2_width;

    // dimensions of the bookshelf
    cout << "Enter the length of the bookshelf (in feet): ";
    cin >> bookshelf_length;
    cout << "Enter the width of the bookshelf (in feet): ";
    cin >> bookshelf_width;

    // dimensions of the room
    cout << "Enter the length of the room (in feet): ";
    cin >> room_length;
    cout << "Enter the width of the room (in feet): ";
    cin >> room_width;
    cout << "Enter the height of the room (in feet): ";
    cin >> room_height;

    // Total area of the room:
    // This program assumes that the total area of the room
    // that will be painted will have area of 4 walls + area of the ceiling
    total_area_of_room = 2 * room_height * (room_width + room_length) + (room_length * room_width); 

    // Area of door, windows, and bookshelf
    door_area = door_length * door_width;
    window1_area = window1_length * window1_width;
    window2_area = window2_length * window2_width;
    bookshelf_area = bookshelf_length * bookshelf_width;

    // Total area to be painted
    total_area_to_be_painted = total_area_of_room - door_area - window1_area - window2_area + bookshelf_area; 

    // Total paint needed 
    // 120 square feet takes up 1 gallon of paint
    // 1 square feet takes up 1 / 120 gallon of paint
    total_paint_needed = total_area_to_be_painted / 120;

    // Output
    cout << "The amount of paint needed is: " << total_paint_needed << " gallons" << endl;    
    
    return 0;
}