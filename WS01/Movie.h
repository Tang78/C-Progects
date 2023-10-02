

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Your name :ORANG TANG ENOW 
//Your Seneca email:otang-enow@mysenecacollege.ca
 //Seneca Student ID:149924219
 //and the date when you completed the work:Wednesday 18th January 2023







#ifndef _Movie_H
#define _Movie_H

namespace sdds{
struct Movie {
   char m_title[128];
   int m_year;
   char m_rating[6];
   int m_duration;
   char m_genres[10][11];
   float m_consumerRating;
};

bool loadMovies();
bool hasGenre(const Movie* mvp, const char genre[]);
void displayMovie(const Movie* mvp);
void displayMoviesWithGenre(const char genre[]);
}


#endif