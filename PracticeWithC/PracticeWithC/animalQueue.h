#pragma once
#include "queue.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// 3.6
// ���� ���� ������ ���� ������ ���� ��ȣ��
// ���� ����̸� ����
// ���� ������ �������� �Ծ��� �����ϰ�, ���� ����� �� ������ ����
// Ư���� ������ ������ ������ ���� ����.
// enqueue, dequeueAny, dequeueDog, dequeueCat ������ ����



// �߻� Ŭ���� Animal�� Dog�� Cat�� ����ϴ� ������
// dequeueAny���� �� ������ �����ϴ� ��ü�� ���ϵǾ�� �ϱ� ����.
// enqueue�� ���� �ϳ��� ǥ���� �� �־� ����.

class Animal {
private:
	string name;
	int order;

public:

	void SetOrder(int _order)
	{
		order = _order;
	}

	void SetName(string _name)
	{
		name = _name;
	}

	int GetOrder()
	{
		return order;
	}

	string GetName()
	{
		return name;
	}

	bool isOlder(Animal* a)
	{
		return order < a->GetOrder();
	}

	Animal()
	{
		SetName("Animal");
	}
	virtual ~Animal() {}
};


class Dog : public Animal {
public:
	Dog()
	{
		SetName("Dog");
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		SetName("Cat");
	}
};

class AnimalQueue {
private:
	MyQueue<Dog*> dogQueue;
	MyQueue<Cat*> catQueue;
	int AnimalOrder;

public:
	AnimalQueue() : AnimalOrder(1) {}

	void enqueue(Animal* a)
	{
		a->SetOrder(AnimalOrder++);
		if (typeid(*a) == typeid(Dog))
		{
			dogQueue.Enqueue(static_cast<Dog*>(a));
		}
		else if (typeid(*a) == typeid(Cat))
		{
			catQueue.Enqueue(static_cast<Cat*>(a));
		}
	}

	Dog* dequeueDog()
	{
		if (dogQueue.isEmpty())
			return nullptr;

		return dogQueue.Dequeue()->data;
	}

	Cat* dequeueCat()
	{
		if (catQueue.isEmpty())
			return nullptr;

		return catQueue.Dequeue()->data;
	}

	Animal* dequeueAny()
	{
		// ��� ���� ��� �ݴ� ������ ��ȯ
		if (dogQueue.isEmpty())
			return dequeueCat();

		else if (catQueue.isEmpty())
			return dequeueDog();

		// �� ���� ť�� ������ ��� ������ ���ؼ� ��ȯ
		Animal* dog = dogQueue.Peek()->data;
		Animal* cat = catQueue.Peek()->data;

		if (dog->isOlder(cat))
			return dequeueCat();
		else
			return dequeueDog();
	}

};
