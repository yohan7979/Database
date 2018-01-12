#pragma once
template <class T>
struct QueueNode {
	T data;
	QueueNode* next;
	QueueNode(T d) : data(d), next(nullptr) {}
};


template <class T>
class MyQueue {
private:
	QueueNode<T>* first;
	QueueNode<T>* last;

public:
	MyQueue() : first(nullptr), last(nullptr) {}
	bool isEmpty()
	{
		if (first == nullptr)
			return true;
		return false;
	}

	void Enqueue(T data)
	{
		QueueNode<T>* newNode = new QueueNode<T>(data);
		if (first == nullptr)
			first = last = newNode;
		else
		{
			last->next = newNode;
			last = newNode;
		}
	}

	QueueNode<T>* Dequeue()
	{
		if (first == nullptr) return nullptr;
		QueueNode<T>* outNode = first;
		first = first->next;
		return outNode;
	}


	QueueNode<T>* Peek()
	{
		if (first == nullptr) return nullptr;
		QueueNode<T>* outNode = first;
		return outNode;
	}


	void PrintAll()
	{
		QueueNode<T>* curNode = first;
		while (curNode != nullptr)
		{
			cout << curNode->data << endl;
			curNode = curNode->next;
		}
	}

};

