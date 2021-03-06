#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node* next = nullptr;
	int data;
	Node(int d) : data(d){}
};

class LinkedList {
private:
	Node* head = nullptr;
	
public:
	void appendNode(int data)
	{
		Node* newNode = new Node(data);
		if (head == nullptr)
		{
			head = newNode;
		}

		else
		{
			Node* n = head;
			while (n->next != nullptr)
			{
				n = n->next;
			}
			n->next = newNode;
		}
	}

	void deleteNode(int data)
	{
		Node* delNode = nullptr;
		if (head->data == data)
		{
			delNode = head;
			head = head->next;
			delete delNode;
		}
		else
		{
			Node* n = head;
			while (n->next != nullptr)
			{
				if (n->next->data == data)
				{
					delNode = n->next;
					n->next = n->next->next;
					delete delNode;
				}
				n = n->next;
			}
		}
		
	}

	void PrintAll()
	{
		Node* n = head;
		while (n != nullptr)
		{
			cout << n->data << endl;
			n = n->next;
		}
	}
};

void main()
{
	LinkedList* myList = new LinkedList;
	myList->appendNode(0);
	myList->appendNode(1);
	myList->appendNode(2);
	myList->appendNode(3);
	myList->deleteNode(2);
	myList->PrintAll();
}


