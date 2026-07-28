#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

Node* root = NULL;

typedef struct NodeStack {
    Node** data;
    int top;
    int capacity;
} NodeStack;

void init_NodeStack(NodeStack* s, int cap) {
    s->capacity = cap;
    s->top = -1;
    s->data = (Node**)malloc(cap * sizeof(Node*));
}
void push(NodeStack* s, Node* x) { s->data[++s->top] = x; }
Node* pop(NodeStack* s) { return s->data[s->top--]; }
Node* top(NodeStack* s) { return s->data[s->top]; }
int isEmpty(NodeStack* s) { return s->top == -1; }

Node* Rinsert(Node *p, int key) {
    Node *t;
    if(p == NULL) {
        t = (Node*)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(p->data > key)
        p->lchild = Rinsert(p->lchild, key);
    else if(p->data < key)
        p->rchild = Rinsert(p->rchild, key);
    return p;
}

void insert(int key) {
    Node *p = root, *r;
    if(p == NULL) {
        p = (Node*)malloc(sizeof(Node));
        p->lchild = p->rchild = NULL;
        p->data = key;
        root = p;
        return;
    }
    else {
        while(p != NULL) {
            r = p;
            if(p->data < key)
                p = p->rchild;
            else if(p->data > key)
                p = p->lchild;
            else 
                return;
        }
        p = (Node*)malloc(sizeof(Node));
        p->lchild = p->rchild = NULL;
        p->data = key;
        if(r->data < key)
            r->rchild = p;
        else
            r->lchild = p;
    }
}

void inorder(Node *p) {
    if(p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        fflush(stdout);
        inorder(p->rchild);
    }
}

int Height(Node *t) {
    if(t == NULL)
        return 0;
    int lh = Height(t->lchild);
    int rh = Height(t->rchild);
    return lh < rh ? rh + 1 : lh + 1;
}

Node *Inprec(Node *p) {
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

Node *Insucc(Node *p) {
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node *Delete(Node *p, int key) {
    Node *t = NULL;
    if (p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL) {
        if (p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(p->data > key)
        p->lchild = Delete(p->lchild, key);
    else if(p->data < key)
        p->rchild = Delete(p->rchild, key);
    else {
        if(Height(p->lchild) > Height(p->rchild)) {
            t = Inprec(p->lchild);
            p->data = t->data;
            p->lchild = Delete(p->lchild, t->data);
        }
        else {
            t = Insucc(p->rchild);
            p->data = t->data;
            p->rchild = Delete(p->rchild, t->data);
        }
    }
    return p;
}

void CreatePre() {
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = 8;
    NodeStack st;
    init_NodeStack(&st, 100);
    Node *p, *t;
    root = (Node*)malloc(sizeof(Node));
    int i = 0;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;
    while (i < n) {
       if(p->data > pre[i]) {
        t = (Node*)malloc(sizeof(Node));
        t->data = pre[i++];
        t->lchild = t->rchild = NULL;
        p->lchild = t;
        push(&st, p);
        p = t;
       }
       else if(p->data < pre[i] && (isEmpty(&st) ? 1 : (top(&st)->data > pre[i] ? 1 : 0))) {
        t = (Node*)malloc(sizeof(Node));
        t->data = pre[i++];
        t->lchild = t->rchild = NULL;
        p->rchild = t;
        p = t;
       }
       else {
            p = top(&st);
            pop(&st);
       }
    }
}

int main() {
    CreatePre();
    inorder(root);
    return 0;
}
