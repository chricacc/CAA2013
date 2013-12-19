#include "cover.h"
#include <stdio.h>


//vertex cover trivial
std::list<Node> vertBlack;
std::list<Node> vertWhite;


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

    if((!current.getNeighbours().empty()) && (current.getNode() != Node(-1))){
        std::list<Node> listNode = current.getNeighbours();
        for(std::list<Node>::iterator it=listNode.begin(); it != listNode.end(); ++it){
            (*goodList).push_back((*it));
            ListAdj *next = (*tree).getListFromNode(*it);
            sortTree( *next, wrongList, goodList,tree);
        }
    }
}

std::list<Node> coverBipart(Bipart *bipart){
    if(bipart->getLeft().size() > bipart->getRight().size())
        return bipart->getRight();
    else
        return bipart->getLeft();
}

//parcours profondeur en marquand les sommets visités -> arbre -> getCover
Tree dfs(Graph *graph){
    std::list<Node> visited;
    Tree result;
    for (std::list<ListAdj>::iterator it=graph->getLists().begin(); it != graph->getLists().end(); ++it){
        if(!isInList((*it).getNode(), visited)){
            result.addVert((*it).getNode());
            visited.push_back((*it).getNode());
            sdfs(graph,(*it), &visited, &result);
         }
    }
    return result;
}

void sdfs(Graph *graph, ListAdj neighbours,std::list<Node> *visited, Tree *result ){
    std::list<Node> nbr = neighbours.getNeighbours();
    for (std::list<Node>::iterator it=nbr.begin(); it != nbr.end(); ++it){
        if(!isInList((*it), *visited)){
            (*result).addVert(*it);
            (*visited).push_back(*it);
            sdfs(graph, *(*graph).getListFromNode(*it), visited, result);
        }
    }
}

std::list<Node> coverGraph(Graph *graph){
    Tree t = dfs(graph);
    return coverTree(&t);
}


