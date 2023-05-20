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

struct sparse * add(struct sparse *s1,struct sparse *s2 ){
    
    
        struct sparse *sum;
        sum=new struct sparse;
        sum->m=s1->m;
        sum->n=s1->n;
        sum->ele= new struct elements[s1->num+s2->num];

        int i,j,k;
        i=j=k=0;

        while(i<s1->num && j<s2->num){
            if(s1->ele[i].i< s2->ele[j].i){
                sum->ele[k]=s1->ele[i];
                i++;
                k++;
            }
            else if(s1->ele[i].i> s2->ele[j].i){
                sum->ele[k]=s2->ele[j];
                j++;
                k++;
            }
            else{
                if(s1->ele[i].j< s2->ele[j].j){
                    sum->ele[k]=s1->ele[i];
                    i++;
                    k++;
                }
                else if(s1->ele[i].j> s2->ele[j].j){
                    sum->ele[k]=s2->ele[j];
                    j++;
                    k++;
                }
                else{
                    sum->ele[k]=s1->ele[i];
                    sum->ele[k].x=s1->ele[i].x+s2->ele[j].x;
                    i++;
                    j++;
                    k++;

                }
            }
           
            


        }

        for(;i<s1->num;i++){
            sum->ele[k]=s1->ele[i];
            k++;
        }
        for(;j<s2->num;j++){
            sum->ele[k]=s2->ele[j];
            k++;
        }

        sum->num=k;

        




    
    return sum;

}

int main(){
    struct sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    if(s1.m!=s2.m && s1.n!=s2.n){
        cout<<"Addition not possible"<<endl;
    }
    else{
        s3=add(&s1,&s2);
        display(*s3);
    }
    
    


}