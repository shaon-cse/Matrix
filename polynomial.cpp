#include<bits/stdc++.h>
using namespace std;

struct term{
    int coef;
    int expon;
};

struct poly{
    int n;
    struct term *t;
};

void display(struct poly p){
    for(int i=0;i<p.n;i++){
        cout<<p.t[i].coef<<" X"<<p.t[i].expon;
        if(i<p.n-1){
            cout<<" + ";
        }
    }
    cout<<endl;

}

void create(struct poly *p){
    cin>>p->n;
    p->t= new struct term[sizeof(struct term)];
    for(int i=0;i<p->n;i++){
        cout<<"coefficient: ";
        cin>>p->t[i].coef;
        cout<<"Exponnent: ";
        cin>>p->t[i].expon;

    }

}

struct poly * add(struct poly *p1, struct poly *p2){
    struct poly *p3;
    p3= new struct poly[sizeof(struct poly)];
    p3->n=p1->n+p2->n;
    int i,j,k;
    i=j=k=0;
    while(i<p1->n && j<p2->n){
        if(p1->t[i].expon>p2->t[j].expon){
            p3->t[k]=p1->t[i];
            i++;
            k++;
        }
        else if(p1->t[i].expon<p2->t[j].expon){
            p3->t[k]=p2->t[j];
            j++;
            k++;
        }
        else{
            if(p1->t[i].expon==p2->t[j].expon){
                p3->t[k].coef= p1->t[i].coef+p2->t[j].coef;
                p3->t[k].expon=p1->t[i].expon;
                i++;
                j++;
                k++;
            }
        }
    }
    
    for(;i<p1->n;i++){
        p3->t[k]=p1->t[i];
            k++; 
    }
    for(;j<p2->n;j++){
        p3->t[k]=p2->t[j];
            k++; 
    }
    p3->n=k;
   

    return p3;
};

int main(){
    struct poly p1;
    struct poly p2;
    create(&p1);
    create(&p2);
    display(p1);
    cout<<endl;
    display(p2);

    struct poly *p3;
    p3=add(&p1, &p2);
    display(*p3);
    cout<<endl;
    

}