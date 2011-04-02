#ifndef _wcglobaldefs
#define _wcglobaldefs

/* comment out to turn debug statements off */
#define debug

/* size for a line, size for a word */
#define buf_size 256
#define small_size 16

/* may as well cover all the bases */
#define true 1
#define TRUE 1
#define True 1
#define false 0
#define FALSE 0
#define False 0


/* function return values */
#define success 0
#define fail -1
#define alloc_fail 1
#define empty 2
#define bad_input 3
#define got_null 4
#define not_null 5

/* I rewrite this too often */
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

/* this should be the most common debug stuff I need to print */
#ifdef debug
#define _num(x,y) printf("%s,%d: -%s: %g-\n", __FILE__, __LINE__ x, y); fflush(stdout); /* uses %g to do floats or ints */
#define _ptr(x,y) printf("%s,%d: -%s: %p-\n", __FILE__, __LINE__, x, y); fflush(stdout); /* for address checking */
#define _str(x) printf("%s,%d: -%s-\n", __FILE__, __LINE__, x); fflush(stdout); /* just an output */
#define _loc printf("%s,%d: ", __FILE__, __LINE__); fflush(stdout);
#else
#define _num(x,y)
#define _ptr(x,y)
#define _str(x)
#define _loc
#endif

#endif
