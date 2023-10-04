#include <iostream>

int main()
{
    std::string input = " ";
    std::string firstNumString;
    std::string secondNumString;
    double firstNumber;
    double secondNumber;
    double answer = 0;
    while (input.at(0) != 'q')
    {
        std::cout << "Enter the expression: ";
        std::cin >> input;
        
        //de dingen tussen de spaties zijn getallen domme yannick

        firstNumber =  std::stod(firstNumString);
        secondNumber =  std::stod(secondNumString);
        switch (input.at(0))
        {
        case '+':
            answer = firstNumber + secondNumber;
            std::cout << firstNumString + " + " + secondNumString + " = " + std::to_string(answer);
            break;
        case '-':
            answer = firstNumber - secondNumber;
            std::cout << firstNumString + " - " + secondNumString + " = " + std::to_string(answer);
            break;
        case '*':
            answer = firstNumber * secondNumber;
            std::cout << firstNumString + " * " + secondNumString + " = " + std::to_string(answer);
            break;
        case '/':
            answer = firstNumber / secondNumber;
            std::cout << firstNumString + " / " + secondNumString + " = " + std::to_string(answer);
            break;
        }
    }
    return 0;
}
