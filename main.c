#include <stdio.h>

struct Vector {
};

int main(void) {
    struct Vector v;

    vector_add(&v, 4);
    vector_add(&v, 5);

    printf("vector size: %zu\n", vector_size(&v)); // 2
    printf("vec[0]: %d\n", vector_get(&v, 0)); // 4



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
