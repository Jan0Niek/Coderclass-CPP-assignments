#include <iostream>


int main()
{
    std::cout << "Enter the first number of the sequence: \n";
    int n;
    std::cin >> n;
    std::cout << n << ' ';

    while (true)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        } else 
        {
            n = n * 3 + 1;
        }
        if (n == 1)
        {
            oneCounter++;
            if (oneCounter == 3)
            {
                std::cout << "1 ...";
                return 0;
            }
        }
        std::cout << n << ' ';
    }
    
    return 0;
}