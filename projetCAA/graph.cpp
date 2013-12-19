#include<cstdlib>
#include<ctime>
#include<fstream>
#include<tuple>
#include "graph.h"
#include "tools.h"

Graph::Graph(){}

Graph::Graph(int nbNode, int prob)
{
    this->nbVerts = 0;
    this->nbEdges = 0;

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
    std::ifstream flux(fileName.c_str(), std::ios::in);
    if(flux){
        this->nbEdges = 0;
        std::string line;
        std::getline(flux, line);
        this->nbVerts = atoi(line.c_str());
        for(int i=0; i < this->nbVerts; i++){
            std::getline(flux, line);
            std::vector<std::string> vLine = split(line, ':');
            Node node(atoi(vLine[0].c_str()));
            std::vector<std::string> vNeighbours = split(vLine[1], ' ');
            std::list<Node> listNeighbours;

            std::list<std::tuple<Node,Node>> listEdges;

            for(std::vector<std::string>::iterator idNeighbour=vNeighbours.begin(); idNeighbour!=vNeighbours.end(); ++idNeighbour)
            {
                Node n(atoi((*idNeighbour).c_str()));
                listNeighbours.push_back(n);
                /*
                 *if(!listEdges.contains(tuple(n,node))
                 *  nbEdges+1;
                 *  listEdges.add(tuple(n,node));
                 */

            }


            this->listListAdj.push_back(ListAdj(node, listNeighbours));
        }

        flux.close();
    }else{
        std::cerr << "file not found" << std::endl;
    }
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
    nbEdges++;
}

std::list<ListAdj> Graph::getLists(){
    return this->listListAdj;
}

ListAdj* Graph::getListFromNode(Node n){
    for(std::list<ListAdj>::iterator it=this->listListAdj.begin(); it != this->listListAdj.end(); ++it)
    {
        if(((*it).getNode())==n){
            return &(*it);
        }
    }
    ListAdj resFault = ListAdj(Node(-1));
    return &resFault;
}

int Graph::getNbVerts(){
    return nbVerts;
}

int Graph::getNbEdges(){
    return nbEdges;
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
