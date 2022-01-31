#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> vx;
vector<int> vy;

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
    ifstream nimage;
    nimage.open("newapollo.ppm");

    string type = "", w="", h="", RGB="";
    nimage >> type;
    nimage >> w;
    nimage >> h;
    nimage >> RGB;
    int width = stoi(w), height = stoi(h);
    int px = width * height;

    cout << "Type of PPM: " << type << endl;
    cout << "Amount of Color: "<< RGB << endl;
    cout << "Amount of px: " << px << endl;
    
    int x = 0, y = 0, xval = 0;

    string red ="", green="", blue="";
    int r=0, g=0, b=0, px_count = 0;
    while (!nimage.eof())
    {
        nimage >> red;
        nimage >> green;
        nimage >> blue;

        r = stoi(red);
        g = stoi(green);
        b = stoi(blue);

        if (r == 255 && g == 255 && b == 255)
        {
            vx.push_back(x);
            vy.push_back(y);
            px_count++;
        }

        
        if (x == width){
            y++;
            xval = x;
            x = 0;
        } 
        x++;
    }
    cout << "X count: " << xval << endl;
    cout << "Y count: " << y << endl;
    return px_count;
}
void black_white(){
    ifstream image;
    ofstream nimage;

    image.open("apollo.ppm");
    nimage.open("newapollo.ppm");

    // get headers
    string type = "", width="", height="", RGB="";
    image >> type;
    image >> width;
    image >> height;
    image >> RGB;

    // Make header for new pic
    nimage << type << endl;
    nimage << width << " " << height << endl;
    nimage << RGB << endl;

    string red ="", green="", blue="";
    int r=0, g=0, b=0;
    while (!image.eof()) // goes by pix till no left.
    {
        image >> red;
        image >> green;
        image >> blue;

        r = stoi(red);
        g = stoi(green);
        b = stoi(blue);

        if (r > 200 && g > 200 && b > 200){ // filter vall
            r = 255, g = 255, b = 255;
        }else{
            r = 0, g = 0, b = 0;
        }

        nimage << r << " " << g << " " << b << endl;
    }
    image.close();
    nimage.close();
}
int main(){
    int px_count = 0;
    black_white();
    px_count = count_pix();
    int stars = count_stars();
    cout << "Px that are white: " << px_count << endl;
    cout << "There are " << stars << " stars in the pic!" << endl;
    return 0;        
}