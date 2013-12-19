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

    cout<<"Graph g1 :\n";
    Graph g1(5, 20);
    g1.display();
    cout<<"\n";

    cout<<"Graph b1 :\n";
    Bipart b1(6,50);
    b1.display();
    cout<<"\n";

    cout<<"Graph t1 :\n";
    Tree t1(5);
    t1.display();
    cout<<"\n";

    cout<<"Graph smc1 :\n";
    SmallCoverGraph smCovGph(5, 50, 2);
    smCovGph.display();
    cout<<"\n";

    cout<<"cover g1 :\n";
    ListAdj testGraph(Node(0), coverGraph(&g1));
    testGraph.display();
    cout<<"\n";

    cout<<"cover b1 :\n";
    ListAdj testBipart(Node(0), coverBipart(&b1));
    testBipart.display();
    cout<<"\n";

    cout<<"cover t1 :\n";
    ListAdj t1Cover(Node(0), coverTree(&t1));
    t1Cover.display();
    cout<<"\n";


    return 0;
}

