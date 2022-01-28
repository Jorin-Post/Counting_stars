#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> vx = {23, 24, 27, 30, 30, 40, 45, 46, 46};
vector<int> vy = {2 , 2  ,10, 20, 21, 30, 31, 31, 32};
vector<int> vx1;
vector<int> vy1;

int main(){
    int count = 0, stars = 0;
    for (int i = 0; i < vx.size(); i++){
        if (vx[i+1] == vx[i] +1 && vy[i+1] == vy [i]){
            vx1.push_back(vx[i]); vx1.push_back(vx[i+1]);
            vy1.push_back(vy[i]); vy1.push_back(vy[i+1]);
            // if for dubble count
            cout << "Vx: "<< vx[i] << " - "<< vx[i+1] << endl;
            cout << "Vy: "<< vy[i] << " - "<< vy[i] << endl;
            cout << "Count: "<< count << endl;
            cout << endl;
        }
        else if (vx[i+1] == vx[i] && vy[i+1] == vy [i] +1){
            vx1.push_back(vx[i]); vx1.push_back(vx[i+1]);
            vy1.push_back(vy[i]); vy1.push_back(vy[i+1]);
            // if for dubble count
            cout << "Vx: "<< vx[i] << " - " << vx[i] << endl;
            cout << "Vy: "<< vy[i] << " - " << vy[i+1] << endl;
            cout << "Count: "<< count << endl;
            cout << endl;
        }
        else{
            count++;
        }
    }
    vx.clear();
    vy.clear();
    for (int i =0; i < vx1.size(); i++){
        cout << vx1[i] << '\t' << ends;
    }
    cout << endl;
    for (int i =0; i < vy1.size(); i++){
        cout << vy1[i] << '\t' << ends;
    }
}