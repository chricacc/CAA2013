#include "edge.h"

Edge::Edge(Node n1, Node n2)
{
    this->n1 = n1;
    this->n2 = n2;
}

Node Edge::getFirstNode(){
    return this->n1;
}

Node Edge::getSecondNode(){
    return this->n2;
}

bool operator== (Edge e1, Edge e2)
{
    return (((e1.n1 == e2.n1)&&(e1.n2 == e2.n2)) || ((e1.n1 == e2.n2)&&(e1.n2==e2.n1)));
}

bool operator!= (Edge e1, Edge e2)
{
    return !(e1==e2);
}
