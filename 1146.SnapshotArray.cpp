#include "defines.h"

#define SET 0
#define SNAP 1
class SnapshotArray {
public:
    int len;
    int snap_index = 0;
    struct Trans {
        int type;
        int index;
        int value;
        Trans(int a, int b, int c): type(a), index(b), value(c) {}
    };
    vector<Trans> trans;
    SnapshotArray(int length) {
        len = length;
    }
    
    void set(int index, int val) {
        trans.emplace_back(SET, index, val);
    }
    
    int snap() {
        trans.emplace_back(SNAP,snap_index, snap_index );
        snap_index ++;
        return snap_index - 1;
    }
    
    int get(int index, int snap_id) {
        int value = 0;
        for (auto &x: trans) {
            if (x.type == SNAP && x.value == snap_id)
                return value;
            if (x.type == SET && x.index == index)
                value = x.value;
        }
        return -1;
    }
};