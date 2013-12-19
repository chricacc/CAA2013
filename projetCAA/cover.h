#ifndef COVER_H
#define COVER_H

#include "tree.h"
#include "graph.h"
#include "bipart.h"

extern std::list<Node> vertBlack;
extern std::list<Node> vertWhite;

std::list<Node> coverTree(Tree *tree);
std::list<Node> coverGraph(Graph *graph);
std::list<Node> coverBipart(Bipart *bipart);

void sortTree(ListAdj current, std::list<Node> *goodList, std::list<Node> *wrongList, Tree *tree);

Tree dfs(Graph *graph);
void sdfs(Graph *graph, ListAdj neighbours,std::list<Node> *visited, Tree *result );

#endif // COVER_H
