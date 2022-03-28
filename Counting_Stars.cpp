#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> vx;
vector<int> vy;
int px_count = 0;

int count_stars(){
    int Stars = 0, stars = 0, i = 0;
    bool down = false;
    while (vx.size() > 0)
    {
        int x = vx[i], x1 = vx[i + 1], y = vy[i], y1 = vy[i + 1];
        //find if there is a white pic on the +1 y axis
        for (int c = 1; c < vx.size(); c++){
            if (vx[c] == x && vy[c] == (vy[0] + 1))
                down = true;
            else if (vx[c] == x - 1 && vy[c] == (vy[0] + 1)) // 1 pixel left
                down = true;
            else if (vx[c] == x + 1 && vy[c] == (vy[0] + 1)) // 1 pixel right
                down = true;
        }
        // erase if there is a other white pixel to te right below -1p below or +1p below
        if ((x == x1 - 1 && y == y1) || down == true){
            vx.erase(vx.begin());
            vy.erase(vy.begin());
        // if there is only 1 pixel left then count it as a star. and erase the pixel.
        }else{
            vx.erase(vx.begin());
            vy.erase(vy.begin());
            Stars++;
        }
        down = false;
    }
    return Stars; // return the amount of stars
}

int count_pix(){
    ifstream image;

    image.open("hubble.ppm", ifstream::binary);

    // get headers
    string type = "", width="", height="", RGB="";
    image >> type;
    image >> width;
    image >> height;
    image >> RGB;
    cout << type << '\t' << width << '\t' << height << '\t' << RGB << endl;

    uint8_t red, green, blue;
    int x=0, y=0, px_white=0, w = stoi(width), h = stoi(height);
    px_count=0;
    while (!image.eof()) // goes by pix till no left.
    {
        image >> red;
        image >> green;
        image >> blue;

        int r = (int)(red), g = (int)(green), b = (int)(blue);

        if (r > 200 && g > 200 && b > 200){ // filter vall
            vx.push_back(x);
            vy.push_back(y);
            px_white++;
        }
        px_count++;
        if (x < w+1)
            x++;
        else 
            y++;
    }
    image.close();
    return px_white;
}

int main(){
    int px_white = count_pix();
    int stars = count_stars();
    cout << "Px that are in pic: " << px_count << endl;
    cout << "Px that are white: " << px_white << endl;
    cout << "There are " << stars << " stars in the pic!" << endl;
    return 0;        
}