#ifndef Movie_h
#define Movie_h

#include <iostream>
#include <string>

struct Movie {
    std::string title;              // Movie title
    unsigned short year;            // Movie release year
    std::string director;           // Director's name
    std::string rating;             // Movie audience rating
    
    Movie() = default;
    Movie( std::istream& infile );  // construct given an input stream
    void write( std::ostream& outfile ) const;
};
std::ostream& operator<<( std::ostream& outfile, const Movie& movie );


#endif
