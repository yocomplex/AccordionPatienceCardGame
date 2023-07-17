#include "LL.h"
#include "LL.cpp"
#include "myStack.h"
#include "myStack.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    LL <myStack<string>> accordian; // Declare Linked List object accordian
    string card; // Create card variable to read in the cards .txt files
    myStack<string> tempStack; // Create a temp stack variable
    while (cin >> card) { // Populate the linked list by reading a card in
        tempStack.push(card); // Push card onto temp stack
        accordian.tailInsert(tempStack); // Tail insert this stack into the linked list
        tempStack.pop(); // Pop cards off stack
    }

    /* Create iterator variables:
        i = For the 3 to the left neighbor(Priority)
        j = For the 1 to left neighbor (Immediate neighbor if j hits the end after trying to decrement 3 times)
        k = Iterator for the whole loop 
    */
    LL < myStack <string > >:: iterator i, j, k;
    k = accordian.begin(); // Set k to be the beginning of the stack
    // cardMoved: Checks if card has moved
    // endStack: Checks if iterator hits the end of the stack
    bool cardMoved, endStack;
    // Loop for the "Accordian" patience game! :)
    for (; k != accordian.end(); k++) {
        // Reset booleans to false to ensure checks
        cardMoved = false, endStack = false;
        i = k; // Set i to k
        for (int x = 0; x < 3; x++) {
            i--;
            // If i hits the end of the stack, the endStack bool will turn true
            if (i == accordian.end()) {
                endStack = true;
            }
        }
        // If endStack bool is false still, run the priority for 3 left neighbor
        if (endStack == false) {
            // If the face/suit for card i and k are the same, push and pop respectively
            if (((*k).peek()[0] == (*i).peek()[0] || (*k).peek()[1] == (*i).peek()[1])) {
                (*i).push((*k).pop()); // Pop k and push that onto the i stack
                // If k is empty, you remove the empty node to avoid dangling pointers
                if ((*k).isEmpty())
                    accordian.removeAtPosition(k);
                k = i; // Set iterator to the position at i and continue from there
                cardMoved = true; // Set the cardMoved bool to true
            }
        }
        
        // This piece of code ran for immediate neighbor to the left
        endStack = false;
        j = k; // Set j to k
        j--; // Decrement j
        // If j hits the end of the stack, you set the endStack bool to true
        if (j == accordian.end()) { 
            endStack = true;
        }
        // If endStack bool is false still, run the immediate neighbor to the left code
        if (endStack == false) {
            // If the face/suit for card j and k are the same, push and pop respectively
            if (((*k).peek()[0] == (*j).peek()[0] || (*k).peek()[1] == (*j).peek()[1])) {
                (*j).push((*k).pop()); // Pop k and push that onto j
                // If k is empty, you remove the empty node to avoid dangling pointers
                if ((*k).isEmpty()) {
                    accordian.removeAtPosition(k);
                }
                k = j; // Set iterator to the position at j
                cardMoved = true; // Set the cardMoved bool to true
            }
        }
        // If cards were moved you continue to the next iteration of the loop
        if(cardMoved == true){
            k--; // Decrement k
            continue; // Go to next loop
        }
    }

    // Iterate through the stack and print the cards in each stack using 'it'
    LL<myStack<string>>::iterator it;
    int s = 0; // This will give the size of the stack
    for (it = accordian.begin(); it != accordian.end(); it++) {
        s++;
    }
    // Display the number of stacks
    cout << s << " Stacks: ";
    // This loop will iterate through the beginning of the finished game stack
    for (it = accordian.begin(); it != accordian.end(); it++) {
        // Shows the number of cards in each of the piles remaining 
        // along with the card on top of each pile and size of each pile
        cout << (*it).peek() << ":" << (*it).getSize() << " ";
    }

    return 0;
}