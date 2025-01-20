#include <iostream>
#include <cstdlib>
#include <ctime>


int MyRandFunc(int first, int last)
{
   return first + rand() % (last - first + 1);
}


int main()
{
    srand(time(0));
	
    int length;
    std::cout << "введіть довжину масиву: ";
    std::cin >> length;

    // Создание динамического массива заданной длины
    int* arr = new int[length];

    int first, last;
    std::cout << "введіть значення мінімального числа: ";
    std::cin >> first;
    std::cout << "введіть значення максимального числа: ";
    std::cin >> last;


    for (int i = 0; i < length; i++)
    {
        arr[i] = MyRandFunc(first, last);
    }

    for (int i = 0; i < length; i++)
    {
        std::cout << "arr[" << i << "]" << arr[i]<< std::endl;
    }
    
    std::cout << "-----------------------------" << std::endl;    

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


     for (int i = 0; i < length; i++)
    {
        std::cout << "sort arr[" << i << "]" << arr[i]<< std::endl;
    }
}