#include <iostream>
#include <cmath>
#include <vector>

double discriminant(double a, double b, double c){
    return b*b - 4 * a * c;
}

std::vector<double> solve(double a, double b, double c, double d){
    std::vector<double> v;
    if (d > 0)
    {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        v.push_back(x1);
        v.push_back(x2);
        return v;
    } else if (d == 0)
    {
        double x;
        double x1 = (-b + sqrt(d)) / (2 * a);
        double y1 = a*(x1*x1) + b*x1 + c;
        double x2 = (-b - sqrt(d)) / (2 * a);
        
        if (y1 == 0)
        {
            x = x1;
        } else {
            x = x2;
        }

        v.push_back(x);
        return v;
    } else{
        return v;
    }
    
    
}

double checkInput(){
    double num;
    if (!(std::cin >> num)) throw std::runtime_error("Malformed user input");
    return num;
}

void output(std::vector<double> solutions){
    if (solutions.size() == 2)
    {
        std::cout << "There are 2 solutions. \n The solutions are: " << solutions.at(0) << " and " << solutions.at(1) << std::endl;
    } else if (solutions.size() == 1)
    {
        std::cout << "There is 1 solution. \nThe solution is: " << solutions.at(0) << std::endl;
    } else 
    {
        std::cout << "There is no solution." << std::endl;
    }
}

int main(){
    std::cout << "Please enter the values of a, b, and c:\n";
    
    try
    {
        double a = checkInput();
        if (a == 0) throw std::runtime_error("a must not be zero");  
        double b = checkInput();
        double c = checkInput();

        double d = discriminant(a, b, c);
        std::vector<double> solutions = solve(a, b, c, d);
    
        output(solutions);
    }
    catch(std::runtime_error &e)
    {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }
}
