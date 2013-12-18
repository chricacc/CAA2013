#include "cover.h"
#include <stdio.h>

std::list<Node> vertBlack;
std::list<Node> vertWhite;

std::list<Node> coverTree(Tree *tree)
{
    vertBlack.clear();
    vertWhite.clear();
    ListAdj current = *((*tree).getListFromNode(Node(0)));
    vertBlack.push_back(current.getNode());

    sortTree(current, &vertWhite, &vertBlack, tree);

    if(vertWhite.size() >= vertBlack.size())
        return vertBlack;
    else
        return vertWhite;
}

void sortTree(ListAdj current, std::list<Node> *goodList, std::list<Node> *wrongList, Tree *tree)
{

    if((!(current.getNeighbours().empty())) && (current.getNode() != Node(-1)))
    {
        std::list<Node> listNode = current.getNeighbours();
        for(std::list<Node>::iterator it=listNode.begin(); it != listNode.end(); ++it)
        {
            (*goodList).push_back((*it));
            ListAdj* next = (*tree).getListFromNode(*it);
            sortTree(*next, wrongList, goodList,tree);
        }
    }
}
