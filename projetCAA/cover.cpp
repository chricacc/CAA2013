#include <stdio.h>
#include <fstream>
#include "cover.h"
#include "tools.h"

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
    for (std::list<ListAdj>::iterator it=lists.begin(); it != lists.end(); ++it)
    {
        Node n = (*it).getNode();
        if(!isInList<Node>(n, visited))
        {
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

/*
 *  c Here is a comment.
 *  p cnf 5 3
 *  1 -5 4 0
 *  -1 5 3 4 0
 *  -3 -4 0
 */

void coverToSAT(Graph *graph, std::string outputFile){
    int nbVert = graph->getNbVerts();
    int nbEdge = graph->getNbEdges();
    std::ofstream file(outputFile.c_str(), std::ios::out);
    if(file){
        file << "p cnf " << nbVert << " " << nbEdge;
        file << "\n";
        std::list<Edge> listEdge = graph->getListEdges();
        for(std::list<Edge>::iterator current=listEdge.begin(); current!=listEdge.end(); ++current){
            file << (*current).getFirstNode().getId();
            file << " " << (*current).getSecondNode().getId();
            file << "\n";
        }
        file.close();
    }else{
        std::cerr << "file not found" << std::endl;
    }

}

std::list<Node> satToCover(std::string inputFile){
    std::list<Node> resultCover;
    std::ifstream flux(inputFile.c_str(), std::ios::in);
    if(flux){
            std::string line;
            std::getline(flux, line);
            if(line == "SAT"){
                std::getline(flux, line);
                std::vector<std::string> vNode = split(line, ' ');
                for(std::vector<std::string>::iterator idNode=vNode.begin(); idNode!=vNode.end(); ++idNode)
                {
                    if(atoi((*idNode).c_str()) >= 0){
                        Node n(atoi((*idNode).c_str()));
                        resultCover.push_back(n);
                    }
                }
            }else{
                std::cerr << "no solution found" << std::endl;
            }
        flux.close();
    }else{
        std::cerr << "file not found" << std::endl;
    }
    return resultCover;
}


