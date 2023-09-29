bool isMonotonic(int* nums, int numsSize) {
    bool inc = true;
    bool dec = true;

    for (int i = 0; i < numsSize - 1; i++) 
    {
        if (nums[i] > nums[i + 1]) {
            inc = false;
        }
        if (nums[i] < nums[i + 1]) {
            dec = false;
        }

        if (!inc && !dec) 
        {
            return false;
        }
    }

    return inc || dec;
}