/**
 * @file clist.c
 * @author Andrew Eissen <andrew@andreweissen.com>
 * @date 2 July 2021
 * @brief Source file for single linked list containing methods permitting its
 * use as a traditional list, stack, or queue.
 */

#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The <code>cl_print</code> function is used to print the contents of
 * the linked list, starting from the head node. A pointer to the head node is
 * passed as the first formal parameter, along with a pointer to the particular
 * type-specific helper function responsible for printing the associated values.
 *
 * @param p_head t_node* A pointer to the head node at the start of the list
 * @param print void A pointer to the type-specific printing function
 * @return void
 */
void cl_print(t_node * p_head, void (* print)(void *)) {

  // Declaration
  t_node * p_current;

  if (p_head == NULL) {
    return;
  }

  // Set head as first current
  p_current = p_head;

  // While nodes exist, print the data
  while (p_current != NULL) {
    (* print)(p_current->p_data);
    p_current = p_current->p_next;
  }
  printf("\n");
}

/**
 * @brief The <code>cl_print_int</code> function is responsible for calling the
 * standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>int</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_int(void * p_data) {
  printf("%d ", *(int *) p_data);
}

/**
 * @brief The <code>cl_print_float</code> function is responsible for calling
 * the standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>float</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_float(void * p_data) {
  printf("%.1f ", *(float *) p_data);
}

/**
 * @brief The <code>cl_print_double</code> function is responsible for calling
 * the standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>double</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_double(void * p_data) {
  printf("%.1lf ", *(double *) p_data);
}

/**
 * @brief The <code>cl_print_char</code> function is responsible for calling the
 * standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>char</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_char(void * p_data) {
  printf("%c ", *(char *) p_data);
}

/**
 * @brief The <code>cl_clear</code> function is responsible for freeing all the
 * space in heap memory previously allocated for each individual node. This
 * function should be called by the initializing function responsible for
 * building the list and passed a double pointer to the address of the head.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @return void
 */
void cl_clear(t_node ** p_head) {

  // Declarations
  t_node * p_current, * p_next;

  if (*p_head == NULL) {
    return;
  }

  // Definitions
  p_current = *p_head;
  p_next = NULL;

  // While the end of list hasn't been reached
  while (p_current != NULL) {

    // Cache next, right-hand node
    p_next = p_current->p_next;

    // Set all pointers to null pointer values
    p_current->p_data = NULL;
    p_current->p_next = NULL;
    p_current = NULL;

    // Deallocate current node
    free(p_current);

    // Redefine current node
    p_current = p_next;
  }
}

/**
 * @brief The <code>cl_reverse</code> function is used to reverse the list,
 * converting the head node specified via the double pointer passed as a formal
 * parameter to the new list tail and reversing the placement of all the other
 * internal nodes accordingly.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @return void
 */
void cl_reverse(t_node ** p_head) {

  // Declarations
  t_node * p_current, * p_previous, * p_next;

  // Do nothing if head has not been set
  if (*p_head == NULL) {
    return;
  }

  // Definitions
  p_current = *p_head;
  p_previous = NULL;
  p_next = NULL;

  // Core of reverse algorithm
  while (p_current != NULL) {
    p_next = p_current->p_next;     // Cache right-hand node
    p_current->p_next = p_previous; // Left-hand node becomes right-hand node
    p_previous = p_current;         // Cache current node as right-hand for next
    p_current = p_next;             // Move right-hand node to next node
  }

  // Set new left-most node as head
  *p_head = p_previous;
}

/**
 * @brief <code>cl_push</code> is one of the functions that allows the list to
 * be used like a stack. It serves as the primary means by which a new node
 * element can be added to the end of the list. It is contrasted with
 * <code>cl_unshift</code>, which adds an element to the beginning of the list.
 *
 * @see https://www.w3schools.com/jsref/jsref_push.asp
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @param p_newData void* A pointer to the location of the new value
 * @return void
 */
void cl_push(t_node ** p_head, void * p_newData) {

  // Declarations
  t_node * p_newNode, * p_current;

  // Allocate space for new node
  p_newNode = malloc(sizeof(t_node));

  // Ensure space has been allocated in heap
  if (p_newNode == NULL) {
    return;
  }

  // Set data property
  p_newNode->p_data = p_newData;

  // Set head as first current
  p_current = *p_head;

  // Iterate through to last extant node in list
  while (p_current != NULL && p_current->p_next != NULL) {
    p_current = p_current->p_next;
  }

  // In the event that head has not been set
  if (p_current == NULL) {

    // Set next node as NULL
    p_newNode->p_next = NULL;

    // Set new node as the head if unset
    *p_head = p_newNode;
    return;
  }

  // Add new node as next of last item
  p_current->p_next = p_newNode;

  // Set next node as NULL
  p_newNode->p_next = NULL;
}

