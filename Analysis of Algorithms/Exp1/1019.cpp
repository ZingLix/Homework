//HDOJ 1002
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

int main(){
    int n, carry=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        std::string str1,str2,res;
        std::cin>>str1>>str2;
        auto it1=str1.rbegin(),it2=str2.rbegin();
        for(;it1!=str1.rend()&&it2!=str2.rend();++it1,++it2){
            int num=*it1+*it2-2*'0'+carry;
            if(num>=10){
                num-=10;
                carry=1;
            }else{
                carry=0;
            }
            res.push_back(num+'0');
        }
        while(it1!=str1.rend()){ 
            res.push_back(*(it1++)+carry);
            carry=0;
        }
        while(it2!=str2.rend()) {
            res.push_back(*(it2++)+carry);
            carry=0;
        }
        std::reverse(res.begin(),res.end());
        printf("Case %d:\n",i);
        std::cout<<str1<<" + "<<str2<<" = "<<res<<std::endl;
        if(i!=n) printf("\n");
    }
}