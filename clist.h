/**
 * @file clist.h
 * @author Andrew Eissen <andrew@andreweissen.com>
 * @date 2 July 2021
 * @brief Header file for single linked list containing methods permitting its
 * use as a traditional list, stack, or queue.
 */

#ifndef __CLIST_H_
#define __CLIST_H_

/**
 * @brief The <code>s_node</code> <code>struct</code> contains a pair of data
 * members, namely <code>p_next</code> and <code>p_data</code>, that take the
 * form of pointers to the next <code>node</code> in the list and the location
 * at which the associated value is stored in memory.
 */
typedef struct s_node {
  struct s_node * p_next; /**< Pointer to next <code>s_node</code> */
  void * p_data;          /**< Pointer to location of associated value */
} t_node;

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
void cl_print(t_node * p_head, void (* print)(void *));

/**
 * @brief The <code>cl_print_int</code> function is responsible for calling the
 * standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>int</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_int(void * p_data);

/**
 * @brief The <code>cl_print_float</code> function is responsible for calling
 * the standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>float</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_float(void * p_data);

/**
 * @brief The <code>cl_print_double</code> function is responsible for calling
 * the standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>double</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_double(void * p_data);

/**
 * @brief The <code>cl_print_char</code> function is responsible for calling the
 * standard <code>printf</code> function and typecasting/dereferencing the
 * <code>p_data</code> pointer passed as the formal parameter. This function is
 * generally passed to <code>cl_print</code> to print <code>char</code>s.
 *
 * @param p_data void* A pointer to the value
 * @return void
 */
void cl_print_char(void * p_data);

/**
 * @brief The <code>cl_clear</code> function is responsible for freeing all the
 * space in heap memory previously allocated for each individual node. This
 * function should be called by the initializing function responsible for
 * building the list and passed a double pointer to the address of the head.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @return void
 */
void cl_clear(t_node ** p_head);

/**
 * @brief The <code>cl_reverse</code> function is used to reverse the list,
 * converting the head node specified via the double pointer passed as a formal
 * parameter to the new list tail and reversing the placement of all the other
 * internal nodes accordingly.
 *
 * @param p_head t_node** A double pointer to the location of the head pointer
 * @return void
 */
void cl_reverse(t_node ** p_head);

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
void cl_push(t_node ** p_head, void * p_newData);

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
void * cl_pop(t_node ** p_head);

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
void cl_unshift(t_node ** p_head, void * p_newData);

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
void * cl_shift(t_node ** p_head);

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
void cl_insert_value_at_index(t_node ** p_head, void * p_data, int index);

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
void * cl_delete_by_index(t_node ** p_head, int index);

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
    int (* compare)(void *, int));

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
int cl_compare_int(void * p_data, int target);

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
int cl_compare_float(void * p_data, float target);

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
int cl_compare_double(void * p_data, double target);

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
int cl_compare_char(void * p_data, char target);

#endif // __CLIST_H_