/**
 * @brief <code>cl_pop</code> is one of the functions that allows the list to be
 * used like a stack. It serves as the primary means by which a node element can
 * be removed from the end of the list. It is contrasted with
 * <code>cl_shift</code>, which removes the head at the beginning of the list.
 *
 * @see https://www.w3schools.com/jsref/jsref_pop.asp
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @return void* A pointer to the location of the removed node element
 */
void * cl_pop(t_node ** p_head) {

  // Declarations
  t_node * p_current, * p_previous;
  void * p_data;

  if (*p_head == NULL) {
    return NULL;
  }

  // Definitions
  p_current = *p_head;
  p_previous = NULL;

  // While current node has a child (isn't tail), iterate
  while (p_current->p_next != NULL) {
    p_previous = p_current;
    p_current = p_current->p_next;
  }

  // Cache data for retrieval and return
  p_data = p_current->p_data;

  // Current node could be head, so only adjust previous pointer if not
  if (p_previous != NULL) {
    p_previous->p_next = NULL;
  }

  // Deallocate heap memory
  free(p_current);

  //Return cached data
  return p_data;
}

/**
 * @brief <code>cl_unshift</code> is one of the functions that allows the list
 * to be used as a queue. It serves as one of the primary means by which a new
 * node can be added to the front of the list. It is contrasted with
 * <code>cl_push</code>, which adds an element to the end of the list.
 *
 * @see https://www.w3schools.com/jsref/jsref_unshift.asp
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @param p_newData void* A pointer to the location of the new value
 * @return void
 */
void cl_unshift(t_node ** p_head, void * p_newData) {

  // Simple handoff to cl_insert_value_at_index with an index of 0
  cl_insert_value_at_index(p_head, p_newData, 0);
}

/**
 * @brief <code>cl_shift</code> is one of the functions that allows the list
 * to be used as a queue. It serves as one of the primary means by which a new
 * node can be removed from the front of the list. It is contrasted with
 * <code>cl_pop</code>, which removes the tail from the end of the list.
 *
 * @see https://www.w3schools.com/jsref/jsref_shift.asp
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @return void* A pointer to the location of the removed node element
 */
void * cl_shift(t_node ** p_head) {

  // Declarations
  t_node * p_next;
  void * p_data;

  // Do nothing if head has not been set
  if (*p_head == NULL) {
    return NULL;
  }

  // Definitions
  p_data = (*p_head)->p_data;
  p_next = (*p_head)->p_next;

  // Set new head if there is more than one node in list
  if (p_next != NULL) {
    *p_head = p_next;
  }

  // Deallocate heap memory for node
  free(*p_head);

  return p_data;
}

/**
 * @brief <code>cl_insert_value_at_index</code> is a specialized function that
 * permits insertion of a new node at a specific index located in relation to
 * the head node (which by convention occupies index 0). If the requested index
 * lies beyond the list's size, the element is simply pushed to the end.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @param p_data void* A pointer to the location of the new value
 * @param index int The index at which the data is to be inserted (from head)
 * @return void
 */
void cl_insert_value_at_index(t_node ** p_head, void * p_data, int index) {

  // Declarations
  t_node * p_current, * p_previous, * p_newNode;
  int counter;

  // Definitions
  p_current = *p_head;
  p_previous = NULL;
  p_newNode = NULL;
  counter = 0;

  // Exit if head doesn't exist and function is not being used to set it
  if (*p_head == NULL && index != 0) {
    return;
  }

  // Iterate while the current node exists and index hasn't been found
  while (p_current != NULL && counter++ < index) {
    p_previous = p_current;
    p_current = p_current->p_next;
  }

  // Push to end of list if index is beyond bounds or at the end
  if (p_current == NULL) {
    cl_push(p_head, p_data);
    return;
  }

  // Allocate space for a new node
  p_newNode = malloc(sizeof(t_node));

  // Ensure space exists in head for new node
  if (p_newNode == NULL) {
    return;
  }

  // Adjust pointer of left-hand node to newNode
  if (p_previous != NULL) {
    p_previous->p_next = p_newNode;
  } else {
    *p_head = p_newNode;
  }

  // newNode should point to current node
  p_newNode->p_next = p_current;

  // Set data of node
  p_newNode->p_data = p_data;
}

