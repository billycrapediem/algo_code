#include<iostream>
#include<vector>

int main(){
    std::vector<int> x = {1,2,3};
    for(int i = 0; i < x.size(); i ++){
        std::cout<<x[i]<<std::endl;
    }
}