class RandomizedSet {
public:
    vector<int>vt;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        vt.push_back(val);
        mp[val]=vt.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        mp[vt.back()]=mp[val];
        swap(vt.back(),vt[mp[val]]);
        vt.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vt[rand()%vt.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */