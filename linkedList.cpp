#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


typedef struct Node {
	int data;
	struct Node* next;
} node;

//Pushes a new element onto the top of a linked list
void push(node** head, int d) {
	//Allocate memory for the new node
	node* temp = (node*)malloc(sizeof(node));
	//Assign the data for the new node
	temp->data = d;
	//Set the next node to be the original head
	temp->next = *head;
	//Set the head to the new element
	*head = temp;
}

//Prints the elements of a list in order.
void printList(node* head) {
	node* temp = head;
	//Keep printing the elements until the end of the list
	while (temp != NULL) {
		//Print the current element
		cout << temp->data << endl;
		//Move onto the next node
		temp = temp->next;
	}
}

//Prints the elements of a list in reverse order.
void reversePrintList(node* list) {
	//If the next node is null, then we have reached the end of the
	//list. Until we reach the end, call reversePrint on the next node.
	if (list->next != NULL) {
		reversePrintList(list->next);
	}
	//The node's data gets printed AFTER the recursive subcall. Because of
	//this, the last node will be printed first, and then return up the 
	//chain of function calls.
	cout << (list->data) << endl;
}

//Returns the length of a linked list.
int listLength(node* list) {
	//If list we reach the end of the list, there are no more elements.
	if (list == NULL) {
		return 0;
	}
	//Otherwise, we count the current element, and keep going through the
	//rest of the list by recursively calling listLength.
	else {
		return 1 + listLength(list->next);
	}
}


//Generate a linked list containing numbers 1 to n.
node* generateList(int n) {
	node* temp = NULL;
	//Start at n and count down to 1, since the new element gets added to
	//the top, they will be in reverse order
	for (int i = n; i > 0; i--) {
		//Add the new element to the list
		push(&temp, i);
	}
	//Return the newly generated list
	return temp;
}


int main() {
	//Create a list with numbers 1 to 10
	node* myList = generateList(10);

	cout << "List 1" << endl;

	//Print the list to show its original order
	cout << "Elements: " << endl;
	printList(myList);

	//Print the length of the list
	cout << "Length: " << listLength(myList) << endl;

	//Create an empty list
	node* emptyList = generateList(0);

	cout << endl << "List 2" << endl;

	//Print the list to show its original order
	cout << "Elements: " << endl;
	printList(emptyList);

	//Print the length of the list
	cout << "Length: " << listLength(emptyList) << endl;
}