#include "DynamicIntegerArray.h"

void DynamicIntegerArray::expand(const int multiplication )
{
	this->capacity *= multiplication;

	int *pTempIntArray = new int[this->capacity];

	for (int i = 0; i < this->numberOfElements; i++)
	{
		pTempIntArray[i] = this->pIntArray[i];
	}

	delete[] this->pIntArray;
	this->pIntArray = pTempIntArray;
}

DynamicIntegerArray::DynamicIntegerArray(const int capacity )
{
	this->capacity = capacity;

	if (this->capacity < 0)
	{
		throw ("Out of bounds exception");
	}

	this->numberOfElements = 0;
	this->pIntArray = new int[capacity];
}

DynamicIntegerArray::~DynamicIntegerArray()
{
	delete[] this->pIntArray; 
}

void DynamicIntegerArray::insert(const int value)
{
	if (this->numberOfElements >= this->capacity)
	{
		expand();
	}
	this->pIntArray[this->numberOfElements++] = value;
}

void DynamicIntegerArray::insertAt(const int value, const int position)
{
	if (position < 0 || position > this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}

	else if (this->numberOfElements >= this->capacity)
	{
		this->capacity *= 2;

		int *pTempIntArray = new int[this->capacity];

		for (int i = 0; i < position; i++)
		{
			pTempIntArray[i] = this->pIntArray[i];
		}

		pTempIntArray[position] = value;

		for (int i = position+1; i < this->numberOfElements+1; i++)
		{
			pTempIntArray[i] = this->pIntArray[i];
		}

		delete[] this->pIntArray;
		this->pIntArray = pTempIntArray;
		this->numberOfElements++;
	}
	else
	{
		for (int i = this->numberOfElements; i > position; i--)
		{
			pIntArray[i] = pIntArray[i-1];
		}
		pIntArray[position] = value;
		this->numberOfElements++;
	}
}

void DynamicIntegerArray::deleteAt(const int position)
{
	int del_resizing_percentage = 4;
	
	if (position < 0 || position >= this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}
	else if(((this->capacity)/(this->numberOfElements-1)) >= del_resizing_percentage)
	{
		this->capacity /= 2;

		int *pTempIntArray = new int[this->capacity];

		for (int i = 0; i < position; i++)
		{
			pTempIntArray[i] = this->pIntArray[i];
		}
		for (int i = position; i < this->numberOfElements-1; i++)
		{
			pTempIntArray[i] = this->pIntArray[i+1];
		}

		delete[] this->pIntArray;
		this->pIntArray = pTempIntArray;
		this->numberOfElements--;
	}
	else
	{
		for (int i = position; i < this->numberOfElements - 1; i++)
		{
			pIntArray[i] = pIntArray[i + 1];
		}
		this->numberOfElements--;
	}
}

int& DynamicIntegerArray::getAt(const int position)
{
	if (position < 0 || position >= this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}
	return this->pIntArray[position];
}

int DynamicIntegerArray::find(const int value)
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		if(this->pIntArray[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int DynamicIntegerArray::size()
{
	return this->numberOfElements;
}

int& DynamicIntegerArray::operator[](const int position)
{
	if (position < 0 || position >= this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}

	return this->pIntArray[position];
}

void DynamicIntegerArray::updateAt(const int value, const int position)
{
	if (position < 0 || position >= this->numberOfElements)
	{
		throw ("Out of bounds exception");
	}
	this->pIntArray[position] = value;
}