#include <iostream>
#include <cstdlib>
#include <ctime>


// test
int get_random_int()
{
    return rand();
}

int get_random_int(int a)
{
    return rand() % (a + 1);
}

int get_random_int(int first, int last)
{
   return first + rand() % (last - first + 1);
}

int binary_search(int* arr, int size, int target)
{
    int left = 0, right = size;
    while (left != right)
    {
        int mid = (left + right) / 2; 

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }

        else 
        {
            right = mid;
        }
    }

    return -1;
}

/*
    n = кількість вхідних єлементів
    k = кількість поділів

    1 - 2 
    2 - 4
    3 - 8
    4 - 16
    ...
    k - 2^k

    n = 2^k 
    log2(n) = log2(2^k)
    log2(n) = k
*/

int search(int* arr, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

struct vector
{
    vector() : size(0), capacity(1024), data(0)
    {
        resize();

        std::cout << "vector()" << std::endl;
    }
    
    vector(int _capacity) : size(0), capacity(_capacity), data(0)
    {
        resize();

        std::cout << "vector(int)" << std::endl;
    }

    ~vector()
    {
        if (data != 0)
        {
            delete[] data;
        }
        
        std::cout << "~vector()" << std::endl;
    }

    int size;
    int capacity;
    int* data;

    void print()
    {
        std::cout << "size: " << size << std::endl;
        std::cout << "capacity: " << capacity << std::endl;
    }
    int get_size()
    {
        return size;
    };
    int get_capacity()
    {
        return capacity;
    };

    void resize()
    {
        if(data == 0)
        {
            data = new int[capacity];
            return;
        }

        capacity *= 2;
        int* p = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            p[i] = data[i];
        }

        delete[] data;
        
        data = p;
    }

    void push_back(int n)
    {
        if(size >= capacity)
        {
            resize();
        }

        data[size] = n;
        size++;
    }
};

int main()
{
    /*
    srand(time(0));
    std::cout << get_random_int() << std::endl;
    std::cout << get_random_int(125) << std::endl;
    std::cout << get_random_int(1, 44) << std::endl;
	
    int length;
    std::cout << "введіть довжину масиву: ";
    std::cin >> length;

    int* arr = new int[length];

    int first, last;
    std::cout << "введіть значення мінімального числа: ";
    std::cin >> first;
    std::cout << "введіть значення максимального числа: ";
    std::cin >> last;


    for (int i = 0; i < length; i++)
    {
        arr[i] = my_rand_func(first, last);
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


    // 5, 10, 5, 3, 9, 3, 1, 8, 11

    for (int i = 0; i < length; i++)
    {
        std::cout << "sort arr[" << i << "]" << arr[i]<< std::endl;
    }

    int target = 0;
    std::cin >> target;

    std::cout << search(arr, length, target) << std::endl;

    std::cout << "binery search" << binary_search(arr, length, target) << std::endl;
    */
    

    vector vector1(11);

    vector1.print();

    vector1.push_back(333);
    vector1.push_back(222);
    vector1.push_back(111);


    for (int i = 0; i < 50; i++)
    {
        vector1.push_back(i);
    }
    
    vector1.print();

    for (int i = 0; i < vector1.size; i++)
    {
        std::cout << vector1.data[i] << std::endl;
    }
    

    {
        vector vector2;
        
        vector2.print();
    }

    std::cout << vector1.get_size() << std::endl;
}