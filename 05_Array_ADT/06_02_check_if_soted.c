#include <stdio.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    for(int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int sort(struct Array arr) {   
    int i = 0;
    while(i < arr.length - 1) {   
        if(arr.A[i] > arr.A[i + 1])
            return 0; // false
        i++;
    }
    return 1; // true
}

int main() {
    struct Array arr = {{1,2,3,4,5,8,10}, 10, 7};
    printf("%d\n", sort(arr));
    return 0;
}
