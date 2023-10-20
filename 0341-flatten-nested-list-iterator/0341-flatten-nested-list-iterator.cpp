/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>v;
    int index;
    vector<int> help(vector<NestedInteger>& nL){
        vector<int>ans;
        if(nL.size()==0){
            return ans;
        }

        for(auto x:nL){
            if(x.isInteger()){
                ans.push_back(x.getInteger());
            }
            else{
                auto x1 = help(x.getList());
                ans.insert(ans.end(), x1.begin(), x1.end());
            }
        }
        return ans;
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        v = this->help(nestedList);
        index = 0;
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index<v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */