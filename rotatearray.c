#include <stdio.h>

void reverse(int nums[], int start, int end) {
    while (start < end) {
        
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        
        start++;
        end--;
    }
}

void rotate(int nums[], int numsSize, int k) {
    
    k = k % numsSize;

    reverse(nums, 0, numsSize - 1);

    reverse(nums, 0, k - 1);

    reverse(nums, k, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, numsSize, k);

    printf("Rotated Array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
