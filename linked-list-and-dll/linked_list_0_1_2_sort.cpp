// CPP Program to sort a linked list 0s, 1s
// or 2s by changing links
#include <bits/stdc++.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data);

// Sort a linked list of 0s, 1s and 2s
// by changing pointers.
Node* sortList(Node* head)
{
	if (!head || !(head->next))
		return head;

	// Create three dummy nodes to point to
	// beginning of three linked lists. These
	// dummy nodes are created to avoid many
	// null checks.
	Node* zeroD = newNode(0);
	Node* oneD = newNode(0);
	Node* twoD = newNode(0);

	// Initialize current pointers for three
	// lists and whole list.
	Node* zero = zeroD, *one = oneD, *two = twoD;

	// Traverse list
	Node* curr = head;
	while (curr) {
		if (curr->data == 0) {
			zero->next = curr;
			zero = zero->next;
			curr = curr->next;
		} else if (curr->data == 1) {
			one->next = curr;
			one = one->next;
			curr = curr->next;
		} else {
			two->next = curr;
			two = two->next;
			curr = curr->next;
		}
	}

	// Attach three lists
	zero->next = (oneD->next) 
? (oneD->next) : (twoD->next);
	one->next = twoD->next;
	two->next = NULL;

	// Updated head
	head = zeroD->next;

	// Delete dummy nodes
	delete zeroD;
	delete oneD;
	delete twoD;

	return head;
}

// Function to create and return a node
Node* newNode(int data)
{
	// allocating space
	Node* newNode = new Node;

	// inserting the required data
	newNode->data = data;
	newNode->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Driver program to test above function*/
int main(void)
{
	// Creating the list 1->2->4->5
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(0);
	head->next->next->next = newNode(1);

	printf("Linked List Before Sorting\n");
	printList(head);

	head = sortList(head);

	printf("Linked List After Sorting\n");
	printList(head);

	return 0;
}
