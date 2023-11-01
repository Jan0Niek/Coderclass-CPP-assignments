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
        double x1 = (-b + sqrt(d)) / 2 * a;
        double y1 = a*(x1*x1) + b*x1 + c;
        double x2 = (-b - sqrt(d)) / 2 * a;
        
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

// I return to do I/O in the main()
int main(){
    double a;
    double b;
    double c;
    std::cout << "Please enter the values of a, b, and c:\n";
    std::cin >> a >> b >> c;
    
    double d = discriminant(a, b, c);
    std::vector<double> v = solve(a, b, c, d);
    
    switch (v.size())
    {
        case 2:
            std::cout << "There are 2 solutions. \n The solutions are: x = " << v.at(0) << " and " << v.at(1) << std::endl;
            break;
        
        case 1:
            std::cout << "There is 1 solution. \nThe solution is: " << v.at(0) << std::endl;
            break;

        default:
            std::cout << "There is no solution." << std::endl;
            break;
    }   

}