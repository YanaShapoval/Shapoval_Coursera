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
 * @file <stats.h> 
 * @brief <The header  file for prolect that implement functions to get statistics of array >
 *
 * <Add Extended Description Here>
 *
 * @author <Iana Shapoval>
 * @date <03/10/2024 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

//Function used to find a median in array
int find_median(unsigned char array[], unsigned int size);
// Function for find a min value in array
int find_minimum(unsigned char array[], unsigned int size);
// Function for find a max value in array
int find_maximum(unsigned char array[], unsigned int size);
//Function used to find a mean in array
int find_mean(unsigned char array[], unsigned int size);
/*Function to sort array in decreasing order by Bubble sort 
(because for 40 elements that complecsity is acceptable)*/
unsigned char* sort_array(unsigned char array[], unsigned int size);
// Function for print array in a screen
void print_array(unsigned char array[], unsigned int size);
//Function for print all statictics
void print_statistics(unsigned char array[], unsigned int size);
/* Function for implement swaip in sorting, 
two elements change their place on each other place*/ 
void swap(unsigned char *a, unsigned char *b);
/*Function to sort array in increasing order by Bubble sort 
(because for 40 elements that complecsity is acceptable) for calculate a median*/
unsigned char* sort_array_increase(unsigned char array[], unsigned int size);


/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */
