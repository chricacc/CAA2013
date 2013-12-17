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

bool operator== (Node n1, Node n2)
{
    return n1.equals(n2);
}

bool operator!= (Node n1, Node n2)
{
    return !(n1==n2);
}
