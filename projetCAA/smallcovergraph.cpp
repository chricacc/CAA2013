#include <iostream>
#include<cstdlib>
#include<ctime>

#include "smallcovergraph.h"

SmallCoverGraph::SmallCoverGraph(int nbNode, int prob, int coverSize)
{
    this->nbVerts=0;
    for(int i=0; i<nbNode; i++)
    {
        Node n(i);
        addVert(n);
        if(i<coverSize)
            cover.push_back(n);
    }

    std::list<Node> done;
    for (std::list<Node>::iterator it=this->cover.begin(); it != this->cover.end(); ++it)
    {
        for (std::list<ListAdj>::iterator it2=listListAdj.begin(); it2 != listListAdj.end(); ++it2)
        {

            if((*it).getId() != (*it2).getNode().getId()){
                if((rand() % 100) < prob){
                    if(!isInList((*it2).getNode(), done)){
                        ListAdj* tmp = getListFromNode(*it);
                        addEdge(tmp, &(*it2));
                    }
                }
            }
            done.push_back((*it));
        }
    }

}

void SmallCoverGraph::display()
{
    Graph::display();
    std::cout<<"Cover : ";
    for (std::list<Node>::iterator it=this->cover.begin(); it != this->cover.end(); ++it)
    {
        std::cout<<(*it).getId()<<" ";
    }
    std::cout<<"\n";
}

ListAdj* SmallCoverGraph::getListFromNode(Node n)
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
