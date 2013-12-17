#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node
{
private:
    int id;

public:
    Node();
    Node(int id);
    int getId();
    bool equals(Node node);

    friend bool operator== (Node n1, Node n2);
    friend bool operator!= (Node n1, Node n2);

};

#endif // NODE_H
