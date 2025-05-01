class Solution {
public:
    bool isCheck(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        multiset<int> st(workers.begin(), workers.begin() + mid); //Best Mid Workers //Asscending
        int pillsUsed = 0;

        for(int i = mid-1; i >= 0; i--) {
            int required = tasks[i];
            auto it = prev(st.end()); //Just Prev element {Pointer Return}

            if(*it >= required) {
                st.erase(it);
            }
            else if(pillsUsed >= pills) {
                return false;
            }
            else {
                //Find The Weakest Worker which Can do this Strongest Task Using Pills
                auto weakerIt = st.lower_bound(required - strength);

                if(weakerIt == st.end()) {
                    return false;
                }

                st.erase(weakerIt);
                pillsUsed++;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        int st = 0;
        int end = min(n, m); //(task, workers)

        sort(tasks.begin(), tasks.end()); //Asscending
        sort(workers.begin(), workers.end(), greater<int>()); //Decending

        int ans  = 0;

        while(st <= end) { //log(n)
            int mid = st + (end - st)/2;

            if(isCheck(tasks, workers, pills, strength, mid)) {
                ans = mid;
                st = mid+1;
            }
            else {
                end = mid-1;
            }
        }

        return ans;
    }
};