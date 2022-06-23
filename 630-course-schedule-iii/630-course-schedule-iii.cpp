class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
         sort(courses.begin(), courses.end(), [](auto& p, auto& q) {return p[1] < q[1];});
        priority_queue<int> mq;
        int sum = 0;
        for (auto& c : courses) {
            mq.push(c[0]);
            sum += c[0];
            if (sum > c[1]) {
                sum -= mq.top();
                mq.pop();
            }
        }
        return mq.size();
    }
};