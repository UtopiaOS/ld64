/* Provide some simple macros that might be missing on non BSD systems */

#ifdef __cpluscplus
#define __BEGIN_DECLS extern "C" {
    #define __END_DECLS }
#else
    #define __BEGIN_DECLS
    #define __END_DECLS
#endif /* __cplusplus */

#define __P(x) x

// Work around GLIBC bugs...
#ifdef __GLIBC__
#ifndef __extern_inline
#define __extern_inline \
    extern __inline __attribute__ ((__gnu_inline__))
#endif

#ifndef __extern_always_inline
#define __extern_always_inline \
    extern __always_inline __attribute__ ((__gnu_inline__))
#endif

#endif /* __GLIBC__ */