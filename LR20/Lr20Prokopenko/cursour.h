#pragma once

class Cursour
{
private:
    int height;
    int width; 
    int first;  // cursour x 
    int second; // cursour y
public:
    Cursour();
    Cursour(int first, int second);
    Cursour(int first, int second, int width, int height);
    ~Cursour();
    void changeX(int x);
    void changeY(int y);
    int getX();
    int getY();
    void pos(); 
    bool checkIfCursourInScreen(int first, int second);
};

