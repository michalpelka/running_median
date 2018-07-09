#include "heap.hpp"
#include <cstdlib>
#include <assert.h>
void BaseHeap::heapify_fromroot(int i)
{
	int l = left(i);
	int r = right(i);
	int ext = i;

	if (l < heapSize && compare(data[l] , data[i]))
		ext = l;
	if (r < heapSize && compare(data[r] , data[ext]))
		ext = r;
	if (ext != i)
	{
		swap(data[i], data[ext]);
		heapify_fromroot(ext);
	}

}
void BaseHeap::reserve(unsigned int capacity)
{
	this->capacity = capacity;
	// There is no direct realloc equivalent in C++, it is usefull alternative to vectors.
	// https://stackoverflow.com/questions/16714937/what-is-c-version-of-realloc-to-allocate-the-new-buffer-and-copy-the-conten
	// using realloc is best option beacuse we can mos likely grow allocation, without copying data.
	// best option would be std container
	data = (int*)realloc((void*)data, capacity * sizeof(int));
	assert(data);
}
void BaseHeap::heapify(int i)
{
	int p = parent(i);

	// comp - differentiate MaxHeap and MinHeap
	// percolates up
	if( p >= 0 && compare(data[i], data[p]) )
	{
		swap(data[i], data[p]);
		heapify(p);
	}
}

BaseHeap::BaseHeap()
{
	data = NULL;
	heapSize = 0;
	reserve(128);
}
BaseHeap::~BaseHeap()
{
	if (data)
	{
		// we allocate that memory using C lan. We cannot free that memory using
		// delete.
		free(data);
		data=NULL;
	}
	heapSize =0;
}

void BaseHeap::swap (int&a, int&b)
{
    int aux = a;
    a = b;
    b = aux;
}

void BaseHeap::insert(int k)
{

	heapSize++;
	if (heapSize>=capacity)
	{
		reserve(capacity*2);
	}
	assert(heapSize < capacity);
	data[heapSize-1] = k;
	heapify(heapSize-1);

}

int  BaseHeap::getRoot()
{

	 int max = -1;

	if( heapSize >= 0 )
	{
		max = data[0];
	}

	return max;

}

int BaseHeap::removeRoot()
{
    int del = -1;

//	data[0]=data[heapSize];
    if(heapSize>0)
    {
    	del = data[0];
		swap(data[0], data[heapSize-1]);
		heapSize--;
		heapify_fromroot(0);
    }
    return del;
}

bool MinHeap::compare(int k, int l)
{
	return  k<l;
}
bool MaxHeap::compare(int k, int l)
{
	return  k>l;
}


void BaseHeap::printHeap()
{

	std::cout << "heap : ";
	for (int i=0; i< heapSize; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "\n";
}
MaxHeap::MaxHeap()
{
}

MaxHeap::~MaxHeap()
{
}

MinHeap::MinHeap()
{

}

MinHeap::~MinHeap()
{
}
