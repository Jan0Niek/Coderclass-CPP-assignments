#include <iostream>

int main()
{
    std::string chosenOperator;
    std::string num1;
    std::string num2;
    double answer = 0;
    while (chosenOperator != "q")
    {
        std::cout << "\nEnter the expression: ";
        std::cin >> chosenOperator;
        if (chosenOperator == "q")
        {
            break;
        }
        std::cin >> num1;
        std::cin >> num2;
        switch (chosenOperator.at(0))
        {
        case '+':
            answer = std::stod(num1) + std::stod(num2);
            std::cout << num1 + " + " + num2 + " = " << answer;
            break;
        case '-':
            answer = std::stod(num1) - std::stod(num2);
            std::cout << num1 + " - " + num2 + " = " << answer;
            break;
        case '*':
            answer = std::stod(num1) * std::stod(num2);
            std::cout << num1 + " * " + num2 + " = " << answer;
            break;
        case '/':
            answer = std::stod(num1) / std::stod(num2);
            std::cout << num1 + " / " + num2 + " = " << answer;
            break;
        default:
            break;
        }
    }
    return 0;
}
