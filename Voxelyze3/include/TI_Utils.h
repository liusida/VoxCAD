#if !defined(TI_UTILS_H)
#define TI_UTILS_H
#include <stdexcept>

#ifdef __CUDACC__
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=false)
{
    if (code != cudaSuccess)
    {
        //fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);

        if (abort) {
            char buffer[200];
            snprintf(buffer, sizeof(buffer), "GPUassert error in CUDA kernel: %s %s %d\n", cudaGetErrorString(code), file, line);
            std::string buffer_string = buffer;
            throw std::runtime_error(buffer_string);
            exit(code);
        }
    }
}
#endif

#ifdef __CUDACC__
#define CUDA_CALLABLE_MEMBER __host__ __device__
#else
#define CUDA_CALLABLE_MEMBER
#endif

#ifdef __CUDACC__
#define CUDA_DEVICE __device__
#else
#define CUDA_DEVICE
#endif



#define DEBUG_HOST_ENABLED true
#define debugHost(cmd) { if (DEBUG_HOST_ENABLED) {printf(("\n[debugHost] %s(%d): <%s> \033[0;33m"), __FILE__, __LINE__,__FUNCTION__); cmd; printf("\033[0m"); } }
#ifdef DEBUG_HOST_ENABLED
#define debugHostx( var_name, cmd ) { printf(("\n[debugHost] %s(%d): <%s> (%s) \033[0;33m"), __FILE__, __LINE__,__FUNCTION__, var_name); cmd; printf("\033[0m");  }
#else
#define debugHostx( a, b ) ;
#endif

#ifdef __CUDACC__
#define DEBUG_DEV_ENABLED true
#define debugDev(cmd) { if (DEBUG_DEV_ENABLED) {printf(("\n[debugDev] %s(%d): <%s> \033[0;32m"), __FILE__, __LINE__,__FUNCTION__); cmd; printf("\033[0m"); } }
#ifdef DEBUG_DEV_ENABLED
#define debugDevice( var_name, cmd ) { printf(("\n[debugDev] %s(%d): <%s> (%s) \033[0;32m"), __FILE__, __LINE__,__FUNCTION__, var_name); cmd; printf("\033[0m");  }
#else
#define debugDevice( a, b ) ;
#endif
#endif


#include "types.h"

#include "TI_vector.h"
#include "TI_Vec3D.h"
#include "TI_Quat3D.h"

#endif // TI_UTILS_H
