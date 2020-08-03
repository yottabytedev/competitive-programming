class MyHashSet {
    int val[10001];
    int index;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        index=-1;
    }
    
    void add(int key) {
        val[++index]=key;
        // for(int i=0;i<=index;i++)
        //     cout<<val[i]<<" ";
        // cout<<endl;
    }
    
    void remove(int key) {
        if(index==-1) return;
        int tempIndex = index;
        while(tempIndex>-1){
            if(val[tempIndex]==key) {
                val[tempIndex] = -1;
            }
            tempIndex--;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(index==-1) return false;
        int tempIndex = index;
        while(tempIndex>-1){
            if(val[tempIndex--]==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */