#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};

void printList(struct node* h) {
	while (h) {
		printf("%d\n", h->data);
		h = h->next;
	}
	printf("\n");
}

void insertToList(struct node** pth, int val) {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = val;
	tmp->next = *pth;
	*pth = tmp;
}

int main() {
	struct node* head = NULL;

	insertToList(&head, 5);
	insertToList(&head, 3);
	insertToList(&head, 9);

	printList(head);
}
