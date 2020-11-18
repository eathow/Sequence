//
//  sequence1.cpp
//  DS Project 2
//
//  Created by Emma Athow on 2/19/20.
//  Copyright © 2020 Emma Athow. All rights reserved.
//

#include "sequence1.h"
#include <cassert>

namespace main_savitch_3 {
sequence :: sequence() {
    //Initialized used. Used represents the number of variables in the sequence.
    used = 0;
}

void sequence :: start() {
    //Postcondition: The first item in the sequence becomes the current item (but if the sequence is empty, then there is no current item).
    current_index = 0;
}

void sequence :: advance() {
    //Precondition: is_item returns true.
    //Postcondition: If the current item was already the last item in the sequence, then there is no longer any current item. Otherwise, the new item is the item immediately after the original current item.
    assert(is_item() == true);
    current_index += 1;
}

void sequence :: insert(const value_type& entry) {
    //Precondition: size( ) < CAPACITY.
    //Postcondition: A new copy of entry has been inserted in the sequence before the current item. If there was no current item, then the new entry has been inserted at the front. In either case, the new item is now the current item of the sequence.
    assert(size() < CAPACITY);
    if(is_item() == false) {
        start();
    }
    //We now want to create a for loop that will go through the sequence and, in a way, shift the values leftward.
        for(unsigned long int i = used; i > current_index; --i)
            data[i] = data[i-1];
    data[current_index] = entry;
    used += 1;
}

void sequence :: attach(const value_type& entry) {
   //Precondition: size( ) < CAPACITY.
   //Postcondition: A new copy of entry has been inserted in the sequence after the current item. If there was no current item, then the new entry has been attached to the end of the sequence. In either case, the new item is now the current item of the sequence.
    assert(size() < CAPACITY);
    if(is_item() == true) {
    //This for loop is much like the for loop used in the function insert. The main difference between the two is the way in which the values of the sequence are being shifted (rightward versus leftward).
        for(unsigned long int i = used; i > current_index + 1; --i)
            data[i] = data[i-1];
        data[current_index + 1] = entry;
        used += 1;
        current_index += 1;
    }
    else {
        //In this case, there was no current item, so the current item then becomes the new entry.
        data[used] = entry;
        current_index = used;
        used += 1;
    }
}

void sequence :: remove_current() {
    //Precondition: is_item returns true.
    //Postcondition: The current item has been removed from the sequence, and the item after this (if there is one) is now the new current item.
    assert(is_item() == true);
    if(size() == 0) {
        current_index = used;
    }
    else {
        //Again, this for loop's logic works much like that of attach and insert wherein we are simply moving around the values of the sequence.
        for(unsigned long int i = current_index + 1; i < used; ++i){
        data[i-1] = data[i];
    }
    used -= 1;
}
}
sequence :: size_type sequence :: size() const {
 //Postcondition: The return value is the number of items in the sequence.
 return used;
}

bool sequence :: is_item() const {
//Postcondition: A true return value indicates that there is a valid “current” item that may be retrieved by the current member function (listed below). A false return value indicates that there is no valid current item.
    if(current_index >= size() || size() == 0) {
        return false;
    }
    else {
        return true;
    }
}

sequence :: value_type sequence :: current() const {
 //Precondition: is_item( ) returns true.
 //Postcondition: The item returned is the current item in the sequence.
 assert(is_item() == true);
 return data[current_index];
}
}
