#include<iostream>
#include<main.hpp>
#include<swoosh.hpp>
#include<test.hpp>

using std::cout;
int main()
{
    struct point X1;
    X1.x = 3;
    X1.y = 3;
    cout<<"Points initialised here x:"<<X1.x<<" and y: "<<X1.y<< std::endl;
    cout<<"Hello World\n";
    cout<<"Square of 6 is :"<<square(6)<<std::endl;
    cout<<"Cube of 6 is :"<<cube(6)<<std::endl;
    return 0;

}