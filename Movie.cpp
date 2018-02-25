#include "Movie.h"

/**
 * @detailed    Read the movie from the given stream.
 *
 * @param[out]  infile    input stream which the movies are read from.
 *
 */
Movie::Movie( std::istream& infile )
{
    std::string temp;                           //temporary strage for the year
    std::getline( infile, title, '|' );         //read the title until |
    std::getline( infile, temp, '|' );          //read the year as a string
    std::getline( infile, director, '|' );      //read the director
    std::getline( infile, rating );             //read the rate
    
    year = std::stoi( temp );                   //convert the string to int
    
    year = static_cast< unsigned short >( year );
}

/**
 * @detailed    Read the movie from the given stream.
 *
 * @param[out]  outfile    output stream which the movies are sent to.
 *
 */
void Movie::write( std::ostream& outfile ) const
{
    outfile << title << " " << "(" << year << ") "
            << rating << " - " << director;
}


/**
 * @detailed    Overloaded << operator for Movie class.
 *
 * @param[out]  outfile     output stream which the movies are sent to.
 * @param[out]  movie       the movie to be displayed
 *
 * @return      output stream by reference
 *
 */
std::ostream& operator<<( std::ostream& outfile, const Movie& movie )
{
    movie.write( outfile );
    return outfile;
}
