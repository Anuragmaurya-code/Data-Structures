//object oriented style of programing 
#include <stdio.h>

struct Rectangle
{
    int length;
    int breath;
};

void init_Rectangle(struct Rectangle* self, int l, int b)
{
    self->length=l;
    self->breath=b;
}
int Rectangle_area(struct Rectangle* self)
{
    return self->length * self->breath;
}
int Rectangle_peri(struct Rectangle* self)
{
    return 2*(self->length + self->breath);
}      

int main()
{
    int l,b;
    printf("Enter lenth and breath of rectangle ");
    scanf("%d %d", &l, &b);
    struct Rectangle r;
    init_Rectangle(&r, l, b);
    int a = Rectangle_area(&r);
    int p = Rectangle_peri(&r);
    printf("%d is area\n%d is perimeter",a,p);
    return 0;
}
