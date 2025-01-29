## EC Tutorial
<hr>

Hope you have the basic knowledge of C language and compile a C source files with headers and link a dynamic library.

### EC_VAR
<hr>
Create dynamic variables.

*student.c*  
<pre><code>
#include &ltstdio.h&gt
#include "student.h"

typedef struct Student {
    int no;
    char *name;
} Student;

EC(Student)

int main () {
    // Create variables
    Student *st1 = Student_Var();
    Student *st2 = Student_Var();
    
    // Initialize variables
    st1->no = 1;
    st1->name = "Arnold";
    
    st2->no = 2;
    st2->name = "Silvester";
    
    // Copy st1 to st2
    Student_Copy(st2, st1);
    
    // Clone st1 and return a new variable
    Student *st3 = Student_Var_Clone(st1);
    
    // Drop st1 to delete lately
    Student_Drop(st1);
    
    // Delete st2 and free memory
    Student_Free(st2);
    
    // Free all
    EC_Clean();

    return 0;
}
</code></pre>


### EC_ARRAY
<hr>

Create dynamic arrays.

*student.c*  
<pre><code>
#include &ltstdio.h&gt
#include "ec.h"

typedef struct Student {
    int no;
    char *name;
} Student;

EC(Student)

int main () {
    // Create array
    Student *sta = Student_Array(2); 
       
    // Initialize variables
    sta->array[0].no = 1;
    sta->array[0].name = "Arnold";
    
    sta->array[1].no = 2;
    sta->array[1].name = "Silvester";
    
    // Loop
    Student *st;
    for_array(sta, st) {
        printf("no: %d name: %s\n", st->no, st->name)
    }
    
    // Free all
    EC_Clean();

    return 0;
}
</code></pre>