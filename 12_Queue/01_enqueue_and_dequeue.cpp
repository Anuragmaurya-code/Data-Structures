#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue();
        void enqueue(int x);
        int dequeue();
        void display();
};
Queue::Queue()
{
    cout<<"Enter the size of queue\n";
    cin>>size;
    Q=new int[size];
    front=rear=-1;
}

void Queue::enqueue(int x)
{
    if(rear==size-1)
        cout<<"Queue is full\n";
    else{
        ++rear;
        Q[rear]=x;

    }
}

int Queue::dequeue()
{
    int x=-1;
    if(front==rear)
        cout<<"Queue is Empty\n";
    else{
        ++front;
        x=Q[front];
    }
    return x;
}

void  Queue::display()
{
    int i=front+1;
    for(;i<=rear;i++)
        cout<<Q[i]<<" ";
    cout<<"\n";
}
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<"Deleted "<<q.dequeue()<<endl;
    q.display();
}