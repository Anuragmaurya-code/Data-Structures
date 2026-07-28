#include <stdio.h>
#include <stdlib.h>

struct RECTANGLE
{
    int length;
    int breath;
};

void fun1(struct RECTANGLE r1)
{
    (r1.length)++;
    (r1.breath)++;
}
void fun2(struct RECTANGLE *r1)
{
    (r1->length)++;
    (r1->breath)++;
}
void fun3(struct RECTANGLE *r1)
{
    r1->length++;
    r1->breath++;
}
struct RECTANGLE * fun4()
{
    struct RECTANGLE *r2;
    r2=(struct RECTANGLE *)malloc(sizeof(struct RECTANGLE));// or r2=(struct RECTANGLE *)malloc(sizeof(struct RECTANGLE));
    r2->length=1;
    r2->breath=2;
    return r2;
}
int main()
{
    struct RECTANGLE r={10,5};
    printf("Before any call %d  %d\n", r.length, r.breath);
    fun1(r);
    printf("After call by value %d  %d\n", r.length, r.breath);
    fun2(&r);
    printf("After call by referece %d  %d\n", r.length, r.breath);
    fun3(&r);
    printf("After call by address %d  %d\n", r.length, r.breath);

    // creating structure in heap memory and accesing them using function
    struct RECTANGLE *ptr=fun4();
    printf("After creating structure in heap memory %d %d\n", ptr->length, ptr->breath);// -> is to access struct elements using pointer
    free(ptr);
    return 0;
}
