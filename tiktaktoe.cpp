#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct plane{
    int simbols[4][4];
    string lastmove;
    bool gameover;
};
void startgame(plane &P);
void printboard(plane P);
bool isvalidmove(plane P, int movex, int movey);
void makemove(plane &P, int movex, int movey, int playerid);
bool isgameover(plane &P);
void wonscreen(plane &P);
void aimove(plane &P);
int main()
{
    plane P;
    bool endgame=false;
    int movex,movey;
    P.gameover = false;
    startgame(P);
    printboard(P);
    while (P.gameover!= true){
        cin >> movex >> movey;
        if(isvalidmove(P,movex,movey)==true){
            makemove(P,movex,movey,1);
            printboard(P);
            P.gameover = isgameover(P);
            if (P.gameover ==true){
                wonscreen(P);
            }else {
            aimove(P);
            P.gameover=isgameover(P);
            if(P.gameover== true){
                wonscreen(P);
            }
            }
        }
    }return 0;
    }


void startgame(plane &P){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            P.simbols[i][j]=0;

        }
    }
}
void printboard(plane P){
    cout << "--------------------" << endl;
    cout <<"  " << 0 << " "<<  1 << " " << 2 << endl;

    for(int i=0;i<3;i++){
        cout << i <<" ";
        for(int j=0;j<3;j++){
            cout << P.simbols[j][i] << " ";
        }
    cout << endl;
    }
}
bool isvalidmove(plane P, int movex, int movey){
    if((movex <3 && movex>-1)&&(movey <3 && movey >-1)){
        if(P.simbols[movex][movey]==0){
            return true;
        }
    }return false;
}
void makemove(plane &P, int movex, int movey, int playerid){
    switch (playerid){
    case 1:
        P.simbols[movex][movey] = 1;
        P.lastmove= "player";
        break;
    case 2:
        P.simbols[movex][movey] = 2;
        P.lastmove= "Computer";
        break;
    }
}
bool isgameover(plane &P){
    int temp;
    bool iswin=true;
    //lines
    for (int i=0;i<3;i++){
        iswin=true;
        temp = P.simbols[0][i];
        for(int j=0;j<3;j++){
            if(temp!= P.simbols[j][i]){
                iswin=false;
            }
        }
        if(iswin==true && temp != 0) {
        return true;
        break;
        }

    }
    //Columns
     for (int i=0;i<3;i++){
        iswin=true;
        temp = P.simbols[i][0];
        for(int j=0;j<3;j++){
            if(temp!= P.simbols[i][j]){
                iswin=false;
            }
        }
        if(iswin==true && temp != 0) {
        return true;
        break;
        }

    }
    //diagonal
    if(P.simbols[0][0]==P.simbols[1][1] && P.simbols[1][1] == P.simbols[2][2] && P.simbols[0][0]!=0){
        return true;
    }else if(P.simbols[0][2]==P.simbols[1][1]&&P.simbols[0][2]==P.simbols[2][0]&& P.simbols[0][2]!=0){
        return true;
    }else {
        return false;
    }

}
void wonscreen(plane &P){
    char response;
    cout << "-----------------"<< endl;
    cout << "Game is over" << endl;
    cout << "Won:" << P.lastmove << endl;
    cout << "-----------------" << endl;
    cout << "Do you want to continue the game?(y for yes, n for no)" << endl;
    cin >> response;
    if(response == 'y'){
        system("cls");//clean screen
        startgame(P);
        printboard(P);
        P.lastmove = "";
        P.gameover =false;
    }
}
void aimove(plane &P){
    srand(time(NULL));
    unsigned lb=0, ub= 2;
    unsigned randomx =lb + (rand()%((ub - lb)+1));
    unsigned randomy =lb + (rand()%((ub - lb)+1));
    while (!isvalidmove(P, randomx, randomy)){
        randomx =lb + (rand()%((ub - lb)+1));
        randomy =lb + (rand()%((ub - lb)+1));
    }
    makemove(P, randomx, randomy, 2);
    printboard(P);

}
