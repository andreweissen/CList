/**
 * @file main.c
 * @author Andrew Eissen <andrew@andreweissen.com>
 * @date 2 July 2021
 * @brief Source file used solely to test the various functions and associated
 * functionality of the linked list data structure created by the author.
 */

#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_INT_ARRAY_SIZE 7
#define INITIAL_DOUBLE_ARRAY_SIZE 3

/**
 * @brief The <code>main</code> function, a required C function, serves as the
 * driver of the program. It contains a number of test cases that measure the
 * linked list data structure's ability to handle the manipulation of data in
 * the form of linked nodes.
 *
 * @param argc int Number of command line arguments
 * @param argv char** Actual command line arguments passed on invocation
 * @return int Default of 0
 */
int main(int argc, char **argv) {

  // Declarations
  t_node * list1, * list2;
  int i, j, int_array[INITIAL_INT_ARRAY_SIZE], int_second, int_third;
  double double_array[INITIAL_DOUBLE_ARRAY_SIZE], double_second, double_third;

  // Define lists
  list1 = NULL, list2 = NULL;

  printf("----Test int----\n");

  // Generate ints
  for (i = 0; i < INITIAL_INT_ARRAY_SIZE; i++) {
    int_array[i] = i;
    cl_push(&list1, &int_array[i]);
  }
  int_second = INITIAL_INT_ARRAY_SIZE;
  int_third = int_second + 1;

  // Generate doubles
  for (j = 0; j < INITIAL_DOUBLE_ARRAY_SIZE; j++) {
    double_array[j] = j;
    cl_push(&list2, &double_array[j]);
  }
  double_second = (double) INITIAL_DOUBLE_ARRAY_SIZE;
  double_third = (double) INITIAL_DOUBLE_ARRAY_SIZE + 1.0f;

  printf("Original list   : ");
  cl_print(list1, cl_print_int);

  cl_reverse(&list1);
  printf("Reverse list    : ");
  cl_print(list1, cl_print_int);

  cl_pop(&list1);
  printf("Pop last item   : ");
  cl_print(list1, cl_print_int);

  cl_reverse(&list1);
  printf("Reverse list    : ");
  cl_print(list1, cl_print_int);

  cl_delete_by_index(&list1, 0);
  printf("Delete index 0  : ");
  cl_print(list1, cl_print_int);

  cl_delete_by_value(&list1, 4, cl_compare_int);
  printf("Delete value 4  : ");
  cl_print(list1, cl_print_int);

  cl_push(&list1, &int_second);
  printf("Push value 7    : ");
  cl_print(list1, cl_print_int);

  cl_reverse(&list1);
  printf("Reverse list    : ");
  cl_print(list1, cl_print_int);

  cl_delete_by_index(&list1, 2);
  printf("Delete index 2  : ");
  cl_print(list1, cl_print_int);

  cl_insert_value_at_index(&list1, &int_third, 2);
  printf("Insert 8 at 2   : ");
  cl_print(list1, cl_print_int);

  cl_reverse(&list1);
  printf("Reverse list    : ");
  cl_print(list1, cl_print_int);

  cl_delete_by_index(&list1, 8);
  printf("Delete index 8  : ");
  cl_print(list1, cl_print_int);

  cl_delete_by_index(&list1, 5);
  cl_delete_by_index(&list1, 4);
  cl_delete_by_index(&list1, 3);
  cl_delete_by_index(&list1, 2);
  cl_delete_by_index(&list1, 1);
  printf("Reduce to one   : ");
  cl_print(list1, cl_print_int);

  printf("\n");
  printf("----Test double----\n");

  printf("Original list   : ");
  cl_print(list2, cl_print_double);

  cl_reverse(&list2);
  printf("Reverse list    : ");
  cl_print(list2, cl_print_double);

  cl_push(&list2, &double_second);
  printf("Push value 3.0  : ");
  cl_print(list2, cl_print_double);

  cl_unshift(&list2, &double_third);
  printf("Insert 4.0 at 0 : ");
  cl_print(list2, cl_print_double);

  cl_reverse(&list2);
  printf("Reverse list    : ");
  cl_print(list2, cl_print_double);

  cl_shift(&list2);
  printf("Perform shift   : ");
  cl_print(list2, cl_print_double);

  // Deallocate all nodes from heap
  cl_clear(&list1);
  cl_clear(&list2);

  return 0;
}
