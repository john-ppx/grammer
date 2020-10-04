//
// Created by Rainy ZHAO on 2020/10/3.
//

#include <stdlib.h>
#include "TreeNode.h"
#define FAILED NULL
//typedef struct Node* Tree;
//struct Node{
//    char label;
//    Tree leftchild, middlechild, rightchild;
//};
Tree makeNode0(char x){
    Tree root;
    root = (Tree) malloc(sizeof(struct Node));
    root->label=x;
    root->leftchild=NULL;
    root->middlechild=NULL;
    root->rightchild=NULL;
    return root;
}

Tree makeNode1(char x, Tree t){
    Tree root;
    root=makeNode0(x);
    root->leftchild=t;
    return root;
}

Tree makeNode2(char x, Tree t1, Tree t2){
    Tree root;
    root=makeNode0(x);
    root->leftchild=t1;
    root->rightchild=t2;
    return root;
}

Tree makeNode3(char x, Tree t1, Tree t2, Tree t3){
    Tree root;
    root=makeNode0(x);
    root->leftchild=t1;
    root->middlechild=t2;
    root->rightchild=t3;
    return root;
}