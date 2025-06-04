/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(x==par[x]){
        return x;
    }
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int pu=find(par,x);
    int pv=find(par,z);
    
    if(pu==pv) return;
    else{
        par[pu]=pv;
        return;
    }
}