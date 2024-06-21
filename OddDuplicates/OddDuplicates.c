#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int* array, int size) {
    int duplicates[20] = {0};
    int numOfDuplicates = 0;
    
    for(int i=0;i<size;i++) { 
        printf("%d ", array[i]);
        if(array[i] % 2 != 0) { // Filter odd numbers
            for(int j = i+1; j<size; j++) {
                if(array[i] == array[j]) { // found a duplicate
                    
                    //check if already in duplicates, if not, add it ~ set-like
                    int firstOccurance = 1;
                    for(int k=0; k<numOfDuplicates;k++) {
                        if(duplicates[k] == array[i]) {
                            firstOccurance = 0;
                            break;
                        }
                    }
                    
                    if(firstOccurance) {
                        duplicates[numOfDuplicates++] = array[i];
                    }
                }
            }
        }
    }
    
    printf("\n");
    for(int i=0;i<numOfDuplicates;i++) {
        printf("%d ", duplicates[i]);
    }
}

int main(void) {
    int array[] = {0, 1, 2, 3, 4, 4, 1, 5, 5, 7, 7};
    int size = sizeof(array) / sizeof(array[0]);
    findDuplicates(array, size);
    return 0;
}