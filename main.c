//
//  main.c
//  ArrayMultiple
//
//  Created by Jonathan on 4/15/13.
//  Copyright (c) 2013 Jonathan. All rights reserved.
//

#include <stdio.h>
int array_absurdity_1(int* a, int N);
int array_absurdity_2(int* array, int N);
int array_absurdity_3(int* array, int N);
void swap(int index1, int index2, int *array);

void dupes(int a[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        while (a[a[i]] != a[i]) {
            int tmp = a[i];
            a[i] = a[tmp];
            a[tmp] = tmp;
        }
    
    for (i = 0; i < n; i++)
        if(i!= a[i]){
            printf("%d ", a[i]);
            return;
        }
}

int main(int argc, const char * argv[])
{

    // insert code here...
    int  a []  = {0, 1, 2, 3, 4, 5, 5};
    dupes(a, sizeof(a)/sizeof(a[0]));
    printf("%d ", array_absurdity_3(a, sizeof(a)/sizeof(a[0])));

}

int array_absurdity_1(int* array, int N) {
    // Your solution goes here...
    
    for (int i = 1; i < N; i++) {
        array[i] ^= array[i-1]^i-1;
        
    }
    return array[N-1];
}

int array_absurdity_2(int* array, int N) {
    // Your solution goes here...
    
    for(int i = 1; i < N;i++){
        array[i]^=array[i-1];
    }
    return array[N-1];
}

int array_absurdity_3(int* array, int N) {
    // Your solution goes here...
    for (int i = 0; i< N; ++i) {
        if(i != array[i]){
            swap(i, array[i], array);
        }
    }
    
    for(int i = 0; i< N; i++){
        if(i != array[i])
            return array[i];
    }
   
}

void swap(int i, int j, int* array){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}