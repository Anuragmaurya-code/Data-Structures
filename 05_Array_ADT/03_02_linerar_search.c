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

int l_search(struct Array* self, int value) {
    for(int i = 0; i < self->length; i++) {
        if(self->A[i] == value) {
            if(i > 0) {
                int t = self->A[i-1]; //Transpose method to improve linear search
                self->A[i-1] = self->A[i];
                self->A[i] = t;
            }
            return i;
        }    
    }
    return -1;
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
    printf("element found at index %d\n", l_search(&arr, 3));
    display(&arr);
    destroy_Array(&arr);
    return 0;
}
