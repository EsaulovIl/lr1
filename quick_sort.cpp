#include <iostream>
#include <vector>

template<typename Type>
void filling(std::vector<Type>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (n * 10);
    }
}

template<typename Type>
void print(const std::vector<Type>& arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename Type>
int partition(std::vector<Type>& arr, int start, int end)
{
	Type temp, pivot;
	int ind = start + rand() % (end - start + 1);
	temp = arr[ind];
	arr[ind] = arr[end];
	arr[end] = temp;
	int index = start;
	pivot = arr[end];
	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	temp = arr[index];
	arr[index] = pivot;
	arr[end] = temp;
	return index;
}

template <typename Type>
void quicksort(std::vector<Type>& arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = partition(arr, start, end);
	quicksort(arr, start, pivot - 1);
	quicksort(arr, pivot + 1, end);
}

int main() 
{
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));
    int n = 0;
    std::cout << "Введите кол-во элементов массива: ";
    std::cin >> n;
    std::vector<int> arr(n);
    filling(arr, n);
    std::cout << "Исходный массив: ";
    print(arr, n);
    quicksort(arr, 0, n - 1);
    std::cout << "Отсортированный массив: ";
    print(arr, n);
    return 0;
}