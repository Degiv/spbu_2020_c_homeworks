#ifndef SPBU_2020_C_HOMEWORKS_AVLTREE_H
#define SPBU_2020_C_HOMEWORKS_AVLTREE_H

#include <stdbool.h>

typedef struct AVLTree AVLTree;

AVLTree* createAVLTree();

bool isAVLEmpty(AVLTree* tree);

bool addToAVLTree(AVLTree* tree, int valueToAdd);

bool removeFromAVLTree(AVLTree* tree, int valueToRemove);

int countInAVLTree(AVLTree* tree, int valueToSearch);

bool existsInAVLTree(AVLTree* tree, int valueToSearch);

void printAVLTreePreOrder(AVLTree* tree);

void printAVLTreePostOrder(AVLTree* tree);

void printAVLTreeInOrder(AVLTree* tree);

void freeAVLTree(AVLTree* tree);

#endif //SPBU_2020_C_HOMEWORKS_AVLTREE_H
