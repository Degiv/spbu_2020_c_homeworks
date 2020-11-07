#include "BST.h"
#include "AVLTree.h"

#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTreeNode {
    int data;
    int counter;
    struct BinarySearchTreeNode* leftChild;
    struct BinarySearchTreeNode* rightChild;
};

struct BinarySearchTree {
    BinarySearchTreeNode* root;
};

BinarySearchTreeNode* createBinarySearchTreeNode(int data)
{
    BinarySearchTreeNode* node = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    node->data = data;
    node->counter = 1;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

BinarySearchTree* createBinarySearchTree()
{
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    tree->root = NULL;
    return tree;
}

bool isLeaf(BinarySearchTreeNode* node)
{
    return node->rightChild == NULL && node->leftChild == NULL;
}

bool isEmpty(BinarySearchTree* tree)
{
    return tree->root == NULL;
}

bool addToTreeRecursive(BinarySearchTreeNode** current, int valueToAdd)
{
    if ((*current) == NULL) {
        (*current) = createBinarySearchTreeNode(valueToAdd);
        return true;
    }

    if ((*current)->data == valueToAdd) {
        (*current)->counter++;
        return false;
    }

    if ((*current)->data > valueToAdd) {
        return addToTreeRecursive(&((*current)->leftChild), valueToAdd);
    }

    if ((*current)->data < valueToAdd) {
        return addToTreeRecursive(&((*current)->rightChild), valueToAdd);
    }
}

bool addToTree(BinarySearchTree* tree, int valueToAdd)
{
    return addToTreeRecursive(&(tree->root), valueToAdd);
}

void removeIncompleteNode(BinarySearchTreeNode** nodeToRemove, BinarySearchTreeNode* newPtr)
{
    free(*nodeToRemove);
    *nodeToRemove = newPtr;
}

void removeNode(BinarySearchTreeNode** nodeToRemove);

void removeCompleteNode(BinarySearchTreeNode** nodeToRemove)
{
    BinarySearchTreeNode** nodeForReplace = &((*nodeToRemove)->leftChild);
    while ((*nodeForReplace)->rightChild != NULL) {
        *nodeForReplace = (*nodeForReplace)->rightChild;
    }
    (*nodeToRemove)->data = (*nodeForReplace)->data;
    (*nodeToRemove)->counter = (*nodeForReplace)->counter;
    removeNode(nodeForReplace);
}

void removeNode(BinarySearchTreeNode** nodeToRemove)
{
    if (isLeaf(*nodeToRemove)) {
        removeIncompleteNode(nodeToRemove, NULL);
        return;
    }

    if ((*nodeToRemove)->leftChild == NULL) {
        removeIncompleteNode(nodeToRemove, (*nodeToRemove)->rightChild);
        return;
    }

    if ((*nodeToRemove)->rightChild == NULL) {
        removeIncompleteNode(nodeToRemove, (*nodeToRemove)->leftChild);
        return;
    }

    removeCompleteNode(nodeToRemove);
}

bool removeFromTreeRecursive(BinarySearchTreeNode** current, int valueToRemove)
{
    if ((*current) == NULL) {
        return false;
    }

    if ((*current)->data == valueToRemove) {
        (*current)->counter--;
        if ((*current)->counter == 0) {
            removeNode(current);
        }
        return true;
    }

    if ((*current)->data > valueToRemove) {
        return removeFromTreeRecursive(&((*current)->leftChild), valueToRemove);
    }

    if ((*current)->data < valueToRemove) {
        return removeFromTreeRecursive(&((*current)->rightChild), valueToRemove);
    }
}

bool removeFromTree(BinarySearchTree* tree, int valueToRemove)
{
    return removeFromTreeRecursive(&(tree->root), valueToRemove);
}

int countInTreeRecursive(BinarySearchTreeNode* current, int valueToSearch)
{
    if (current == NULL) {
        return 0;
    }

    if (current->data == valueToSearch) {
        return current->counter;
    }

    if (current->data > valueToSearch) {
        return countInTreeRecursive(current->leftChild, valueToSearch);
    }

    if (current->data < valueToSearch) {
        return countInTreeRecursive(current->rightChild, valueToSearch);
    }
}

int countInTree(BinarySearchTree* tree, int valueToSearch)
{
    return countInTreeRecursive(tree->root, valueToSearch);
}

bool exists(BinarySearchTree* tree, int valueToSearch)
{
    return countInTree(tree, valueToSearch) > 0;
}

void printTreePreOrderRecursive(BinarySearchTreeNode* current)
{
    printf("(%d ", current->data);

    if (current->leftChild != NULL) {
        printTreePreOrderRecursive(current->leftChild);
    } else {
        printf("null");
    }
    printf(" ");
    if (current->rightChild != NULL) {
        printTreePreOrderRecursive(current->rightChild);
    } else {
        printf("null");
    }
    printf(")");
}

void printTreePreOrder(BinarySearchTree* tree)
{
    if (!isEmpty(tree)) {
        printTreePreOrderRecursive(tree->root);
    }
    printf("\n");
}

void printTreePostOrderRecursive(BinarySearchTreeNode* current)
{
    printf("(");

    if (current->leftChild != NULL) {
        printTreePostOrderRecursive(current->leftChild);
    } else {
        printf("null");
    }
    printf(" ");
    if (current->rightChild != NULL) {
        printTreePostOrderRecursive(current->rightChild);
    } else {
        printf("null");
    }

    printf(" %d)", current->data);
}

void printTreePostOrder(BinarySearchTree* tree)
{
    if (!isEmpty(tree)) {
        printTreePostOrderRecursive(tree->root);
    }
    printf("\n");
}

void printTreeInOrderRecursive(BinarySearchTreeNode* current)
{
    printf("(");
    if (current->leftChild != NULL) {
        printTreeInOrderRecursive(current->leftChild);
    } else {
        printf("null");
    }

    printf(" %d ", current->data);

    if (current->rightChild != NULL) {
        printTreeInOrderRecursive(current->rightChild);
    } else {
        printf("null");
    }
    printf(")");
}

void printTreeInOrder(BinarySearchTree* tree)
{
    if (!isEmpty(tree)) {
        printTreeInOrderRecursive(tree->root);
    }
    printf("\n");
}

void freeTreeRecursive(BinarySearchTreeNode* current)
{
    if (current->leftChild != NULL) {
        freeTreeRecursive(current->leftChild);
    }
    if (current->rightChild != NULL) {
        freeTreeRecursive(current->rightChild);
    }
    free(current);
}

void freeTree(BinarySearchTree* tree)
{
    if (!isEmpty(tree)) {
        freeTreeRecursive(tree->root);
    }
    free(tree);
}


//AVL tree

struct AVLTree {
    BinarySearchTree* binarySearchTree;
};

AVLTree* createAVLTree()
{
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->binarySearchTree = createBinarySearchTree();
}

bool isAVLEmpty(AVLTree* tree)
{
    return isEmpty(tree->binarySearchTree);
}

bool addToAVLTree(AVLTree* tree, int valueToAdd)
{
    bool isNew = addToTree(tree->binarySearchTree, valueToAdd);
    return isNew;
}

bool removeFromAVLTree(AVLTree* tree, int valueToRemove)
{
    bool wasRemoved = removeFromTree(tree->binarySearchTree, valueToRemove);
    return wasRemoved;
}

int countInAVLTree(AVLTree* tree, int valueToSearch)
{
    return countInTree(tree->binarySearchTree, valueToSearch);
}

bool existsInAVLTree(AVLTree* tree, int valueToSearch)
{
    return exists(tree->binarySearchTree, valueToSearch);
}

void printAVLTreePreOrder(AVLTree* tree)
{
    printTreePreOrder(tree->binarySearchTree);
}

void printAVLTreePostOrder(AVLTree* tree)
{
    printTreePostOrder(tree->binarySearchTree);
}

void printAVLTreeInOrder(AVLTree* tree)
{
    printTreeInOrder(tree->binarySearchTree);
}

void freeAVLTree(AVLTree* tree)
{
    freeTree(tree->binarySearchTree);
    free(tree);
}

