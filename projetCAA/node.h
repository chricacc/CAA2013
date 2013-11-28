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

};

#endif // NODE_H
