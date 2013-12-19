#include "listadj.h"
#include "tools.h"

ListAdj::ListAdj(Node node)
{
    this->node = node;
}

ListAdj::ListAdj(Node node, std::list<Node> neighbours)
{
    this->node = node;
    this->neighbours = neighbours;
}

Node ListAdj::getNode()
{
    return this->node;
}

std::list<Node> ListAdj::getNeighbours()
{
    return this->neighbours;
}

void ListAdj::addNeighbour(Node node)
{
    if(!isInList<Node>(node, neighbours) && !(this->node==node))
        this->neighbours.push_back(node);
}

void ListAdj::removeNeighbour(Node node)
{
    if(isInList<Node>(node, neighbours))
        this->neighbours.remove(node);
}

/*
bool isInList(Node node, std::list<Node> list)
{
    bool res =false;

    for (std::list<Node>::iterator it=list.begin(); it != list.end(); ++it)
        if(node.equals(*it))
            res = true;

    return res;
}
*/
void ListAdj::display()
{
    std::cout << this->getNode().getId() << " : ";
    for (std::list<Node>::iterator it=this->neighbours.begin(); it != this->neighbours.end(); ++it)
        std::cout << ' ' << (*it).getId();
}


