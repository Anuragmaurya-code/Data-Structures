//modular style of programing along with structure
#include <stdio.h>

struct Rectangle
{
    int length;
    int breath;
};
void initialization(struct Rectangle *r,int l,int b)
{
    r->length=l;
    r->breath=b;
}
int area(struct Rectangle r1)
{
    return r1.length*r1.breath;
}
int peri(struct Rectangle r1)
{
    return 2*(r1.length+r1.breath);
}
int main()
{
    struct Rectangle r={0,0};
    int l,b;
    printf("Enter lenth and breath of rectangle ");
    scanf("%d %d", &l, &b);
    initialization(&r,l,b);
    int a=area(r);
    int p=peri(r);
    printf("%d is area\n%d is perimeter",a,p);
    return 0;
}
