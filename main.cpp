#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void SetDistance(int **D,int r,int c,int value,const int row,const int col){
    if(r<0||r>=row||c<0||c>=col){}
    else if(D[r][c]<=value){}
    else{
        D[r][c]=value;
        SetDistance(D,r+1,c,value+1,row,col);
        SetDistance(D,r-1,c,value+1,row,col);
        SetDistance(D,r,c+1,value+1,row,col);
        SetDistance(D,r,c-1,value+1,row,col);
    }
}

int main(){
    ifstream fin;
    ofstream fout;
    string fname;
    string line;
    int row;
    int col;
    int battery;
    int Rrow, Rcol;

    cout << "Enter file name: ";
    getline(cin,fname);
    fin.open(fname);
    getline(fin,line);
    stringstream(line) >> row >> col >> battery;
    int M[row][col];
    char tmpchar;
    for(int r=0;r<row;r++){
        getline(fin,line);
        for(int c=0;c<col;c++){
            if(line.at(c)=='R'){
                M[r][c]=2;
                Rrow=r;
                Rcol=c;
            }
            else{
                tmpchar=line.at(c);
                M[r][c]=tmpchar-48;
            }
        }
    }

    int **D;
    D=new int*[row];
    for(int i=0;i<row;i++){
        D[i]=new int[col];
    }
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            if(M[r][c]==1)
                D[r][c]=-1;
            else
                D[r][c]=INT8_MAX;
        }
    }
    SetDistance(D,Rrow,Rcol,0,row,col);

    for(int r=0;r<row;r++){
        cout << endl;
        for(int c=0;c<col;c++)
            cout << D[r][c] << " ";}//FOR TESTING MATRIX

    return 0;
}