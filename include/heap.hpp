#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>


class BaseHeap
{
private :
	int * data;
	int capacity;
	int heapSize;
public:
	/// constructor
	BaseHeap();

	~BaseHeap();

	/// method that allows heap to grow
	/// \param capacity new capacity of heap array
	void reserve(unsigned int capacity);

	/// add new element to heap
	/// \param capacity new capacity of heap array
	void insert(int k);

	/// returns a root element
	int getRoot ();

	/// returns a root element, then remove it
	int removeRoot ();

	/// returns number of elements
	inline unsigned int getCount(){
		return heapSize;
	}

	void printHeap();

	/// returns number of elements allocated in memory
	inline int getCapacity()
	{
		return capacity;
	}

	/// return pointer to internall data
	inline int* getData()
	{
		return data;
	}
protected:
	void heapify(int i);
	void heapify_fromroot(int i);
	virtual bool compare(int k, int l)=0;

	inline int parent(int i)
	{
		if (i <=0 ) return -1;
		return (i-1)/2;
	}
	inline int left(int i) { return (2*i + 1); }
	inline int right(int i) { return (2*i + 2); }


	void swap (int&k, int&l);

};

class MaxHeap : public BaseHeap
{
public:
	MaxHeap();
	~MaxHeap();
protected:
	virtual bool compare(int k, int l);

};
class MinHeap : public BaseHeap
{
public:
	MinHeap();
	~MinHeap();
protected:
	virtual bool compare(int k, int l);

};


#endif //STACK_HPP
