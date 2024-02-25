#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Node & List Data Structures
typedef struct _node {
    char* _data;
    struct _node* _next;
} Node;

struct _StrList {
    Node* _head;
    size_t _size;
} ;

//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(const char* data, Node* next) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p != NULL) {
        // Allocate memory for the string and copy its content
        p->_data = strdup(data);
        if (p->_data == NULL) {
            free(p);
            return NULL;
        }
        p->_next = next;
    }
    return p;
}

void Node_free(Node* node) {
    if (node != NULL) {
        free(node->_data);
        free(node);
    }

}

//------------------------------------------------
// List implementation
//------------------------------------------------

StrList* StrList_alloc() {
    StrList* p = (StrList*)malloc(sizeof(StrList));
    if (p != NULL) {
        p->_head = NULL;
        p->_size = 0;
    }
    return p;
}

void StrList_free(StrList* strList) {
    if (strList != NULL) {
        Node* current = strList->_head;
        Node* next;
        while (current != NULL) {
            next = current->_next;
            Node_free(current);
            current = next;
        }
        free(strList);
    }
}

size_t StrList_size(const StrList* StrList) {
    return StrList->_size;
}
void StrList_insertLast(StrList* StrList,const char* data)
{
    Node* p= StrList->_head;
    Node* tmp= Node_alloc(data, NULL);
    if(p==NULL)
    {
        StrList->_head = tmp;
    }
    else
    {
     while(p->_next!=NULL) 
     {
      p= p->_next;
     }
     p->_next=tmp;
    }
    
    ++(StrList->_size);
    
   
}
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    if(index<0 || index > StrList->_size){
        return;
    }
   Node* tmp = Node_alloc(data, NULL);  
    if (index == 0)
    {
        
        tmp->_next = StrList->_head;
        StrList->_head = tmp;
    }
    else
    {
        Node* p = StrList->_head;
        for (int i = 0; i < index - 1; ++i)
        {
            p = p->_next;  
        }
        tmp->_next = p->_next;  
        p->_next = tmp;  
    }

    ++(StrList->_size);  
    
}


char* StrList_firstData(const StrList* StrList) {
    return StrList->_head->_data;
}




void StrList_print(const StrList* StrList) {
    const Node* p= StrList->_head;
    if(p!=NULL){
        printf("%s",p->_data);
        p= p->_next;
    }
    while(p) {
        printf(" %s",p->_data);
        p= p->_next;
    }

}
/* Return the amount of chars in the list.*/
 void StrList_printAt(const StrList* Strlist,int index)
{ if(index<0 || index > Strlist->_size){
        return;
    }
    const Node* p= Strlist->_head;
    for(int i=0;i<index && p != NULL;i++){
        p= p->_next;
    }
    printf("%s",p->_data);
} 
   
int StrList_printLen(const StrList* Strlist)
{
    const Node* p= Strlist->_head;
    int sumtotal=0;
    while(p)
    {
     if(p->_data !=NULL)
     {
        sumtotal=sumtotal+strlen(p->_data);
     }
     p= p->_next;
    }
return sumtotal;
}
int StrList_count(StrList* Strlist, const char* data)
{   
    Node* p = Strlist->_head;
    int count=0;
    while (p != NULL)
    {
        
        if (strcmp(p->_data, data) == 0)
        {
          count++;
        }
        p = p->_next;  
    }
    return count;
}

    void StrList_remove(StrList* StrList, const char* data)
{
     if(StrList==NULL&&StrList==NULL)
    {   
        return;
    }
    if(StrList==NULL)
    {
        return;
    }
    Node* current = StrList->_head;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->_data, data) == 0)
        {
            Node* temp = current;
            if (previous == NULL)
            {
                StrList->_head = current->_next;
            }
            else
            {
                previous->_next = current->_next;
            }

            current = current->_next;
            
             free(temp);
            --(StrList->_size); 
        }
        else
        {
            previous = current;
            current = current->_next;
        }
        }

    
}
 
void StrList_removeAt(StrList* StrList, int index)
{    if(StrList==NULL||StrList_size(StrList)==0)
    {   
        return;
    }
    if(index<0 || index > StrList->_size)
    {
        return;
    }
  
    
    Node* current = StrList->_head;
    Node* prev = NULL;

    
    for (int i = 0; i < index; ++i) {
        prev = current;
        current = current->_next;
    }

    if (prev == NULL) {
        
        StrList->_head = current->_next;
    } else {
        
        prev->_next = current->_next;
    }

    // Free the memory of the removed node
    free(current->_data);
    free(current);

    // Decrease the size of the list
    StrList->_size--;
}


int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    const int eq = 0;
    const int neq = 1;
    if(StrList1==NULL&&StrList2==NULL)
    {   
        return neq;
    }
    if(StrList_size(StrList1)==0&&StrList_size(StrList1)==0)
    {
        return neq;
     }

    if(StrList1->_head==NULL&&StrList1==NULL)
    {
        return neq;
    }
    const Node* p1 = StrList1->_head;
    const Node* p2 = StrList2->_head;

    while (p1) {
        // Check if p2 is NULL or the strings are not equal
        if (p2 == NULL || strcmp(p1->_data, p2->_data) != 0) {
            return eq;
        }

        p1 = p1->_next;
        p2 = p2->_next;
    }

    // If p2 is not NULL, the lists are not equal
    if (p2 != NULL) {
        return eq;
    }

    return neq;
}

StrList* StrList_clone(const StrList* StrLis) {
    StrList* ret= StrList_alloc();
    const Node* old= StrLis->_head;
    Node* * copy= &(ret->_head);
    ret->_size= StrLis->_size;
    while(old) {
        *copy= Node_alloc(old->_data,NULL);
        old= old->_next;
        copy= &((*copy)->_next);
    }
    return ret;
}

void StrList_reverse( StrList* StrList)
{
  if(StrList==NULL||StrList_size(StrList)==0)
    {   
        return;
    }
    Node* current = StrList->_head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    StrList->_head = prev;
    
}
void swapNodes(Node* node1, Node* node2) {
    char* temp = node1->_data;
    node1->_data = node2->_data;
    node2->_data = temp;
}
void StrList_sort( StrList* StrList)
{ if(StrList==NULL||StrList_size(StrList)==0)
    {   
        return;
    }
    
 if (StrList->_head == NULL || StrList->_size <= 1) {
        // Nothing to sort if the list is empty or has only one element
        return;
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = StrList->_head;

        while (ptr1->_next != lptr) {
            if (strcmp(ptr1->_data, ptr1->_next->_data) > 0) {
                // Swap the data of two nodes
                swapNodes(ptr1, ptr1->_next);
                swapped = 1;
            }
            ptr1 = ptr1->_next;
        }
        lptr = ptr1;
    } while (swapped);
}


int StrList_isSorted(StrList* StrList)
{ 

    Node* p = StrList->_head;

    while (p->_next != NULL)
    {
        if (strcmp(p->_data, p->_next->_data) > 0)
        {
            return 0;
        }
        p = p->_next; 
    }

    
    return 1;
}
