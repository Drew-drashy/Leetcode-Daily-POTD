// class NumberContainers {
// public:
//     unordered_map<int,int> mp;
//     // Maps number -> min-heap of indices
//     unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mpp;
//     NumberContainers() {
        
//     }
    
//     void change(int index, int number){
//         mp[index]=number;
//         mpp[number].push(index);

//     }
    
//     int find(int number) {
//         if(mpp[number].empty()) return -1;
//         return mpp[number].pop();
//     }
// };

// // ind-number
// number-[ind,ind,ind]


class NumberContainers {
public:
    // Maps index -> number
    unordered_map<int,int> mp;
    // Maps number -> min-heap of indices
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mpp;

    NumberContainers() {
        // Constructor
    }
    
    void change(int index, int number) {
        // Update the mapping index->number
        mp[index] = number;
        // Push this index into the min-heap for 'number'
        mpp[number].push(index);
    }
    
    int find(int number) {
        // If we have no record for this 'number', return -1
        if (mpp.find(number) == mpp.end()) return -1;

        // Pop from the heap any indices that are no longer valid
        // (because their mapping has changed to a different number).
        while (!mpp[number].empty()) {
            int topIndex = mpp[number].top();
            // Check if the topIndex in mp really maps to 'number'
            if (mp[topIndex] == number) {
                return topIndex;  // Found valid index with smallest value
            }
            mpp[number].pop();   // Otherwise, discard and keep checking
        }

        //     int ko= mpp[number].top();
        //     // mpp[number].pop();
        // return ko;  // No valid indices left for 'number'
        return -1;
    }
};
 
//  nc f c c c c f c
//  [] [10]  2->10 1->10 3->10 5->10 10 1->20 10
//      n      

//     10->2,1,3,5
//     1 
//     20-1
//     10 ->2.

