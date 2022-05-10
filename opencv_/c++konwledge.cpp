// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Transform{
// public:
//     int operator()(int v){
//         return v+10;
//     }
// };

// class Myprint{
// public:
//     void operator()(int val){
//         cout<<val<<" ";
//     }
// };

// //常见遍历算法--transform
// void test01(){
//     vector<int>v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }
//     vector<int>vTarget;//目标容器
//     vTarget.resize(v.size());//目标容器需要提前开辟空间
//     transform(v.begin(),v.end(),vTarget.begin(),Transform());
//     for_each(vTarget.begin(),vTarget.end(),Myprint());
// }

// int main(){
//     test01();
//     system("pause");
//     return 0;
// }