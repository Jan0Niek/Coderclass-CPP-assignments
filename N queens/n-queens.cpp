#include <iostream>
#include <vector>

int checkInput(){
    int n;
    std::cout << "How many queens to place on the board? ";
    std::cin >> n;
    if (std::cin.fail() || n < 1)
    {
        std::cout << "error: invalid input";
        return -1;
    }
    

    return n;
}

int main(){
    const int N = checkInput();
    if (N == -1)
    {
        return 1;
    }    

    return 0;
}