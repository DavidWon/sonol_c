#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
    int s,e;
    
    Time() { }
    Time(int _s,int _e) : s(_s),e(_e) { }
};

bool cmp(const Time &t1, const Time &t2){
    if(t1.e == t2.e){
        return t1.s < t2.s;
    }else{
        return t1.e < t2.e;
    }
}

int n,s,e,ans,eTime;
vector<Time> v;

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s >> e;
        v.push_back(Time(s,e));
    }
    
    sort(v.begin(),v.end(),cmp);
    
    ans = 0;
    eTime = -1;
    for(int i=0; i<v.size(); i++){
        if(v[i].s >= eTime){
            ans++;
            eTime = v[i].e;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
