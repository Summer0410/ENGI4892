//
//  assign1.h
//
//
//  Created by Xialinqiao on 2017-05-29.
//
//

#ifndef assign1_h
#define assign1_h


/*
 This is the function to calculate the maximum value of the array.
 pre-condition: Pointer to an array of ‘n’ integers
 post-condition: Calculates the maximum element in the array (array is unchanged)
 @ param    array   a pointer to an array of intergers
 @ param    size    the size of the array
 @ return   the maximum value in type of int          */

int calMax(int* array,int size);

/*
 This is the function to calculate the minimum value of the array
 pre-condition: Pointer to an array of ‘n’ integers
 post-condition: Calculates the minimum element in the array (array is unchanged)*
 @ param    array   a pointer to an array of intergers
 @ param    size    the size of the array
 @ return   the minimum value in type of int            */

int calMin(int* array,int size);

/*
 This is the function to calculate the average value of the array
 pre-condition: Pointer to an array of ‘n’ integers
 post-condition: Calculates the average of the elements in the array (array is unchanged)
 @ param    array   a pointer to an array of intergers
 @ param    size    the size of the array
 @ return   the average value in type of double          */

double calAvg(int* array,int size);


struct array_struct{
    int *arrNum;
    int size;
    int maxNum;
    int minNum;
    double avg;
};


#endif /* assign1_h */
