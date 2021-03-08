#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i;
    fstream obj;
    obj.open("input.txt", ios::out);
    for(int i = 6; i < 1001; i++)
    {
        obj<<"1\n";
        obj<<"I am block "<< i << "\n";
    }

    obj<<"3\n1000\n";

    obj<<"5\n";
}