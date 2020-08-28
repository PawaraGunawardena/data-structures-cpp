#pragma once

template<typename T>
class DynamicTemplateArray
{
private:
	int capacity;
	int numberOfElements;
	T *pTArray;

	void expand(const int multiplication = 2);

public:
	DynamicTemplateArray(const int capacity = 10);
	~DynamicTemplateArray();

	void insert(const T& value);
	void insertAt(const T& value, const int position);
	void deleteAt(const int position);
	void updateAt(const T& value, const int position);
	T& getAt(const int position);
	int find(const T& value);
	int size();
	T& operator[](const int index);
};

template<typename T> 
void DynamicTemplateArray<T>::expand(const int multiplication)
{
	this->capacity *= multiplication;
	T *pTempTArray = new T[capacity];

	for (int i = 0; i < this->numberOfElements; i++)
	{
		pTempTArray[i] = this->pTArray[i];
	}
	delete[] this->pTArray;
	this->pTArray = pTempTArray;
}

template<typename T>
DynamicTemplateArray<T>::DynamicTemplateArray(const int capacity)
{
	this->capacity = capacity;
	if (capacity < 0)
	{
		throw ("Out of bounds exception");
	}

	this->numberOfElements = 0;
	this->pTArray = new T[capacity];
}

template<typename T>
DynamicTemplateArray<T>::~DynamicTemplateArray()
{
	delete[] this->pTArray;
}

template<typename T>
void DynamicTemplateArray<T>::insert(const T& value)
{
	if (this->numberOfElements >= capacity)
	{
		this->expand();
	}
	pTArray[this->numberOfElements++] = value;
}

template<typename T>
void DynamicTemplateArray<T>::insertAt(const T& value, const int position)
{
	if (position < 0 || position > this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}

	else if (this->numberOfElements >= this->capacity)
	{
		this->capacity *= 2;

		T *pTempTArray = new T[this->capacity];

		for (int i = 0; i < position; i++)
		{
			pTempTArray[i] = this->pTArray[i];
		}

		pTempTArray[position] = value;

		for (int i = position+1; i < numberOfElements+1; i++)
		{
			pTempTArray[i] = pTArray[i];
		}
		delete[] this->pTArray;
		this->pTArray = pTempTArray;
		this->numberOfElements++;
	}
	else
	{
		for (int i = this->numberOfElements; i > position; i--)
		{
			pTArray[i] = this->pTArray[i-1];
		}
		this->pTArray[position] = value;
		this->numberOfElements++;
	}
}

template<typename T>
void DynamicTemplateArray<T>::deleteAt(const int position)
{
	int del_resizing_percentage = 4;
	if (position < 0 || position >= this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}
	else if(((this->capacity)/(this->numberOfElements-1)) >= del_resizing_percentage)
	{
		this->capacity /= 2;

		T *pTempTArray = new T[this->capacity];

		for (int i = 0; i < position; i++)
		{
			pTempTArray[i] = this->pTArray[i];
		}
		for (int i = position; i < this->numberOfElements-1; i++)
		{
			pTempTArray[i] = this->pTArray[i+1];
		}

		delete[] this->pTArray;
		this->pTArray = pTempTArray;
		this->numberOfElements--;
	}
	else
	{
		for (int i = position; i < this->numberOfElements - 1; i++)
		{
			this->pTArray[i] = this->pTArray[i + 1];
		}
		this->numberOfElements--;
	}
}

template<typename T>
T& DynamicTemplateArray<T>::getAt(const int position)
{
	if (position <0 || position >= this->numberOfElements)
	{
		throw("Out of bounds");
	}
	return this->pTArray[position];
}

template<typename T>
int DynamicTemplateArray<T>::find(const T& value)
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		if(this->pTArray[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
int DynamicTemplateArray<T>::size()
{
	return this->numberOfElements;
}

template<typename T>
inline T & DynamicTemplateArray<T>::operator[](const int index)
{
	if (index < 0 || index >= this->numberOfElements)
	{
		throw ("Index out of bound");
	}
	return this->pTArray[index];
}

template<typename T>
inline void DynamicTemplateArray<T>::updateAt(const T& value, const int position)
{
	if (position < 0 || position >= this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}
	this->pTArray[position] = value;
}