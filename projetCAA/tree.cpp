#include<cstdlib>
#include<ctime>
#include<list>
#include "tree.h"

Tree::Tree(){
    nbVerts = 0;
}

Tree::Tree(int nbNode)
{
    nbVerts = 0;
    for(int i=0; i<nbNode; i++)
    {
        Node n(i);
        addVert(n);

        int rdNodeId = rand()%nbVerts;
        while((nbVerts>1) && (rdNodeId==i))
            rdNodeId = rand()%nbVerts;

        ListAdj* Lrd = getListFromNode(Node(rdNodeId));
        ListAdj* Ln = getListFromNode(n);

        if((*Lrd).getNode() != n)
            addEdge(Lrd, Ln);

    }
}



Tree::Tree(std::string fileName)
{

}

void Tree::addVert(Node node)
{
    listListAdj.push_back(ListAdj(node));
    nbVerts += 1;
}

void Tree::addEdge(ListAdj *n1, ListAdj *n2)
{
    n1->addNeighbour(n2->getNode());
}

void Tree::removeEdge(ListAdj *n1, ListAdj *n2)
{
    n1->removeNeighbour(n2->getNode());
}

ListAdj* Tree::getListFromNode(Node n)
{
    for(std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        if(((*it).getNode())==n){
            return &(*it);
        }
    }
    ListAdj resFault = ListAdj(Node(-1));
    return &resFault;
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

