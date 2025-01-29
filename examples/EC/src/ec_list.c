#include "ec_list.h"

#if 0
/* Create a new list with zero list variables */
StudentList *grade_6 = Student_List (0);

/* Create and append a new list variable at once */
StudentListVar *st = Student_Append_New (grade_6);

/* Create a new list variable */
StudentListVar *st = Student_List_Var ();

/* Append a new list variable */
Student_Append (grade_6, st);

/* Append a new list variable */
Student_Append (grade_6, st);

/* Append more than one list variables */
Student_Append_Copy (grade_6, st);

/* Delete list variable */
Student_Delete (grade_6, st);

/* Drop a list variable */
Student_Drop (grade_6, st);

/* Insert variable before or after another variable */
Student_Insert_Before (grade_6, st1, st3);
Student_Insert_After (grade_6, st1, st3);

/* Replace a list variable */
Student_Replace (grade_6, st1, st2);

/* Exchange list variables */
Student_Exchange (grade_6, st1, st2);

/* Copy list variable */
StudentListVar *st_copy = Student_Copy (st);

/* Copy a list */
StudentList *grade_6_copy = Student_Copy_List (grade_6);

/* Merge list to another list */
Student_Merge_Before (grade_6, splitedlist, st);
Student_Merge_After (grade_6, splitedlist, st);

/* Slice a list */
StudentList *list_slice = Student_Slice (grade_6, st1, st3);

/* Copy a list Slice */
StudentList *slice_copy = Student_Copy_List_Slice (grade_6, st1, st3);


/* EC_Warn_List_Var_Not_Exist (test_this_var, stl3); */

#endif
