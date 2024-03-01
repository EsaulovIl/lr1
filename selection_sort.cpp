#include <iostream>
#include <vector>
#include <ctime>


void filling(std::vector<int>& arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%(n*10);
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

template<typename Type>
void selection_sort(std::vector<Type>& arr) 
{
    int n = arr.size();
    Type temp = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() 
{
    srand(time(nullptr));
    setlocale(LC_ALL, "rus");
    int n;
    std::cout << "Введите кол-во элементов массива: ";
    std::cin >> n;
    std::vector<int> arr(n);
    filling(arr, n);
    std::cout << "Исходный массив: ";
    print(arr, n);
    selection_sort(arr);
    std::cout << "Отсортированный массив: ";
    print(arr, n);
    return 0;
}