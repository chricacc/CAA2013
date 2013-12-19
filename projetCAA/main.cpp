#include <iostream>
#include<cstdlib>
#include<ctime>

#include "graph.h"
#include "bipart.h"
#include "tree.h"
#include "cover.h"
#include "smallcovergraph.h"

using namespace std;

int main()
{
    //initialisation de la fonction rand()
    srand(time(0));

    Graph g1(5, 50);
    g1.display();
    cout<<"\n";

    Bipart b1(6,50);
    b1.display();
    cout<<"\n";

    Tree t1(5);
    t1.display();
    cout<<"\n";
/*
    ListAdj testGraph(Node(0), coverGraph(&g1));
    testGraph.display();
    cout<<"\n";
*/
    ListAdj testBipart(Node(0), coverBipart(&b1));
    testBipart.display();
    cout<<"\n";

    ListAdj t1Cover(Node(0), coverTree(&t1));
    t1Cover.display();
    cout<<"\n";

    SmallCoverGraph smCovGph(5, 50, 2);
    smCovGph.display();

    return 0;
}

