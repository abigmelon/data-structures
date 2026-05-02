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
}  * Node;

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}

Node insert(Node root, E element) {
    if (root) {
        if (root->element > element) {  //小于当前节点就放到左边
            root->left = insert(root->left, element);
        } else if (root->element < element) {   //大于当前节点就放到右边
            root->right = insert(root->right, element);
        }
    } else {    //节点为空说明走到最底下了，可以放置这个数据了
        root = createNode(element);
    }
    return root;
}

void inOrder(Node root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->element);
    inOrder(root->right);
}   //中序遍历

Node find(Node root, E target) {
    while (root) {
        if (root->element > target) root = root->left;
        else if (root->element < target) root = root->right;
        else return root;
    }
    return NULL;
}

Node findMax(Node root) {
    while (root && root->right) root = root->right;
    return root;    //只要一直往右跑就可以了
}

Node delete(Node root, E target){
    if(root == NULL) return NULL;   //都走到底了还是没有找到要删除的结点，说明没有，直接返回空
    if(root->element > target)   //这里的判断跟之前插入是一样的，继续往后找就完事，直到找到为止
        root->left = delete(root->left, target);
    else if(root->element < target)
        root->right = delete(root->right, target);
    else {   //这种情况就是找到了
        if(root->left && root->right) {   //先处理最麻烦的左右孩子都有的情况
            Node max = findMax(root->left);  //寻找左子树中最大的元素
            root->element = max->element;  //找到后将值替换
            root->left = delete(root->left, root->element);  //替换好后，以同样的方式去删除那个替换上来的结点
        } else {   //其他两种情况可以一起处理，只需要删除这个结点就行，然后将root指定为其中一个孩子，最后返回就完事
            Node tmp = root;
            if(root->right) {   //不是左边就是右边
                root = root->right;
            } else {
                root = root->left;
            }
            free(tmp);   //开删
        }
    }
    return root;   //返回最终的结点
}

int main(){
    Node root = NULL;
    while (1) {
        E element;
        scanf("%d", &element);
        root = insert(root, element);
        inOrder(root);
        putchar('\n');
    }   //直接写成扫描的方式
}