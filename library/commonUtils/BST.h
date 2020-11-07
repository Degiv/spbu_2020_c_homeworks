#ifndef SPBU_2020_C_HOMEWORKS_BST_H
#define SPBU_2020_C_HOMEWORKS_BST_H

#include <stdbool.h>

typedef struct BinarySearchTreeNode BinarySearchTreeNode;

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createBinarySearchTree();

bool isEmpty(BinarySearchTree* tree);

bool addToTree(BinarySearchTree* tree, int valueToAdd);

bool removeFromTree(BinarySearchTree* tree, int valueToRemove);

int countInTree(BinarySearchTree* tree, int valueToSearch);

bool exists(BinarySearchTree* tree, int valueToSearch);

void printTreePreOrder(BinarySearchTree* tree);

void printTreePostOrder(BinarySearchTree* tree);

void printTreeInOrder(BinarySearchTree* tree);

void freeTree(BinarySearchTree* tree);

#endif //SPBU_2020_C_HOMEWORKS_BST_H
