#include <iostream>
#include "stack.h"
#include <string>
using namespace std;

bool isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isvalid(string& sample)
{
    stack<char> paren;
    for (int i = 0; i < sample.length(); i++)
    {
        char c = sample[i];
        if (c == '(')
        {
            paren.push(c);
        }
        else if (c == ')')
        {
            if (paren.isempty())
            {
                return false;
            }
            else
            {
                paren.pop();
            }
        }
    }
    return paren.isempty();
}

bool precedence(char op1, char op2)
{
    if (op1 == '*' || op1 == '/')
    {
        return true;
    }

    if (op1 == '+' || op1 == '-')
    {
        return op2 == '+' || op2 == '-';
    }

    return false;
}

double evaluatesample(string& sample)
{
    stack<double> operands;
    stack<char> operators;
    bool isnegative = false;

    for (int i = 0; i < sample.length(); i++)
    {
        char c = sample[i];

        if (isdigit(c) || c == '.')
        {
            string str;
            while (isdigit(c) || c == '.')
            {
                str += c;
                c = sample[++i];
            }
            double operand = stod(str);
            if (isnegative)
            {
                operand = -operand;
                isnegative = false;
            }
            operands.push(operand);
            i--;
        }
        else if (c == '-')
        {

            if (i == 0 || isoperator(sample[i - 1]) || sample[i - 1] == '(')
            {
                isnegative = true;
            }
            else
            {
                while (!operators.isempty() && precedence(operators.topvalue(), c))
                {
                    double num2 = operands.pop();
                    double num1 = operands.pop();
                    char op = operators.pop();

                    double result;
                    switch (op)
                    {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        result = num1 / num2;
                        break;
                    }

                    operands.push(result);
                }

                operators.push(c);
            }
        }
        else if (isoperator(c))
        {
            while (!operators.isempty() && precedence(operators.topvalue(), c))
            {
                double num2 = operands.topvalue();
                operands.pop();
                double num1 = operands.topvalue();
                operands.pop();
                char op = operators.topvalue();
                operators.pop();

                double result;
                switch (op)
                {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                }

                operands.push(result);
            }

            operators.push(c);
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.isempty() && operators.topvalue() != '(')
            {
                double num2 = operands.topvalue();
                operands.pop();
                double num1 = operands.topvalue();
                operands.pop();
                char op = operators.topvalue();
                operators.pop();

                double result;
                switch (op)
                {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                }

                operands.push(result);
            }

            operators.pop();
        }
    }

    while (!operators.isempty())
    {
        double num2 = operands.topvalue();
        operands.pop();
        double num1 = operands.topvalue();
        operands.pop();
        char op = operators.topvalue();
        operators.pop();

        double result;
        switch (op)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        }

        operands.push(result);
    }

    return operands.topvalue();
}

int main()
{
    string sample;

    cout << "Enter a sample: ";
    getline(cin, sample);

    if (isvalid(sample))
    {
        cout << "Valid sample." << endl;
        cout << "Computed value: " << evaluatesample(sample) << endl;
    }
    else
    {
        cout << "Not valid." << endl;
    }

    return 0;
}
