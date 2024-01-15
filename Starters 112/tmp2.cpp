#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
//    auto lambda = [&a]() mutable { a = 10; };

// auto lambda = [a]() { a = 10; };
// auto lambda = [&a]() { a = 10; };
auto lambda = [a]() mutable { a = 10; };





    lambda();
    std::cout<<a<<endl;
}