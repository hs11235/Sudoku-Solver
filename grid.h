#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
#include <iostream>

const int DIM_SIZE = 9;

class Grid
{
private:
    int a[DIM_SIZE][DIM_SIZE];
public:
    Grid();
    void setPoint(int n, int row, int col);
    int getPoint(int row, int col);
    bool checkRow(int n, int col);
    bool checkCol(int n, int row);
    bool checkBlock(int n, int row, int col);
    bool checkAll(int n, int row, int col);
    void printPoint(int row, int col);
    void printAll();
};

#endif // GRID_H_INCLUDED
