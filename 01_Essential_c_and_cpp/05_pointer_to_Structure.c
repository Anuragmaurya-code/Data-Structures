#include <stdlib.h>
#include <stdio.h>

struct RECTANGLE
{
    int length;
    int breath;
    /* data */
};

int main()
{
    struct RECTANGLE r={5,5};
    r.length=10;//editing rectangle value
    printf("Structure Rectangle in stack and accessed using variable %d %d\n", r.length, r.breath);

    //Now Using Pointer
    struct RECTANGLE *p1=&r;
    p1->length=2;//could even be (*p).length=2
    printf("Structure Rectangle in stack and accessed using pointer %d %d\n", p1->length, p1->breath);

    //Now creating object structure rectangle in heap memory using pointer
    struct RECTANGLE *p2;//struct can be skipped in c++
    p2=(struct RECTANGLE *)malloc(sizeof(struct RECTANGLE));//this is for c++ for c it would be p2=(return datatype *)malloc(size of object need to be created)
                    //here it would be p2=(struct RECTANGLE *)malloc(sizeof(struct RECTANGLE))
    p2->length=14;
    p2->breath=15; 
    printf("Structure Rectangle in heap and accessed using pointer %d %d\n", p2->length, p2->breath);
    free(p2);
    return 0;
}
