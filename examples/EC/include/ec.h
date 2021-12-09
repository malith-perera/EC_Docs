/* Extended C Library
 * ------------------
 * Extended C (ec) is a library help you to develop programs with objects in mind.
 * Allow you to create varibles, arrays, lists, queues, stacks and there relevent functions easily
 * And automate memory management without memory leaks if you are interested in.
 */

/* vi: set ts=4 sw=4 expandtab: */

#ifndef EC_H
#define EC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    EC_VAR_TYPE,
    EC_ARRAY_TYPE,
    EC_LIST_TYPE,
    EC_LIST_VAR_TYPE,
    EC_QUEUE_TYPE,
    EC_QUEUE_VAR_TYPE,
    EC_STACK_TYPE,
    EC_STACK_VAR_TYPE
} ECType;

#include "ec_string.h"
#include "ec_error.h"
#include "ec_file.h"


#include "ec_memory.h"
ECMemoryList* ec_memory;

#include "ec_list.h"
#include "ec_variable.h"
#include "ec_array.h"
#include "ec_queue.h"
#include "ec_stack.h"
//#include "ec_syntax.h"
//#include "ec_bits.h"
//#include "ec_vector.h"


#endif // EC_H
