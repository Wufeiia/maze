//Wufei Luo
//maze solver program
//June 13, 2020
#include <iostream>
#include <fstream>
#include "apmatrix.h"
#include "stack.h"

Stack path;
int row = 6;
int col = 6;
using namespace std;
void findPath(int x, int y, apmatrix<char> &m);
bool checkPath(int x, int y, apmatrix<char> &m);

int main() {
    ifstream file("maze1.txt");

    if(!file.is_open()){
        cout << "no file";
        return 0;
    }

    //declare & initialize
    int x = 0;
    int y = 0;
    apmatrix<char> map1(row,col);
    char temp;

    //read file
    for (int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            file >> temp;
            map1[i][j] = temp;
            if(map1[i][j] == 'S'){
                x = j;
                y = i;
            }
        }
    }

    findPath(x, y, map1);

    //output result
    for (int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(map1[i][j] == ','){
                map1[i][j] = '.'; //get rid of the visited sign
            }
            cout << map1[i][j];
        }
        cout << endl;
    }
}

void findPath(int x, int y, apmatrix<char> &m){
    //cout << x << " " << y << endl;
    if(m[y][x]=='G'){
        cout << "end" << endl;
    }
    //North
    else if(checkPath(x, y-1, m) == true){
        findPath(x, --y, m);
    }
    //East
    else if(checkPath(x+1, y, m) == true){
        findPath(++x, y, m);
    }
    //South
    else if(checkPath(x, y+1, m) == true){
        findPath(x, ++y, m);
    }
    //West
    else if(checkPath(x-1, y, m) == true){
        findPath(--x, y, m);

    }else{
        //if returned to start, there's no solution
        if(path.top == 0){
            cout << "no solution"<< endl;

        }else{
            m[y][x] = ','; //let ',' be a visited sign for now
            int temp = path.pop(); //get the number on the stack that keeps track
            y = temp/row; //re-calculate x and y
            x = temp%row;
            findPath(x, y, m); //go back and retry
        }
    }
}

bool checkPath(int x, int y, apmatrix<char> &m){
    //out of map
    if( x>=col || x<0 || y>=row || y<0){
        return false;
    }
    if(m[y][x]=='.'){
        m[y][x] = '+';
        path.push(y*row+x); // change x and y to a single number to indicate position
        //and putting it in the stack
        return true;
    }
    if(m[y][x] == '#'){
        return false;
    }
    if(m[y][x] == 'G'){
        return true;

    }else{
        return false;
    }
}
