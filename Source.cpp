#include<iostream>
#include<vector>

void readVector(std::vector<int>& vect)
{
	int size;
	std::cout << "Number of values in array: ";
	std::cin >> size;
	vect.resize(size);
	std::cout << "The numbers are: ";
	for (int i=0;i<size;++i)
		std::cin >> vect[i];
}

void maxHeapify(std::vector<int>&vect, int index)
{
	int left = index * 2 + 1, right = index * 2 + 2, indexMax = index;
	if (left<vect.size() && vect[left]>vect[indexMax])
		indexMax = left;
	if (right<vect.size() && vect[right]>vect[indexMax])
		indexMax = right;
	if (indexMax != index)
	{
		std::swap(vect[index], vect[indexMax]);
		maxHeapify(vect, indexMax);
	}
}
void buildMaxHeap(std::vector<int>&vect)
{
	for (int i = vect.size() / 2 - 1; i >= 0; --i)
		maxHeapify(vect, i);
}
void heapSort(std::vector<int>&vect)
{
	buildMaxHeap(vect);
	std::vector<int>sorted;
	int size = vect.size();
	sorted.resize(size);
	while (!vect.empty())
	{
		sorted[--size] = vect[0];
		std::swap(vect[0], vect[size]);
		vect.pop_back();
		maxHeapify(vect, 0);
	}
	vect = sorted;
}
int main()
{
	std::vector<int> arr;// = { 9,19,4,0,420,8,69 };
	readVector(arr);

	heapSort(arr);

	for (int it : arr)
		std::cout << it << " ";
	return 0;
}