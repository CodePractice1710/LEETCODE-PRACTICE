int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}
int minimumCost(int* nums, int numsSize) {
    int k=nums[0];
    int smallmin = nums[1];
    int min1 = nums[2];
    if (smallmin > min1) {
        int temp = smallmin;
        smallmin = min1;
        min1 = temp;
    }
    for (int i = 3; i < numsSize; i++) {
        if (nums[i] < smallmin) {
            min1 = smallmin;
            smallmin = nums[i];
        } else if (nums[i] < min1) {
            min1 = nums[i];
        }
    }
return k+smallmin+min1;
}