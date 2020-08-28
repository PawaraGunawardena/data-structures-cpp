#pragma once

class LinkedListInt
{
private:
	struct node
	{
		int data;
		node* next;
		node* prev;
	};

	node* head;
	node* last;
	int numberOfElements;
	int iterator;

	node* pNewNode;
	node* pTempNode;

public:
	LinkedListInt();
	~LinkedListInt();
	void addElementBack(const int data);
	void addElementFront(const int data);
	void addElementAt(const int data, const int index);
	void removeElementAt(const int index);
	void updateElementAt(const int new_data, const int index);
	int& getElementAt(const int index);
	int& getElementEnd();
	int& getElementFront();
	int find(const int value);
	bool empty();
	int size();
};