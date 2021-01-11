#include <stdio.h>
#include <stdlib.h>

#define stackentry int

 typedef struct stacknode
 {
    stackentry entry;
    struct stacknode *next;
 } node;

 typedef struct stack
 {
    node *Top;
    int size;
 } Stack;

 void creatstack(Stack *ps)
 {
    ps->Top=NULL;
    ps->size=0;
 }

 void push(stackentry e, Stack *ps)
 {
    node *pn=(node*)malloc(sizeof(node));
    pn->entry=e;
    pn->next=ps->Top;
    ps->Top=pn;
    ps->size++;
 }

 void pop(stackentry *pe,Stack *ps)
 {
    *pe=ps->Top->entry;
    ps->Top=ps->Top->next;
    ps->size--;
 }
 void top(stackentry *pe,Stack *ps)
 {
    *pe=ps->Top->entry;
 }
 int stackempty(Stack *ps)
 {
    if(ps->Top==NULL)
        return 1;
    else
        return 0;
 }
 int stackfull(Stack *ps)
 {
    return 0;
 }

 int stacksize(Stack *ps)
 {

    return ps->size;
 }
 void clearstack(Stack *ps)
 {

    node *pn;

    while(ps->Top!=NULL)
    {
        pn=ps->Top->next;
        free(ps->Top);
        ps->Top=pn;

    }
    ps->size=0;
 }
 void traverssatack(Stack *ps, void(*pf)(stackentry))
 {
    node *pn;
    while(pn!=NULL)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }
 }

 int main()
 {

    Stack s;
    creatstack(&s);
    push(5,&s);
    push(4,&s);
    stackentry e ;
    pop(&e,&s);
    printf("%d\n",e);
    top(&e,&s);
    printf("%d\n",e);

    return 0;
 }
