#include <iostream>
#include <set>

// Function to find the maximum number of integers in S
// after performing the operations optimally
int findMaxNum(std::set<int> S)
{
    int maxNum = 0;

    // Loop until we can no longer perform the operation
    while (true)
    {
        // Flag to keep track of whether we performed the operation
        bool performedOperation = false;

        // Loop through all pairs of integers in the set
        for (auto x : S)
        {
            for (auto y : S)
            {
                // If x > y and x - y is not in the set,
                // perform the operation and update the flag
                if (x > y && S.find(x - y) == S.end())
                {
                    S.insert(x - y);
                    performedOperation = true;
                    break;
                }
            }
        }

        // If we didn't perform the operation, we are done
        if (!performedOperation)
            break;

        // Update the maximum number of integers in the set
        maxNum = std::max(maxNum, (int)S.size());
    }

    return maxNum;
}

int main()
{
    // Set containing positive integers
    std::set<int> S = { 1, 2, 3, 4, 5 };

    // Print the maximum number of integers in S after performing the operations optimally
    std::cout << findMaxNum(S) << std::endl;

    return 0;
}
