#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char data[20];
	struct ListNode* link;
}listNode;

typedef struct{
	listNode* head;
}linkedList_h;

linkedList_h * createLinkedList_h(void)
{
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L -> head = NULL;
	return L;
}

void insertFirstNode(linkedList_h* L, char* data)
 
{
	listNode* node1;
	node1 = (listNode*)malloc(sizeof(listNode));
	strcpy(node1 -> data, data);

	if(L -> head == NULL)
	{	
		node1 -> link = NULL;
		L -> head = node1;
	}
		
	else
	{
		node1 -> link  = L-> head;
		L->head = node1;
	}
		
}

void insertLastNode(linkedList_h* L, char* data)
{
	listNode* node1;
        node1 = (listNode*)malloc(sizeof(listNode));
        strcpy(node1 -> data, data);
	
 	listNode* p;
	p = L -> head;
	
	while(p -> link != NULL)
	{
		p=p->link;	
	}
	
	node1->link = NULL;
	p->link = node1;
}

listNode * searchNode(linkedList_h* L, char* data)
{
	listNode* p;
	p = L -> head;

	if(L-> head == NULL)
	{
		printf("empty");
	}

	else
	{	while(1)
		{
			if(strcmp(p->data ,data) == 0)
			{
				return p;
				break;
				free(p);
			}

			else
				 return p->link;
		}

	}
}

void insertMiddleNode(linkedList_h* L, listNode* p, char* data)
{ 
	listNode* node1;
	node1 = (listNode*)malloc(sizeof(listNode));
	strcpy(node1 -> data, data);

	node1 -> link = p->link;
	p->link = node1;

	
}

linkedList_h* reverse(linkedList_h* L)
{
        linkedList_h* R;
        R = (linkedList_h*)malloc(sizeof(linkedList_h));
        R -> head = NULL;
	
	listNode* p;
        p = L -> head;


	//while
	

	
        return R;

}



void deleteNode(linkedList_h* L, listNode* p)
{
	if(L->head == NULL)
	{
		printf("empty");
	}

	else
	{
		listNode* n;
		n = L->head;

		while(1)


		{
			if(L->head==p)
			{
				L->head = p->link;
				free(p);
				break;
			}

			if(p == n->link)
			{
				n->link = p->link;
				free(p);
				break;
			}
		
			else
				n = n->link;		

		}

	}
}

void deleteFirstNode(linkedList_h* L)
{
	listNode* p;
        p = L -> head;


	if(L->head==NULL)
        {
                printf("empty\n");
        }

	else
	{

		L->head = p->link;
	
		free(p);
	}

}

void deleteLastNode(linkedList_h* L)
{	

	if(L->head==NULL)
        {
                printf("empty\n");
        }

        else
        {
                listNode* p;
                p = L->head;


		while(1)
		{
			if(p-> link-> link == NULL) 
			{
                        	p->link = NULL;
				free(p->link);
				break;
			}

			p = p->link;
                }		               
		
		
        }

}


void printList(linkedList_h * L) {

	if(L->head==NULL)
	{
		printf("empty\n");
	}
	else
	{
		listNode* p;
        	p = L -> head;

		while(p->link != NULL) {
			printf("%s ", p->data);
			p = p->link;
		}

		printf("%s\n", p->data);}

}

void freeLinkedList_h(linkedList_h * L) {
	listNode* p;
	while(L -> head != NULL) {
		p = L -> head;
		L -> head = L -> head -> link;
		free(p);
		p = NULL;
	}
}

int main() {
	
	linkedList_h* L;
	L=createLinkedList_h();
	listNode* p;
	
	

	printf("[create]\n");	
	printList(L);
	printf("\n");

	printf("[insert]\n");
	insertFirstNode(L, "apple");	
	printList(L);
	printf("\n");

	printf("[last insert]\n");
	insertLastNode(L, "banana");

	printList(L);
	printf("\n");

	printf("[last insert]\n");
	insertLastNode(L, "grape");

	printList(L);
	printf("\n");

	printf("[banana search]\n");
	p = searchNode(L,"banana");
	
	if(p == NULL) { printf("data NULL"); }
	else { printf("%s search\n", p->data); }
	
	printf("\n");
	searchNode(L, "banana");

	printf("[banana next orange input]\n");
	insertMiddleNode(L,p,"orange");
	printList(L);

	printf("\n");
	printf("[reverse]\n");
	reverse(L);
	printList(L);	

	printf("\n");
	printf("[banana delete]\n");
	p = searchNode(L, "banana");

	deleteNode(L,p);
	printList(L);
	printf("\n");

	printf("[FirstNode delete]\n");
	deleteFirstNode(L);
	printList(L);
	printf("\n");

	printf("[LastNode delete]\n");
	deleteLastNode(L);
	printList(L);
	printf("\n");
	

	printf("[end]\n");
	freeLinkedList_h(L);

	printList(L);

	return 0;
}
