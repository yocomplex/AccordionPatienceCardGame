#include <cstdlib>
#include "myStack.h"

// Default constructor
template <class type>
myStack<type>::myStack()
{
	size = 0; // Set size to 0
	capacity = 5; // Set capacity to 5
	stackElements = new type[capacity]; // Create a stackElements array
}

// Deep copy constructor
template <class type>
myStack<type>::myStack(const myStack<type>& copy)
{
	copyStack(copy); // Deep copies the stackElements array
}

// Assignment operator deallocates this stackElements and copies the param into copyStack
template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs)
{
	if (this != &rhs)
	{
		clearStack(); // Deallocates this->stackElements array
		copyStack(rhs); // Copies rhs into this object
	}

	return *this;
}

// Destructor
template <class type>
myStack<type>::~myStack()
{
	clearStack(); // Call clearStack function
}

// Function inserts item on top of stack
template <class type>
void myStack<type>::push(const type& item)
{
	// Resize stack if full
	if (size == capacity) 
	{
		capacity *= 2; // Double the capacity
		type *newStack = new type[capacity]; // Create a new stack with new resize
		for (size_t i = 0; i < size; i++) {
			newStack[i] = stackElements[i];
		}
		delete[] stackElements;
		stackElements = newStack; // Set the new sized stack to stackElements
	}
	// Inserts item on top of stackElements at [size]
	// then increase size by 1
	stackElements[size] = item;
	size++;
}

// Function returns the topmost element of the stack
template <class type>
type myStack<type>::peek() const
{
	// If stack is empty, throw out of range exception
	if (isEmpty()) 
	{
		throw std::out_of_range("Empty stack");
	}
	return stackElements[size - 1]; // Returns topmost element
}

// getSize() function returns size
template <class type>
std::size_t myStack<type>::getSize() const
{
	return size;
}

// Function removes the topmost element of the stack
template <class type>
type myStack<type>::pop()
{
	size--; // Removes topmost element by decrementing size
	return stackElements[size]; // Return topmost element
}

// Function checks if size of stack is zero
template <class type>
bool myStack<type>::isEmpty() const
{
	if (size == 0) {
		return true;
	}
	return false;
}

// Function deallocates the stack array and sets all integer fields to 0
template <class type>
void myStack<type>::clearStack()
{
	delete[] stackElements; // Deallocate stackElements array
	stackElements = nullptr;
	// Setting all integer fields to 0
	size = 0;
	capacity = 0;
}

// copyStack() function copies all of the fields of copyThisStack
template <class type>
void myStack<type>::copyStack(const myStack<type>& copyThisStack)
{
	size = copyThisStack.size; // Copies the size
	capacity = copyThisStack.capacity; // Copies the capacity
	stackElements = new type[capacity]; // Creates a new stackElement array
	// Copies the stack
	for (size_t i = 0; i < size; i++) {
		stackElements[i] = copyThisStack.stackElements[i];
	}
}