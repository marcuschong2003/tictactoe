#include<iostream>
#include<string>
using namespace ::std;
bool cont=true;
int turn = 0;
int spot;
int spotX;
int spotY;
string board[3][3];
string playermove;
void split(int spot){
    spotY = (spot%3);
    spotX = (spot-spotY)/3;
}
void init(){
    for(int x=0;x<=2;x++){
        for(int y=0;y<=2;y++){
            board[x][y]="n";
        }
    }
}
void printboard(){
    bool ended=true;
    for(int x=0;x<=2;x++){
        for(int y=0;y<=2;y++){
            if(board[x][y]=="n"){
                ended = false;
            }
        }
    }
    if(ended){
        for(int x=0;x<=2;x++){
            for(int y=0;y<=2;y++){
                if(board[x][y]=="n"){
                    cout<< to_string(3*x+y+1)<<" ";
                }else{
                    cout<<board[x][y][0]<<" ";
                }
            }
            cout<<endl;
        }
        cout<<"It's a tie!"<<endl;
        exit(0);
    }
    for(int x=0;x<=2;x++){
        for(int y=0;y<=2;y++){
            if(board[x][y]=="n"){
                cout<< to_string(3*x+y+1)<<" ";
            }else{
                cout<<board[x][y][0]<<" ";
            }
        }
        cout<<endl;
    }
}
bool won(string charac){
    bool box1 = board[0][0]==charac;
    bool box2 = board[0][1]==charac;
    bool box3 = board[0][2]==charac;
    bool box4 = board[1][0]==charac;
    bool box5 = board[1][1]==charac;
    bool box6 = board[1][2]==charac;
    bool box7 = board[2][0]==charac;
    bool box8 = board[2][1]==charac;
    bool box9 = board[2][2]==charac;
    bool final = ((box1&&box2&&box3)||(box4&&box5&&box6)||(box7&&box8&&box9)||(box1&&box5&&box9)||(box3&&box5&&box7));
    return final;
}
void game(){
    cin>>playermove;
    spot = int(playermove[0])-49;
    split(spot);
    bool finished = true;
    for(int x=0;x<=2;x++){
        for(int y=0;y<=2;y++){
            if(board[x][y]=="n"){
                finished = false;
            }
        }
    }
    if(!finished){
        if(board[spotX][spotY]!="n"){
            cout<<"The spot is used!"<<endl;
            printboard();
            game();
        }else{
            if(turn%2){
                board[spotX][spotY]="O";
                turn=turn+1;
                if(won("O")){
                    printboard();
                    cout<<"O won the game!"<<endl;
                    finished = true;
                    exit(0);
                }
                printboard();
                game();
            }else{
                board[spotX][spotY]="X";
                turn=turn+1;
                if(won("X")){
                    printboard();
                    cout<<"X won the game!"<<endl;
                    finished = true;
                    exit(0);
                }
                printboard();
                game();
            }
        }
    }else{
        cout<<"It's a tie"<<endl;
        cont = false;
        exit(0);
    }
}
int main(){
    init();
    while(cont){
        cout<<"Please enter the move to be played."<<endl;
        printboard();
        game();
    }
}