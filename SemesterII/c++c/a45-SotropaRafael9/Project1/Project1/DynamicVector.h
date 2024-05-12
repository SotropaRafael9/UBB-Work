#pragma once
#include "Domain.h"

typedef Dog TElem;

template <typename TElem>

class DynamicVector {
private:
	TElem* elements;
	int capacity;
	int size;

public:
	//construcot
	DynamicVector(int cap);

	DynamicVector(const DynamicVector<TElem>& other);

	~DynamicVector();

	DynamicVector<TElem>& operator=(const DynamicVector other_vect);

	void add_elem(TElem element);

	void delete_element(int pos);

	void update_element(TElem element, int pos);
	
	int get_size();

	TElem get_element(int pos);
	
	TElem* get_elements();

//	void initialize(vector_vector);

	DynamicVector operator+(const TElem v);
	
private:
	void size_grow();

};

template <typename TElem>
DynamicVector<TElem>::DynamicVector(int cap)
{
	if (cap <= 0)
		throw("capacity must be a positive non-zero intiger");
	this->capacity = cap;
	this->size = 0;
	this->elements = new TElem[capacity];

}

template <typename TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector<TElem>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->elements = new TElem[capacity];

	for (int i = 0; i < other.size; i++)
		this->elements[i] = other.elements[i];

}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector()
{
	delete[] this->elements;
}

template <typename TElem>
void DynamicVector<TElem>::size_grow()
{
	this->capacity *= 2;
	TElem* tempArr = new TElem[capacity];

	for (int i = 0; i < this->size; i++)
		tempArr[i] = this->elements[i];

	delete[] this->elements;
	this->elements = tempArr;
}

template <typename TElem>
void DynamicVector<TElem>::add_elem(TElem element)
{
	if (size >= capacity) size_grow();

	elements[size++] = element;
}

template <typename TElem>
void DynamicVector<TElem>::delete_element(int pos)
{
	if (pos >= this->size || pos < 0) throw ("Index out of range!");

	for (int i = pos; i < this->size - 1; i++)
		this->elements[i] = this->elements[i + 1];

	this->size--;
}

template <typename TElem>
void DynamicVector<TElem>::update_element(TElem element, int pos)
{
	if (pos >= this->size) throw ("Index out of range!");

	this->elements[pos] = element;
}


template <typename TElem>
int DynamicVector<TElem>::get_size()
{
	return this->size;
}

template <typename TElem>
TElem DynamicVector<TElem>::get_element(int pos)
{
	if (pos >= this->size || pos < 0) throw("Index out of range.");

	return this->elements[pos];
}

template <typename TElem>
TElem* DynamicVector<TElem>::get_elements()
{
	return this->elements;
}


template <typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator=(const DynamicVector other_vect)
{
	this->size = other_vect.size;
	this->capacity = other_vect.capacity;

	delete[] this->elements;
	this->elements = new TElem[other_vect.capacity];
	for (int i = 0; i < other_vect.size; i++)
		this->elements[i] = other_vect.elements[i];

	return *this;
}

template <typename TElem>
DynamicVector<TElem> DynamicVector<TElem>::operator+(const TElem v)
{
	DynamicVector<TElem> new_vect{ capacity };


	new_vect.size = this->size;

	for (int i = 0; i < this->size; i++)
		new_vect.elements[i] = this->elements[i];
	new_vect.add_elem(v);
	return new_vect;
}