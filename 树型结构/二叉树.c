//
// Created by 63092 on 2026/3/31.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode *Node;

void preOrder(Node root){
    if (root == NULL) return;
    printf("%c", root->element);
    preOrder(root->left);
    preOrder(root->right);
}   //前序遍历的递归写法

void inOrder(Node root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%c", root->element);
    inOrder(root->right);
}   //中序遍历的递归写法

void postOrder(Node root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->element);   //时机延迟到最后
}   //后序遍历的递归写法

int main(){
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;

    d->left = NULL;
    d->right = NULL;
    e->left = NULL;
    e->right = NULL;
    f->left = NULL;
    f->right = NULL;

    preOrder(a);
    return 0;
}
