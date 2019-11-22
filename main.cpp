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

void TurnBack(int **M,int **D,int &Crow,int &Ccol,int &Lrow,int &Lcol){
    if(Crow==Lrow && (Ccol+1)==Lcol && M[Crow+1][Ccol]!=INT32_MAX && M[Crow][Ccol-1]==INT32_MAX && M[Crow-1][Ccol]==INT32_MAX){
        Lrow=Crow;
        Lcol=Ccol;
        if(D[Crow+1][Ccol]==D[Crow][Ccol]-1)
            M[Crow+1][Ccol]--;
        Crow++;
    }
    else if(Crow==Lrow && (Ccol+1)==Lcol && M[Crow+1][Ccol]==INT32_MAX && M[Crow][Ccol-1]!=INT32_MAX && M[Crow-1][Ccol]==INT32_MAX){
        Lrow=Crow;
        Lcol=Ccol;
        if(D[Crow][Ccol-1]==D[Crow][Ccol]-1)
            M[Crow][Ccol-1]--;
        Ccol--;
    }
    else if(Crow==Lrow && (Ccol+1)==Lcol && M[Crow+1][Ccol]==INT32_MAX && M[Crow][Ccol-1]==INT32_MAX && M[Crow-1][Ccol]!=INT32_MAX){
        Lrow=Crow;
        Lcol=Ccol;
        if(D[Crow-1][Ccol]==D[Crow][Ccol]-1)
            M[Crow-1][Ccol]--;
        Crow--;
    }
    
        else if((Crow+1)==Lrow && Ccol==Lcol && M[Crow][Ccol+1]!=INT32_MAX && M[Crow][Ccol-1]==INT32_MAX && M[Crow-1][Ccol]==INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow][Ccol+1]==D[Crow][Ccol]-1)
                M[Crow][Ccol+1]--;
            Ccol++;
        }
        else if((Crow+1)==Lrow && Ccol==Lcol && M[Crow][Ccol+1]==INT32_MAX && M[Crow][Ccol-1]!=INT32_MAX && M[Crow-1][Ccol]==INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow][Ccol-1]==D[Crow][Ccol]-1)
                M[Crow][Ccol-1]--;
            Ccol--;
        }
        else if((Crow+1)==Lrow && Ccol==Lcol && M[Crow][Ccol+1]==INT32_MAX && M[Crow][Ccol-1]==INT32_MAX && M[Crow-1][Ccol]!=INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow-1][Ccol]==D[Crow][Ccol]-1)
                M[Crow-1][Ccol]--;
            Crow--;
        }
    
        else if(Crow==Lrow && (Ccol-1)==Lcol && M[Crow][Ccol+1]!=INT32_MAX && M[Crow+1][Ccol]==INT32_MAX && M[Crow-1][Ccol]==INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow][Ccol+1]==D[Crow][Ccol]-1)
                M[Crow][Ccol+1]--;
            Ccol++;
        }
        else if(Crow==Lrow && (Ccol-1)==Lcol && M[Crow][Ccol+1]==INT32_MAX && M[Crow+1][Ccol]!=INT32_MAX && M[Crow-1][Ccol]==INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow+1][Ccol]==D[Crow][Ccol]-1)
                M[Crow+1][Ccol]--;
            Crow++;
        }
        else if(Crow==Lrow && (Ccol-1)==Lcol && M[Crow][Ccol+1]==INT32_MAX && M[Crow+1][Ccol]==INT32_MAX && M[Crow-1][Ccol]!=INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow-1][Ccol]==D[Crow][Ccol]-1)
                M[Crow-1][Ccol]--;
            Crow--;
        }
    
        else if((Crow-1)==Lrow && Ccol==Lcol && M[Crow][Ccol+1]!=INT32_MAX && M[Crow+1][Ccol]==INT32_MAX && M[Crow][Ccol-1]==INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow][Ccol+1]==D[Crow][Ccol]-1)
                M[Crow][Ccol+1]--;
            Ccol++;
        }
        else if((Crow-1)==Lrow && Ccol==Lcol && M[Crow][Ccol+1]==INT32_MAX && M[Crow+1][Ccol]!=INT32_MAX && M[Crow][Ccol-1]==INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow+1][Ccol]==D[Crow][Ccol]-1)
                M[Crow+1][Ccol]--;
            Crow++;
        }
        else if((Crow-1)==Lrow && Ccol==Lcol && M[Crow][Ccol+1]==INT32_MAX && M[Crow+1][Ccol]==INT32_MAX && M[Crow][Ccol-1]!=INT32_MAX){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow][Ccol-1]==D[Crow][Ccol]-1)
                M[Crow][Ccol-1]--;
            Ccol--;
        }
    
    else{
    Lrow=Crow;
    Lcol=Ccol;
    
    if(M[Crow][Ccol+1]<=M[Crow+1][Ccol] && M[Crow][Ccol+1]<=M[Crow][Ccol-1] && M[Crow][Ccol+1]<=M[Crow-1][Ccol]){
        if(D[Crow][Ccol+1]==D[Crow][Ccol]-1)
            M[Crow][Ccol+1]--;
        Ccol++;
    }
    else if(M[Crow+1][Ccol]<M[Crow][Ccol+1] && M[Crow+1][Ccol]<=M[Crow][Ccol-1] && M[Crow+1][Ccol]<=M[Crow-1][Ccol]){
        if(D[Crow+1][Ccol]==D[Crow][Ccol]-1)
            M[Crow+1][Ccol]--;
        Crow++;
    }
    else if(M[Crow][Ccol-1]<M[Crow][Ccol+1] && M[Crow][Ccol-1]<M[Crow+1][Ccol] && M[Crow][Ccol-1]<=M[Crow-1][Ccol]){
        if(D[Crow][Ccol-1]==D[Crow][Ccol]-1)
            M[Crow][Ccol-1]--;
        Ccol--;
    }
    else if(M[Crow-1][Ccol]<M[Crow][Ccol+1] && M[Crow-1][Ccol]<M[Crow+1][Ccol] && M[Crow-1][Ccol]<M[Crow][Ccol-1]){
        if(D[Crow-1][Ccol]==D[Crow][Ccol]-1)
            M[Crow-1][Ccol]--;
        Crow--;
    }

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

    //Input the file. Set the variables and Main matrix.
    cout << "Enter file name: ";
    getline(cin,fname);
    fin.open(fname);
    getline(fin,line);
    stringstream(line) >> row >> col >> battery;
    int **M;
    M=new int*[row];
    for(int i=0;i<row;i++){
        M[i]=new int[col];
    }
    for(int r=0;r<row;r++){
        getline(fin,line);
        for(int c=0;c<col;c++){
            if(line.at(c)=='R'){
                M[r][c]=INT16_MAX;
                Rrow=r;
                Rcol=c;
            }
            else if(line.at(c)=='0')M[r][c]=0;
            else if(line.at(c)=='1')M[r][c]=INT32_MAX;
        }
    }
    fin.close();

    //Set Distance matrix.
    int **D;
    D=new int*[row];
    for(int i=0;i<row;i++){
        D[i]=new int[col];
    }
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            if(M[r][c]==INT32_MAX)
                D[r][c]=-1;
            else
                D[r][c]=INT16_MAX;
        }
    }
    SetDistance(D,Rrow,Rcol,0,row,col);

    //Count the number of places to visit.
    int numzeros=0;
    for(int r=1;r<row-1;r++){
        for(int c=1;c<col-1;c++)
            if(M[r][c]==0)
                numzeros++;
    }

    //Traverse the space.
    int steps=0;
    int totalsteps=0;
    int Crow=Rrow;
    int Ccol=Rcol;
    int Lrow, Lcol; //Last position
    fout.open("temporary.path");
    fout << Crow << " " << Ccol << endl;
    while(numzeros>0 || Crow!=Rrow || Ccol!=Rcol){
        //Go home when the battery is about to be used up.
        if(D[Crow][Ccol]==battery-steps || numzeros==0){
            Lrow=Crow;
            Lcol=Ccol;
            if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1)Ccol++;
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1)Crow++;
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1)Ccol--;
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1)Crow--;
            else if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1){
                if(M[Crow][Ccol+1]<=M[Crow+1][Ccol])Ccol++;
                else{Crow++;}
            }
            else if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1){
                if(M[Crow][Ccol+1]<=M[Crow][Ccol-1])Ccol++;
                else{Ccol--;}
            }
            else if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1){
                if(M[Crow][Ccol+1]<=M[Crow-1][Ccol])Ccol++;
                else{Crow--;}
            }
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1){
                if(M[Crow+1][Ccol]<=M[Crow][Ccol-1])Crow++;
                else{Ccol--;}
            }
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1){
                if(M[Crow+1][Ccol]<=M[Crow-1][Ccol])Crow++;
                else{Crow--;}
            }
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1){
                if(M[Crow][Ccol-1]<=M[Crow-1][Ccol])Ccol--;
                else{Crow--;}
            }
            else if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]!=D[Crow][Ccol]-1){
                if(M[Crow][Ccol+1]<=M[Crow+1][Ccol] && M[Crow][Ccol+1]<=M[Crow][Ccol-1])Ccol++;
                else if(M[Crow+1][Ccol]<M[Crow][Ccol+1] && M[Crow+1][Ccol]<=M[Crow][Ccol-1])Crow++;
                else if(M[Crow][Ccol-1]<M[Crow][Ccol+1] && M[Crow][Ccol-1]<M[Crow+1][Ccol])Ccol--;
            }
            else if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]!=D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1){
                if(M[Crow][Ccol+1]<=M[Crow+1][Ccol] && M[Crow][Ccol+1]<=M[Crow-1][Ccol])Ccol++;
                else if(M[Crow+1][Ccol]<M[Crow][Ccol+1] && M[Crow+1][Ccol]<=M[Crow-1][Ccol])Crow++;
                else if(M[Crow-1][Ccol]<M[Crow][Ccol+1] && M[Crow-1][Ccol]<M[Crow+1][Ccol])Crow--;
            }
            else if(D[Crow][Ccol+1]==D[Crow][Ccol]-1 && D[Crow+1][Ccol]!=D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1){
                if(M[Crow][Ccol+1]<=M[Crow][Ccol-1] && M[Crow][Ccol+1]<=M[Crow-1][Ccol])Ccol++;
                else if(M[Crow][Ccol-1]<M[Crow][Ccol+1] && M[Crow][Ccol-1]<=M[Crow-1][Ccol])Ccol--;
                else if(M[Crow-1][Ccol]<M[Crow][Ccol+1] && M[Crow-1][Ccol]<M[Crow][Ccol-1])Crow--;
            }
            else if(D[Crow][Ccol+1]!=D[Crow][Ccol]-1 && D[Crow+1][Ccol]==D[Crow][Ccol]-1 && D[Crow][Ccol-1]==D[Crow][Ccol]-1 && D[Crow-1][Ccol]==D[Crow][Ccol]-1){
                if(M[Crow+1][Ccol]<=M[Crow][Ccol-1] && M[Crow+1][Ccol]<=M[Crow-1][Ccol])Crow++;
                else if(M[Crow][Ccol-1]<M[Crow+1][Ccol] && M[Crow][Ccol-1]<=M[Crow-1][Ccol])Ccol--;
                else if(M[Crow-1][Ccol]<M[Crow+1][Ccol] && M[Crow-1][Ccol]<M[Crow][Ccol-1])Crow--;
            }

            if(M[Crow][Ccol]!=0){
                M[Crow][Ccol]--;
                numzeros++;
            }            
        }

        //On the road.
        else if(Crow!=0 && Crow!=row-1 && Ccol!=0 && Ccol!=col-1){
            if(M[Crow][Ccol+1]==0){
                Lrow=Crow;
                Lcol=Ccol;
                Ccol++;
            }
            else if(M[Crow+1][Ccol]==0 && M[Crow][Ccol+1]!=0){
                Lrow=Crow;
                Lcol=Ccol;
                Crow++;
            }
            else if(M[Crow][Ccol-1]==0 && M[Crow][Ccol+1]!=0 && M[Crow+1][Ccol]!=0){
                Lrow=Crow;
                Lcol=Ccol;
                Ccol--;
            }
            else if(M[Crow-1][Ccol]==0 && M[Crow][Ccol+1]!=0 && M[Crow+1][Ccol]!=0 && M[Crow][Ccol-1]!=0){
                Lrow=Crow;
                Lcol=Ccol;
                Crow--;
            }
            else if(M[Crow][Ccol+1]!=0 && M[Crow+1][Ccol]!=0 && M[Crow][Ccol-1]!=0 && M[Crow-1][Ccol]!=0){
                TurnBack(M,D,Crow,Ccol,Lrow,Lcol);
                numzeros++;
            }
        }

        else if(Crow==0){
            Lrow=Crow;
            Lcol=Ccol;
            if(M[Crow+1][Ccol]==0)Crow++;
            else{Crow++;numzeros++;}
        }
        else if(Crow==row-1){
            Lrow=Crow;
            Lcol=Ccol;
            if(M[Crow-1][Ccol]==0)Crow--;
            else{Crow--;numzeros++;}
        }
        else if(Ccol==0){
            Lrow=Crow;
            Lcol=Ccol;
            if(M[Crow][Ccol+1]==0)Ccol++;
            else{Ccol++;numzeros++;}
        }
        else if(Ccol==col-1){
            Lrow=Crow;
            Lcol=Ccol;
            if(M[Crow][Ccol-1]==0)Ccol--;
            else{Ccol--;numzeros++;}
        }

        steps++;
        totalsteps++;
        numzeros--;
        M[Crow][Ccol]++;
        fout << Crow << " " << Ccol << endl;
        if(steps==battery){
            steps=0;
        }
    }
    fout.close();
    fout.open("final.path");
    fout << totalsteps;
    fin.open("temporary.path");
    while(fin){
        fout << endl;
        getline(fin,line);
        fout << line;
    }
    fin.close();
    
    //FOR TESTING MATRIX
    /*for(int r=0;r<row;r++){
        fout << endl;
        for(int c=0;c<col;c++)
            fout << M[r][c] << " ";}*/
    
    fout.close();

    return 0;
}