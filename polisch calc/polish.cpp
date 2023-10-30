#include <iostream>

int main()
{
    char chosenOperator;
    double num1;
    double num2;
    double answer = 0;
    std::cout << "\nEnter the expression: ";
    std::cin >> chosenOperator;
    while (chosenOperator != 'q')
    {
        std::cin >> num1 >> num2;
        switch (chosenOperator)
        {
        case '+':
            answer = num1 + num2;
            std::cout << num1 << " + " << num2 << " = " << answer;
            break;
        case '-':
            answer = num1 - num2;
            std::cout << num1 << " - " << num2 << " = " << answer;
            break;
        case '*':
            answer = num1 * num2;
            std::cout << num1 << " * " << num2 << " = " << answer;
            break;
        case '/':
            answer = num1 / num2;
            std::cout << num1 << " / " << num2 << " = " << answer;
            break;
        default:
            break;
        }
        std::cout << "\nEnter the expression: ";
        std::cin >> chosenOperator;
    }
    return 0;
}
