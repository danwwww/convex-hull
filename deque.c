/* * * * * * *
 * Deque module (i.e., double ended queue) for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by Dan Wu
 */

//                   WRITE YOUR IMPLEMENTATION HERE
//
// You should fill in the function definitions for
//  - new_deque()
//  - free_deque()
//  - deque_push()
//  - deque_insert()
//  - deque_pop()
//  - deque_remove()
//  - deque_size()
//
// Don't be shy to add any extra functions or types you may need.

#include <stdio.h>
#include <stdlib.h>

#include "deque.h"
#include "point.h"

#define NUM 30

// TODO: Fill in this struct definition, or change the typedef in deque.h
struct deque {
  // TODO: Add fields here
  Point * data;
	int maxsize;
	int left;
	int right;
	int nItems;
};

// Create a new empty Deque and return a pointer to it
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Deque *new_deque() {
  // TODO: Implement new_deque()
  //Create an empty deque
  Deque * Q = (Deque*)malloc(sizeof(Deque));
	Q->data = malloc(sizeof(Point)*NUM);
	Q->left = 0;
	Q->right = 1;
	Q->nItems = 0;
	Q->maxsize = NUM;
	return Q;
  fprintf(stderr, "Error: new_deque() not implemented\n");
  exit(EXIT_FAILURE);
}


// Free the memory associated with a Deque
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void free_deque(Deque *deque) {
  // TODO: Implement free_deque()
  free(deque->data);
  fprintf(stderr, "Error: free_deque() not implemented\n");
  exit(EXIT_FAILURE);
}

// Add a Point to the top of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_push(Deque *deque, Point data) {
  // TODO: Implement deque_push()
  if (!isFull(deque))
	{
		if (deque->right == 0)
			deque->right = deque->maxsize - 1;
		else
    deque->right--;
		deque->data[deque->right] = data;
		deque->nItems++;
	}
	else
	{
		fprintf(stderr, "Error: deque_push() not implemented\n");
		exit(EXIT_FAILURE);
	}
}

// Add a Point to the bottom of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_insert(Deque *deque, Point data) {
  // TODO: Implement deque_insert()
  if (!isFull(deque))
	{
		if (deque->left == deque->maxsize - 1)
			deque->left = 0;
		else deque->left++;
		deque->data[deque->left] = data;
		deque->nItems++;
	}
	else
	{
		fprintf(stderr, "Error: deque_insert() not implemented\n");
		exit(EXIT_FAILURE);
	}
}

// Remove and return the top Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_pop(Deque *deque) {
  // TODO: Implement deque_pop
  if (!isEmpty(deque)) {
		if (deque->right == deque->maxsize - 1)
			deque->right = 0;
		else deque->right++;
		deque->nItems--;
	}
  fprintf(stderr, "Error: deque_pop() not implemented\n");
  exit(EXIT_FAILURE);
}

// Remove and return the bottom Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_remove(Deque *deque) {
  // TODO: Implement deque_remove()
  if (!isEmpty(deque))
	{
		if (deque->left==0)
		{
			deque->left = deque->maxsize - 1;
		}
		else
		{
			deque->left--;
		}
		deque->nItems--;
	}
  fprintf(stderr, "Error: deque_remove() not implemented\n");
  exit(EXIT_FAILURE);
}

// Return the number of Points in a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(n)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
int deque_size(Deque *deque) {
  // TODO: Implement deque_size()
  return deque->nItems;
  fprintf(stderr, "Error: deque_size() not implemented\n");
  exit(EXIT_FAILURE);
}

// TODO: Add any other functions you might need for your Deque module
int isEmpty(Deque *deque)
{
	return deque->nItems == deque->maxsize;
}

int isFull(Deque *deque)
{
	return deque->nItems == 0;
}
