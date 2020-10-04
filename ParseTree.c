//
// Created by Rainy ZHAO on 2020/10/3.
//

/*
 * char *input: the input string that is tested if it is part of the grammar
 * We need to determine whether the tree is part of the grammar and return the parse tree if it is.
 */
#include "TreeNode.h"
#include "ParseTree.h"
#include <stdlib.h>
#include <stdio.h>
#define FAILED NULL;

static char* lookForward;

Tree ParseTree(char *input){
    lookForward=input;
    Tree tree=E();
    if (*lookForward!='\0'){
        return FAILED;
    }
    return tree;
}

Tree E(){
    Tree c=C();
    if (c!=FAILED){
        Tree et = ET();
        if (et == FAILED){
            return FAILED;
        }
        else return makeNode2('E', c, et);
    }
    else return FAILED;
}

Tree ET(){
    if (*lookForward=='|'){
        char ch=*lookForward++;

        Tree e=E();

//        if (*lookForward=='%'){
//            printf("%c", ch);
//        }
        if (e==FAILED){
            return FAILED;
        }
        else return makeNode2('ET', makeNode0('|'), e);
    }
    else return makeNode1('ET', makeNode0('eps'));
}

Tree C(){
    Tree s=S();
    if (s==FAILED){
        return FAILED;
    }
    Tree ct=CT();
    if (ct==FAILED){
        return FAILED;
    }
    return makeNode2('C', s, ct);
}

Tree CT(){
    if (*lookForward=='.'){
        char ch=lookForward++;
//        if (*lookForward=='%'){
//            printf("%c", ch);
//        }
        Tree c=C();
        if (c!=FAILED){
            return makeNode2('CT', makeNode0('.'), c);
        }
        else return FAILED;
    }
    else return makeNode1('CT', makeNode0('eps'));
}

Tree S(){
    Tree a=A();
    if (A==FAILED){
        return FAILED;
    }
    Tree st=ST();
    if (st==FAILED){
        return FAILED;
    }
    return makeNode2('S', a, st);
}

Tree ST(){
    if (*lookForward=='*'){
        char ch=*lookForward++;
        Tree st=ST();
        if (st==FAILED){
            return FAILED;
        }
        else return makeNode2('ST', makeNode0('*'), st);
    }
    else return makeNode1('ST', makeNode0('eps'));
}

Tree A(){
    if (*lookForward=='('){
        char ch=*lookForward++;
        Tree e=E();
        if (e!=FAILED && *lookForward==')'){
            return makeNode3('A', makeNode0('('), e, makeNode0(')'));
        }
        else return FAILED;
    }
    else{
        Tree x=X();
        if (x==FAILED){
            return FAILED;
        }
        else return makeNode1('A', x);
    }
}

Tree X(){
    if (*lookForward=='a' || *lookForward=='b' || *lookForward=='c' || *lookForward=='d' || *lookForward=='e' ||
            *lookForward=='f' || *lookForward=='g' || *lookForward=='h' || *lookForward=='i' || *lookForward=='j' ||
            *lookForward=='k' || *lookForward=='l' || *lookForward=='m' || *lookForward=='n' || *lookForward=='o' ||
            *lookForward=='p' || *lookForward=='q' || *lookForward=='r' || *lookForward=='s' || *lookForward=='t' ||
            *lookForward=='u' || *lookForward=='v' || *lookForward=='w' || *lookForward=='x' || *lookForward=='y' ||
            *lookForward=='z'){
        Tree leaf=makeNode1('X', makeNode0(*lookForward));
        char ch=*lookForward++;
        return leaf;
    }
    else return FAILED;
}

