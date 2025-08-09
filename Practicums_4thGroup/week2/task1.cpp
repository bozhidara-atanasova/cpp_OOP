#include <iostream>
//task`
template<typename T>
T findMax(T a[], int b)
{
	T temp = a[0];
	for (int i = 0; i < b; i++)
	{
		if (temp < a[i])temp = a[i];
	}
	return temp;
}
//task2
template<typename T>
std::size_t findMinIndex(const T arr[], std::size_t start, std::size_t count)
{
	std::size_t minIndex = start;
	for (std::size_t i = start + 1; i < count; ++i) {
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}
template<typename T>
void swapValues(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void sort(T arr[], std::size_t count)
{
	for (std::size_t i = 0; i < count - 1; ++i) {
		std::size_t minIndex = findMinIndex(arr, i, count);
		if (minIndex != i) {
			swapValues(arr[i], arr[minIndex]);
		}
	}
}
template<typename T, std::size_t N>
void printArr(const T(&arr)[N])
{
	for (std::size_t i = 0; i < N; ++i)
		std::cout << arr[i] << (i + 1 < N ? ' ' : '\n');
}
int main()
{
	//task1
	int arr1[5] = { 1, 5, 3, 9, 2 };
	std::cout << findMax(arr1, 5) << std::endl; // -> 9
	double arr2[4] = { 2.5, 7.1, 3.3, 5.0 };
	std::cout << findMax(arr2, 4) << std::endl; // -> 7.1
	//task2
	int arr1[5] = { 1, 5, 3, 9, 2 };
	sort(arr1, 5);
	printArr(arr1);  // -> 1 2 3 5 9
	double arr2[4] = { 2.5, 7.1, 3.3, 5.0 };
	sort(arr2, 4);
	printArr(arr2);  // -> 2.5 3.3 5.0 7.1

	return 0;
}

