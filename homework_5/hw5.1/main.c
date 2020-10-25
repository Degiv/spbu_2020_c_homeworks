#include "../../library/commonUtils/BST.h"
#include <stdio.h>

int main()
{
    BinarySearchTree* tree = createBinarySearchTree();
    printf("Binary search tree created\n");

    addToTree(tree, 12);
    printf("Number '12' added:\n");
    printTreePreOrder(tree);

    addToTree(tree, 7);
    printf("\nNumber '7' added:\n");
    printTreePreOrder(tree);

    addToTree(tree, 9);
    printf("\nNumber '9' added:\n");
    printTreePreOrder(tree);

    addToTree(tree, 15);
    printf("\nNumber '15' added:\n");
    printTreePreOrder(tree);

    addToTree(tree, 21);
    printf("\nNumber '21' added:\n");
    printTreePreOrder(tree);

    addToTree(tree, 1);
    printf("\nNumber '1' added:\n");
    printTreePreOrder(tree);

    addToTree(tree, -2);
    printf("\nNumber '-2' added:\n");
    printTreePreOrder(tree);

    if (exists(tree, 12) && exists(tree, 7) && exists(tree, 9) && exists(tree, -2) && exists(tree, 1)
    && exists(tree, 21) && exists(tree, 15) && !exists(tree, 0)) {
        printf("\n'exists()' works fine\n");
    } else {
        printf("\nSomething went wrong with 'exists()'\n");
    }

    removeFromTree(tree, -2);
    printf("\nNumber '-2' removed:\n");
    printTreePreOrder(tree);

    removeFromTree(tree, 12);
    printf("\nNumber '12' removed:\n");
    printTreePreOrder(tree);

    removeFromTree(tree, 15);
    printf("\nNumber '15' removed:\n");
    printTreePreOrder(tree);

    printf("\nYour tree also can de represented by in-order traversal:\n");
    printTreeInOrder(tree);
    printf("\nOr by post-order traversal:\n");
    printTreePostOrder(tree);

    freeTree(tree);
    return 0;
}
