//
// Created by 63092 on 2026/4/2.
//

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int flag;
};

typedef struct TreeNode * Node;

//--------------- 队列 ----------------
typedef Node T;   //还是将Node作为元素

struct QueueNode {
    T element;
    struct QueueNode * next;
};

typedef struct QueueNode * QNode;

struct Queue{
    QNode front, rear;
};

typedef struct Queue * LinkedQueue;

_Bool initQueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isEmpty(LinkedQueue queue){
    return queue->front == queue->rear;
}

T pollQueue(LinkedQueue queue){
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}
//--------------------------------

void levelOrder(Node root){
    struct Queue queue;   //先搞一个队列
    initQueue(&queue);
    offerQueue(&queue, root);  //先把根节点入队
    while (!isEmpty(&queue)) {   //不断重复，直到队列空为止
        Node node = pollQueue(&queue);   //出队一个元素，打印值
        printf("%c", node->element);
        if(node->left)    //如果存在左右孩子的话
            offerQueue(&queue, node->left);  //记得将左右孩子入队，注意顺序，先左后右
        if(node->right)
            offerQueue(&queue, node->right);
    }
}
