/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <create function that print out statistic about array>
 *
 * <Add Extended Description Here>
 *
 * @author <Iana Shapoval>
 * @date <03/10/2024 >
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test,SIZE);
  print_array(sort_array(test,SIZE),SIZE);
  return 0;

}

//Function used to find a median in array
int find_median(unsigned char array[], unsigned int size){
  array = sort_array_increase(array,SIZE);
  int median = 0;
  if(size % 2 == 0){
    median = (array[size / 2] + array[size / 2 + 1]) / 2;
  }
  else {
    median = array[size / 2 + 1];
  }
  return median;
}

// Function for find a min value in array
int find_minimum(unsigned char array[], unsigned int size){
  int min = array[0];
  for(int i = 0; i < size; i++){
    if (min > array[i]){
      min = array[i];
    }
  }
  return min;
}

// Function for find a max value in array
int find_maximum(unsigned char array[], unsigned int size){
  int max = array[0];
  for(int i = 0; i < size; i++){
    if (max < array[i]){
      max = array[i];
    }
  }
  return max;
} 

//Function used to find a mean in array
int find_mean(unsigned char array[], unsigned int size){
  int mean;
  unsigned int summ = 0;
  if (size == 0) {
    return 0; // Avoid division by zero
  }
  for(int i = 0; i < size; i++){
    summ += array[i];
  }
  mean = (int)summ / size;
  return mean;

}
/*Function to sort array in decreasing order by Bubble sort 
(because for 40 elements that complecsity is acceptable)*/
unsigned char* sort_array(unsigned char array[], unsigned int size){
  unsigned char* sortedArray = malloc(size * sizeof(unsigned char));
  if (sortedArray == NULL) {
    printf("Memory allocation failed.");
    exit(1);
  }
  for (int i = 0; i < size; i++) {
    sortedArray[i] = array[i];
  }
  for (int i = 0; i < size - 1; i++){
    for (int j = 0; j < size - i - 1; j++){
      if (sortedArray[j] < sortedArray[j + 1]){
        swap(&sortedArray[j], &sortedArray[j + 1]);
      }
    }
  }

  return sortedArray;
}


// Function for print array in a screen
void print_array(unsigned char array[], unsigned int size){
  printf("Sort array: ");
  for(int i = 0; i < size; i++){
    printf("%u, ", array[i]);
  }
  printf("\n");

}

//Function for print all statictics
void print_statistics(unsigned char array[], unsigned int size){
  printf("Median value of array: %d\n", find_median(array, size));
  printf("Mean value of array: %d\n",  find_mean(array, size));
  printf("Maximum value of array: %d\n", find_maximum(array, size));
  printf("Minimum value of array: %d\n", find_minimum(array, size));
}


/* Add other Implementation File Code Here */

/* Function for implement swaip in sorting, 
two elements change their place on each other place*/ 
void swap(unsigned char *a, unsigned char *b){
  unsigned char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/*Function to sort array in increasing order by Bubble sort 
(because for 40 elements that complecsity is acceptable) for calculate a median*/
unsigned char* sort_array_increase(unsigned char array[], unsigned int size){
  unsigned char* sortedArray = malloc(size * sizeof(unsigned char));
  if (sortedArray == NULL) {
    printf("Memory allocation failed.");
    exit(1);
  }

  for (int i = 0; i < size; i++) {
    sortedArray[i] = array[i];
  }

  for (int i = 0; i < size - 1; i++){ 
    for (int j = 0; j < size - i - 1; j++){
      if (sortedArray[j] > sortedArray[j + 1]){
        swap(&sortedArray[j], &sortedArray[j + 1]);
      }
    }
  }

  return sortedArray;
}