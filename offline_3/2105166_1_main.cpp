#include <iostream>
#include "2105166_1_a_queue.cpp"
//#include "2105166_1_ll_queue.cpp"
using namespace std;

template <typename T>
void processQueue() {
    queue<T> sample;
    int choice;
    T value;

    do {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                sample.enqueue(value);
                break;

            case 2:
                if (!sample.isempty())
                    cout<< sample.dequeue() << endl;
                else
                    cout << "empty" << endl;
                break;

            case 3:
                cout << sample.length() << endl;
                break;

            case 4:
                if (!sample.isempty())
                    cout << sample.front() << endl;
                else
                    cout <<"empty." << endl;
                break;

            case 5:
                if (!sample.isempty())
                    cout << sample.back() << endl;
                else
                    cout << "empty." << endl;
                break;

            case 6:
                if (sample.isempty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;

            case 7:
                sample.clear();
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
    int choice;
    /*cout << "Choose the type of queue: " << endl;
    cout << "1. Integer Queue" << endl;
    cout << "2. Character Queue" << endl;
    cout << "3. Double Queue" << endl;
    cout << "Enter your choice: ";
    cin >> choice;*/
    choice=1;

    switch (choice) {
        case 1:
            processQueue<int>();
            break;

        case 2:
            processQueue<char>();
            break;

        case 3:
            processQueue<double>();
            break;

        default:
            cout << "Invalid choice. Exiting..." << endl;
            break;
    }

    return 0;
}
