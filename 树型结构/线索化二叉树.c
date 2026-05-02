//
// Created by 63092 on 2026/4/7.
//

#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int leftTag, rightTag;
} * Node;

Node createNode(E element){   //单独写了个函数来创建结点
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;  //这里我们需要一个pre来保存后续结点的指向

void preOrderThreaded(Node root){   //前序遍历线索化函数
    if(root == NULL) return;

    if(root->left == NULL) {   //首先判断当前结点左边是否为NULL，如果是，那么指向上一个结点
        root->left = pre;
        root->leftTag = 1;  //记得修改标记
    }
    if(pre && pre->right == NULL) {  //然后是判断上一个结点的右边是否为NULL，如果是那么进行线索化，指向当前结点
        pre->right = root;
        pre->rightTag = 1;  //记得修改标记
    }

    pre = root;   //每遍历完一个，需要更新一下pre，表示上一个遍历的结点

    if(root->leftTag == 0)   //注意只有标志位是0才可以继续向下，否则就是线索了
        preOrderThreaded(root->left);
    if(root->rightTag == 0)
        preOrderThreaded(root->right);
}

void preOrder(Node root){  //前序遍历一棵线索化二叉树非常简单
    while (root) {   //到头为止
        printf("%c", root->element);   //因为是前序遍历，所以直接按顺序打印就行了
        if(root->leftTag == 0)
            root = root->left;   //如果是左孩子，那么就走左边
        else
            root = root->right;   //如果左边指向的不是孩子，而是线索，那么就直接走右边，因为右边无论是线索还是孩子，都要往这边走了
    }
}


int main() {
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');

    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;

    preOrderThreaded(a);
    preOrder(a);

    return 0;
}
