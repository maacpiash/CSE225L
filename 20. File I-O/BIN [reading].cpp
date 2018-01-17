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
    STUDENT x;
    char filename[] = "ABC.txt";
    ifstream infile(filename, ios::in|ios::binary);
    if(!infile)
        cout << "ERROR!";

    int counter = 0;
    infile.read((char *) &x, sizeof(STUDENT));

    while(!infile.eof()) {
        cout << "ID:\t" << x.ID << endl;
        cout << "Name:\t" << x.name << endl;
        cout << "Dept.:\t" << x.dept << endl;
        cout << "------------------------------" << endl;
        counter++;
        infile.read((char *) &x, sizeof(STUDENT));
    }
    infile.close();
    cout << counter << " records available!" << endl;

    return 0;
}
