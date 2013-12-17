#include <iostream>
#include<cstdlib>
#include<ctime>

#include "graph.h"
#include "bipart.h"
#include "tree.h"

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

    Tree t1(10);
    t1.display();
    cout<<"\n";

    return 0;
}

