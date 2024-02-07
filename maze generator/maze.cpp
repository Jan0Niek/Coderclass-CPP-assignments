#include <iostream>
#include <stack>
#include <vector>

class Coordinate{
    public:
        Coordinate(int nx, int ny) { x = nx; y = ny; }
        int x;
        int y;
};
class Cell{
    public:
        Cell();
        void setVisited(bool vis) { visited = vis; }
        void setOpeningDirection(int way) { opening = way; }
        bool getVisited() { return visited; }
        int getOpeningDirection() { return opening; }
    private:
        bool visited;
        int opening; // 0 north, 1 east, 2 south, 3 west
};
Cell::Cell(){
    visited = false;
    opening = -1;
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
        bool checkPossible(Coordinate newPos) { return !(board.at(newPos.y * width + newPos.x).getVisited() == true && (!(newPos.x >= 0 && newPos.x < width && newPos.y >= 0 && newPos.y < height))); }
        

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
    Coordinate newPos(-1, -1);
    int direction = -1;

    bool northPossible = true;
    bool eastPossible = true;
    bool southPossible = true;
    bool westPossible = true;

    backtrackStack.push(currentPos);
    board.at(currentPos.y * width + currentPos.x).setVisited(true);
    visitedNum++; 

    while (board.at(newPos.y * width + newPos.x).getVisited() == true && (!(newPos.x >= 0 && newPos.x < width && newPos.y >= 0 && newPos.y < height)))
    {
        direction = rand() % 3 + 0;
        switch (direction)
        {
        case 0: //go north
            newPos = Coordinate(currentPos.x, currentPos.y - 1);
            if (checkPossible(newPos) == false)
            {
                northPossible = false;
            }
            break;
        case 1: //go east
            newPos = Coordinate(currentPos.x + 1, currentPos.y);
            if (checkPossible(newPos) == false)
            {
                eastPossible = false;
            }
            break;
        case 2: //go south
            newPos = Coordinate(currentPos.x, currentPos.y + 1);
            if (checkPossible(newPos) == false)
            {
                southPossible = false;
            }
            break;
        case 3: //go west
            newPos = Coordinate(currentPos.x - 1, currentPos.y);
            if (checkPossible(newPos) == false)
            {
                westPossible = false;
            }
            break;
        }
    }
    std::cout << "direction = " << direction << std::endl;
    board.at(currentPos.y * width + currentPos.x).setOpeningDirection(direction);    
    

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