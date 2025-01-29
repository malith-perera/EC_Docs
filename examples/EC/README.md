# EC

## Introduction

EC is an easy to use extended C library and a tool kit for high performance, rapid application development in pure C language.

### EC Features
+ Extended variables & functions
+ Easy tool kit
+ Objects in mind
+ Entity component system
+ Dynamic memory management
+ Rapid application development
+ Optimizable code
+ High performance

## Overview

```c
typedef struct Student {
   int  index;
   char *name;
} Student;

EC(Student)
```
Declare a Student  

### Create a Student
```c
Student *student1 = Student_New();

student->index = 101;
student->name = "Arnold";
```
Create a new student and initialize the student variables.  

### Create a Student List

```c
StudentList *student_list = Student_List();
```
Create a new student_list.  

### Append student
```c
Student_Append(student_list, student1);
```
Append student1 to the student_list.  

### Insert student
```c
Student_Insert(student_list, student1, 5);
```

Insert student1 as the 5th student of the student_list. 

### Move student

```c
Student_Move(student_list, student1, 5);
```
Move student1 5 steps towards end of the student_list.  

### Exchange students
```c
Student_Exchange(student_list, student1, student2);
```
Exchange student1 with student2 in the student_list.  

### Replace list student
```c
Student_Replace(student_list, student1, student2);
```
Replace student1 by student2 in the student_list.  

### Remove student

```c
Student_Remove(student_list, student1);
```
Remove student1 from the student_list.  

### Loop in the list

```c
Student *st;
for_list(student_list, st) {
  printf("Id %d Name %s\n", st->id, st->name);
}
```
Go through the student_list and get student one by one in the list.  

## Welcome!
> Not only these. EC does many things for you. For manuals, tutorials, examples and binary downloads please follow the link below. Also you are warmly welcome to upgrade EC to the next level. Hope you will enjoy with EC programming.  
  
Be EC !
  
![Logo, Extended C logo ](doc/logo.png)  
  
<http://www.eclab.org>  

