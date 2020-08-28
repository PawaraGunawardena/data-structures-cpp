#include "LinkedListInt.h"

LinkedListInt::LinkedListInt()
{
	this->head = nullptr;
	this->last = nullptr;
	this->iterator = 0;
	this->numberOfElements = 0;

	this->pNewNode = nullptr;
	this->pTempNode = nullptr;
}

LinkedListInt::~LinkedListInt()
{
	this->pTempNode = this->head;
	while (this->pTempNode->next != nullptr)
	{
		this->pNewNode = this->pTempNode->next;
		delete this->pTempNode;
		this->pTempNode = this->pNewNode;
	}
	delete this->pNewNode;
}

void LinkedListInt::addElementBack(int data)
{
	this->pNewNode = new node;
	this->pNewNode->next = nullptr;
	this->pNewNode->data = data;

	if (!empty())
	{
		this->last->next = this->pNewNode;
		this->pNewNode->prev = this->last;
		this->last = this->pNewNode;
		this->numberOfElements++;
	}
	else
	{
		this->pNewNode->prev = nullptr;
		this->head = this->pNewNode;
		this->last = this->pNewNode;
		this->numberOfElements++;
	}
}

void LinkedListInt::addElementFront(int data)
{
	this->pNewNode = new node;
	this->pNewNode->prev = nullptr;
	this->pNewNode->data = data;

	if (!empty())
	{
		this->head->prev = this->pNewNode;
		this->pNewNode->next = this->head;
		this->head = this->pNewNode;
		this->numberOfElements++;
	}
	else
	{
		this->pNewNode->next = nullptr;
		this->head = this->pNewNode;
		this->last = this->pNewNode;
		this->numberOfElements++;
	}
}

void LinkedListInt::addElementAt(int data, int index)
{
	if (index > this->numberOfElements || index < 0)
	{
		throw "Out of bound";
	}
	else if (this->numberOfElements == index)
	{
		this->addElementBack(data);
	}
	else if (index == 0)
	{
		this->addElementFront(data);
	}
	else
	{
		this->pNewNode = new node;
		this->pNewNode->data = data;
		this->pTempNode = this->head;
		
		this->iterator = 0;
		while (this->iterator < index)
		{
			this->pTempNode = this->pTempNode->next;
			this->iterator++;
		}
	
		this->pNewNode->prev = this->pTempNode->prev;
		this->pTempNode->prev->next =this-> pNewNode;
		this->pNewNode->next = this->pTempNode;
		this->pTempNode->prev = this->pNewNode;
		this->numberOfElements++;
	}
}

void LinkedListInt::removeElementAt(int index)
{
	if (index > this->numberOfElements-1 || index < 0)
	{
		throw "Out of bound";
	}

	this->iterator = 0;
	this->pTempNode = this->head;
	while (this->iterator < index)
	{
		this->pTempNode = this->pTempNode->next;
		this->iterator++;
	}
	this->pTempNode->prev->next = this->pTempNode->next;
	this->pTempNode->next->prev = this->pTempNode->prev;
	this->numberOfElements--;
}

void LinkedListInt::updateElementAt(int new_data, int index)
{
	if (index > this->numberOfElements - 1 || index < 0)
	{
		throw "Out of bound";
	}

	this->iterator = 0;
	this->pTempNode = this->head;
	while (this->iterator < index)
	{
		this->pTempNode = this->pTempNode->next;
		this->iterator++;
	}

	this->pTempNode->data = new_data;
}

int& LinkedListInt::getElementAt(int index)
{
	if (index > this->numberOfElements - 1 || index < 0)
	{
		throw "Out of bound";
	}

	this->iterator = 0;
	this->pTempNode = this->head;

	while (this->iterator < index)
	{
		this->pTempNode = this->pTempNode->next;
		this->iterator++;
	}

	return this->pTempNode->data;
}

bool LinkedListInt::empty()
{
	if (this->head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedListInt::size()
{
	return this->numberOfElements;
}

int& LinkedListInt::getElementEnd()
{
	if (this->numberOfElements == 0)
	{
		throw "Empty List. Index out of bound";
	}
	return this->last->data;
}

int& LinkedListInt::getElementFront()
{
	if (this->numberOfElements == 0)
	{
		throw "Empty List. Index out of bound.";
	}
	return this->head->data;
}

int LinkedListInt::find(const int value)
{
	this->iterator = 0;
	this->pTempNode = this->head;

	while (this->iterator < this->numberOfElements)
	{
		if(this->pTempNode->data == value)
		{
			return this->iterator;
		}
		this->pTempNode = this->pTempNode->next;
		this->iterator++;
	}
	return -1;
}
