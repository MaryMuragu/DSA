#include <stdio.h>

int summation(int nums[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    return sum;
}

int maximum(int nums[], int n) {
    int max = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int sum = summation(nums, n);
    printf("Sum of the integers: %d\n", sum);

    int max = maximum(nums, n);
    printf("Maximum integer: %d\n", max);

    return 0;
}
