#include <stdio.h>
#include <stdlib.h>

List *reverse1(List * head)
{
    List *tg=head;
    List *out=NULL;
    
    while(tg!=NULL){
        out=Insert_ToHead(out,tg->Inf);
        tg=tg->Next;
    }    
    return out; 
}

List *reverse2(List *head)
{
	List *t1, *t2, *t3;
	if ((head == NULL) || (head->Next == NULL)) return head;
	t1 = NULL;
	t2 = head;
	t3 = head->Next;
	while (t3!=NULL)
	{
		t2->Next = t1;
		t1 = t2;
		t2 = t3;
		t3 = t3->Next;
	}
	t2->Next=t1;
	return t2;
}

List *reverse3(List *head){
    if(head==NULL) return NULL;
    if(head->Next==NULL) return head;
    
    List *l=daothutuds3(head->Next);
    //thuc hien dao chieu mui ten

    head->Next->Next=head;
    head->Next=NULL;
    return l;
}

List *reverse_solution_page_39(List *li)
{
    List *cur, *prev;
    cur = prev = NULL;
    while (li != NULL){
        cur = li;
        li = li->next;
        prev = cur;
    }
    return prev;
} //NOT WORKING
