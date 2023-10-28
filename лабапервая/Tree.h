#pragma once

typedef struct NodeCBT {
    int value;
    struct NodeCBT* left;
    struct NodeCBT* right;
} NodeCBT;

NodeCBT* createCBT(int data);
NodeCBT* pushCBT(NodeCBT* root, int data);
NodeCBT* minimum(NodeCBT* root);
NodeCBT* popCBT(NodeCBT* root, int data);
void printCBT(NodeCBT* root);

