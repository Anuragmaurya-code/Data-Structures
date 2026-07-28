#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create() {
    struct Node *t = NULL, *last = NULL;
    int num;
    printf("Enter the number of polynomials ");
    scanf("%d", &num);
    
    printf("Enter the coefficient and exponent of each polynomial ");
    for(int i = 0; i < num; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        if(poly == NULL) {
            poly = last = t;
        }
        else {
            last->next = t;
            last = t;
        }
        last->next = NULL;
    }
}

void display(struct Node *p) {
    while(p) {
        printf("%dx**%d + ", p->coeff, p->exp);
        p = p->next;
    }
}

long eva(struct Node *p, int x) {
    long val = 0;
    while(p) {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main() {
    create();
    display(poly);
    printf("\nAnswer of Evaluation%ld", eva(poly, 1));
    return 0;
}
