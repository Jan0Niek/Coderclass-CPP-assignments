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


void printSolution(std::vector<std::vector<bool>> board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (board.at(i).at(j) == true)
            {
                std::cout << "Q" << std::endl;
            } else {
                std::cout << "." << std::endl;
            }
    }
}
 
bool isSafe(std::vector<std::vector<bool>> board, int row, int col, int N)
{
    for (int i = 0; i < col; i++)
    {
        if (board.at(row).at(i))
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board.at(i).at(j))
            return false;
    }
 
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board.at(i).at(j))
            return false;
    }
 
    return true;
}
 
bool solveNQUtil(std::vector<std::vector<bool>> board, int col, int N)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(board, i, col, N) )
        {
            board.at(i).at(col) = 1;
            if (solveNQUtil(board, col + 1, N) == true)
                return true;
            board.at(i).at(col) = 0;
        }
    }
    return false;
}
 
bool solveNQ(int N)
{
    std::vector<std::vector<bool>> board(N, std::vector<bool>(N, false));
    if (solveNQUtil(board, 0, N) == false)
    {
        std::cout << "Solution does not exist" << std::endl;
        return false;
    }
    printSolution(board, N);
    return true;
}

int main(){
    const int N = checkInput();
    if (N == -1)
    {
        return 1;
    }
    solveNQ(N);
    

    return 0;
}