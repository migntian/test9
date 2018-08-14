#include <stdio.h>
#include <stdlib.h>

#define seqlistmaxsize 1000
typedef char seqtype;
typedef struct seqlist{
    seqtype arr[seqlistmaxsize];
    size_t size;
}seqlist;

void printseqlist(seqlist *s)
{
    if(s == NULL)
    {
        return;
    }
    int i = 0;
    for(;i < s->size;i++)
    {
        printf("%c",s->arr[i]);
    }
    printf("\n");
}
void initseqlist(seqlist *s)
{
    if(s == NULL)
    {
        return;
    }
    s->size = 0;
}
void push_back(seqlist *s,char value)
{
    if(s == NULL)
    {
        return;
    }
    s->arr[s->size++] = value;
}
void pop_back(seqlist *s)
{
    if(s == NULL)
    {
        return;
    }
    if(s->size == 0)
    {
        return;
    }
    s->size--;
}
void push_front(seqlist *s,char value)
{
    if(s == NULL)
    {
        return;
    }
    int i = s->size-1;
    s->size++;
    for(i;i>=0;i--)
    {
        s->arr[i+1] = s->arr[i];
    }
    s->arr[0] = value;
}
void pop_front(seqlist *s)
{
    if(s == NULL)
    {
        return;
    }
    int i = 0;
    for(i;i<s->size;i++)
    {
        s->arr[i] = s->arr[i+1];
    }
    s->size--;
}
void insert_pos(seqlist *s,size_t pos,char value)
{
    if(s == NULL)
    {
        return;
    }
    int i = s->size-1;
    s->size++;
    
    for(i;i >= pos;i--)
    {
        s->arr[i+1] = s->arr[i];
    }
    s->arr[pos] = value;
}
void pop_pos(seqlist *s,size_t pos)
{
    if(s == NULL)
    {
        return;
    }
    int i = pos;
    for(i;i < s->size;i++)
    {
        s->arr[i] = s->arr[i+1]; 
    }
    s->size--;
}
int find(seqlist *s,char value)
{
    if(s == NULL)
    {
        return;
    }
    int i = 0;
    for(i;i<s->size;i++)
    {
        if(s->arr[i] == value)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    seqlist s;
    initseqlist(&s);
    push_back(&s,'a');
    push_back(&s,'b');
    push_back(&s,'c');
    push_back(&s,'d');
    printseqlist(&s);
    pop_back(&s);
    printseqlist(&s);
    push_front(&s,'x');
    printseqlist(&s);
    pop_front(&s);
    printseqlist(&s);
    insert_pos(&s,2,'x');
    printseqlist(&s);
    pop_pos(&s,1);
    printseqlist(&s);
    int ret = find(&s,'x');
    printf("%d\n",ret);
    return 0;
}
