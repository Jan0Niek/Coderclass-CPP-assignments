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
        void setOpeningDirection(int way) { openings.at(way) = true; }
        bool isOpenInDirection(int direction) { return openings.at(direction); }
        void setVisited(bool vis) { visited = vis; }
        bool getVisited() { return visited; }
        void setWin(bool win) { onWinPath = win; }
        bool onWinpath() { return onWinPath; }
    private:
        bool visited;
        bool onWinPath;
        std::vector<bool> openings; // 0 north, 1 east, 2 south, 3 west
};
Cell::Cell(){
    visited = false;
    onWinPath = false;
    std::vector<bool> openings(4);
}

class Maze{
    public:
        Maze();
        void setSize(int width, int height);
        void generate();
        void makeWinPath();
        void output();

    private:
        int width = -1;
        int height = -1;
        std::vector<Cell> board; 
        std::stack<Coordinate> backtrackStack;
        int visitedNum = 0;
        bool checkPossible(Coordinate newPos) { return !((!(newPos.x >= 0 && newPos.x < width && newPos.y >= 0 && newPos.y < height)) || board.at(newPos.y * width + newPos.x).getVisited() == true); }
        std::stack<Coordinate> pathToWin;

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
}
void Maze::generate(){
    Coordinate currentPos(0, 0);
    Coordinate newPos(0, 0);
    int direction = -1;

    //loop vanaf

    while (visitedNum <= width*height-2)
    {
        bool northPossible = true;
        bool eastPossible = true;
        bool southPossible = true;
        bool westPossible = true;

        if (currentPos.x == width - 1 && currentPos.y == height - 1){ pathToWin = backtrackStack; std::cout << "pad gevonden!??!\n"; }
        
        board.at(currentPos.y * width + currentPos.x).setVisited(true);
        visitedNum++; 
        std::cout << "visnum= " << visitedNum << std::endl;

        while ((!(newPos.x >= 0 && newPos.x < width && newPos.y >= 0 && newPos.y < height)) || board.at(newPos.y * width + newPos.x).getVisited() == true)
        {
            direction = rand() % 4 + 0;
            switch (direction)
            {
            case 0: //go north
                newPos = Coordinate(currentPos.x, currentPos.y - 1);
                if (checkPossible(newPos) == false)
                {
                    northPossible = false;
                } else { northPossible = true; }
                break;
            case 1: //go east
                newPos = Coordinate(currentPos.x + 1, currentPos.y);
                if (checkPossible(newPos) == false)
                {
                    eastPossible = false;
                }else { eastPossible = true; }
                break;
            case 2: //go south
                newPos = Coordinate(currentPos.x, currentPos.y + 1);
                if (checkPossible(newPos) == false)
                {
                    southPossible = false;
                }else { southPossible = true; }
                break;
            case 3: //go west
                newPos = Coordinate(currentPos.x - 1, currentPos.y);
                if (checkPossible(newPos) == false)
                {
                    westPossible = false;
                }else { westPossible = true; }
                break;

            }

            if (northPossible == false && eastPossible == false && southPossible == false && westPossible == false)
            {
                currentPos = backtrackStack.top();
                std::cout << backtrackStack.top().x << "  " << backtrackStack.top().y << '\n';
                backtrackStack.pop();
                northPossible = true;
                eastPossible = true;
                southPossible = true;
                westPossible = true;
            }
            
        }
        backtrackStack.push(currentPos);

        std::cout << "direction = " << direction << std::endl;
        board.at(currentPos.y * width + currentPos.x).setOpeningDirection(direction);   

        currentPos = newPos;
    }

}

void Maze::makeWinPath()
{
    Coordinate pos(-1, -1);
    for (int i = 0; i < pathToWin.size(); i++)
    {
        pos = pathToWin.top();
        board.at(pos.y * width + pos.x).setWin(true);
        pathToWin.pop();
    }  
}

void Maze::output()
{
    //hier komt de rest
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