/*https://www.interviewbit.com/problems/matrix-median/*/
-----------------------------------------------------------------------------------------
/*
    M1: Brute Force
    O(n*m*log(n*m)) time and O(n*m) space
    -> insert all elements in exatra auxilary array then sort it and find the median
*/
-----------------------------------------------------------------------------------------
/*
    M2: Binary Search
    O(nlog(m)) time and O(1) space
*/
    int countSmallerThanMid(vector<int> &row, int mid) {
        int l = 0, h = row.size() - 1; 
        while(l <= h) {
            int md = (l + h) >> 1; 
            if(row[md] <= mid) {
                l = md + 1;
            }
            else {
                h = md - 1;
            }
        }
        return l; 
    }
    int Solution::findMedian(vector<vector<int> > &A) {
        int low = INT_MIN;
        int high = INT_MAX; 
        int n = A.size();
        int m = A[0].size(); 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            int cnt = 0;
            for(int i = 0;i<n;i++) {
                cnt += countSmallerThanMid(A[i], mid); 
            }
            
            if(cnt <= (n * m) / 2) low = mid + 1; 
            else high = mid - 1; 
        }
        return low; 
    }
-----------------------------------------------------------------------------------------