#ifndef SPBU_2020_C_HOMEWORKS_BST_H
#define SPBU_2020_C_HOMEWORKS_BST_H

#include <stdbool.h>

typedef struct BinarySearchTreeNode {
    int data;
    int counter;
    struct BinarySearchTreeNode* leftChild;
    struct BinarySearchTreeNode* rightChild;
} BinarySearchTreeNode;

typedef struct BinarySearchTree {
    BinarySearchTreeNode* root;
} BinarySearchTree;

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
