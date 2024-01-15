#include <iostream>
#include <vector>

class Stack {
   public:
       Stack();

   	    bool isEmpty() const{
            // returns true if stack has no elements stored
            return elements.empty();
        }

   	    int top() const{
            // returns element from top of the stack
            // throws std::runtime_error("stack is empty")
            if (isEmpty())
            {
                throw std::runtime_error("stack is empty");
            }
            return elements.front();
        }

       int pop(){
            // returns element from top of the stack and removes it
            // throws std::runtime_error("stack is empty")
            if (isEmpty())
            {
                throw std::runtime_error("stack is empty");
            }
            int top = elements.front();
            elements.erase(elements.begin());
            return top;
       }

   	    void push(int val){
            // puts a new element on top of the stack
            elements.insert(elements.begin(), val);
        }

       std::string toString() const{
            // returns the contents of the stack in the format
            // [top,next,...,bottom]
            // e.g.: push(1), push(2), toString() -> [2,1]
            std::string returnString = "["
            for (int i = 0; i < elements.size(); i++)
            {
                returnString = returnString + elements.at(i) + "," //fix
            }
            
       }


   private:
       std::vector<int> elements;
};


int main()
{

    
    return 0;
}