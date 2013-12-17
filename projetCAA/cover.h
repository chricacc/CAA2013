#ifndef COVER_H
#define COVER_H

#include "tree.h"

extern std::list<Node> vertBlack;
extern std::list<Node> vertWhite;

std::list<Node> coverTree(Tree *tree);

void sortTree(ListAdj current, std::list<Node> *goodList, std::list<Node> *wrongList, Tree *tree);

#endif // COVER_H
