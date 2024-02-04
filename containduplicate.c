#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int nums[], int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true; 
            }
        }
    }
    return false;  
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    bool result = containsDuplicate(nums, numsSize);

    if (result) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }

    return 0;
}
