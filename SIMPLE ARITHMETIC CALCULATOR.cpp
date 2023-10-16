#include <iostream>
using namespace std;
double a, b;
char choice;

void add(double x, double y) {
    cout << "The result of addition is " << " " << x + y << endl;
}

void subtract(double x, double y) {
    cout << "The result of subtraction is " << " " << x - y << endl;
}

void multiply(double x, double y) {
    cout << "The result of multiplication is " << " " << x * y << endl;
}

void divide(double x, double y) {
    if (y != 0) {
        cout << "The result of division is " << " " << x / y << endl;
    }
    else {
        cout << "Division by zero is not allowed." << endl;
    }
}

int main() {
 

    do {
        cout << "Enter the first number: ";
        cin >> a;

        if (cin.fail()) {
            cout << "Invalid input for the first number." << endl;
            cin.clear();             
            cin.ignore(10000, '\n'); 
            continue;            
        }

        cout << "Enter the second number: ";
        cin >> b;

        if (cin.fail()) {
            cout << "Invalid input for the second number." << endl;
            cin.clear();             
            cin.ignore(10000, '\n'); 
            continue;              
        }

        cout << "Choose operation to perform:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cin >> choice;

        switch (choice) {
        case '1':
            add(a, b);
            break;
        case '2':
            subtract(a, b);
            break;
        case '3':
            multiply(a, b);
            break;
        case '4':
            divide(a, b);
            break;
        default:
            cout << "Invalid input" << endl;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
