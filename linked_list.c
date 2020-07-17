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

linkedList_h * createLinkedList_h(void);
void insertLastNode(linkedList_h* L, char* data);
void deleteNode(linkedList_h* L, listNode* p);
void printList(linkedList_h * L);
void deleteFirstNode(linkedList_h* L);
listNode * searchNode(linkedList_h* L, char* data);

int main(){

    linkedList_h* L;
	L=createLinkedList_h();
	listNode* p = NULL;

    int play = 1;
    while(play){
        printf("메뉴를 선택하세요\n 1. 삽입  2. 삭제  3. 출력  4. 종료\n");
        int menu;
        scanf("%d", &menu);
        if(menu == 1){
            printf("마지막 노드에 추가할 데이터를 입력하세요 : ");
            char data[20] = {'\0', };
            scanf("%s", data);
            insertLastNode(L, data);
        }else if(menu == 2){
            printf("메뉴를 선택하세요\n 1. 첫번째 노드 삭제  2. 선택삭제\n");
            int deletemenu;
            scanf("%d", &deletemenu);
            if(deletemenu == 1){
                deleteFirstNode(L);
            }else if(deletemenu == 2){
                printf("삭제할 데이터를 입력하세요 : ");
                char data[20] = {'\0', };
                scanf("%s", data);
                p = searchNode(L, data);
                deleteNode(L, p);
            }else{
                 printf("메뉴를 잘못선택하여 메인으로 돌아갑니다.\n\n");
            }
        }else if(menu == 3){
            printf("리스트 데이터 출력\n");
            printList(L);
        }else if(menu == 4){
            printf("프로그램을 종료합니다\n\n");
            play = 0;
        }else{
            printf("메뉴 선택을 다시해주세요\n\n");
        }
    }
}

linkedList_h * createLinkedList_h(void)
{
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L -> head = NULL;
	return L;
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
