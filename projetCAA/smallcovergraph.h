#ifndef SMALLCOVERGRAPH_H
#define SMALLCOVERGRAPH_H
#include "graph.h"

class SmallCoverGraph : public Graph
{
private:
    std::list<Node> cover;

public:
    SmallCoverGraph(int nbVerts, int proba, int coverSize);
    void display();
    ListAdj* getListFromNode(Node n);
};

#endif // SMALLCOVERGRAPH_H
