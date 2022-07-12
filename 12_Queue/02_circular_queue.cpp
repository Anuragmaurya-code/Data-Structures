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
    size++;
    Q=new int[size];
    front=rear=0;
}

void Queue::enqueue(int x)
{
    if((rear+1)%size==front)
        cout<<"Queue is full\n";
    else{
        rear=(rear+1)%size;
        Q[rear]=x;

    }
}

int Queue::dequeue()
{
    int x=-1;
    if(front==rear)
        cout<<"Queue is full\n";
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

void  Queue::display()
{
    int i=front+1;
    do{
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
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
    q.enqueue(67);
    q.display();
}