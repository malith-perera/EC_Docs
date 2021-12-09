#ifndef STUDENT_H
#define STUDENT_H

#include "main.h"

#define student_vars   \
    int index;         \
    char name[20];     \
    int grade;

EC_VAR(Student, student_vars)

EC_ARRAY(Student, student_vars)
EC_ARRAY_FUNCTION_PROTOTYPES(Student)

#endif //STUDENT_H
