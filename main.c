#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VEC_CAPACITY 4

struct Vector {
    int *ptr;
    size_t currentAmount;
};

void vector_init(struct Vector *v) {
    // v->ptr = NULL; // same as: (*v).ptr = NULL;
    v->currentAmount = 0;
    v->ptr = malloc(sizeof(int) * INITIAL_VEC_CAPACITY);
    if (v->ptr == NULL) {
        printf("PANIC\n");
        return;
    }
}

void vector_push_back(struct Vector *v, int elem) {
    v->ptr[v->currentAmount] = elem; // *(v->ptr + v->currentAmount) = elem;
    v->currentAmount += 1;
}

size_t vector_size(struct Vector *v) {
    return v->currentAmount;
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

    vector_push_back(&v, 4);
    vector_push_back(&v, 5);

    printf("vector size: %zu\n", vector_size(&v)); // 2
    printf("vec back: %d\n", vector_back(&v)); // 5

    vector_deinit(&v);


    // TODO(mistler): init vector.
    // TODO(mistler): add elems (i-th, last, first).
    // TODO(mistler): access elems (i-th, last, first).
    // TODO(mistler): remove elems (i-th, last, first).
    // TODO(mistler): lenght of vector.
    // TODO(mistler): is empty?
    // TODO(mistler): clear.
    //
    //
    // TODO(katya): sort.
    // TODO(petr): search elem.
    // TODO(mistler): deinit vector.
    return 0;
}
