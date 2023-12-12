#include <iostream>
#include <vector>

std::vector<int> towerSizeInput()
{
    std::vector<int> A;
    int H;

    std::cout << "How many disks should the tower consist of?\n";
    std::cin >> H;
    if (std::cin.fail() || H <= 0)
    {
        std::cout << "invalid input. \n";
        return std::vector<int>{-1};
    }
    
    for (int i = 0; i < H; i++)
    {
        A.push_back(i+1);
    }
    return A;
}

void solve(int H, std::vector<int> A)
{
    std::vector<int> B;
    std::vector<int> C;
    if (A.size() % 2 == 0)
    {
        // beweeg de steen van a naar b
    } //else van a naar c
    
}

int main()
{



    return 0;
}