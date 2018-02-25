#include "MovieNode.h"

/**
 * @detailed    Destructor for MovieNode class.
 *              Display the movie title that has been destroyed.
 *
 */
MovieNode::~MovieNode()
{
    cout << "\nThe node destroyed: " << movie.title << endl;
}


/**
 * @detailed    Overloaded << operator for MovieNode class
 *
 * @param[out]        fout     output stream which the objects are sent to
 * @param[out]        node     MovieNde object to be displayed
 *
 * @return      output streama by reference
 *
 */
std::ostream& operator<< (std::ostream& fout, const MovieNode& node)
{
    node.write( fout );
    return fout;
}


/**
 * @detailed    Overloaded < operator for MovieNode class
 *
 * @param[out]  rhs    MovieNde object to be compared
 *
 * @return      the boolean result of comparison
 */
bool MovieNode::operator< ( const MovieNode& rhs ) const
{
    std::string upper_title1 = to_uppercase(movie.title);
    std::string upper_title2 = to_uppercase(rhs.movie.title);
    return upper_title1 < upper_title2;
}



/**
 * @detailed    Convert the first letter of the title to uppercase.
 *
 * @param       s    movie's title to be converted to uppercase
 *
 * @return      string whose first letter has been converted to uppercase
 */
std::string to_uppercase(std::string s)
{
    char first_letter = s.at(0);            //extract the first letter
    first_letter = toupper(first_letter);   //convert to uppercase
    s.erase(s.begin());                     //erase the old first letter
    s.insert(s.begin(), first_letter);      //insert the new first letter
    return s;
}
