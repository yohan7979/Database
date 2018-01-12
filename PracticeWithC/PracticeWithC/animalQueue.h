#pragma once
#include "queue.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// 3.6
// 먼저 들어온 동물이 먼저 나가는 동물 보호소
// 개와 고양이만 수용
// 가장 오래된 동물부터 입양이 가능하고, 개와 고양이 중 선택이 가능
// 특정한 동물을 지정해 데려갈 수는 없다.
// enqueue, dequeueAny, dequeueDog, dequeueCat 연산을 제공



// 추상 클래스 Animal이 Dog와 Cat을 상속하는 이유는
// dequeueAny에서 두 동물을 포함하는 객체가 리턴되어야 하기 때문.
// enqueue할 때도 하나로 표현할 수 있어 편리함.

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
		// 비어 있을 경우 반대 동물을 반환
		if (dogQueue.isEmpty())
			return dequeueCat();

		else if (catQueue.isEmpty())
			return dequeueDog();

		// 두 개의 큐가 차있을 경우 오더를 비교해서 반환
		Animal* dog = dogQueue.Peek()->data;
		Animal* cat = catQueue.Peek()->data;

		if (dog->isOlder(cat))
			return dequeueCat();
		else
			return dequeueDog();
	}

};
