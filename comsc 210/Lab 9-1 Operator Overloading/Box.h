#ifndef BOX_H
#define BOX_H

class Box{
private:
    double length;
    double width;
    double height;
    double volume;
public:
    // Constructor definition with default values
    Box(double l = 2.0, double w = 2.0, double h = 2.0)
    	{ length = l; width = w; height = h; volume = getVolume();}

    double getVolume() {return length * width * height;}
    double getLength() {return length;}
    double getWidth() {return width;}
    double getHeight() {return height;}

    //operator overloading
    bool operator == (const Box &);
    bool operator > (const Box &);
    bool operator < (const Box &);
    bool operator >= (const Box &);
    bool operator <= (const Box &);
};

#endif //BOX_H
