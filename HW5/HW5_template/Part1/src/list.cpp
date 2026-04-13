#include "list.h"
#include <sstream>
#include <string>


std::string Node::toString()
{
    std::stringstream ss; ss << "Node address: " << this;
    return ss.str();
}



void List::insert(Node* node)
{
    // dummy
}


/**
 * TODO: complete this file
 *  - You CANNOT modify list.h.
 */
