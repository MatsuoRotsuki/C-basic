#include <stdio.h>


void Insert_List(ElementType x, Position p, DoubleList *DL)
{
	if (*DL == NULL) {
		(*DL)=(Node*)malloc(sizeof(Node));
		(*DL)->Previous = NULL;
		(*DL)->Element = X;
		(*DL)->Next = NULL;
	}
	else{
		Position temp;
		temp=(Node*)malloc(sizof(Node));
		temp->Element=x;
		temp->Next=p;
		temp->Previous=p->Previous;
		if(p->Previous!=NULL)
		    p->Previous->Next=temp;
		p->Previous=temp;
	}
}

int main ()
{
	
}
