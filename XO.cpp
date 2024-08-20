// C++ program to generate random numbers 
#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <math.h>

void input(char arr [3][3], int player , int &row , int &col );
void output(char arr[3][3]);
int check (int a );
char checkwinner(char arr[3][3]);
void compmove(char arr[3][3]);
void makemov(int a , int b , char arr[3][3] , char c );
bool Draw(char arr[3][3]);
void bestval (char arr [3][3] , int &row, int &col);



const int INF = std::numeric_limits<int>::max();

int main (){

bool gameover = false ;


char mat [3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };;
int row = 0 ; 
int col = 0 ;
int bestrow = -1;
int bestcol = -1 ;



for(int i = 0 ; i <9 ; i += 2){
    input(mat , 1 , row , col);
     output(mat );
    if(row == -1 ) break ; 
      if(checkwinner(mat)=='X'){
        std::cout<< "Player 'X' is the winner\n ";
        break;
    }
     if(checkwinner(mat)=='O'){
        std::cout<< "Player 'O' is the winner\n ";
        break;
    }
    if(i == 8 )break;

   

bestval(mat, bestrow ,  bestcol);
mat[bestrow][bestcol]= 'O';


  
    output(mat );

    


    if(checkwinner(mat)=='X'){
        std::cout<< "Player 'X' is the winner ";
        break;
    }
     if(checkwinner(mat)=='O'){
        std::cout<< "Player 'O' is the winner ";
        break;
    }
    


}
if(checkwinner(mat)=='\0') std:: cout<< "DRAW !!\n" ;
std :: cout << "Gameover";





}

void input(char arr[3][3], int player,int &row , int &column){
    while (true ){
row = 0 ;
column = 0 ;

std::cout << "Enter a row 1 - 3 ";
std::cin >> row ;

if(row == -1 )return  ;




std :: cout << "Now enter a column 1 - 3\n ";
std:: cin >> column;
row -= 1 ;
column -= 1 ;
if (row >= 0 && row < 3 && column >= 0 && column < 3){
    if(arr[row][column]== ' '){
        arr[row][column] = (player == 1) ? 'X' : 'O';
        break;}
        else{ std::cout<< "Occupied\n";}
}

        else {std::cout<<"Please enter a number from 1-3\n";}
    }

}
void output (char arr [3][3]){

        std::cout<<"----------------\n";
    for (int i = 0 ; i < 3 ; i ++){
        std::cout<<" | ";
        for (int j = 0 ; j < 3 ; j++){
            if(arr[i][j] == 'X'){
                std:: cout<< 'X' ; 
                std::cout<<" | " ;}

                else if(arr[i][j]== 'O'){
                
                      std:: cout<< 'O' ; 
                std::cout<<" | " ;}

                

           else  
           {
            std::cout<<0; std :: cout<< " | ";}

        }
        std:: cout << std:: endl;
        std::cout << "  ___|___|___" << std::endl;
    }


}

char  checkwinner(char arr[3][3]){
for(int i = 0 ; i <3 ; i ++){
    if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0]!= ' '){
        return arr[i][0];
    }
}

for(int i = 0 ; i < 3 ; i ++){
      if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i]!= ' '){
        return arr[i][0];
    }

}

if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') {
        return arr[0][0];  
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ') {
        return arr[0][2];  
    }

    
    return '\0';




}



bool Draw(char arr[3][3]){
    for (int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j++){
            if(arr[i][j] == ' '){
                return false ;

            }
        }
    }
    return true ; 
}


void makemov(int a , int b , char arr[3][3] , char c ){

    arr[a][b] = c ;
    std::cout<<std::endl<<"___________________________________________"<<std::endl <<std::endl;

}

int minimax(char arr [3][3], bool ismax){

int winner = checkwinner(arr);
if(winner=='O')return 10 ;
if(winner=='X') return -10 ;
if(Draw(arr))return 0 ;

if(ismax){
    int best = -INF;
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j ++){
            if(arr[i][j]==' '){
                arr[i][j] = 'O';
                best = std::max(best,minimax(arr,!ismax));
                arr[i][j] =' ';
            }
            

        }
    }
    return best ;
}
else{
    int best = INF;
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j ++){
            if(arr[i][j] == ' '){
                arr[i][j]='X';
                best = std::min(best,minimax(arr,!ismax));
                arr[i][j] =' ';
            }
        }
    }
    return best ; 
}
 
}


void bestval (char arr [3][3] , int &row, int &col){

int bestval = - INF;
 row = -1 ;
 col = -1 ;


for (int i = 0 ; i < 3 ; i ++){
    for (int j = 0 ; j< 3 ; j ++){
        if(arr[i][j]==' '){
            arr[i][j]= 'O';
            int move = minimax(arr, false);
            arr[i][j]= ' ';


            if(move > bestval ) {
                row = i ;
                col = j ;
                bestval = move ;
            }
        }


    }
}


}
