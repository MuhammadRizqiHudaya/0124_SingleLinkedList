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
            if ((START != NULL)&& (nim == START->nomhs))
            {
                cout << "\nduplikasi nomhs tidak diijinkan\n";
                return;
            }
        }
        nodebaru -> next = START;
        START = nodebaru;
        return; 
    };

    node *previous = START;
    node *currrent = START;

    while ((current ! = NULL)&&(nim >= current ->nomhs))
    {
        if (nim == current -> nomhs)
        {
            cout << "\nduplikasi nomhs tidak diijinkan\n;"
            return;
        }
        previous = current;
        current = current -> next
    }

    nodebaru -> next = current ;
    previous -> next = nodebaru;
}

bool lisitempty()