#include "graph.h"


Graph::Graph()
{
    this->nbVerts = 0;
}

void Graph::setGraphFromFile(std::string fileName)
{

}

void Graph::addVert(Node node)
{

}

void Graph::addEdge(Node origin, Node dest)
{

}

void Graph::Display()
{
    std::cout << this->nbVerts << "\n";
    for (std::list<ListAdj>::iterator it=this->listAdj.begin(); it != this->listAdj.end(); ++it)
    {
        (*it).Display();
        std::cout << "\n";
    }
}
