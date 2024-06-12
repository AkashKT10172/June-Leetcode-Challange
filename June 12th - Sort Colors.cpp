// I asked this question in all of the IEEE Student Branch Interviews I took :))
// Brute Force
// TC - O(2*n)

class Solution {
public:
    void sortColors(vector<int>& arr) {
    int cnt0=0, cnt1=0, cnt2=0;
    for (auto it : arr) it==0?cnt0++:it==1?cnt1++:cnt2++;  
    for(int i=0; i<cnt0; i++) arr[i]=0;
    for(int i=cnt0; i<cnt0+cnt1; i++) arr[i]=1;
    for(int i=cnt0+cnt1; i<cnt0+cnt1+cnt2; i++) arr[i]=2;
}
};

// Optimal , also known as DUTCH NATIONAL FLAG ALGORITHM
//TC - O(n), SC - O(1)
class Solution {
public:
    void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
            if(arr[mid] == 1) mid++;
        } else if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else {
            mid++;
        }
    }
}
};
