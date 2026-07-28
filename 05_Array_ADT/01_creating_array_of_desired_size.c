#include <stdio.h>
#include <stdlib.h>

struct Array {
    int* A;
    int size;
    int length;
};

void init_Array(struct Array* self, int size) {
    self->size = size;
    self->length = 0;
    self->A = (int*)malloc(size * sizeof(int));
}

void create(struct Array* self) {
    printf("Enter number of elements: ");
    fflush(stdout);
    scanf("%d", &self->length);
    printf("Enter the array elements: \n");
    for (int i = 0; i < self->length; i++){
        printf("Array element: %d = ", i);
        fflush(stdout);
        scanf("%d", &self->A[i]);
    }
}

void append(struct Array* self, int a) {
    if(self->length < self->size) {
        self->A[self->length] = a;
        self->length++;
    }
}

void display(struct Array* self) {
    for (int i = 0; i < self->length; i++){
        printf("%d ", self->A[i]);
    }
}

void insert(struct Array* self, int index, int value) {
    if(index >= 0 && index <= self->size){
        for(int i = self->length; i > index; i--) {
            self->A[i] = self->A[i-1];
        }
        self->A[index] = value;
        self->length++;
    }
}

void destroy_Array(struct Array* self) {
    free(self->A);
    printf("Array destroyed\n");
}

int main() {
    struct Array arr;
    init_Array(&arr, 10);
    create(&arr);
    append(&arr, 2);
    insert(&arr, 3, 78);
    display(&arr);
    destroy_Array(&arr);
    return 0;
}
