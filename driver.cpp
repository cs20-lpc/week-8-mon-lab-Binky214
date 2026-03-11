#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& s) {

    cout << "Original Stack:\n";
    cout << s << endl;

    s.rotate(Stack<T>::RIGHT);
    cout << "After RIGHT rotate:\n";
    cout << s << endl;

    s.rotate(Stack<T>::LEFT);
    cout << "After LEFT rotate:\n";
    cout << s << endl;
}

int main() {

    try {

        //int stack
        ArrayStack<int> s(5);

        cout << "Pushing elements..." << endl;
        s.push(1);
        s.push(2);
        s.push(3);

        cout << s << endl;

        cout << "Peek: " << s.peek() << endl;

        cout << "Pop..." << endl;
        s.pop();
        cout << s << endl;

        testRotate(s);

        //string stack
        cout << "Testing with strings..." << endl;

        ArrayStack<string> s2(4);
        s2.push("A");
        s2.push("B");
        s2.push("C");

        cout << s2 << endl;

        testRotate(s2);

    }
    catch (string e) {
        cout << "Exception: " << e << endl;
    }

    return 0;
}