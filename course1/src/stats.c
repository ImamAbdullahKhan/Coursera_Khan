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
 * @file stats.c 
 * @brief Its a program made for coursera course assigment which does the following :
    Prints Array
    Prints Statistical Data(Mean, Max, Min) and
    Prints Median
 *
 * <Add Extended Description Here>
 *
 * @author Imam Abdullah Khan
 * @date 13 July 2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char array[]);
void print_median(unsigned char med[], int n);
void sort_array(unsigned char sort[], int n);
void print_statistics(unsigned char sort[], int n);
int find_minimum(unsigned char array[], int n);
int find_mean(unsigned char * ptr, int count);
int find_maximum(unsigned char array[], int count);

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */

print_array(test);              //Prints the given array(test) on the screen
print_median(test, SIZE);       //Takes array and its length and gives median as output
sort_array(test, SIZE);		// Takes array and its length and sorts the array from largest to smallest.
print_array(test);      	//Prints the given array(test) after sorting is performed
print_statistics(test, SIZE);	//Prints the given array(test) statistics including minimum, maximum, mean and median on the screen

}

void print_array(unsigned char array[]){
int i;
for(i = 0; i < SIZE; i++){

if(i%8 == 0){ 
printf("\n%d   ", array[i]);
}
else{
printf("%d   ", array[i]);
}
}
}

void sort_array(unsigned char sort[], int n){
int i, j, temp;
for(i=0; i<n-1;i++){
	for(j=0; j<n-1-i; j++){
		if(sort[j]<sort[j+1])
{
temp = sort[j];
sort[j] = sort[j+1];
sort[j+1] = temp;

}
}
}
}
void print_median(unsigned char med[], int n){
float median;
sort_array(med, n);
if(n%2==0){
median = (med[(n/2)-1]+med[(n/2)])/2;
}
else
median = med[(n/2)];

printf("\nMedian is %f\n", median);
}

int find_mean(unsigned char array[], int count){
  int i;
  int mean = 0; 
  for(i = 0; i < count; i++){
    mean += array[i];
    
  }
 
  return (mean / count);
}
int find_maximum(unsigned char array[], int count){
int i = 0;
int max = 0;
for(i=0; i < count; i++){
    
    if (array[i] >= max){
      max = array[i];
    }    
}
return max;
}
int find_minimum(unsigned char array[], int count){
int i = 0;
int min;
for(i=0; i < count; i++){
    
    if (array[i] <= min){
      min = array[i];
    }  
}
  
return min;
}
void print_statistics(unsigned char stat[], int n){
int mean;
int max;
int minimum;

mean = find_mean(stat, n);
max = find_maximum(stat, n);
printf("\nMean value of array is %d", mean);
printf("\nMaximum value of number in array is %d", max);
minimum = find_minimum(stat, n);
printf("\nMinimum value of number in array is %d", minimum);
print_median(stat, n);
}



/* Add other Implementation File Code Here */
