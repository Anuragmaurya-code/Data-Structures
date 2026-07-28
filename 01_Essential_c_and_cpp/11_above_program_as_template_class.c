#include <stdio.h>

// int specialization
struct Rectangle_int
{
    int length;
    int breadth;
};

void init_Rectangle_int(struct Rectangle_int* self, int l, int b)
{
    self->length = l;
    self->breadth = b;
}
int Rectangle_int_area(struct Rectangle_int* self)
{
    return self->length * self->breadth;
}
int Rectangle_int_perimeter(struct Rectangle_int* self)
{
    return 2*(self->length + self->breadth);
}
void Rectangle_int_setLength(struct Rectangle_int* self, int l)
{
    self->length = l;
}
void Rectangle_int_setbreadth(struct Rectangle_int* self, int b)
{
    self->breadth = b;
}
int Rectangle_int_getLength(struct Rectangle_int* self)
{
    return self->length;
}
int Rectangle_int_getbreadth(struct Rectangle_int* self)
{
    return self->breadth;
}
void destroy_Rectangle_int(struct Rectangle_int* self)
{
    printf("Destructor\n");
}


// float specialization
struct Rectangle_float
{
    float length;
    float breadth;
};

void init_Rectangle_float(struct Rectangle_float* self, float l, float b)
{
    self->length = l;
    self->breadth = b;
}
float Rectangle_float_area(struct Rectangle_float* self)
{
    return self->length * self->breadth;
}
float Rectangle_float_perimeter(struct Rectangle_float* self)
{
    return 2.0f * (self->length + self->breadth);
}
void Rectangle_float_setLength(struct Rectangle_float* self, float l)
{
    self->length = l;
}
void Rectangle_float_setbreadth(struct Rectangle_float* self, float b)
{
    self->breadth = b;
}
float Rectangle_float_getLength(struct Rectangle_float* self)
{
    return self->length;
}
float Rectangle_float_getbreadth(struct Rectangle_float* self)
{
    return self->breadth;
}
void destroy_Rectangle_float(struct Rectangle_float* self)
{
    printf("Destructor\n");
}


int main()
{
    printf("INTEGER\n");
    struct Rectangle_int r;
    init_Rectangle_int(&r, 10, 4);
    int a = Rectangle_int_area(&r);
    int p = Rectangle_int_perimeter(&r);
    printf("area = %d perimerter = %d\n", a, p);
    
    Rectangle_int_setLength(&r, 5);
    Rectangle_int_setbreadth(&r, 4);
    a = Rectangle_int_area(&r);
    p = Rectangle_int_perimeter(&r);
    printf("area = %d perimerter = %d\n", a, p);
    
    int l = Rectangle_int_getLength(&r);
    int b = Rectangle_int_getbreadth(&r);
    printf("Length = %d breadth = %d\n", l, b);
    
    destroy_Rectangle_int(&r);


    printf("\n\nFLOAT\n");
    struct Rectangle_float r1;
    init_Rectangle_float(&r1, 10.0, 4.0);
    float a1 = Rectangle_float_area(&r1);
    float p1 = Rectangle_float_perimeter(&r1);
    printf("area = %f perimerter = %f\n", a1, p1);
    
    Rectangle_float_setLength(&r1, 5.3);
    Rectangle_float_setbreadth(&r1, 4.1);
    a1 = Rectangle_float_area(&r1);
    p1 = Rectangle_float_perimeter(&r1);
    printf("area = %f perimerter = %f\n", a1, p1);
    
    float l1 = Rectangle_float_getLength(&r1);
    float b1 = Rectangle_float_getbreadth(&r1);
    printf("Length = %f breadth = %f\n", l1, b1);
    
    destroy_Rectangle_float(&r1);

    return 0;
}
