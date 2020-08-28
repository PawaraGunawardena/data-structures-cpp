#pragma once

template<typename T>
class LinkedListTemplate
{
private:
	struct node
	{
		T data;
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
	LinkedListTemplate();
	~LinkedListTemplate();
	void addElementBack(const T& data);
	void addElementFront(const T& data);
	void addElementAt(const T& data, const int index);
	void removeElementAt(int index);
	void updateElementAt(const T& new_data, const int index);
	T& getElementAt(const int index);
	T& getElementEnd();
	T& getElementFront();
	bool empty();
	int size();
	int find(const T& value);
};

template<typename T>
LinkedListTemplate<T>::LinkedListTemplate()
{
	this->head = nullptr;
	this->last = nullptr;
	this->iterator = 0;
	this->numberOfElements = 0;

	this->pNewNode = nullptr;
	this->pTempNode = nullptr;
}

template<typename T>
LinkedListTemplate<T>::~LinkedListTemplate()
{
	this->pTempNode = head;
	while (this->pTempNode->next != nullptr)
	{
		this->pNewNode = this->pTempNode->next;
		delete this->pTempNode;
		this->pTempNode = this->pNewNode;
	}
	delete this->pNewNode;
}

template<typename T>
inline void LinkedListTemplate<T>::addElementBack(const T & data)
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

template<typename T>
inline void LinkedListTemplate<T>::addElementFront(const T & data)
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

template<typename T>
inline void LinkedListTemplate<T>::addElementAt(const T & data, const int index)
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

		iterator = 0;
		while (iterator < index)
		{
			this->pTempNode = this->pTempNode->next;
			this->iterator++;
		}

		this->pNewNode->prev = this->pTempNode->prev;
		this->pTempNode->prev->next = this->pNewNode;
		this->pNewNode->next = this->pTempNode;
		this->pTempNode->prev = this->pNewNode;
		this->numberOfElements++;
	}
}

template<typename T>
void LinkedListTemplate<T>::removeElementAt(const int index)
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
	this->pTempNode->prev->next = this->pTempNode->next;
	this->pTempNode->next->prev = this->pTempNode->prev;
	this->numberOfElements--;
}

template<typename T>
void LinkedListTemplate<T>::updateElementAt(const T& new_data, const int index)
{
	if (index > this->numberOfElements - 1 || index < 0)
	{
		throw "Out of bound";
	}

	this->iterator = 0;
	this->pTempNode = head;
	while (this->iterator < index)
	{
		this->pTempNode = this->pTempNode->next;
		this->iterator++;
	}

	this->pTempNode->data = new_data;
}

template<typename T>
inline T & LinkedListTemplate<T>::getElementAt(const int index)
{
	if (index > this->numberOfElements - 1 || index < 0)
	{
		throw "Out of bound";
	}

	this->iterator = 0;
	this->pTempNode = this->head;

	while (iterator < index)
	{
		this->pTempNode = this->pTempNode->next;
		this->iterator++;
	}
	return this->pTempNode->data;
}

template<typename T>
inline bool LinkedListTemplate<T>::empty()
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

template<typename T>
inline int LinkedListTemplate<T>::size()
{
	return this->numberOfElements;
}

template<typename T>
inline T & LinkedListTemplate<T>::getElementEnd()
{
	if (this->numberOfElements == 0)
	{
		throw "Empty List. Index out of bound";
	}
	return this->last->data;
}

template<typename T>
inline T & LinkedListTemplate<T>::getElementFront()
{
	if (this->numberOfElements == 0)
	{
		throw "Empty List. Index out of bound.";
	}
	return this->head->data;
}

template<typename T>
inline int LinkedListTemplate<T>::find(const T& value)
{
	this->iterator = 0;
	this->pTempNode = this->head;

	while (this->iterator < this->numberOfElements)
	{
		if(this->pTempNode->data == value)
		{
			return this->iterator;
		}
		this->pTempNode = pTempNode->next;
		this->iterator++;
	}
	return -1;
}
