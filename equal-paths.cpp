#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int pathLen(Node* n);


bool equalPaths(Node * root)
{
    // Add your code below
    return pathLen(root) != -1;
}

int pathLen(Node* n)
{
    if(n == nullptr) {
        return 0;
    }
    int l = pathLen(n->left);
    int r = pathLen(n->right);
    if(l == -1 || r == -1) {
        return -1;
    }
    if(n->left != nullptr && n->right != nullptr && l != r) {
        return -1;
    }
    return 1 + (l > r ? l : r);
}