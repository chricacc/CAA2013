#include <iostream>
#include<cstdlib>
#include<ctime>

#include "graph.h"
#include "bipart.h"
#include "tree.h"
#include "cover.h"
#include "smallcovergraph.h"

using namespace std;

int main(int argc, char *argv[])
{
    //initialisation de la fonction rand()
    srand(time(0));

    if (argc > 1) {
        //"-sat <graphfilename> <outputfilename>" to coverToSAT.
        if (string (argv[1]).compare("-sat") == 0) {
            Graph g(argv[2]);
            coverToSAT(&g,argv[3]);
            return 0;

        //"-cover <graphfilename>" to coverGraph.
        } else if (string (argv[1]).compare("-cover") == 0) {
            Graph g(argv[2]);
            ListAdj afficheGraph(Node(0), coverGraph(&g));
            afficheGraph.display();
            cout<<"\n";
            return 0;

        //"-postSATCover <inputfilename>" to salToCover
        }else if (string (argv[1]).compare("-postSATCover") == 0) {
            ListAdj cover(Node(0),satToCover(string (argv[2])));
            cover.display();
            cout<<"\n";
            return 0;
        }

    //jeu de test
    }else {
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

    cout<<"Graph from file g2 :\n";
    Graph g2("../dataTest/file_test_graph.gph");
    g2.display();
    cout<<"\n";

    cout<<"cover g1 :\n";
    ListAdj testGraph(Node(0), coverGraph(&g1));
    testGraph.display();
    cout<<"\n";

    cout<<"cover g2 :\n";
    ListAdj testGraph2(Node(0), coverGraph(&g2));
    testGraph2.display();
    cout<<"\n";

    cout<<"cover b1 :\n";
    ListAdj testBipart(Node(0), coverBipart(&b1));
    testBipart.display();
    cout<<"\n";

    cout<<"cover t1 :\n";
    ListAdj t1Cover(Node(0), coverTree(&t1));
    t1Cover.display();
    cout<<"\n";


    cout<<"Graph from file g3:\n";
    Graph g3("../dataTest/file_test_graph_non_connexe.gph");
    g3.display();
    cout<<"\n";

    cout<<"cover g3 :\n";
    ListAdj testGraph3(Node(0), coverGraph(&g3));
    testGraph3.display();
    cout<<"\n";

    cout<<"Graph from file g5 :\n";
    Graph g5("../dataTest/file_test_graph.gph");
    g5.display();
    cout<<"\n";

    cout<<"covertToSAT g5:\n";
    coverToSAT(&g5, "../dataTest/g5.minisat");
    cout<<"Done, run minisat on g5.minisat\n";
    cout<<"\n";

    cout<<"satToCover g6:\n";
    ListAdj testGraph6(Node(0),satToCover("../dataTest/g6.aftersat"));
    testGraph6.display();
    cout<<"\n";

    cout<<"satToCover g7:\n";
    ListAdj testGraph7(Node(0),satToCover("../dataTest/g7.aftersat"));
    testGraph7.display();
    cout<<"\n";
    return 0;
    }
}

