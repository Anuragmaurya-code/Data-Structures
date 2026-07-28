#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    int height;
    struct Node* rchild;
} *root = NULL;

struct NodeStack {
    struct Node** data;
    int top;
    int capacity;
};
void init_NodeStack(struct NodeStack* s, int cap) {
    s->capacity = cap;
    s->top = -1;
    s->data = (struct Node**)malloc(cap * sizeof(struct Node*));
}
void NodeStack_push(struct NodeStack* s, struct Node* val) {
    s->data[++(s->top)] = val;
}
struct Node* NodeStack_pop(struct NodeStack* s) {
    return s->data[(s->top)--];
}
struct Node* NodeStack_top(struct NodeStack* s) {
    return s->data[s->top];
}
int NodeStack_isEmpty(struct NodeStack* s) {
    return s->top == -1;
}

int NodeHeight(struct Node *p) {
    if(p == NULL)
        return 0;
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node* LLRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    p->lchild = plr;
    pl->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p == root) {
        root = pl;
        return pl;
    }
    return p;
}

struct Node* RRRotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(p == root) {  
       root = pr;
        return pr;
    }
    return p;
}

struct Node* LRRotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(p == root)
        root = plr;

    return plr;
}

struct Node* RLRotation(struct Node *p) {
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(p == root)
        root = prl;

    return prl;
}

struct Node* Rinsert(struct Node *p, int key) {
    struct Node *t;
    if(p == NULL) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(p->data > key)
        p->lchild = Rinsert(p->lchild, key);
    else if(p->data < key)
        p->rchild = Rinsert(p->rchild, key);
    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    return p;
}

struct Node* Inprec(struct Node *p) {
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node* Insucc(struct Node *p) {
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node* Delete(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL) {
        if (p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(p->data > key) {
        p->lchild = Delete(p->lchild, key);
    }
    else if(p->data < key)
        p->rchild = Delete(p->rchild, key);
    else {
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
            t = Inprec(p->lchild);
            p->data = t->data;
            p->lchild = Delete(p->lchild, t->data);
        } else {
            t = Insucc(p->rchild);
            p->data = t->data;
            p->rchild = Delete(p->rchild, t->data);
        }
    }
    
    p->height = NodeHeight(p);
 
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){
        return RRRotation(p);
    }
 
    return p;
}

void Display(struct Node *p) {
    printf("%d\n", p->data);
    if(p->lchild) {
        printf("left child of %d is ", p->data);
        Display(p->lchild);
    }
        
    if(p->rchild) {
        printf("right child of %d is ", p->data);
        Display(p->rchild);
    }
}

int main() {
    root = Rinsert(root, 50);
    Rinsert(root, 60);
    Rinsert(root, 40);
    Rinsert(root, 30);
    Rinsert(root, 55);
    Rinsert(root, 45);
    Rinsert(root, 35);

    Delete(root, 60);
    Display(root);
    return 0;
}
