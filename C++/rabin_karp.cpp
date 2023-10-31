#include<iostream>
using namespace std;
void rabin(string text,string pattern,int q){
    int n=text.length();
    int m=pattern.length();
    int i,j,t=0,p=0,h=1,d=256;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<m;i++){
        p=(p*d+pattern[i])%q;
        t=(t*d+text[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
            }
            if(j==m){
                cout<<"pattern found at "<<i<<endl;
            }
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0){
                t=t+q;
            }
        }
    }
}
int main(){
    string text,pattern;
    cin>>text>>pattern;
    int q=INT8_MAX;
    rabin(text,pattern,q);
    return 0;
}