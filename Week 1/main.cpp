#include <iostream>


int main()
{
    std::cout << "Enter the first number of the sequence:";
    int n;
    std::cin >> n;
    std::cout << n << '\n';
    while (true)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        } else 
        {
            n = n * 3 + 1;
        }
        std::cout << n << '\n';
    }
    
    return 0;
}