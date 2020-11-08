#include "../../library/commonUtils/AVLTree.h"
#include <stdio.h>

int main()
{
    AVLTree* tree = createAVLTree();
    printf("AVL tree created\n");

    addToAVLTree(tree, 12);
    printf("Number '12' added:\n");
    printAVLTreePreOrder(tree);

    addToAVLTree(tree, 7);
    printf("\nNumber '7' added:\n");
    printAVLTreePreOrder(tree);

    addToAVLTree(tree, 9);
    printf("\nNumber '9' added:\n");
    printAVLTreePreOrder(tree);

    addToAVLTree(tree, 15);
    printf("\nNumber '15' added:\n");
    printAVLTreePreOrder(tree);

    addToAVLTree(tree, 21);
    printf("\nNumber '21' added:\n");
    printAVLTreePreOrder(tree);

    addToAVLTree(tree, 1);
    printf("\nNumber '1' added:\n");
    printAVLTreePreOrder(tree);

    addToAVLTree(tree, -2);
    printf("\nNumber '-2' added:\n");
    printAVLTreePreOrder(tree);

    if (existsInAVLTree(tree, 12) && existsInAVLTree(tree, 7) && existsInAVLTree(tree, 9) && existsInAVLTree(tree, -2) && existsInAVLTree(tree, 1) && existsInAVLTree(tree, 21) && existsInAVLTree(tree, 15) && !existsInAVLTree(tree, 0)) {
        printf("\n'exists()' works fine\n");
    } else {
        printf("\nSomething went wrong with 'exists()'\n");
    }

    printf("\nYour tree also can de represented by in-order traversal:\n");
    printAVLTreeInOrder(tree);
    printf("\nOr by post-order traversal:\n");
    printAVLTreePostOrder(tree);

    removeFromAVLTree(tree, -2);
    printf("\nNumber '-2' removed:\n");
    printAVLTreePreOrder(tree);

    removeFromAVLTree(tree, 12);
    printf("\nNumber '12' removed:\n");
    printAVLTreePreOrder(tree);

    removeFromAVLTree(tree, 9);
    printf("\nNumber '9' removed:\n");
    printAVLTreePreOrder(tree);

    removeFromAVLTree(tree, 7);
    printf("\nNumber '7' removed:\n");
    printAVLTreePreOrder(tree);

    removeFromAVLTree(tree, 1);
    printf("\nNumber '1' removed:\n");
    printAVLTreePreOrder(tree);

    removeFromAVLTree(tree, 15);
    printf("\nNumber '15' removed:\n");
    printAVLTreePreOrder(tree);

    printf("\nYour tree also can de represented by in-order traversal:\n");
    printAVLTreeInOrder(tree);
    printf("\nOr by post-order traversal:\n");
    printAVLTreePostOrder(tree);
    removeFromAVLTree(tree, 21);
    printf("\nNumber '21' removed:\n");
    printAVLTreePreOrder(tree);

    freeAVLTree(tree);
    return 0;
}
