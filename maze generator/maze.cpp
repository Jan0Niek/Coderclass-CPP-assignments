#include <iostream>
#include <stack>
#include <vector>


class Cell{
    public:
        Cell();
        void setVisited(bool vis) { visited = vis; }
        void setOpeningDirection(char ch) { opening = ch; }
        

    private:
        int x;
        int y;
        bool visited;
        char opening; // north east south west N E S W

};
Cell::Cell(){
    x = -1;
    y = -1;
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
        std::stack<Cell> backtrackStack;
        

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
    
}

class RNG{
    public:
        RNG();
    private:

};
RNG::RNG(){

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