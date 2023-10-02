
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Your name :ORANG TANG ENOW 
//Your Seneca email:otang-enow@mysenecacollege.ca
 //Seneca Student ID:149924219
 //and the date when you completed the work:Wednesday 18th January 2023







#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Movie.h"

using namespace std;
using namespace sdds;

bool yes();
void flushkeys();



int main() {
   bool done = false;
   char genre[128];
   loadMovies();
   cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
   while (!done) {
      cout << "Enter the movie genre to start the search: ";
      cin >> genre;
      flushkeys();
      displayMoviesWithGenre(genre);
      cout << "Do another search? (Y)es: ";
      done = !yes();
      cout << endl;
   }
   cout << "Goodbye!" << endl;
   return 0;
}

void flushkeys() {
   while (cin.get() != '\n');
}

bool yes() {
   char ch = cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}
