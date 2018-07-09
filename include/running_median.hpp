#ifndef RUNNING_MEDIAN_HPP
#define RUNNING_MEDIAN_HPP
#include <stdlib.h>     /* abs */
#include "heap.hpp"
#include <assert.h>

class RunningMedian
{
private:
	enum HEAP_BALANCE
	{
		HB_BALANCED = 0,
		HB_LEFT_HEAP_LESS = -1,
		HB_LEFT_HEAP_GREATER = 1
	};

	HEAP_BALANCE getHeapBalanceStatus();
	inline float avg (int e1, int e2)
	{
		return 1.0*(e1 + e2) / 2;
	}
public:
	/// contructor
	RunningMedian();

	/// returns currently computed median
	inline float getMedian()
	{
		return currentMedian;
	}
	// add element to RunningMedian
	// Method aggragate input @param elementToAdd
	void addElement(int elementToAdd);
private:
	float currentMedian;
	MaxHeap leftMaxHeap;
	MinHeap rightMinHeap;
};


#endif //RUNNING_MEDIAN_HPP
