#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VEC_CAPACITY 4

struct Vector {
    int *ptr;
    size_t currentAmount;
    size_t allocatedAmount;
};

void vector_init(struct Vector *v) {
    // v->ptr = NULL; // same as: (*v).ptr = NULL;
    v->currentAmount = 0;
    v->ptr = malloc(sizeof(int) * INITIAL_VEC_CAPACITY);
    if (v->ptr == NULL) {
        printf("PANIC\n");
        return;
    }
    v->allocatedAmount = INITIAL_VEC_CAPACITY;
}

void expandMemoryIfNeeded(struct Vector *v) {
    if (v->currentAmount == v->allocatedAmount) {
        const size_t newAmount = v->allocatedAmount * 2;

        int *tmpPtr = malloc(sizeof(int) * newAmount);
        if (tmpPtr == NULL) {
            printf("PANIC\n");
            return;
        }

        // Copy
        for (size_t i = 0; i < v->currentAmount; ++i) {
            tmpPtr[i] = v->ptr[i];
        }

        // Free old
        free(v->ptr);

        // Assing new to vector
        v->ptr = tmpPtr;

        v->allocatedAmount = newAmount;
    }
}

void vector_push_back(struct Vector *v, int elem) {
    expandMemoryIfNeeded(v);
    v->ptr[v->currentAmount] = elem; // *(v->ptr + v->currentAmount) = elem;
    v->currentAmount += 1;
}

size_t vector_size(struct Vector *v) {
    return v->currentAmount;
}

size_t vector_capacity(struct Vector *v) {
    return v->allocatedAmount;
}

void vector_debug_print(struct Vector *v) {
    for(size_t i = 0; i < v->currentAmount; ++i) {
        printf("%d ", v->ptr[i]);
    }
    printf("\n");
}

int vector_back(struct Vector *v) {
    return v->ptr[v->currentAmount - 1];
}

void vector_deinit(struct Vector *v) {
    free(v->ptr);
}

int main(void) {
    struct Vector v;

    vector_init(&v);

    while(1) {
        int newElem;
        scanf("%d", &newElem);
        vector_push_back(&v, newElem);

        printf("vector size: %zu\n", vector_size(&v));
        printf("vector capacity: %zu\n", vector_capacity(&v));
        printf("vec back: %d\n", vector_back(&v));
        vector_debug_print(&v);
    }

    vector_deinit(&v);


    // TODO(mistler): add elems (i-th, !last, first).
    // TODO(mistler): access elems (i-th, !last, first).
    // TODO(mistler): remove elems (i-th, last, first).
    // TODO(mistler): is empty?
    // TODO(mistler): clear.
    //
    //
    // TODO(katya): sort.
    // TODO(petr): search elem.
    return 0;
}
