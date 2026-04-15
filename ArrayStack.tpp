// Constructor: creates a stack with a given maximum size
template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    if (i <= 0) { // check for invalid size
        throw string("Invalid stack size."); // throw error if size is not positive
    }

    maxSize = i;            // set the maximum capacity of the stack
    this->length = 0;       // initialize current number of elements to 0
    buffer = new T[maxSize]; // dynamically allocate array to hold elements
}

// Copy constructor: creates a new stack as a copy of another
template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj); // call helper function to copy data
}

// Assignment operator: handles assigning one stack to another
template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) { // avoid self-assignment
        clear();             // free existing memory
        copy(rightObj);      // copy data from right-hand object
    }
    return *this; // return current object to allow chaining
}

// Destructor: called when object is destroyed
template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear(); // free dynamically allocated memory
}

// Clears the stack and resets values
template <typename T>
void ArrayStack<T>::clear() {
    delete[] buffer;   // delete dynamically allocated array
    buffer = nullptr;  // set pointer to null to avoid dangling pointer
    this->length = 0;  // reset number of elements
    maxSize = 0;       // reset capacity
}

// Copies data from another stack
template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    maxSize = copyObj.maxSize;       // copy capacity
    this->length = copyObj.length;   // copy current size

    buffer = new T[maxSize];         // allocate new array

    for (int i = 0; i < this->length; i++) { // copy each element
        buffer[i] = copyObj.buffer[i];
    }
}

// Returns number of elements in stack
template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

// Returns maximum capacity of stack
template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

// Checks if stack is empty
template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

// Checks if stack is full
template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

// Returns the top element without removing it
template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) { // error if stack is empty
        throw string("Cannot peek from an empty stack.");
    }

    return buffer[this->length - 1]; // return last element
}

// Removes the top element
template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) { // error if stack is empty
        throw string("Cannot pop from an empty stack.");
    }

    this->length--; // decrease size (effectively removes top element)
}

// Adds a new element to the top
template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) { // error if stack is full
        throw string("Cannot push to a full stack.");
    }

    buffer[this->length] = elem; // place new element at next position
    this->length++;              // increase size
}

// Rotates elements left or right
template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {

    if (this->length <= 1) { // nothing to rotate if 0 or 1 element
        return;
    }

    if (dir == Stack<T>::RIGHT) { // rotate right

        T temp = buffer[this->length - 1]; // save last element

        for (int i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i - 1]; // shift elements right
        }

        buffer[0] = temp; // move last element to front
    }
    else if (dir == Stack<T>::LEFT) { // rotate left

        T temp = buffer[0]; // save first element

        for (int i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1]; // shift elements left
        }

        buffer[this->length - 1] = temp; // move first element to end
    }
}

// Overloads << operator to print stack contents
template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) { // check if stack is empty
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        // print elements from top to bottom
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream; // return stream for chaining
}
