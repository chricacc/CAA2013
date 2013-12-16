#include "bipart.h"
#include<cstdlib>

//prob 0 - 100
Bipart::Bipart(int nbNode, int prob)
{
    this->nbVerts = nbNode;
    partLeft.push_back(ListAdj((Node(0))));
    partRight.push_back(ListAdj((Node(1))));
    for(int i=2; i < nbVerts; i++){
        Node n(i);
        addVert(n);
    }
    for (std::list<ListAdj>::iterator it=this->partLeft.begin(); it != this->partLeft.end(); ++it)
    {
        for (std::list<ListAdj>::iterator it2=this->partRight.begin(); it2 != this->partRight.end(); ++it2)
        {
            if(it != it2){
                if((rand() % 100) < prob){
                    addEdge(&(*it), &(*it2));
                }
            }
        }
    }

}

void Bipart::setBipartFromFile(std::string fileName)
{

}

void Bipart::addVert(Node node)
{
    if((rand() % 100) < 50){
        partLeft.push_back(ListAdj(node));
    }else{
        partRight.push_back(ListAdj(node));
    }
}

void Bipart::addEdge(ListAdj *n1, ListAdj *n2)
{
    n1->addNeighbour(n2->getNode());
    n2->addNeighbour(n1->getNode());
}

void Bipart::display()
{
    std::cout << this->nbVerts << "\n";
    for (std::list<ListAdj>::iterator it=this->partLeft.begin(); it != this->partLeft.end(); ++it)
    {
        (*it).display();
        std::cout << "\n";
    }

    for (std::list<ListAdj>::iterator it=this->partRight.begin(); it != this->partRight.end(); ++it)
    {
        (*it).display();
        std::cout << "\n";
    }
}

