/* -----------
 * Extended C 
 * -----------

 * Extended C - EC is a library and a tool kit that help you to develop C programs more easily.
 * It allows you to create varibles, arrays, lists, queues, stacks and their relevent functions more quickly.
 * It helps you to think and develop the programs with objects in mind.
 * It also supports data oriented desing using inbult entity component system.
 * Further more EC can manage dynamic memory and minimize errors and memory leaks if you are interested in.
 * Finaly it extends the space you to optimize the code and gain it's maximum value.   
 
 * Syntax
 * ------
 
 THIS_IS_A_CONSTANT_OR_MACRO                -> constant / macro
 This_Is_A_Function_Or_Function_Like_Macro  -> function / function like macro
 NewType                                    -> new type
 this_is_a_variable                         -> variable
 thisIsAPointer                             -> pointer / array / list / queues / stacks
 EC_ ec_  									-> prefixes used for external functions and variables
 
 vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4

 Also uses more spaces to minimize headaches. :)
*/


#ifndef EC_H
#define EC_H


/* Development stage debuging */

#ifndef EC_DEV 			// if not define EC_DEV

#define EC_DEV 		0

#ifndef EC_DEBUG
#define EC_DEBUG 	0
#endif

#ifndef EC_WARN
#define EC_WARN 	0
#endif

#ifndef EC_MEMORY
#define EC_MEMORY 	0
#endif

#else 					// if EC_DEV defined

#undef 	EC_DEV
#define EC_DEV 		1
#define EC_DEBUG 	1
#define EC_WARN 	1
#define EC_MEMORY 	1

#endif 					// end EC_DEV

#define EC_INTER_DEV 0 // Use for intrenal fixes 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "ec_debug.h"
#include "ec_string.h"

#include "ec_text_color.h"
#include "ec_type.h"
#include "ec_macro.h"
#include "ec_file.h"

#include "ec_test.h"
#include "ec_error.h"
#include "ec_warn.h"
#include "ec_memory.h"
#include "ec_time.h"

#include "ec_var.h"
#include "ec_array.h"
#include "ec_list.h"
#include "ec_queue.h"
#include "ec_stack.h"
#include "ec_ecs.h"



//#include "ec_syntax.h"
//#include "ec_bits.h"
//#include "ec_vector.h"

#define EC(TYPE) 	\
	EC_VAR(TYPE)	\
	EC_ARRAY(TYPE) 	\
	EC_LIST(TYPE) 	\
	EC_QUEUE(TYPE) 	\
	EC_STACK(TYPE) 	

#endif // EC_H
