#include "TI_vector.h"
#ifdef _0

template <typename T>
CUDA_DEVICE void TI_vector<T>::push_back(T p, bool debug) {
    unsigned current_cursor;
    if (debug) {
        printf("push_back: %p num_main %d, sizeof_chunk: %d.\n", this, num_main, sizeof_chunk);
    }
    if (flag==2) current_cursor = atomicAdd(&num_main,1);
    else current_cursor = num_main++;
    if (num_main >= sizeof_chunk) {
        //TODO: here is still not thread-safe.
        unsigned size = sizeof_chunk*sizeof(T);
        T* temp = (T*) malloc(size*2);
        memcpy( temp, main, size );
        memset( temp+size, 1, size );
        delete main;
        main = temp;
        sizeof_chunk *= 2;
    }
    main[current_cursor] = p;
}
#endif