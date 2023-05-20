#include<bits/stdc++.h>
using namespace std;

struct matrix{
    int A[5];
    int n;
};

void Set(struct matrix *m,int i,int j,int x){
    if(i==j){
        m->A[i-1]=x;
    }
}

void get(struct matrix m,int i,int j){
    if(i==j){
        cout<<m.A[i-1]<<endl;
    }
    else{
        cout<<"0"<<endl;
    }

}

void display(struct matrix m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i==j){
                cout<<m.A[i]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    struct matrix m;
    m.n=4;
    Set(&m,1,1,5);
    Set(&m,2,2,8);
    Set(&m,3,3,9);
    Set(&m,4,4,12);
    get(m,2,2);
    display(m);


}