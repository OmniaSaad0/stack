#include <stdio.h>
#include <stdlib.h>
#define maxstack 100000
#define stackentry int



 typedef struct Stack
 {
    int Top;
    stackentry entry[maxstack];
 } Stack;

 void creatstack(Stack *ps)
 {
    ps->Top=0;
 }
 void push(stackentry e,Stack *ps)
 {
    ps->entry[ps->Top++]=e;
 }

 void pop(stackentry *pe,Stack *ps)
 {

    *pe=ps->entry[--ps->Top];
 }

 void top(stackentry *pe,Stack *ps)
 {
    *pe= ps->entry[ps->Top-1];

 }
 int stackfull(Stack *ps)
 {
    if(ps->Top==maxstack)
        return 1;
    return 0;
 }
 int stackempty (Stack *ps)
 {
    if(ps->Top==0)
        return 1;
    return 0;
 }

 int stacksize(Stack *ps)
 {
    return ps->Top;
 }

 void clearstack(Stack *ps)
 {
    ps->Top=0;
 }
 void traversstack(Stack *ps,void(*pf)(stackentry))
 {
    int siz=ps->stacksize;
    while(siz>0)
    {
        (*pf)(ps->entry[siz]);
        siz--;
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
