//monolytic style of programing
#include <stdio.h>
int main()
{
    int l,b;
    printf("Enter lenth and breath of rectangle ");
    scanf("%d %d", &l, &b);
    int area=l*b;
    int peri=2*(l+b);
    printf("%d is area\n%d is perimeter",area,peri);
    return 0;
}
