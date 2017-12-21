void update4(int index,int l,int r,int val,int base){
    if(r<=l){
        seg4[index] =1;
    }
    int mid = l+(r-l)/2;
    if(index<mid){
        update4(index,l,mid-1,2*base);
        if(seg4[2*base]&&seg4[2*base+1]&&a[mid-1]>=a[mid]) seg4[base]=1;
    }else{
        update4(index,mid,r,2*base+1);
        if(seg4[2*base]&&seg4[2*base+1]&&a[mid-1]>=a[mid]) seg4[base]=1;
    }
}
int search4(int start,int end,int l,int r,int base){
    if(end-start<1){
        return seg4[base];
    }
    int mid = l+(r-l)/2;
    if(end<mid){
        return search4(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search4(start,end,mid,r,2*base+1);
    }
    if(search4(start,mid-1,l,mid-1,2*base)&&search4(mid,end,mid,r,2*base+1)&&a[mid-1]>=a[mid]) return 1;
    return 0;
}