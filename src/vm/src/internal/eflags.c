#include "../core/eflags.h"
#include <stdlib.h>

EFLAGS *vm__eflags_create() {
    EFLAGS* ptr = (EFLAGS *)malloc(sizeof(EFLAGS));
    ptr->CM = EQUALS;
    return ptr;
}

void vm__eflags_free(EFLAGS **eflags) {
    free(*eflags);
    *eflags = NULL;
}
