#ifndef MovieNode_h
#define MovieNode_h

#include "Movie.h"
#include <iostream>
using std::cout;
using std::endl;

class MovieNode
{
public:
    MovieNode  () = default;
    MovieNode  (const Movie& new_movie) : movie( new_movie ) {}
    ~MovieNode ();
    Movie      get_movie    ( ) const                    { return movie; }
    MovieNode* get_next     ( ) const                    { return next; }
    void       set_next     (MovieNode* new_next)        { next = new_next; }
    void       write        (std::ostream& fout) const   { movie.write(fout); }
    bool       operator<    (const MovieNode& rhs) const;
private:
    Movie      movie;
    MovieNode* next = nullptr;
};
std::ostream& operator<< (std::ostream& fout, const MovieNode& node);


#endif
