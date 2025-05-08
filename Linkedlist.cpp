#include <iostream>
#include <string.h>
using namespace std;

class node 
{
public:
    int nomhs;
    node*next;
};

class list
{
    node *START;

public:
    list()
    {
        START = NULL;
    }
};
{
Public :
    list()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        cout <<"\nMasukkan nomor mahasiswa:";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru->nomhs = nim;

        if (START == NULL || nim <= START -> nomhs)
        {
            
        }
    }
}