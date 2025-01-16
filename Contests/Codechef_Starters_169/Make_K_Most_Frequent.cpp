#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
public:
    void method(vi &v, int n, int k){
        unordered_map<int, int>initial;
        int maxi = 0;
        for(auto it: v){
            initial[it]++;
            maxi = max(maxi, initial[it]);
        }
        if(initial[k] == maxi){
            cout<<0<<endl;
            return;
        }
        unordered_map<int, int>prefix;
        maxi = 0;
        bool f = 0;
        rep(i,0,n){
            prefix[v[i]]++;
            maxi = max(maxi, prefix[v[i]]);
            if(prefix[k] == maxi){
                f = 1;
                break;
            }
        }
        if(f){
            cout<<1<<endl;
            return;
        }
        unordered_map<int, int>suffix;
        maxi = 0;
        f = 0;
        for(int i=n-1; i>=0; i--){
            suffix[v[i]]++;
            maxi = max(maxi, suffix[v[i]]);
            if(suffix[k] == maxi){
                f = 1;
                break;
            }
        }
        if(f){
            cout<<1<<endl;
            return;
        }
        cout<<2<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, k;
        cin>>n>>k;
        vi v(n);
        inpvec(v, n);
        Kaarti *ob = new Kaarti;
        ob->method(v, n, k);
    }
    return 0;
}