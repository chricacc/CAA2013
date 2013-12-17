#include "cover.h"
#include <stdio.h>

std::list<Node> coverTree(Tree *tree){
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

void sortTree(ListAdj current, std::list<Node> *goodList, std::list<Node> *wrongList, Tree *tree){

    if((!current.getNeighbours().empty()) || (current.getNode() == Node(-1))){
        for(std::list<Node>::iterator it=current.getNeighbours().begin(); it != current.getNeighbours().end(); ++it){
            (*goodList).push_back((*it));
            sortTree( *((*tree).getListFromNode((*it))), wrongList, goodList,tree);
            std::cout << (*it).getId() << "\n";
            getchar();
        }
    }
}
