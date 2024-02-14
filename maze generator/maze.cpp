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
    openings.resize(4);
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

    while (visitedNum != width*height-1)
    {
        bool northPossible = true;
        bool eastPossible = true;
        bool southPossible = true;
        bool westPossible = true;

        board.at(currentPos.y * width + currentPos.x).setVisited(true);
        visitedNum++; 
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
                backtrackStack.pop();
                northPossible = true;
                eastPossible = true;
                southPossible = true;
                westPossible = true;
            }
            
        }
        backtrackStack.push(currentPos);
        board.at(currentPos.y * width + currentPos.x).setOpeningDirection(direction);   

        currentPos = newPos;
        //win check
        if (currentPos.x == width - 1 && currentPos.y == height - 1){ pathToWin = backtrackStack; pathToWin.push(Coordinate(width-1, height-1)); }
    }

}

void Maze::makeWinPath()
{
    Coordinate pos(-1, -1);
    int pathSize = pathToWin.size(); // why do i have to declare this as int outside of the for-loop? argh
    for (int i = 0; i < pathSize; i++)
    {
        pos = pathToWin.top();
        board.at(pos.y * width + pos.x).setWin(true);
        pathToWin.pop();
    }  
}

void Maze::output()
{
    std::cout << "+";
    for (int i = 0; i < width; i++)
    {
        std::cout << "---+";
    }
    std::cout << std::endl;

    for (int j = 0; j < height; j++)
    {
        std::cout << "|";
        for (int i = 0; i < width; i++)
        {
            std::cout << " ";
            if (board.at(j * width + i).onWinpath()) 
            { 
                std::cout << "."; 
            } else {
                std::cout << " ";
            }

            std::cout << " ";
            if (i < width - 1)
            {
                if (board.at(j * width + i + 1).isOpenInDirection(3) || board.at(j * width + i).isOpenInDirection(1)) 
                { 
                    std::cout << " "; 
                } else {
                    std::cout << "|";
                }
            } else {
                if (board.at(j * width + i).isOpenInDirection(1)) 
                { 
                    std::cout << " "; 
                } else {
                    std::cout << "|";
                }
            }
            
        }
        std::cout << std::endl;
        
        std::cout << "+";
        for (int i = 0; i < width; i++)
        {
            if (j < height - 1)
            {
                if (board.at(j * width + i).isOpenInDirection(2) || board.at((j + 1) * width + i).isOpenInDirection(0))
                {
                std::cout << "   ";
                } else {
                    std::cout << "---";
                }
            } else {
                if (board.at(j * width + i).isOpenInDirection(2)) 
                {
                std::cout << "   ";
                } else {
                    std::cout << "---";
                }
            }

            std::cout << "+";
        }

        std::cout << std::endl;
    }
    
    
    
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
    maze.makeWinPath();
    maze.output();
    return 0;
}