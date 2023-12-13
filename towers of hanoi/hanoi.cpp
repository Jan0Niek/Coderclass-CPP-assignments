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

void solve(const int maxH, int H, char A, char B, char C)
{
    if (H == maxH)
    {
        return;
    }
    solve(maxH, H - 1, A, C, B);
    std::cout << "Move disk " << H << " from " << A << " to " << C << '.\n';
    solve(maxH, H - 1, B, A, C);
}

int main()
{
    int H = towerSizeInput();
    if (H == -1) return -1;

    solve(0, H, 'A', 'B', 'C');
    return 0;
}