#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hash_table{
    
    int key;
    int value;
    struct hash_table* next;
    
}hash_table;

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize==1){return false;}
    hash_table* data = (hash_table*)malloc(numsSize*(sizeof(hash_table)));
    hash_table* aux = (hash_table*)malloc(sizeof(hash_table));
    hash_table* ptr;
    int i;
    //Init hash - Leaving 0's and NULL data in case a key value is not presented
    for(i=0;i<numsSize;i++){
        ptr = &data[i];
        ptr->key = 0;
        ptr->value = 0;
        ptr->next = NULL;
    }
    
    //Search & inserting
    for(i=0;i<numsSize;i++){
        
        int key_idx = nums[i]%numsSize < 0 ? (nums[i]%numsSize)+numsSize : nums[i]%numsSize; 
        ptr = &data[key_idx];
        
        //May Collide, so Else If Collides...
        if(ptr->value == nums[i] && ptr->key != 0){ 
            
            free(data); 
            free(aux);
            return true;
            
        }else if(ptr->key!=0 && ptr->value != 0){
            
            //Move towards all nested hash until find NULL value
            //And look for duplicated on the way
            while(ptr->next != NULL){
                if(ptr->value == nums[i] && ptr->key != 0){ 
                    free(data); 
                    free(aux);
                    return true;
                }
                ptr = ptr->next;
            }
            
            //Check if the last element is a duplicated
            if(ptr->value == nums[i] && ptr->key != 0){ 
                free(data); 
                free(aux);
                return true;
            }
            
            //Append hash  
            ptr->next = aux;
            ptr = ptr->next;
            ptr->next = NULL;
        }
        
        //Insert if not found
        ptr->key = i+1;
        ptr->value = nums[i];
    }
    
    free(data);
    free(aux);
    return false;

}

int main(){
	int nums[] = {2,7,8,9,22,2,7};
	printf("%s", containsDuplicate(nums,sizeof(nums)/sizeof(nums[0])) ? "true" : "false");
	return 0;
}
