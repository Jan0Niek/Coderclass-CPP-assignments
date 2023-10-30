#include <iostream>
#include <cmath>

double discriminant(double a, double b, double c){
    double d = b*b - 4 * a * c;
    return d;
}

double solution(double a, double b, double d){
    double x = (-b +- sqrt(d)) / 2 * a;
    return x;
}

std::string ouputSolution(){

    return output;
}

int main(){

}