#include "node.h"

Node::Node()
{
    this->id = 0;
}

Node::Node(int id)
{
    this->id = id;
}

int Node::getId()
{
    return id;
}

bool Node::equals(Node node)
{
    if(node.getId() == this->id)
        return true;
    else
        return false;
}
