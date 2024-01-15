#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<int> reverseAndCount(std::vector<int>& A, int K) {
    int N = A.size();
    std::vector<int> result = A;

    for (int L = 1; L <= N; ++L) {
        for (int R = L; R <= N; ++R) {
            int num_permutations = (R - L + 1) * (N - R + 1);

            if (K <= num_permutations) {
                // Reverse the subarray A[L:R]
                std::reverse(result.begin() + L - 1, result.begin() + R);
                return result;
            }

            K -= num_permutations;
        }
    }

    return result;
}
int main() {
    int n,k;cin>>n>>k;
    vector<int> A(n);
    int K = k;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int> result = reverseAndCount(A, K);

    for (int num : result) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}
