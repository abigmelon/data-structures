//
// Created by 63092 on 2026/4/12.
//

#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct TreeNode {
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
}  * Node;

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node root) {
    if (root == NULL) return 0;
    return root->height;
}

Node leftRotation(Node root) {
    Node newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

Node rightRotation(Node root) {
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

Node leftRightRotation(Node root){
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node rightLeftRotation(Node root){
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node insert(Node root, E element){
    if(root == NULL) {    //如果结点为NULL，说明找到了插入位置，直接创建新的就完事
        root = createNode(element);
    }else if(root->element > element) {   //和二叉搜索树一样，判断大小，该走哪边走哪边，直到找到对应插入位置
        root->left = insert(root->left, element);
        if(getHeight(root->left) - getHeight(root->right) > 1) {   //插入完成之后，需要计算平衡因子，看看是否失衡
            if(root->left->element > element) //接着需要判断一下是插入了左子树的左边还是右边，如果是左边那边说明是LL，如果是右边那说明是LR
                root = rightRotation(root);   //LL型得到左旋之后的结果，得到新的根结点
            else
                root = leftRightRotation(root);    //LR型得到先左旋再右旋之后的结果，得到新的根结点
        }
    }else if(root->element < element){
        root->right = insert(root->right, element);
        if(getHeight(root->left) - getHeight(root->right) < -1){
            if(root->right->element < element)
                root = leftRotation(root);
            else
                root = rightLeftRotation(root);
        }
    }
    //前面的操作完成之后记得更新一下树高度
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;  //最后返回root到上一级
}
