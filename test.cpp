#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    ifstream file ("stars.ppm");
    if (file.fail())
        cout << "Can't open file!" << endl;
    else
        cout << "File open!" << endl;
        
    string type = "", width="", height="", RGB="";
    file >> type;
    file >> width;
    file >> height;
    file >> RGB;
    cout << type << '\t' << width << '\t' << height << '\t' << RGB << endl;
    
    uint8_t red, green, blue;
    int nearwhite = 0, px =0, t = stoi(width)*stoi(height);
    while (!file.eof()){
        file >> red;
        file >> green;
        file >> blue;
        int r =(int)(red), g = (int)(green), b=(int)(blue);
        //cout << r << '\t' << g << '\t' << b << endl;
        if (r > 50 && g > 50 && b > 50)
            nearwhite++;
        px++;
    }
    cout << nearwhite << '\t' << px << endl;
    file.close();
}