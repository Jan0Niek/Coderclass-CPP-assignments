#include <vector>

#include <iostream>


bool checkIfPlaceable(std::vector<std::vector<bool>>& board, int row, int colom, int N)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board.at(i).at(colom)) 
        {
            return false;
        }
    }

    for (int i = row, j = colom; i >= 0 && j >= 0; i--, j--)
    {
        if (board.at(i).at(j))
        {
            return false;
        }
    }

    for (int i = row, j = colom; i >= 0 && j < N; i--, j++)
    {
        if (board.at(i).at(j))
        {
            return false;
        }
    }

    return true;
}


bool solve(std::vector<std::vector<bool>>& board, int row, int N)
{
      
    for (int collumn = 0; collumn < N; collumn++) if (checkIfPlaceable(board, row, collumn, N)) //hiero
    {
        board.at(row).at(collumn) = true;
        if (row == N - 1 || solve(board, row + 1, N)) return true;
        board.at(row).at(collumn) = false;
    }
    return false;
}

void outputSolution(std::vector<std::vector<bool>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.at(i).size(); j++)
        {
            if (board.at(i).at(j))
            {
                std::cout << 'Q';
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}


int main()
{
    int N;
    std::cout << "How many queens to place on the board? ";
    std::cin >> N;
    
    if (N < 2 || std::cout.fail())
    {
        std::cout << "error: invalid input\n";
        return -1;
    }
    else if (N < 4)
    {
        std::cout << "No solution found to place " << N << " queens on a " 
            << N << " by " << N << " chessboard\n";
        return -1;
    }

    std::vector<std::vector<bool>> board(N, std::vector<bool>(N, false));
    solve(board, 0, N);
    outputSolution(board);
    return 0;
}
