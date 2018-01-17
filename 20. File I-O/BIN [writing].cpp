#include <iostream>
#include <fstream>
using namespace std;

struct STUDENT
{
    int ID;
    char name[256];
    char dept[256];
};

int main()
{
    int count = 3;
    STUDENT x[count];
    for(int i = 0; i < count; i++) {
        x[i].ID = (i + 1) * 100;
        cout << "Name: ";
        cin.getline(x[i].name, 256);
        cout << "Department: ";
        cin.getline(x[i].dept, 256);
    }
    char filename[256] = "ABC.txt";
    ofstream outfile(filename, ios::out | ios::binary);
    if(!outfile)
        cout << "ERROR!";
    for(int i = 0; i < count; i++) {
        outfile.write((char*)(&x[i]), sizeof(STUDENT));
    }
    outfile.close();

    return 0;
}
