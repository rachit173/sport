#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d",a)
#define sc1(a) scanf("%lld",&a)
#define pf1(a) printf("%lld",a)
#define sc2(a) scanf("%d %d",&a.first,&a.second)
#define br printf("\n")
#define sp printf(" ")
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,st,n) for(int i=st;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define mod 1000000007
#define mod1 1000000009
#define oo 1000000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
    typedef struct Point { 
        ll x;
        ll y;
        int ind;
    } Point;
    Point haha;
    int sz;
    int orientation(const Point &a,const Point &b,const Point &c){
        ll u = (ll)(b.x-a.x)*(ll)(c.y-a.y)-(ll)(b.y-a.y)*(ll)(c.x-a.x);
        if(u==0) return 0;
        return u<0?1:2;
        //1 is cw
        //2 is ccw 
    }   
    ll distsq(Point a,Point b){
       ll dx = (a.x-b.x);
       ll dy = (a.y-b.y);
       return dx*dx + dy*dy; 
    }
    bool cmp(const Point &a,const Point &b){
        if(a.x==b.x&&a.y==b.y){
            return !(a.ind<b.ind);
        }
        int u = orientation(haha,a,b);
        if(u==0){
            return distsq(haha,a)<distsq(haha,b);
        }
        return u==1?false:true;
    }
    stack<Point> convexHull(vector<Point>& points){
        stack<Point> st;
        haha = points[0];
        int k=0;
        f1(i,1,sz){
            if(points[i].y<haha.y){
                k=i;
                haha = points[i];
            }
            else if(points[i].y==haha.y&&points[i].x<haha.x){
                k=i;
                haha = points[i];
            }
            else if(points[i].x==haha.x&&points[i].y==haha.y){
                if(points[i].ind<haha.ind)
                {
                    k=i;
                    haha = points[i];
                }
            }
        }
        {
            points[k] = points[0];
            points[0] = haha;
        }
        // cout<<haha.ff<<" "<<haha.ss<<endl;
        sort(points.begin(),points.end(),cmp);
        // f(i,points.size()) cout<<points[i].x<<" "<<points[i].y<<endl;
        st.push(points[0]);
        st.push(points[1]);
        // st.push(points[2]);
        int i = 2;
        while(i<sz){
            Point tmp = points[i];
            Point t1 = st.top();
            st.pop();
            Point t2 = st.top();
            while(st.size()>=1&&orientation(t2,t1,tmp)!=2){
                // cout<<tmp.x<<" "<<tmp.y<<",";
                // cout<<t1.x<<" "<<t1.y<<",";
                // cout<<t2.x<<" "<<t2.y<<endl;
                t1 = st.top();
                st.pop();
                t2 = st.empty()?t1:st.top();
            }
            st.push(t1);
            st.push(tmp);
            i++;
        }
        return st;
    }
bool pred(Point &a,Point &b){
    return (a.x==b.x&&a.y==b.y);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<Point> points(n);
        f(i,n){
            sc1(points[i].x);
            sc1(points[i].y);
            points[i].ind = i+1;
        }
        auto last = unique(points.begin(),points.end(),pred);
        points.erase(last,points.end());
        sz = points.size();
        if(sz==1){
            printf("0.00\n1\n");

            continue;
        }
        stack<Point> ret;
            ret = convexHull(points);
            vector<Point> ans;
            vi fafa;
        while(!ret.empty()){
            // cout<<ret.top().x<<" "<<ret.top().y<<endl;
            ans.pb(ret.top());
            fafa.pb(ret.top().ind);
            ret.pop();
        }
        int lt = ans.size();
        double cir = 0;
        cir+=sqrt(distsq(ans[0],ans[lt-1]));
        f1(i,0,lt-1) cir+=sqrt(distsq(ans[i],ans[i+1]));
        printf("%.2lf",cir);br;
        for(int i=fafa.size()-1;i>=0;i--){
            pf(fafa[i]);sp;
        }br;
        
        // delete[] points;
    }
return 0;
}
