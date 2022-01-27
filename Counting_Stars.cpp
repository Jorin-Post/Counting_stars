#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int count_pix(){
    ifstream nimage;
    nimage.open("newpollo.ppm");
    //skip headers
    for (int i = 0; i < 4; i++)
    {
        string header = "";
        nimage >> header;
    }   

    string red ="", green="", blue="";
    int r=0, g=0, b=0, px_count;
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
            px_count++;
        }
        
    }
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
    cout << px_count << endl;
    return 0;        
}