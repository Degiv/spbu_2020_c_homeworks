#include "AVLTree.h"

#include "../../library/commonUtils/BST.h"
#include <stdlib.h>

struct AVLTree {
    BinarySearchTree* bst;
};

AVLTree* createAVLTree()
{
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->bst = createBinarySearchTree();
}

bool isAVLEmpty(AVLTree* tree)
{
    return isEmpty(tree->bst);
}

bool addToAVLTree(AVLTree* tree, int valueToAdd)
{
    bool isNew = addToTree(tree->bst, valueToAdd);
    return isNew;
}

bool removeFromAVLTree(AVLTree* tree, int valueToRemove)
{
    bool wasFound = removeFromTree(tree->bst, valueToRemove);
    return wasFound;
}

int countInAVLTree(AVLTree* tree, int valueToSearch)
{
    return countInTree(tree->bst, valueToSearch);
}

bool existsInAVLTree(AVLTree* tree, int valueToSearch)
{
    return exists(tree->bst, valueToSearch);
}

void printAVLTreePreOrder(AVLTree* tree)
{
    printTreePreOrder(tree->bst);
}

void printAVLTreePostOrder(AVLTree* tree)
{
    printTreePostOrder(tree->bst);
}

void printAVLTreeInOrder(AVLTree* tree)
{
    printTreeInOrder(tree->bst);
}

void freeAVLTree(AVLTree* tree)
{
    freeTree(tree->bst);
    free(tree);
}
