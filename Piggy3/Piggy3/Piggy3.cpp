// Piggy3.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <string>
#include<string.h>


using namespace std;
int right_banana = 0;
int down_banana = 0;


//A=-1
//B=-2
//X=-3


int forest[5][5]{
         -1,3,3,-3,5,
         3,0,-3,2,1,
         1,1,-3,1,1,
         0,0,3,1,0,
         1,1,2,0,-2
};

int maxb = 0;

int MaxPath[5][5];


int getBannas(int x, int y, int count, int path[5][5]) {
    int n = 0;

    if ((x < 5) && (y < 5)) {

        if (forest[x][y] == -1) {
            path[0][0] = 1;

            //sprintf_s(path, 100, "(0, 0),");
            getBannas(x, y + 1, 0, path);

            getBannas(x + 1, y, 0, path);

        }
        else if (forest[x][y] == -3) {
            path[x][y] = 0;
            return forest[x][y];
        }
        else if (forest[x][y] == -2) {
            path[4][4] = 1;
            if (count > maxb) {
                maxb = count;
                
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        MaxPath[i][j]= path[i][j];
                    }
                }
                //memcpy(MaxPath, path, sizeof(path));
                for (int i = 0; i < 5; i++) {
                    cout << endl;
                    for (int j = 0; j < 5; j++) {
                        cout << path[i][j];
                    }
                }
                
                printf("=%d\n", count);

            }
            //return maxb;

        }
        else {


            int thispath[5][5] = {};
            path[x][y] = 1;
            //memcpy(thispath, path, sizeof(path));
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    thispath[i][j] = path[i][j];
                }
            }
            maxb = getBannas(x, y + 1, count + forest[x][y], thispath);
          
            maxb = getBannas(x + 1, y, count + forest[x][y], thispath);

        }

    }


    return maxb;

}
int main()
{
    int count = 0;
    int x = 0;
    int y = 0;
    //string string;
    int path[5][5] = {  };

    cout << getBannas(x, y, count, path) << endl;

    for (int i = 0; i < 5; i++) {
        cout << endl;
        for (int j = 0; j < 5; j++) {
            cout << MaxPath[i][j];
        }
    }

}

