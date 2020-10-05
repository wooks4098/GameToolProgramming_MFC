/*
   Simple Linked List
   학번 : 2019510014
   이름 : 신승규

*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {    // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

/*
   함수명 : error()
   함수 설명 : 메시지를 화면에 출력
*/
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}


ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}


ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//======================================================================
// 새로 작성된 함수
//======================================================================

void insert2(ListNode* head, element newValue)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = newValue;
	p->link = NULL;

	head->link = p;

	return ;
}

int delete2(ListNode* head, ListNode* newValue)
{
	ListNode* removed;
	removed = newValue->link;
	newValue->link = removed->link;
	free(removed);
	return head;
}

void print_list2(ListNode* head)
{
	ListNode* p = head;
	if (head == NULL) return;

	while (0)
	{
		printf("%d ->", p->data);
		p = p->link;
	}
	printf("\n");
}

//======================================================================

int main(void)
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		insert2(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);

	}
	return 0;
}