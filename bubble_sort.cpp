#include <iostream>
#include <ctime>
#include <vector>

template<typename Type>
void filling(std::vector<Type>& arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % (n*10);
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
void bubble_sort(std::vector<Type>& arr, int n) 
{
    Type temp = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));
    int n;
    std::cout << "Введите кол-во элементов массива: ";
    std::cin >> n;
    std::vector<int> arr(n);
    filling(arr, n);
    std::cout << "Исходный массив: ";
    print(arr, n);
    bubble_sort(arr, n);
    std::cout << "Отсортированный массив: ";
    print(arr, n);
    return 0;
}
