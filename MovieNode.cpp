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
    return movie.title < rhs.movie.title;
}
