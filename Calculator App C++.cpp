#include <iostream>
#include <cmath>
using namespace std;

class Calculator
{
    private:
        void showMenu()
        {
            cout << "-----CalculatorApp-----" << "\n";
            cout << "-----------------------" << "\n";
            cout << "Select Operation:" << "\n";
            cout << " + Addition" << "\n";
            cout << " - Subtraction" << "\n";
            cout << " * Multiplication" << "\n";
            cout << " / Division" << "\n";
            cout << " s Square Root" << "\n";
            cout << " c Cub Root" << "\n";
            cout << "-----------------------" << "\n";
            cout << "Choice: ";
        }

        double getuserinput(int index)
        {
            double number;
            cout << "Enter Number " << index << ": ";
            cin >> number;
            return number;
        }

    public:
        double add(double number1, double number2)
        {
            return number1 + number2;
        }

        double subtraction(double number1, double number2)
        {
            return number1 - number2;
        }

        double multiplication(double number1, double number2)
        {
            return number1 * number2;
        }

        double division(double number1, double number2)
        {
            if (number2 != 0) 
            {
                return number1 / number2;
            }
            else {
                cout << "Error: Division by zero is not allowed!" << "\n";
                return 0;
            }
        }

        double squareroot(double number)
        {
            if (number < 0)
            {
                cout << "Error: Cannot calculate square root for negative number!" << "\n";
                return 0;
            }

            return sqrt(number);
        }

        double cubroot(double number)
        {
            return cbrt(number);
        }           

        void run()
        {
            char choice = 'y';
            while (choice == 'y' || choice == 'Y')
            {
                char operation;

                showMenu();
                cin >> operation;

                double inputs[2] = {};
                inputs[0] = getuserinput(1);

                if (operation != 's' && operation != 'c')
                {
                    inputs[1] = getuserinput(2);
                }

                double result = 0;

                switch (operation)
                {
                case '+':
                    result = add(inputs[0], inputs[1]);
                    break;

                case '-':
                    result = subtraction(inputs[0], inputs[1]);
                    break;

                case '*':
                    result = multiplication(inputs[0], inputs[1]);
                    break;

                case '/':
                    result = division(inputs[0], inputs[1]);
                    break;

                case 's':
                    result = squareroot(inputs[0]);
                    break;

                case 'c':
                    result = cubroot(inputs[0]);
                    break;

                default:
                    cout << "Invalid operation selected!" << "\n";
                    continue;
                }

                cout << "Result: " << result << "\n";

                cout << "Do you want another operation (y/n): ";
                cin >> choice;
            }

            cout << "Calculator closed" << "\n";
        }

};

int main()
{
    Calculator calculator;
    
    calculator.run();

    return 0;
}