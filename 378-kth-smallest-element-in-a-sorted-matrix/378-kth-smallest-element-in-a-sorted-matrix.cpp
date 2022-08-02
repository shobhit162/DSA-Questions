class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //   int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        // priority_queue<int> maxHeap;
        // for (int r = 0; r < m; ++r) {
        //     for (int c = 0; c < n; ++c) {
        //         maxHeap.push(matrix[r][c]);
        //         if (maxHeap.size() > k) maxHeap.pop();
        //     }
        // }
        // return maxHeap.top();
        	int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri)
		{
			mid = le + (ri-le)/2;
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
    }
};