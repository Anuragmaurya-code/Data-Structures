class Queue
{
    private:
        int size;
        int front=-1;
        int rear=-1;
        Node  **Q;
    public:
        Queue();
        void enqueue(Node* x);
        Node* dequeue();
        int isEmpty();
};
Queue::Queue()
{
    size=100;
    Q=new Node*[size];
    front=rear=-1;
}

void Queue::enqueue(Node *x)
{
    if(rear==size-1)
        cout<<"Queue is full\n";
    else {
        ++rear;
        Q[rear]=x;

    }
}

Node *Queue::dequeue()
{
    Node *x=NULL;
    if(front==rear)
        cout<<"Queue is Empty\n";
    else{
        ++front;
        x=Q[front];
    }
    return x;
}

int Queue::isEmpty()
{
    return front==rear;
}
