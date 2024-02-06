#include <iostream>
#include <stack>
#include <vector>

class Coordinate{
    public:
        Coordinate(int nx, int ny){ x = nx; y = ny; }
        int x;
        int y;
};
class Cell{
    public:
        Cell();
        void setVisited(bool vis) { visited = vis; }
        void setOpeningDirection(char ch) { opening = ch; }
    private:
        bool visited;
        int opening; // 0 north, 1 east, 2 south, 3 west
};
Cell::Cell(){
    visited = false;
    opening = 'x';
}

class Maze{
    public:
        Maze();
        void setSize(int width, int height);
        void generate();

    private:
        int width = -1;
        int height = -1;
        std::vector<Cell> board; 
        std::stack<Coordinate> backtrackStack;
        int visitedNum = 0;
        

};
Maze::Maze(){

}
void Maze::setSize(int width, int height){
    this->width = width;
    this->height = height;
    for (int i = 0; i < width*height; i++)
    {
        if (i % width == 0) std::cout << '\n';
        std::cout << "hokje ";
        
        Cell cell;
        board.push_back(cell);
    }
    std::cout << board.size();
}
void Maze::generate(){
    Coordinate currentPos(0, 0);
    backtrackStack.push(currentPos);
    board.at(currentPos.y * width + currentPos.x); //? idk
}


int main(int argc, char *argv[])
{
    int height;
    int width;
    Maze maze;

    if (argc != 3 && argc != 4) return -1;
    else if (argc == 4) srand(std::stoi(argv[3])); 
    
    height = std::stoi(argv[1]);
    width = std::stoi(argv[2]);
    maze.setSize(width, height);
    maze.generate();
    // Pathfinder.dothings




    return 0;
}