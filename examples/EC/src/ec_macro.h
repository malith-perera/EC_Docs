/* All are hard coded so we can't go further than 11 arguments here. It's not expected behaviour.  
 * I think this isn't the way to do this. Please find a good way to genereate macros other than hard coding.
 */

#include "ec.h"


#ifndef EC_MACRO
#define EC_MACRO


// CONCAT
#ifndef EC_CONCAT
#define EC_CONCAT(x, y) x ## y
#endif

#ifndef EC_CONCAT2
#define EC_CONCAT2(x, y) x ## y
#endif

#ifndef EC_CONCAT3
#define EC_CONCAT3(x, y, z) x ## y ## z
#endif

#ifndef EC_CONCAT4
#define EC_CONCAT4(a, b, c, d) a ## b ## c  ## d
#endif

#ifndef EC_CONCAT5
#define EC_CONCAT5(a, b, c, d, e) a ## b ## c  ## d ## e
#endif


// Variadic macro
#define ARG1(a1, ...) a1
#define ARG2(a1, a2, ...) a2
#define ARG3(a1, a2, a3, ...) a3
#define ARG4(a1, a2, a3, a4, ...) a4
#define ARG5(a1, a2, a3, a4, a5, ...) a5
#define ARG6(a1, a2, a3, a4, a5, a6, ...) a6
#define ARG7(a1, a2, a3, a4, a5, a6, a7, ...) a7
#define ARG8(a1, a2, a3, a4, a5, a6, a7, a8, ...) a8
#define ARG9(a1, a2, a3, a4, a5, a6, a7, a8, a9, ...) a9
#define ARG10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, ...) a10
#define ARG11(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) a11

// #define ARG(n, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) CONCAT2(a, n)


#define ARG_SET1(...)       \
    ARG1(__VA_ARGS__)();

#define ARG_SET2(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();

#define ARG_SET3(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();

#define ARG_SET4(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();

#define ARG_SET5(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();

#define ARG_SET6(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();    \
    ARG6(__VA_ARGS__)();

#define ARG_SET7(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();    \
    ARG6(__VA_ARGS__)();    \
    ARG7(__VA_ARGS__)();

#define ARG_SET8(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();    \
    ARG6(__VA_ARGS__)();    \
    ARG7(__VA_ARGS__)();    \
    ARG8(__VA_ARGS__)();

#define ARG_SET9(...)       \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();    \
    ARG6(__VA_ARGS__)();    \
    ARG7(__VA_ARGS__)();    \
    ARG8(__VA_ARGS__)();    \
    ARG9(__VA_ARGS__)();

#define ARG_SET10(...)      \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();    \
    ARG6(__VA_ARGS__)();    \
    ARG7(__VA_ARGS__)();    \
    ARG8(__VA_ARGS__)();    \
    ARG9(__VA_ARGS__)();    \
    ARG10(__VA_ARGS__)();

#define ARG_SET11(...)      \
    ARG1(__VA_ARGS__)();    \
    ARG2(__VA_ARGS__)();    \
    ARG3(__VA_ARGS__)();    \
    ARG4(__VA_ARGS__)();    \
    ARG5(__VA_ARGS__)();    \
    ARG6(__VA_ARGS__)();    \
    ARG7(__VA_ARGS__)();    \
    ARG8(__VA_ARGS__)();    \
    ARG9(__VA_ARGS__)();    \
    ARG10(__VA_ARGS__)();   \
    ARG11(__VA_ARGS__)();


#define EC_COUNT_ARGS(...) ARG11( __VA_ARGS__ __VA_OPT__(,) 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)


/* below are examples from internet __VA_OPT__()*/

#define F(...) f(0 __VA_OPT__(,) __VA_ARGS__) 
/*
F(a, b, c) // replaced by f(0, a, b, c)
F()        // replaced by f(0)
*/
 
#define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)
/*
G(a, b, c) // replaced by f(0, a, b, c)
G(a, )     // replaced by f(0, a)
G(a)       // replaced by f(0, a)
*/
 
#define SDEF(sname, ...) S sname __VA_OPT__(= { __VA_ARGS__ })
/*    
SDEF(foo);       // replaced by S foo;
SDEF(bar, 1, 2); // replaced by S bar = { 1, 2 };
*/

#endif
