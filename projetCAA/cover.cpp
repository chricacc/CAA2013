#include "cover.h"
#include <stdio.h>


//vertex cover trivial
std::list<Node> vertBlack;
std::list<Node> vertWhite;

std::list<Node> coverTree(Tree *tree)
{
    vertBlack.clear();
    vertWhite.clear();
    ListAdj current = (*tree).getRoot();
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

std::list<Node> coverBipart(Bipart *bipart){
    if(bipart->getLeft().size() > bipart->getRight().size())
        return bipart->getRight();
    else
        return bipart->getLeft();
}

//parcours profondeur en marquand les sommets visités -> arbre -> getCover
std::list<Tree> dfs(Graph *graph){
    std::list<Node> visited;
    std::list<Tree> result;
    std::list<ListAdj> lists = graph->getLists();
    for (std::list<ListAdj>::iterator it=lists.begin(); it != lists.end(); ++it){
        if(!isInList((*it).getNode(), visited)){
            Tree treeRes;
            treeRes.addVert((*it).getNode());
            visited.push_back((*it).getNode());
            sdfs(graph,(*it), &visited, &treeRes);
            result.push_back(treeRes);
         }
    }
    return result;
}

void sdfs(Graph *graph, ListAdj neighbours,std::list<Node> *visited, Tree *result ){
    std::list<Node> nbr = neighbours.getNeighbours();
    for (std::list<Node>::iterator it=nbr.begin(); it != nbr.end(); ++it){
        if(!isInList((*it), *visited)){
            (*result).addVert(*it);

            ListAdj *n1 = (*result).getListFromNode(neighbours.getNode());
            ListAdj *n2 = (*result).getListFromNode(*it);
            (*result).addEdge(n1, n2);

            (*visited).push_back(*it);

            ListAdj *next = (*graph).getListFromNode(*it);
            sdfs(graph, *next, visited, result);
        }
    }
}

std::list<Node> coverGraph(Graph *graph){
    std::list<Tree> lt = dfs(graph);
    std::list<Node> res;

    for(std::list<Tree>::iterator tree=lt.begin(); tree!=lt.end(); ++tree){
        std::list<Node> tmpRes = coverTree(&(*tree));
        res.insert(res.end(), tmpRes.begin(), tmpRes.end());
    }

    return res;
}


void coverToSAT(Graph *graph, std::string outputFile){
    int nbVert = graph->getNbVerts();

}