/**
 * @brief The <code>cl_delete_by_index</code> function is similar to
 * <code>cl_insert_value_at_index</code> in that it selects a node based on
 * its index in relation to the head node and removes that node from the list.
 * A pointer to the address of that removed node is returned from the function.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @param index int The index of the data to be removed (from head)
 * @return void* A pointer to the location of the removed node element
 */
void * cl_delete_by_index(t_node ** p_head, int index) {

  // Declarations
  t_node * p_current, * p_previous;
  void * p_data;
  int counter;

  if (*p_head == NULL) {
    return NULL;
  }

  // Definitions
  p_current = *p_head;
  p_previous = NULL;
  counter = 0;

  // Iterate while the current node exists and index hasn't been found
  while (p_current != NULL && counter++ < index) {
    p_previous = p_current;
    p_current = p_current->p_next;
  }

  // Return if requested index lies beyond list limits
  if (p_current == NULL) {
    return 0;
  }

  // Cache data for retrieval and return
  p_data = p_current->p_data;

  // Desired node could be head, so reset head to right-hand node if so
  if (p_previous == NULL) {
    *p_head = p_current->p_next;

  // ... otherwise, set left-hand node's "next" to right node
  } else {
    p_previous->p_next = p_current->p_next;
  }

  // Deallocate heap memory for node
  free(p_current);

  return p_data;
}

/**
 * @brief <code>cl_delete_by_value</code> is a more involved version of
 * <code>cl_delete_by_index</code> that removes a node from the list based on
 * its associated value rather than its index. A comparator function is used to
 * typecast and compare each node's value with the target passed as a parameter.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @param target int The target value of the node to be removed
 * @param compare int A pointer to a helper function used to compare values
 * @return void
 */
void cl_delete_by_value(t_node ** p_head, int target,
    int (* compare)(void *, int)) {

  // Declarations
  t_node * p_current, * p_previous;

  if (*p_head == NULL) {
    return;
  }

  // Definitions
  p_current = *p_head;
  p_previous = NULL;

  // While current node exists and its data doesn't match target, iterate
  while (p_current != NULL && (* compare)(p_current->p_data, target)) {
    p_previous = p_current;
    p_current = p_current->p_next;
  }

  // Requested data has not been found
  if (p_current == NULL) {
    return;
  }

  // Desired node could be head, so reset head to right-hand node if so
  if (p_previous == NULL) {
    *p_head = p_current->p_next;

  // ... otherwise, set lefthand node's next to right node
  } else {
    p_previous->p_next = p_current->p_next;
  }

  // Deallocate heap memory for node
  free(p_current);
}

/**
 * @brief <code>cl_compare_int</code> is one of the comparator helper functions
 * that are used by <code>cl_delete_by_value</code> to compare that function's
 * <code>target</code> value to the value of each individual node. It returns an
 * <code>int</code> indicating the status of the operation.
 *
 * @param p_data void* A pointer to the location of the node value
 * @param target int The value to which the function compares the node value
 * @return int A return value of 1 if match found or 0 if not
 */
int cl_compare_int(void * p_data, int target) {
  return *(int *) p_data != target;
}

/**
 * @brief <code>cl_compare_float</code> is one of the comparator helper
 * functions that are used by <code>cl_delete_by_value</code> to compare that
 * function's <code>target</code> value to the value of each individual node.
 * It returns an <code>int</code> indicating the status of the operation.
 *
 * @param p_data void* A pointer to the location of the node value
 * @param target float The value to which the function compares the node value
 * @return int A return value of 1 if match found or 0 if not
 */
int cl_compare_float(void * p_data, float target) {
  return *(float *) p_data != target;
}

/**
 * @brief The <code>cl_compare_double</code> function is one of the comparator
 * helper functions that are used by <code>cl_delete_by_value</code> to compare
 * that function's <code>target</code> value to the value of each individual
 * node. It returns an <code>int</code> indicating the status of the operation.
 *
 * @param p_data void* A pointer to the location of the node value
 * @param target double The value to which the function compares the node value
 * @return int A return value of 1 if match found or 0 if not
 */
int cl_compare_double(void * p_data, double target) {
  return *(double *) p_data != target;
}

/**
 * @brief <code>cl_compare_char</code> is one of the comparator helper functions
 * that are used by <code>cl_delete_by_value</code> to compare that function's
 * <code>target</code> value to the value of each individual node. It returns an
 * <code>int</code> indicating the status of the operation.
 *
 * @param p_data void* A pointer to the location of the node value
 * @param target char The value to which the function compares the node value
 * @return int A return value of 1 if match found or 0 if not
 */
int cl_compare_char(void * p_data, char target) {
  return *(char *) p_data != target;
}
