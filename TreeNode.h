//
// Created by Rainy ZHAO on 2020/10/3.
//

#ifndef UNTITLED2_TREENODE_H
#define UNTITLED2_TREENODE_H

typedef struct Node* Tree;
struct Node{
    char label;
    Tree leftchild, middlechild, rightchild;
};
Tree makeNode0(char x);
Tree makeNode1(char x, Tree t);
Tree makeNode2(char x, Tree t1, Tree t2);
Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);
//Tree makeNode4(char x, Tree t1, Tree t2, Tree t3, Tree t4);

#endif //UNTITLED2_TREENODE_H
