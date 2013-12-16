#include<cstdlib>
#include<ctime>
#include<list>
#include "tree.h"

Tree::Tree(int nbNode, int prob)
{
    this->nbVerts = nbNode;
    for(int i=0; i < nbVerts; i++){
        Node n(i);
        addVert(n);
    }
    std::list<Node> done;
    for (std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        for (std::list<ListAdj>::iterator it2=this->listListAdj.begin(); it2 != this->listListAdj.end(); ++it2)
        {

            if(it != it2){
                if((rand() % 100) < prob){
                    if(!isInList((*it2).getNode(), done)){
                        addEdge(&(*it), &(*it2));
                        if(this->isCyclic())
                            removeEdge(&(*it), &(*it2));
                    }
                }
            }
            done.push_back((*it).getNode());
        }
    }

}

Tree::Tree(std::string fileName)
{

}

void Tree::addVert(Node node)
{
    listListAdj.push_back(ListAdj(node));
}

void Tree::addEdge(ListAdj *n1, ListAdj *n2)
{
    n1->addNeighbour(n2->getNode());
    n2->addNeighbour(n1->getNode());
}

void Tree::removeEdge(ListAdj *n1, ListAdj *n2)
{
    n1->removeNeighbour(n2->getNode());
    n2->removeNeighbour(n1->getNode());
}

ListAdj Tree::getListFromNode(Node n)
{
    for(std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        if(((*it).getNode())==n){
            return (*it);
        }
    }
    return ListAdj(Node(-1));
}

bool Tree::isCyclicUtil(ListAdj lAdjV, bool visited[], ListAdj lAdjParent)
{
    // Mark the current node as visited
    int v = lAdjV.getNode().getId();

    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (std::list<Node>::iterator it=lAdjV.getNeighbours().begin(); it != lAdjV.getNeighbours().end(); ++it)
    {

        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[((*it).getId())])
        {
           if (isCyclicUtil(this->getListFromNode(*it), visited, lAdjV))
              return true;
        }

        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (!((*it)==(lAdjParent.getNode())))
           return true;
    }
    return false;
}

bool Tree::isCyclic()
{

    bool* visited = new bool[this->nbVerts];
    for(int i=0; i<this->nbVerts; i++)
        visited[i] = false;

    for (std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        if (!visited[(*it).getNode().getId()] && isCyclicUtil((*it), visited, ListAdj(Node(-1))))
        {
            return true;
        }
    }
    return false;
}

void Tree::display()
{
    std::cout << this->nbVerts << "\n";
    for (std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        (*it).display();
        std::cout << "\n";
    }
}

