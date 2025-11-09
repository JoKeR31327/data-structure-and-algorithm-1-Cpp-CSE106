#include <iostream>
#include "2105166_stack.cpp"
using namespace std;

template <typename T>
void processStack() {
    Stack<T> stack;
    int choice;
    T value;

    do {

        cin >> choice;

        switch (choice) {
            case 1:
                    stack.clear();
                    break;
            case 2:
                cin >> value;
                stack.push(value);
                break;

            case 3:
                if (!stack.empty())
                    cout << stack.pop() <<endl;
                else
                    cout << "empty." << endl;
                break;
            case 4:
                cout<< stack.length()<<endl;
                break;

            case 5:
                if (!stack.empty())
                    cout << stack.top() << endl;
                else
                    cout << "empty." << endl;
                break;

            case 6:
                if (stack.empty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);
}

int main() {
    int choice2;
    /*cout << "Choose the type of stack: " << endl;
    cout << "1. Integer Stack" << endl;
    cout << "2. Character Stack" << endl;
    cout << "3. Double Stack" << endl;
    cout << "Enter your choice: ";
    cin >> choice2;*/
    choice2=1;

    switch (choice2) {
        case 1:
            processStack<int>();
            break;

        case 2:
            processStack<char>();
            break;

        case 3:
            processStack<double>();
            break;

        default:
            cout << "Invalid choice. Exiting..." << endl;
            break;
    }

    return 0;
}
