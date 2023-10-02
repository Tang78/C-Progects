

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Your name :ORANG TANG ENOW 
//Your Seneca email:otang-enow@mysenecacollege.ca
 //Seneca Student ID:149924219
 //and the date when you completed the work:Wednesday 18th January 2023







#ifndef _File_H 
#define _File_H



bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);
 


 #endif