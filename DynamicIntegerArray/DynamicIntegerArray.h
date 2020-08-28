#pragma once

class DynamicIntegerArray
{
private:
	int capacity;
	int numberOfElements;
	int *pIntArray;
	void expand(const int multiplication = 2);

public:
	DynamicIntegerArray(const int capacity = 10);
	~DynamicIntegerArray();
	void insert(const int value);
	void insertAt(const int value, const int position);
	void deleteAt(const int position);
	void updateAt(const int value, const int position);
	int& getAt(const int position);
	int find(const int value);
	int size();
	int& operator[](const int position);
};