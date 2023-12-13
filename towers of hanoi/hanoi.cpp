#include <iostream>

int towerSizeInput()
{
    int H;
    std::cout << "How many disks should the tower consist of?\n";
    std::cin >> H;
    if (std::cin.fail() || H <= 0)
    {
        std::cout << "invalid input. \n";
        return -1;
    }
    return H;
}

int solve(int H, int newH)
{
    if (H % 2 == 0)
    {
        std::cout << "move disk " << H-newH << " from a to b" << std::endl;
    } else {
        std::cout << "move disk " << H-newH << " from a to c" << std::endl;
    }
    if (newH==0)
    {
        return 1;
    }
    

    solve(H, newH-1);
    
}

int main()
{
    int H = towerSizeInput();
    if (H == -1) return -1;
    solve(H, H-1);
    

    return 0;
}