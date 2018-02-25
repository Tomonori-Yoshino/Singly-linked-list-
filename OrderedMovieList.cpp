#include "OrderedMovieList.h"


/**
 * @detailed    Display all the movies in the list.
 *
 * @param[out]  fout    output stream which the objects are sent to
 *
 */
void OrderedMovieList::write( std::ostream& fout ) const
{
    MovieNode* current = head;
    while ( current )
    {
        fout << current -> get_movie();     //print the movie in the current node
        fout << endl;
        current = current -> get_next();    //point current to next node
    }
}


/**
 * @detailed    Overloaded << operator for OrderedMovieList class
 *
 * @param[out]        fout     output stream which the objects are sent to
 * @param[out]        list     singly lined list containg movies
 *
 * @return      output streama by reference
 *
 */
std::ostream& operator<< (std::ostream& fout, const OrderedMovieList& list)
{
    list.write( fout );
    return fout;
}


/**
 * @detailed    Remove the first movie in the list.
 *
 * @return      Movie object which has been removed.
 *
 */
Movie OrderedMovieList::removeFromHead ()
{
    MovieNode* old_head = head;
    Movie      old_movie;
    if (!head)  // the list was empty
    {
        throw std::length_error("Cannot remove from empty list.");
    }
    else
    {
        head      = old_head -> get_next();     // point head to node following old head
        old_movie = old_head -> get_movie();    // save the movie data from the removed node for later return
        delete old_head;
        old_head = nullptr;     // delete the removed node
    }
    return old_movie;
}


/**
 * @detailed    Erace the movie from the list by removing the first movie in the list
 *              untill it is empty.
 *
 */
void OrderedMovieList::erase ( )
{
    while ( head )
    {
        Movie movie_removed = removeFromHead();     //continue to remove the first movie
    }
}



/**
 * @detailed    Insert the movie to the list which is alphabetically orderd.
 *
 * @parameter[out]      new_movie       the movie to be added
 *
 */
void OrderedMovieList::insert (const Movie& new_movie)
{
    MovieNode* new_node = new MovieNode {new_movie};    //create new node containing new_movie
    MovieNode* current  = nullptr;
    MovieNode* previous = nullptr;        //initialize "current" & "previous" pointers for list traversal
    
    if ( !head )        //if the list is empty...
    {
        new_node -> set_next(head);
        head = new_node;
    }
    else        //if there are some movies in the list...
    {
        bool stop = false;
        current = head;
        while ( current && !stop )      //while correct location not yet found...
        {
            if ( *current < *new_node )
            {
                previous = current;         //save the preveous node for later use
                current = current -> get_next();        //move on to next location to check
            }
            else        //the location has been found...
            {
                stop = true;
            }
        }
        if ( current != head )      //if the location is middle of the list
        {
            previous -> set_next( new_node );
            new_node -> set_next( current );
        }
        else        //if the location is at the head
        {
            new_node -> set_next(head);
            head = new_node;
        }
    }
}




