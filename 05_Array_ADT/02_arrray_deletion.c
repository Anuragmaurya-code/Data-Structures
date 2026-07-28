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

void display(struct Array* self) {
    for (int i = 0; i < self->length; i++){
        printf("%d ", self->A[i]);
    }
    printf("\n");
}

void del(struct Array* self, int index) {
    if(index >= 0 && index <= self->length) {
        for(int i = index; i < self->length - 1; i++) {
            self->A[i] = self->A[i+1];
        }
        self->length--;
        printf("deleted index %d element in array\n", index);
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
    display(&arr);
    del(&arr, 3);
    display(&arr);
    destroy_Array(&arr);
    return 0;
}
