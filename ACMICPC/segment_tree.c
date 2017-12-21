#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int seg[1000000];
int a[1000000];
int n;
int build(int start,int end,int index){
    // printf("%d %d",end,start); 
    if(end<start) return 0;
    if(end==start){
        seg[index] = a[start];
        return seg[index];
    }
    int mid= start + (end-start+1)/2;

    seg[index] = build(start,mid-1,2*index+1)+build(mid,end,2*index+2);
    return seg[index];
}
void update(int index,int val,int start,int end,int base){
    if(end<=start){
        if(start==index)
        seg[base]+=val;
        return ;
    }
    seg[base]+=val;
    int mid = start +(end-start+1)/2;
    if(index<mid) update(index,val,start,mid-1,2*base+1);
    else update(index,val,mid,end,2*base+2);
}
int search(int l,int r,int start,int end,int base){
    if(l==start&&r==end) return seg[base];
    int mid = start + (end-start+1)/2;
    if(r<mid) return search(l,r,start,mid-1,2*base+1);
    else if(l>=mid) return search(l,r,mid,end,2*base+2);
    else {
        return search(l,mid-1,start,mid-1,2*base+1) + search(mid,r,mid,end,2*base+2);
    }
}
int main(){
    FILE* f = fopen("data.temp","w");
    clock_t start,end;
    // for(int i=0;i<3*n;i++){
    //     printf("%d ",seg[i]);
    // }
    for(int i=1024;i<=70000;i=i*2){
        n=i;
        for(int j=0;j<n;j++){
            a[j] = rand()%100;
        }
        build(0,n-1,0);
        int q=10000;
        start = clock();
        while(q--){
            int c=rand()%2;
            // printf("%d : ",c);
            if(c==0){
                int t=rand()%n;
                // printf("%d ",t);
                // printf("%d\n",search(0,t,0,n-1,0));
            }
            else{
                int k=rand()%n;
                int p = rand()%100;
                // printf("%d %d\n",k,p);
                update(k,p,0,n-1,0);
            }
        }
        end = clock();
        fprintf(f,"%lf %lf\n",(double)i,(double)(end-start)/10000.0);
    }
    fclose(f);
}