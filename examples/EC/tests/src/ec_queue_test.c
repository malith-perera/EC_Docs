/*Todo */
/* ***************** should do a empty queue dequeue test */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_queue_test.h"

void
Test_New_Queue ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    EC_Test_Print_Subtitle ("Create student stack");

    StudentQueue* stq = Student_Queue ();
    EC_Error_Print_Msg ("Create new queue", "OK");

    assert (stq != NULL);
    EC_Test_Print_Msg ("Initaial stack == NULL", "OK", __LINE__);

    assert (stq->first == NULL);
    EC_Test_Print_Msg ("stq->first == NULL", "OK", __LINE__);

    assert (stq->last == NULL);
    EC_Test_Print_Msg ("stq->last == NULL", "OK", __LINE__);

    assert (stq->var == NULL);
    EC_Test_Print_Msg ("stq->var == NULL", "OK", __LINE__);
}


void
Test_Enqueue_Queue ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    EC_Test_Print_Subtitle ("Create student queue");

    StudentQueue* stq = Student_Queue ();

    // Enqueue st0
    Student_Enqueue(stq, st0);
    assert (Student_Compare(stq->first->var, st0)); 
    assert (Student_Compare(stq->last->var, st0)); 
    assert (stq->last->next == NULL); 
    EC_Test_Print_Msg ("st0 enqueued", "OK", __LINE__);

    // Enqueue st1
    Student_Enqueue(stq, st1);
    assert (Student_Compare(stq->first->var, st0)); 
    assert (Student_Compare(stq->last->var, st1)); 
    assert (stq->last->next == NULL); 
    EC_Test_Print_Msg ("st1 enqueued", "OK", __LINE__);

    // Enqueue st2
    Student_Enqueue(stq, st2);
    assert (Student_Compare(stq->first->var, st0)); 
    assert (Student_Compare(stq->first->next->var, st1)); 
    assert (Student_Compare(stq->last->var, st2)); 
    assert (stq->last->next == NULL); 
    EC_Test_Print_Msg ("st2 enqueued", "OK", __LINE__);
}


void
Test_Dequeue_Queue ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    EC_Test_Print_Subtitle ("student dequeue");

    StudentQueue *stq = Student_Queue ();

    Student_Enqueue(stq, st0);
    Student_Enqueue(stq, st1);
    Student_Enqueue(stq, st2);

    StudentQueueVar *stqv;

    stqv = Student_Dequeue(stq);
    assert (Student_Compare(stqv->var, st0)); 
    EC_Test_Print_Msg ("st0 dequeued", "OK", __LINE__);

    stqv = Student_Dequeue(stq);
    assert (Student_Compare(stqv->var, st1)); 
    EC_Test_Print_Msg ("st1 dequeued", "OK", __LINE__);

    stqv = Student_Dequeue(stq);
    assert (Student_Compare(stqv->var, st2)); 
    EC_Test_Print_Msg ("st2 dequeued", "OK", __LINE__);
}


void
Test_Queue_For_Queue ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    EC_Test_Print_Subtitle ("student for_queue");

    int i = 0;

    StudentQueue *stq = Student_Queue ();

    Student_Enqueue(stq, st0);
    Student_Enqueue(stq, st1);
    Student_Enqueue(stq, st2);
    Student_Enqueue(stq, st3);
    Student_Enqueue(stq, st4);

    i = 0;
    for_queue (stq)
    {
        assert (Student_Compare(stq->var, &students[i])); 
        i++;
    }
    EC_Test_Print_Msg ("for_queue", "OK", __LINE__);
}


void
Test_Queue_Copy ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    EC_Test_Print_Subtitle ("student copy");

    int i = 0;

    StudentQueue *stq = Student_Queue ();

    Student_Enqueue(stq, st0);
    Student_Enqueue(stq, st1);
    Student_Enqueue(stq, st2);
    Student_Enqueue(stq, st3);
    Student_Enqueue(stq, st4);
    EC_Test_Print_Msg ("enqueued", "OK", __LINE__);

    StudentQueue *stq2 = Student_Queue_Copy(stq);
    EC_Test_Print_Msg ("copy stq to stq2", "OK", __LINE__);

    i = 0;
    for_queue (stq2)
    {
        assert (Student_Compare(stq2->var, &students[i])); 
        i++;
    }
    assert (i == 5);
    EC_Test_Print_Msg ("stq copied to stq2", "OK", __LINE__);
}


void
Run_Queue_Test ()
{
    EC_Test_Print_Header ("Test: ec_queue.h");
    printf ("\n");

    Test_New_Queue ();
    printf ("\n");

    Test_Enqueue_Queue ();
    printf ("\n");

    Test_Dequeue_Queue ();
    printf ("\n");

    Test_Queue_For_Queue ();
    printf ("\n");

    Test_Queue_Copy ();
    printf ("\n");

    EC_Test_Print_Msg ("Test: ec_queue.h", "PASS", __LINE__);
}
