#include <iostream>
#include "vector.h"

vector::vector()
{
	this->size = 0;				
	this->arr = nullptr;
}

vector::vector(const int * mas, int length)
{
	this->size = length;
	this->arr = new int[this->size]{ 1 };
	for (int i = 0; i < length; i++)
		this->arr[i] = mas[i];
}

vector::~vector()
{
	delete[] arr;
}
  
vector::vector(const vector & v)
{
	this->size = v.size;
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = v.arr[i];
} 

bool vector::push(const int & item)
{
	int * tmp = new int[this->size];
	for (int i = 0; i < this->size; i++)
		tmp[i] = this->arr[i];
	delete[]this->arr;

	this->arr = new int[this->size+1];
	if (this->arr == nullptr)		// validation of memory allocation
		return false;
	for (int i = 0; i < this->size; i++)
		this->arr[i] = tmp[i];
	this->arr[this->size++] = item;
	delete[] tmp;

	return true;
}

bool vector::pushByIndex(int index, const int & item)
{
	if (index > this->size)
		this->push(item);
	else if (index < 0)
		std::cout << "Index cannot be less than 0!!!\n";
	else
	{
		int * tmp = new int[++this->size];
		for (int i = 0; i < index; i++)
			tmp[i] = this->arr[i];
		tmp[index] = item;
		for (int j = index; j < this->size; j++)
			tmp[j+1] = this->arr[j];
		delete[] this->arr;
		this->arr = new int[this->size];
		if (this->arr == nullptr)		// validation of memory allocation
			return false;
		for (int i = 0; i < this->size; i++)
			this->arr[i] = tmp[i];
		delete[] tmp;
	}
	return true;
}

bool vector::popByIndex(int index)
{
	if (index > this->size)
	{
		std::cout << "Size of array is less than index of element "
			<< "that you want to delete!!!\n";
		return false;
	}
	int * tmp = new int[this->size-1];
	for (int i = 0; i < index; i++)
		tmp[i] = this->arr[i];
	for (int i = index; i < this->size; i++)
		tmp[i] = this->arr[i+1];
	delete[] this->arr;
	this->arr = new int[--this->size];
	if (this->arr == nullptr)		// validation of memory allocation
		return false;
	for (int i = 0; i < this->size; i++)
		this->arr[i] = tmp[i];
	delete[] tmp;

	return true;
}

void vector::clear()
{
	delete[] arr;
	this->size = 0;
	arr = new int[this->size];
}

int vector::findIndex(const int & item)
{
	int res = -1;
	for (int i = 0, j = this->size-1; i <=this->size/2; i++, j--)
	{
		if (this->arr[i] == item)
		{
			res = i;
			break;
		}
		if (this->arr[j] == item)
		{
			res = j;
			break;
		}
	}
	return res;
}

vector & vector::operator=(const vector & v)
{
	if (this == &v)
		return *this;
	delete[] this->arr;
	this->size = v.size;
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = v.arr[i];
	return *this;
}

std::ostream & operator<<(std::ostream & os,
	const vector & v)
{
	for (int i = 0; i < v.size; i++)
		os << v.arr[i] << ' ';

	return os;
}