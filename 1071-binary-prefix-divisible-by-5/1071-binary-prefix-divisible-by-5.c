/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
bool* arr=(bool*)malloc(numsSize*(sizeof(int)));
int k=0;
for(int i=0;i<numsSize;i++){
int x=k<<1;
int y=x|nums[i];
k=y%5;
    if(k==0){
        arr[i]=true;
    }    
    else{
        arr[i]=false;
    }
}
*returnSize=numsSize;
return arr;
}