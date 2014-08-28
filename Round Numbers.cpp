#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>N
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

const int inf = 2000000000;
const int SZ = 100000 + 7;

typedef long long Long;
typedef double dd;

Long DP[33][33][33][2];
bitset<33> bin;

Long rec(int pos, int ones,int lone, int  mmin)
{
    if(pos<0)
    {
        if((lone+1)>=(ones*2)) return 1;
        return 0;
    }
    Long &ret = DP[pos][ones][lone][mmin];
    if(~ret) return ret;
    int range = mmin ? 1:(int)bin[pos];
    ret = 0LL;
    REP(i,0,range)
    {
        if(i==1)
        ret += rec(pos-1,ones+(i==1),lone==0?pos:lone,i<range||mmin);
        else ret += rec(pos-1,ones+(i==1),lone,i<range||mmin);

    }
    return ret;
}
int main(int argc, const char **argv) {
    Long A, B, rA, rB;
    sf("%lld %lld",&A, &B);
    mem(DP,-1);
    A--;
    if(A>=0)
    {
        bin = bitset<33>(A);
        rA = rec(32,0,0,0);
    }
    else rA = 0;
    mem(DP,-1);
    bin = bitset<33>(B);
    rB = rec(32,0,0,0);
    pf("%lld\n",rB-rA);
    return 0;
}
