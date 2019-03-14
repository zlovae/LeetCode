class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> path;
        for(int i=0; i<candidates.size(); i++) {
            func(res, path, candidates, i, candidates.size()-1, target);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        
        return res;//{path};//{candidates};
    }
    
    void func(vector<vector<int> >& res, vector<int>& path, vector<int>& candidates,int l, int r, int target) {
        if(l>r) return;
        if(candidates[l]==target) {
            path.push_back(candidates[l]);
            res.push_back(path);
            path.pop_back();
        } else if(candidates[l]<target) {
            path.push_back(candidates[l]);
            for(int i=l; i<r; i++) {
                func(res, path, candidates, i+1, r, target-candidates[l]);
            }
            
            path.pop_back();
        } else {
            return;
        }
    }
};