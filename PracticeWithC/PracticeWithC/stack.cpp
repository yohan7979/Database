#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct StackNode {
	int data;
	StackNode* next;
	StackNode(int d) : data(d), next(NULL) { }
};


class MyStack {
private:
	StackNode* top;

public:
	MyStack() : top(nullptr) {}
	bool isEmpty()
	{
		if (top == nullptr) return true;
		return false;
	}

	//push stack
	void Push(int data)
	{
		StackNode* newNode = new StackNode(data);
		if (top == nullptr)
			top = newNode;
		else
		{
			newNode->next = top;
			top = newNode;
		}
	}

	//pop stack
	StackNode* Pop()
	{
		if (top == nullptr) return nullptr;
		StackNode* topNode = top;
		top = top->next;
		return topNode;	
	}

	//peek stack
	StackNode* Peek()
	{
		if (top == nullptr) return nullptr;
		return top;
	}

	void PrintAll()
	{
		StackNode* curNode = top;
		while (curNode != nullptr)
		{
			cout << curNode->data << endl;
			curNode = curNode->next;
		}
	}
};

void main()
{
	MyStack stack;
	for(int i =0; i<10; ++i)
		stack.Push(i);
	
	StackNode* node = stack.Pop();
	delete node;

	stack.PrintAll();
}