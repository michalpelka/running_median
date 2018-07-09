#include "running_median.hpp"
#include <math.h>
RunningMedian::RunningMedian():currentMedian(0)
{

}

RunningMedian::HEAP_BALANCE RunningMedian::getHeapBalanceStatus()
{
	if (leftMaxHeap.getCount() == rightMinHeap.getCount())
		return HB_BALANCED;
	if (leftMaxHeap.getCount() > rightMinHeap.getCount())
		return HB_LEFT_HEAP_GREATER;
	return HB_LEFT_HEAP_LESS;
}

void RunningMedian::addElement(int elementToAdd)
{
	// check balance of heaps
	HEAP_BALANCE bal = getHeapBalanceStatus();

	// at any state maximum unbalnce should not be greater that one

	assert (abs(this->leftMaxHeap.getCount() - this->rightMinHeap.getCount()) <= 1);
	if (bal == HB_BALANCED)
	{
		// heaps are balanced.
		// we add element to left or right heap
		// according to its comparision to currentMedian
		if (elementToAdd < (currentMedian))
		{
			// element goes to left heap
			leftMaxHeap.insert(elementToAdd);
			currentMedian = leftMaxHeap.getRoot();
			return;
		}
		else
		{
			// element goes to right heap
			rightMinHeap.insert(elementToAdd);
			currentMedian = rightMinHeap.getRoot();
			return;
		}
	}
	// that means minHeap is smaller than maxHeap
	if (bal == HB_LEFT_HEAP_LESS)
	{
		// Left (MaxHeap) is smaller.
		// After adding we have to keep the balanced by one element

		if (elementToAdd < (currentMedian))
		{
			// element goes to left heap
			leftMaxHeap.insert(elementToAdd);
		}
		else
		{
			// we need to first transfer root element of right heap to left
			// element goes to left heap
			leftMaxHeap.insert(rightMinHeap.removeRoot());
			rightMinHeap.insert(elementToAdd);
		}

		assert(leftMaxHeap.getCount()==rightMinHeap.getCount());
		currentMedian = avg(leftMaxHeap.getRoot(), rightMinHeap.getRoot());
		return;

	}
	// that means minHeap is larger than maxHeap
	if (bal == HB_LEFT_HEAP_GREATER)
	{
		// Left (MaxHeap) is bigger.
		// After adding we have to keep the balanced by one element

		if (elementToAdd > currentMedian)
		{
			// element goes to right heap
			rightMinHeap.insert(elementToAdd);
		}else
		{

			// we need to first transfer root element of left (max) heap to right (min)
			// element goes to left heap (max)
			rightMinHeap.insert(leftMaxHeap.removeRoot());
			leftMaxHeap.insert(elementToAdd);

		}
		assert(leftMaxHeap.getCount()==rightMinHeap.getCount());
		currentMedian = avg(leftMaxHeap.getRoot(), rightMinHeap.getRoot());
		return;
	}


}
