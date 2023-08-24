# accordionCardGame
***I give copyright to my Professor, James Andro Vasko for assigning this project. He is awesome and I found this project to be really fun and creative! It's a great way to implement and practice Linked Lists, Stacks, and Templates!***


Simulate playing games of Accordion. The rules are as follows:
Deal cards one by one in a row from left to right, not overlapping. Whenever the card matches its immediate neighbor on the left, or matches the third card to the left, it may be moved onto that card. Cards match if 
they are of the same suit or same rank. After making a move, look to see if it has made additional moves possible. Only the top card of each pile may be moved at any given time. Gaps between piles should be closed up
as soon as they appear by moving all piles on the right of the gap one position to the left. Deal out the whole pack, combining cards towards the left whenever possible. The game is won if the pack is reduced to a
single pile. Situations can arise where more than one play is possible. Where two cards may be moved, you should adopt the strategy of always moving the leftmost card possible. Where a card may be moved either one 
position to the left or three positions to the left, move it three positions. In order to solve the problem, create a custom stack and linked list classes.

How to run:
You run the main file and execute using "./a.out < <cards0#>.txt". Note the "#" Indicates from 1 or 2 so use whichever one according to preference.

The input:
Input data to the program specifies the order in which cards are dealt from the pack. The input contains a set of 52 cards. Cards are represented as a two character code. The first character is the face-value (A=Ace,
2–9, T=10, J=Jack, Q=Queen, K=King) and the second character is the suit (C=Clubs, D=Diamonds, H=Hearts, S=Spades). The cards are read in through linux redirection.

The output:
Output shows the number of cards in each of the piles remaining along with the card on top of each pile and size of each pile after playing “Accordian patience”.

cards01.txt outputs:
6 Stacks : 2 H :40 QC :8 3 D :1 9 S :1 7 H :1 5 C :1

cards02.txt outputs:
1 Stacks : KS :52
