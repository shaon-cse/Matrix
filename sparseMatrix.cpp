#include<bits/stdc++.h>
using namespace std;

struct elements{
    int i;
    int j;
    int x;
};

struct sparse{
    int m;
    int n;
    int num;
    struct elements *ele;
};

void create(struct sparse *s){
    cout<<"Enter number of row: ";
    cin>>s->m;
    cout<<"Enter number of column: ";
    cin>>s->n;
    cout<<"Enter number of non zero elements: ";
    cin>>s->num;

    s->ele=new struct elements[s->num];

    for(int i=0;i<s->num;i++){
        cout<<"Row number: ";
        cin>>s->ele[i].i;
        cout<<"column number: ";
        cin>>s->ele[i].j;
        cout<<"Non zero elements: ";
        cin>>s->ele[i].x;


    }


}

void display(struct sparse s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                cout<<s.ele[k].x<<" ";
                k++;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main(){
    struct sparse s;
    create(&s);
    display(s);


}