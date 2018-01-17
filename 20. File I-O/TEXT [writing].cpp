#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile ("me.txt");
    if(myfile.is_open()) {
        myfile << "Md. Abdul Ahad Chowdhury\n";
        myfile << "1410575042\n";
        cout << "Write Successful!" << endl;
        myfile.close();
    } else
        cout << "Unable to open file!";

    return 0;
}
