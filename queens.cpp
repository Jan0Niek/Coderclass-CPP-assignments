#include <iostream>
#include <vector>

void printSolve(std::vector<std::vector<bool>>& board)
{
    for (std::vector<bool> i : board)
    {
        for (bool j : i) std::cout << ((j) ? 'Q' : '.');
        std::cout << '\n';
    }
}

bool canPlace(std::vector<std::vector<bool>>& board, int row, int collumn, int boardSize)
{
    for (std::vector<bool> currentRow : board) if (currentRow.at(collumn)) return false;
    for (int currentRow = row, currentCollumn = collumn;
            currentRow >= 0 && currentCollumn >= 0;
            currentRow--, currentCollumn--)
        if (board.at(currentRow).at(currentCollumn)) return false;

    for (int currentRow = row, currentCollumn = collumn;
            currentRow >= 0 && currentCollumn < boardSize;
            currentRow--, currentCollumn++)
        if (board.at(currentRow).at(currentCollumn)) return false;

    return true;
}

bool solve(std::vector<std::vector<bool>>& board, int row, int boardSize)
{
      
    for (int collumn = 0; collumn < boardSize; collumn++) if (canPlace(board, row, collumn, boardSize))
    {
        board.at(row).at(collumn) = true;
        if (row == boardSize - 1 || solve(board, row + 1, boardSize)) return true;
        board.at(row).at(collumn) = false;
    }
    return false;
}

int main()
{
    int boardSize;
    std::cout << "How many queens to place on the board? ";
    std::cin >> boardSize;
    
    if (boardSize < 2 || std::cout.fail())
    {
        std::cout << "error: invalid input\n";
        return -1;
    }
    else if (boardSize == 2 || boardSize == 3)
    {
        std::cout << "No solution found to place " << boardSize << " queens on a " 
            << boardSize << " by " << boardSize << " chessboard\n";
        return -1;
    }

    std::vector<std::vector<bool>> board(boardSize, std::vector<bool>(boardSize, false));
    solve(board, 0, boardSize);
    printSolve(board);
    return 0;
}
