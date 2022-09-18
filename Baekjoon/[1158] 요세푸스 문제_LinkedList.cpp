#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* nextNode;
	Node* prevNode;
}Node;

typedef struct LinkedList
{
	Node* head;
	Node* tail;
	int size = 0;
}LinkedList;

void Push(LinkedList* list, int data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (list->head == nullptr)
	{
		list->head = newNode;
	}
	else
	{
		newNode->prevNode = list->tail;
		list->tail->nextNode = newNode;
	}

	++list->size;
	list->tail = newNode;
}

int Pop(LinkedList* list, int index)
{
	int count = 0;
	int data;
	Node* currentNode = list->head;

	while (count < index)
	{
		currentNode = currentNode->nextNode;
		++count;
	}

	if (count > 0)
		currentNode->prevNode->nextNode = currentNode->nextNode;
	else
		list->head = currentNode->nextNode;

	if (count < list->size - 1)
		currentNode->nextNode->prevNode = currentNode->prevNode;
	else
		list->tail = currentNode->prevNode;

	--list->size;
	data = currentNode->data;

	free(currentNode);

	return data;
}

int GetSize(LinkedList* list)
{
	return list->size;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	LinkedList list = {};

	cin >> n >> k;

	for (int i = 1; i < n + 1; ++i)
		Push(&list, i);

	int index = 0;
	cout << '<';
	while (GetSize(&list) > 0)
	{
		index += k;

		if (index % GetSize(&list) != 0)
			index = index % GetSize(&list) - 1;
		else
			index = GetSize(&list) - 1;

		cout << Pop(&list, index);
		if (GetSize(&list) != 0)
			cout << ", ";
	}
	cout << '>';
}