class SnapshotArray {
private:
    int id;
    vector<vector<pair<int, int> > > vec;

public:
    SnapshotArray(int length) {
        id = 0;
        vec.assign(length, {});
        for (int i=0; i<length; i++) {
            vec[i].push_back(make_pair(-1, 0));
        }
    }
    
    void set(int index, int val) {
        vec[index].push_back(make_pair(id, val));
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        int ind = upper_bound(vec[index].begin(), vec[index].end(), make_pair(snap_id, 0x3f3f3f3f)) - vec[index].begin();
        return vec[index][ind - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */