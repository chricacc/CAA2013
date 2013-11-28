#include <iostream>
#include "listadj.h"
using namespace std;

int main()
{
    Node n0(0);
    Node n1(1);
    Node n2(2);

    ListAdj l(n0);
    l.AddEdge(n1);
    l.AddEdge(n2);

    l.Display();

    return 0;
}

