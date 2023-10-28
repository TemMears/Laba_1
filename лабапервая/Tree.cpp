#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

NodeCBT* createCBT(int data) { //„ƒ„€„x„t„p„v„} „t„u„‚„u„r„€
    NodeCBT* newNode = (NodeCBT*)malloc(sizeof(NodeCBT));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NodeCBT* pushCBT(NodeCBT* Tree, int data) {
    if (Tree == NULL) //„u„ƒ„|„y „x„~„p„‰„u„~„y„‘ „~„u„„ „r „{„€„‚„~„u, „„„€ „t„€„q„p„r„|„‘„u„}
        return createCBT(data);
    if (data <= Tree->value)
        Tree->left = pushCBT(Tree->left, data);
    else
        Tree->right = pushCBT(Tree->right, data);
    return Tree;
}

NodeCBT* minimum(NodeCBT* Tree) {
    if (Tree->left != NULL)
    {
        Tree = Tree->left;
    }
    return Tree;
}

NodeCBT* popCBT(NodeCBT* Tree, int data) {
    if (Tree == NULL) {
        return Tree;
    }
    if (data < Tree->value)
        Tree->left = popCBT(Tree->left, data);
    else if (data > Tree->value)
        Tree->right = popCBT(Tree->right, data);
    else {

        if (Tree->left == NULL) {
            NodeCBT* temp = Tree->right;
            free(Tree);
            return temp;
        }
        else if (Tree->right == NULL) {
            NodeCBT* temp = Tree->left;
            free(Tree);
            return temp;
        }
        NodeCBT* temp = minimum(Tree->right);
        Tree->value = temp->value;
        Tree->right = popCBT(Tree->right, temp->value);
    }
    return Tree;
}

void printCBT(NodeCBT* Tree) {
    if (Tree == NULL)
    {
        return;
    }
    printf("%d ", Tree->value);
    printCBT(Tree->left);
    printCBT(Tree->right);
}

