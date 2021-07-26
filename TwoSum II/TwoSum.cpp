/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 #include <stdlib.h>
 #include <iostream>
 
 using namespace std;
 
int* twoSum(int* numbers, int numbersSize, int target){
	
    //Array to store our result
	int* indexes = (int*)malloc(2*sizeof(int));
    numbersSize--;
    
	//Find closest number to target
	while(numbers[numbersSize]>target && numbers[numbersSize-1]>0) numbersSize--;
    
	//Look for sum in ascending order
	int remaining = 0;
	while(numbers[remaining]+numbers[numbersSize]!= target){
        numbers[remaining]+numbers[numbersSize]>target ? numbersSize-- : remaining++;
    }
	
	indexes[0] = remaining+1;
	indexes[1] = numbersSize+1;
	return indexes; //Output Index: 1 (3), Index: 2 (-3)
}

int main(){
	
	int input[] = {-3,3,9,11};
	int target = 0;
	int size = sizeof(input)/sizeof(input[0]);
	int* indexes = twoSum(input, size, target);
	cout << "Index 1:[" << indexes[0] << "] Index 2:[" << indexes[1] << "]" << endl;
	return 0;
}
