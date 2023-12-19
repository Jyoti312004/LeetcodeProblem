
//  Queue using Stacks
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct {
    node* front;
    node* rear;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    if(obj->rear == NULL){
        obj->front = obj->rear = newNode;
        return;
    }

    obj->rear->next = newNode;
    obj->rear = newNode;
}

int myQueuePop(MyQueue* obj) {
    if(obj->front == NULL){
        return -1;
    }
    int data = obj->front->data;
    node* temp = obj->front;
    obj->front = obj->front->next;

    if(obj->front == NULL){
        obj->rear = NULL;
    }

    free(temp);
    return data;
    
}

int myQueuePeek(MyQueue* obj) {
    return obj->front ? obj->front->data : -1;
    
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front == NULL;
}

void myQueueFree(MyQueue* obj) {
    while(obj->front){
        node* temp = obj->front;
        obj->front = obj->front->next;
        free(temp);
    }

    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
