#define _CRT_SECURE_NO_WARNINGS

#ifndef __LIST_H_
#define __LIST_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef struct Node 
{
	int data;
	struct Node* next;
}pNode_t,*pNode,**pNode_p;

pNode alloc_node(int data)
{
	pNode L = (pNode)malloc(sizeof(pNode_t));
	L->data = data;
	L->next = NULL;
	return L;
}
int is_empty(pNode _L)
{	
	assert(_L);
	return _L->next==NULL?1:0;
}
void delete_node(pNode _L)
{
	assert(_L);
	if(_L)
	{
		free(_L);
	}
}
void init_List(pNode_p _L)
{
	assert(_L);
	*_L = alloc_node(0);
}
void push_node(pNode _L,int data)
{
	pNode temp = alloc_node(data);//�ȶ�����ʹ��
	assert(_L);
	
	temp->next = _L->next;
	_L->next = temp;
}

void pop_list(pNode _L)
{
	assert(_L);
	if(!is_empty(_L))
	{
		pNode temp = _L->next;
		_L->next = temp->next;
		delete_node(temp);
	}
}
void destory_node(pNode _L)
{
	assert(_L);
	while(!is_empty(_L))
	{
		pop_list(_L);
	}
	delete_node(_L);
}
void show_node(pNode _L)
{
    pNode p = _L->next;
	assert(_L);
	
	while(p!=NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}
#endif
