#include<iostream>
#include<main.hpp>
#include<swoosh.hpp>
#include<test.hpp>
#include<fstream>



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

    std::fstream f("res.txt");
    cout<<f.rdbuf()<<std::endl;
    #ifdef FOO
    cout<<"FOO is defined in the code"<<std::endl;
    cout<<"Value of BAR: "<<BAR<<std::endl;
    #endif

    return 0;

}