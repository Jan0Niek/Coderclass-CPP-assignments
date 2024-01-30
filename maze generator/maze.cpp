#include <iostream>
#include <stack>
#include <vector>


class Cell{
    public:
        Cell();

    private:
        int x;
        int y;
        bool visited;

};
Cell::Cell(){
    x = -1;
    y = -1;
    visited = false;
}

class Maze{
    public:
        Maze();

    private:
        int width;
        int height;
        std::vector<std::vector<Cell>> board; //kut!
        

};
Maze::Maze(){

}

class Pathfinder{
    public:
        Pathfinder();
    private:

};
Pathfinder::Pathfinder(){

}

int main(int argc, char *argv[])
{
    int height;
    int width;

    if (argc == 3)
    {
        height = std::stoi(argv[1]);
        width = std::stoi(argv[2]);
    } else if (argc == 4)
    {
        std::cout << "haha, nahh";
        srand(std::stoi(argv[3])); 
    } else {
        return -1;
    }



    return 0;
}