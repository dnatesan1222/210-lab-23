// COMSC-210 | Lab 23 | Diksha Tara Natesan
// IDE used: Vim/Terminal

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;
    bool run = true;
    while (run){
	int choice = main_menu();
	if (choice == 1)
	    add_goat(trip, names, colors);
	else if (choice == 2)
	    delete_goat(trip);
	else if (choice == 3)
	    display_trip(trip);
 	else
	    run = false;
    }
    cout << "Thanks for using the GOAT MANAGER 3001!" << endl;
    return 0;
}



int select_goat(list<Goat> trip){
    display_trip(trip);
    cout << "\tChoice --> ";
    int input;
    cin >> input;
    if (input > trip.size() || input < 1){
	cout << "Error. Please select a valid choice within the range.\n" << endl;
        input = select_goat(trip);
    }
    return input;
}

void delete_goat(list<Goat> &trip){
    cout << "Please select a Goat you would like to remove from the trip." << endl;
    int pos = select_goat(trip);
    trip.erase(pos);
}

void add_goat(list<Goat> &trip, string [] names, string [] colors){
    int age = rand() % (MAX_AGE + 1);  // returns random number 0-20
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    Goat temp = new Goat(name, age, color);
    trip.push_back(temp);
}

void display_trip(list<Goat> trip){
    int count = 1;
    for (Goat g : trip){
        cout << "\t[" << count << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
	count += 1;
    }
}

int main_menu(){
    cout << "\t*** GOAT MANAGER 3001 ***" << endl;	//choice display
    cout << "\t[1] Add a goat" << endl;
    cout << "\t[2] Delete a goat" << endl;
    cout << "\t[3] List goats" << endl;
    cout << "\t[4] Quit" << endl;
    cout << "\tChoice --> ";
    int input;				//obtain user input
    cin >> input;
    if (input < 1 || input > 4){	//validate user input
	cout << "Error. Please input a value within the range 1-4 to select a choice.\n" << endl;
	input = main_menu();
    } 
    return input;			//return validated user input
}
