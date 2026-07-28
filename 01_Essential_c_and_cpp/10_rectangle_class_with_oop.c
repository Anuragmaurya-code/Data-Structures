#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

void init_Rectangle_default(struct Rectangle* self)
{
    self->length=0;
    self->breadth=0;
}
void init_Rectangle(struct Rectangle* self, int l, int b)
{
    self->length=l;
    self->breadth=b;
}
int Rectangle_area(struct Rectangle* self)
{
    return self->length * self->breadth;
}
int Rectangle_perimeter(struct Rectangle* self)
{
    return 2*(self->length + self->breadth);
}
void Rectangle_setLength(struct Rectangle* self, int l)
{
    self->length=l;
}
void Rectangle_setbreadth(struct Rectangle* self, int b)
{
    self->breadth=b;
}
int Rectangle_getLength(struct Rectangle* self)
{
    return self->length;
}
int Rectangle_getbreadth(struct Rectangle* self)
{
    return self->breadth;
}
void destroy_Rectangle(struct Rectangle* self)
{
    printf("Destructor\n");
}

int main()
{
    struct Rectangle r;
    init_Rectangle(&r, 10, 4);
    int a=Rectangle_area(&r);
    int p=Rectangle_perimeter(&r);
    printf("area = %d perimerter = %d\n",a,p);
    Rectangle_setLength(&r, 5);
    Rectangle_setbreadth(&r, 4);
    a=Rectangle_area(&r);
    p=Rectangle_perimeter(&r);
    printf("area = %d perimerter = %d\n",a,p);
    int l=Rectangle_getLength(&r);
    int b=Rectangle_getbreadth(&r);
    printf("Length = %d breadth = %d\n",l,b);
    
    destroy_Rectangle(&r);
    return 0;
}
