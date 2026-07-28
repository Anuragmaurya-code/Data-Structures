#include <stdio.h>
#include <stdlib.h>

struct Array_int {
    int * A;
    int size;
    int length;
};

void init_Array_int_default(struct Array_int* self) {
    self->size = 10;
    self->length = 0;
    self->A = (int*)malloc(self->size * sizeof(int));
}

void init_Array_int(struct Array_int* self, int size) {
    self->size = size;
    self->length = 0;
    self->A = (int*)malloc(self->size * sizeof(int));
}

void insert(struct Array_int* self, int index, int value) {
    if(index >= 0 && index <= self->size){
        for(int i = self->length; i > index; i--) {
            self->A[i] = self->A[i - 1];
        }
        self->A[index] = value;
        self->length++;
    }
}

void append(struct Array_int* self, int x) {
    if(self->length < self->size) {
        self->A[self->length] = x;
        self->length++;
    }
}

void display(struct Array_int* self) {
    for (int i = 0; i < self->length; i++){
        printf("%d ", self->A[i]);
    }
}

int l_search(struct Array_int* self, int value) {
    for(int i = 0; i < self->length; i++) {
        if(self->A[i] == value) {
            return i;
        }
    }
    return -1;
}

void deletion(struct Array_int* self, int index) {
    if(index >= 0 && index <= self->length) {
        for(int i = index; i < self->length - 1; i++) {
            self->A[i] = self->A[i + 1];
        }
        self->length--;
        printf("deleted index %d element in array\n", index);
    }    
}

int Sum(struct Array_int* self) {
    int sum = 0;
    for(int i = 0; i < self->length; i++)
        sum = sum + self->A[i];
    return sum;
}

struct Array_int* Union(struct Array_int* self, struct Array_int arr2) {
    struct Array_int* arr3 = (struct Array_int*)malloc(sizeof(struct Array_int));
    init_Array_int(arr3, 100);
    int i = 0, j = 0, k = 0, m = 0;
    for(i = 0; i < self->length; i++, k++)
        arr3->A[k] = self->A[i];
    for(i = 0; i < arr2.length; i++) {
        int l = 0, j = 0;
        while(j < self->length) {
            if(arr2.A[i] == self->A[j]) {
                l = 1;
                break;
            }
            j++;
        }
        if(l == 0)
            arr3->A[k++] = arr2.A[i];
    }
    arr3->length = k;
    return arr3;
}

void destroy_Array_int(struct Array_int* self) {
    free(self->A);
}

int main() {
    int i, sz;
    int x;
    printf("Enter size of array ");
    fflush(stdout);
    scanf("%d", &sz);
    struct Array_int arr;
    init_Array_int(&arr, sz);
    int ch;
    do {
        printf("\nMenu\n");
        printf("1.Append\n");
        printf("2.Insert\n");
        printf("3.Search\n");
        printf("4.Sum\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Exit\n");

        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter element to appended\n");
                fflush(stdout);
                scanf("%d", &x);
                append(&arr, x);
                break;

            case 2:
                printf("Enter element to be inserted\n");
                fflush(stdout);
                scanf("%d", &x);
                printf("Enter position of element\n");
                fflush(stdout);
                scanf("%d", &i);
                insert(&arr, i, x);
                break;

            case 3:
                printf("Enter element to be searched\n");
                fflush(stdout);
                scanf("%d", &x);
                i = l_search(&arr, x);
                if(i == -1)
                    printf("Element not found\n");
                else
                    printf("Element found at %d position ", i);
                break;

            case 4:
                printf("Sum of array elements is %d", Sum(&arr));
                break;

            case 5:
                display(&arr);
                break;

            case 6:
                printf("Enter index at which elements will be deleted\n");
                fflush(stdout);
                scanf("%d", &i);
                deletion(&arr, i);
                break;
        }
    } while(ch < 7);

    struct Array_int a2;
    init_Array_int(&a2, 10);
    append(&a2, 4);
    append(&a2, 5);
    append(&a2, 6);
    struct Array_int* a3 = Union(&arr, a2);
    display(a3);

    destroy_Array_int(&arr);
    destroy_Array_int(&a2);
    destroy_Array_int(a3);
    free(a3);

    return 0;
}
