#ifndef OrderedMovieList_h
#define OrderedMovieList_h

#include "Movie.h"
#include "MovieNode.h"
#include <iostream>
using std::cout;
using std::endl;

class OrderedMovieList
{
public:
    OrderedMovieList() = default;       //default constructor
    ~OrderedMovieList() { erase(); }    //destructor to free the memory
    
    void        write          (std::ostream& fout) const;
    void        erase          ();
    void        insert         (const Movie& new_movie);
    Movie       removeFromHead ();
private:
    MovieNode* head = nullptr;
};
std::ostream& operator<< (std::ostream& fout, const OrderedMovieList& list);



#endif
