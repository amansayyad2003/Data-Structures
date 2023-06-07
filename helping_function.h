#define AVLTREE

#include "AVLTree.h"

node *adjust_bf(AVLTree t);
void LLrotate(AVLTree *at, node *A);
void LRrotate(AVLTree *at, node *A);
void RRrotate(AVLTree *at, node *A);
void RLrotate(AVLTree *at, node *A);
int height(node *t);
int max(int num1, int num2);
