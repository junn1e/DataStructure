#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{
	if (head == NULL) return;
	ListNode* p = head;
	while (p->link != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d\n", p->data);
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->link = head;
	node->data = data;
	return node;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) {//head�� NULL�� ��� �б� ���� ����
		node->link = NULL;
		node->data = data;
		return node;
	}
	ListNode* p = head;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = node;
	node->link = NULL;
	node->data = data;
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

int search_list(ListNode* head, element value) {
	if (head == NULL) {
		printf("head�� NULL�Դϴ�.");
		return -1;
	}
	if (head->data == value) {
		return 1;
	}
	ListNode* p = head->link;
	int i;
	for ( i = 2; p->link != NULL; i++, p = p->link) {
		if (p->data == value) {
			return i;
		}
	}
	if (p->data == value) {
		return i;
	}
	else {
		printf("���� �������� �ʽ��ϴ�.\n");
		return -1;
	}
}

ListNode* delete_by_pointer(ListNode* head, ListNode* pre) {
	if (head == NULL);
	else if (pre == NULL) {//ù��° ��带 �����ϱ� ���� �μ�
		ListNode* removed = head;
		head = removed->link;
		free(removed);
	}
	else if (pre->link == NULL);
	else {
		ListNode* removed;
		removed = pre->link;
		pre->link = removed->link;
		free(removed);
	}
	return head;
}

ListNode* delete_by_index(ListNode* head, int index) {
	if (head == NULL || index < 1) {
		return head;
	}
	if (index == 1) {
		return delete_by_pointer(head, NULL);
	}
	ListNode* p = head->link;
	for (int i = 1; i < index; i++) {
		if (p == NULL) {
			printf("�б� ����.\n");
			return head;
		}
		p = p->link;
	}
	return delete_by_pointer(head, p);
}

ListNode* search_delete(ListNode* head, element value) {
	int index = search_list(head, value);
	return delete_by_index(head, index);
}

int main(void)
{
	ListNode* head = NULL;

	head = insert_last(head, 10);
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	print_list(head);

	head = search_delete(head, 10);
	print_list(head);
	head = delete_by_index(head, 2);
	print_list(head);
	head = delete_by_index(head, 2);
	print_list(head);

	return 0;
}