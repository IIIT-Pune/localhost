// Segment Tree Basic 

// Segment Tree - A Segment Tree is a data structure that stores information about array intervals as a tree.
// This allows answering range queries over an array efficiently, such as finding sum of elements in the range 
// or find min/max element in the range.

// Time Complexity -: construction - O(N)
//                    sum query - O(log(N))
//                    Update query - O(log(N))
//                    Min/Max query - O(log(N))

class SGTree{
    vector<ll> seg;
public :
    SGTree(ll n){
        seg.resize(4*n+1);
    }
    
    // Constructing Segment tree which stores information

    void build(ll ind,ll low,ll high,ll a[]){
    if(low==high){
        seg[ind]=a[low];
        return;
    }

    ll mid=(low+high)/2;

    // Recursively Constructing the Tree
    build(2*ind+1,low,mid,a);
    build(2*ind+2,mid+1,high,a);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}

    // Query - Min/Max/Sum
    ll query(ll ind,ll low,ll high,ll l,ll r){
        
        if(low>=l and high<=r){
            return seg[ind];
        }

        if(high<l or low>r){
            return INT_MIN;
        }

        ll mid=(low+high)/2;

        ll left=query(2*ind+1,low,mid,l,r);
        ll right=query(2*ind+2,mid+1,high,l,r);
        return max(left,right);
    
    }

    // Update Query to update info in the segment tree

    void Update(ll ind ,ll low,ll high,ll i,ll val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        ll mid=(low+high)/2;

        if(i<=mid){
            Update(2*ind+1,low,mid,i,val);
        }
        else{
            Update(2*ind+2,mid+1,high,i,val);
        }
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
           
    }

};