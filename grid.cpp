#include "grid.h"
#include <iostream>

Grid::Grid()
{
    for (int i=0; i<9; i++) {
        for (int j=0; j<9 ; j++) {
            a[i][j] = 0;
        }
    }
}

void Grid::setPoint(int n, int row, int col)
{
    a[row][col] = n;
}

int Grid::getPoint(int row, int col)
{
    return a[row][col];
}

bool Grid::checkRow(int n, int col)
{
    for (int i=0; i<9; i++) {
        if (a[i][col] == n)
            return false;
    }
    return true;
}

bool Grid::checkCol(int n, int row)
{
    for (int i=0; i<9; i++) {
        if (a[row][i] == n)
            return false;
    }
    return true;
}

bool Grid::checkBlock(int n, int row, int col)
{
    int c = (row) % 3;
    int b = (col) % 3;
    c = row - c;
    b = col - b;

    for (int i=c; i<c+3; i++) {
        for (int j=b; j<b+3; j++) {
            if (!(i == row && j ==col)) {
                if (a[i][j] == n)
                    return false;
            }
        }
    }

    return true;
}

bool Grid::checkAll(int n, int row, int col)
{
    if (checkRow(n,col) && checkCol(n,row) && checkBlock(n,row,col))
        return true;
    else return false;
}

void Grid::printPoint(int row, int col)
{
    std::cout << a[row][col] << std::endl;
}

void Grid::printAll()
{
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            std::cout << a[i][j] << " ; ";
        }
        std::cout << std::endl;
    }
}
