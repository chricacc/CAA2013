#ifndef COVER_H
#define COVER_H

#include "tree.h"
#include "graph.h"
#include "bipart.h"


std::list<Node> coverTree(Tree *tree);
std::list<Node> coverGraph(Graph *graph);
std::list<Node> coverBipart(Bipart *bipart);

void sortTree(ListAdj current, std::list<Node> *goodList, std::list<Node> *wrongList, Tree *tree);

std::list<Tree> dfs(Graph *graph);
void sdfs(Graph *graph, ListAdj neighbours,std::list<Node> *visited, Tree *result );
/*
 *TODO :
 *
 *- Algorithme 2-approché pour des graphes quelconques qui couvre une arête puis élimine son voisinage (cf TD)
 *- Algorithme optimal paramétrique qui résout le problème pour les graphes ayant une petite couverture
 */
#endif // COVER_H
