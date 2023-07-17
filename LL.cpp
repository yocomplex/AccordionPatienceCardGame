#include "LL.h"

// Postfix Opeator moves the iterator over to the next node
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++(int)
{
	iterator current(position);
	position = position->next;

	return current;
}

// Prefix operator that moves the iterator over the next node
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++()
{
	position = position->next;

	return *this;
}

// Postfix operator that moves the iterator over to the previous node
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--(int)
{
	iterator current(position);
	position = position->prev;

	return current;
}

// Prefix operator that moves the iterator over to the previous node
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--()
{
	position = position->prev;

	return *this;
}

// Default constructor
template <class type>
LL<type>::LL()
{
	dummy = new node; // Allocates a node to dummy
	dummy->next = dummy; // Set dummy next to dummy
	dummy->prev = dummy; // Set dummy prev to dummy
}

// Copy constructor
template <class type>
LL<type>::LL(const LL<type>& copy)
{
	dummy = new node; // Allocates a node to dummy
	dummy->next = dummy; // Set dummy next to dummy
	dummy->prev = dummy; // Set dummy prev to dummy
	copyList(copy); // Calls copyList function to the given param
}

// Assignment operator that calls clearlist and copylist
template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
	if (this != &rhs)
	{
		clearList();
		copyList(rhs);
	}

	return *this;
}

// Destructor
template <class type>
LL<type>::~LL()
{
	clearList(); // Call clearList function
	delete dummy; // Deallocate dummy noode
}

// headInsert() function inserts new node to the front of LL
template <class type>
void LL<type>::headInsert(const type& item)
{
	node *newNode = new node; // Insert new node
	newNode->item = item; // Setting new node item to item

    if (isEmpty())
    {
        newNode->next = dummy; // Set new node next to dummy
        newNode->prev = dummy; // Set new node prev to dummy
        dummy->next = newNode; // Set dummy next to new node
        dummy->prev = newNode; // Set dummy prev to new node
    } else {
        newNode->next = dummy->next; // Dummy next points to new node
        newNode->prev = dummy; // Dummy points to newNode prev
        dummy->next->prev = newNode; //  New node points to dummy next prev
        dummy->next = newNode; // New node points to dummy next
    }
}

// tailInsert() function inserts new node to the end of LL
template <class type>
void LL<type>::tailInsert(const type& item)
{
	node *newNode = new node; // Insert new node
	newNode->item = item; // Set new node item field to item

	if (isEmpty())
    {
        newNode->prev = dummy; // Set new node prev to dummy
        newNode->next = dummy; // Set new node next to dummy
        dummy->prev = newNode; // Set dummy prev to new node
        dummy->next = newNode; // Set dummy next to new node
	} else {
		newNode->next = dummy; // New node next points back to dummy next
		newNode->prev = dummy->prev; // Dummy prev points to new node prev
		dummy->prev->next = newNode; // Set dummy prev next to new node
		dummy->prev = newNode; // Set new node next and prev to dummy
	}
}

// Function removes the front node if list isn't empty
template <class type>
void LL<type>::headRemove()
{
	// If list is not empty, remove front node
	if (!isEmpty()) 
	{
		node *temp = dummy->next; // Create a temp variable that holds node of dummy next
		dummy->next = temp->next; // Sets dummy next to temp next
		temp->next->prev = dummy; // Sets temp next prev to dummy node
		delete temp; // Remove node
	}
}

// Function removes the end node if list isn't empty
template <class type>
void LL<type>::tailRemove()
{
	// If list is not empty, remove end node
	if (!isEmpty()) 
	{
		node *temp = dummy->prev; // Create a temp variable that holds node of dummy prev
		dummy->prev = temp->prev; // Sets dummy prev to the temp prev
		temp->prev->next = dummy; // linking the temp prev next to dummy
		delete temp; // Remove node
	}
}

// Function removes the node that the iterator points to
template <class type>
void LL<type>::removeAtPosition(LL<type>::iterator & it)
{
	node *itTemp = it.position; // Create temporary iterator pointer that holds position
	// If position points to front or end, call headRemove or tailRemove
	if (it.position == dummy->next) {
		headRemove(); // Call headRemove
		it.position = dummy->next; // Set it position to point to new front node 
	} else if (it.position == dummy->prev) {
		tailRemove(); // Call tailRemove
		it.position = dummy->prev; // Set it position to point to new tail node
	// If it position points to middle
	} else {
		it.position = itTemp->next; // iterator position points to next node
		itTemp->prev->next = itTemp->next; // Iterator prev next points to iterator next
		itTemp->next->prev = itTemp->prev; // Iterator next prev points to iterator prev
		delete itTemp; // Remove node
	}
}

// Deallocate the list using headRemove function until node is a dummy node
template <class type>
void LL<type>::clearList()
{
	while (!isEmpty()) 
	{
		headRemove(); // Call headRemove function
	}
}

// Function deep copies copyThisList into *this 
template <class type>
void LL<type>::copyList(const LL<type>& copyThisList)
{
	// Deep copies copyThisList into this obj using tailInsert
	iterator iterate = copyThisList.begin();
	while (iterate != copyThisList.end()) 
	{
		tailInsert(*iterate); // Call tailInsert function
		++iterate; // Increment the iterator
	}
}