#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
    //Set up some sudoku grid.

    Grid A;

    A.setPoint(5,0,0);
    A.setPoint(3,0,1);
    A.setPoint(7,0,4);

    A.setPoint(6,1,0);
    A.setPoint(1,1,3);
    A.setPoint(9,1,4);
    A.setPoint(5,1,5);

    A.setPoint(9,2,1);
    A.setPoint(8,2,2);
    A.setPoint(6,2,7);

    A.setPoint(8,3,0);
    A.setPoint(6,3,4);
    A.setPoint(3,3,8);

    A.setPoint(4,4,0);
    A.setPoint(8,4,3);
    A.setPoint(3,4,5);
    A.setPoint(1,4,8);

    A.setPoint(7,5,0);
    A.setPoint(2,5,4);
    A.setPoint(6,5,8);

    A.setPoint(6,6,1);
    A.setPoint(2,6,6);
    A.setPoint(8,6,7);

    A.setPoint(4,7,3);
    A.setPoint(1,7,4);
    A.setPoint(9,7,5);
    A.setPoint(5,7,8);

    A.setPoint(8,8,4);
    A.setPoint(7,8,7);
    A.setPoint(9,8,8);

    //Set default grid for later comparison.

    int b[9][9];

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            b[i][j] = A.getPoint(i,j);
            cout << A.getPoint(i,j) << " ; ";
        }
        cout << endl;
    }

    //Solver.

    int nx=0, ny=0;
    int steps = 0;

    while (nx<9 && ny<9) {

        //case for default elements
        if (A.getPoint(ny, nx) == b[ny][nx] && A.getPoint(ny,nx) != 0) {
            // forward step
            if (nx==8) {
                nx=0;
                ny+=1;
            } else nx+=1;
        } else {
            for (int i=A.getPoint(ny,nx); i<10; i++) {
                if (A.checkAll(i,ny,nx)) {
                    A.setPoint(i,ny,nx);
                    if (nx==8) {
                        nx=0;
                        ny+=1;
                    } else nx+=1;
                    goto start;
                }
            }
            // backstep; no match available.
            // single backstep
            A.setPoint(0,ny,nx);
            if (nx==0) {
                nx=8;
                ny-=1;
            } else nx-=1;

            // backstep over any default values.

            while (A.getPoint(ny, nx)==b[ny][nx]) {
                if (nx==0) {
                    nx=8;
                    ny-=1;
                } else nx-=1;
            }
        }

        start:
            steps++;
            cout << steps << endl;
        if (steps>100000) {
            A.printAll();
            cout << "too many steps" << endl;
            return 1;
        }
    }

    //Print results to console.
    A.printAll();

    cout << "Hello world!" << endl;
    return 0;
}
