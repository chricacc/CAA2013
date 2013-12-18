#include<cstdlib>
#include<ctime>

#include "graph.h"


Graph::Graph(){}

Graph::Graph(int nbNode, int prob)
{
    this->nbVerts = 0;
    for(int i=0; i < nbNode; i++){
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
                    }
                }
            }
            done.push_back((*it).getNode());
        }
    }

}

Graph::Graph(std::string fileName)
{

}

void Graph::addVert(Node node)
{
    listListAdj.push_back(ListAdj(node));
    this->nbVerts += 1;
}

void Graph::addEdge(ListAdj *n1, ListAdj *n2)
{
    n1->addNeighbour(n2->getNode());
    n2->addNeighbour(n1->getNode());
}

void Graph::display()
{
    std::cout << this->nbVerts << "\n";
    for (std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        (*it).display();
        std::cout << "\n";
    }
}
