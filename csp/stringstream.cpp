//
// Created by 赵婉如 on 2019-09-15.
//

#include <iostream>
#include <sstream>//stringstream的头文件
using namespace std;

int main(){
    stringstream s;
    double d=3.00;
    s<<d;
    string dd=s.str();
    cout<<"dd: "<<dd<<endl;

    double f;
    stringstream ss;
    ss.str(dd);
    ss>>f;
    cout<<"f: "<<f<<endl;
}