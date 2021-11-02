#include<iostream>

using namespace std;

char matrix[3][3] = { '1' , '2' , '3' , '4' , '5' , '6', '7' ,'8', '9'};
char player = 'X';
bool flag = false;
int steps = 0;
int moves = 0;
int n = 10;
char a, check;
bool playerCheck = false ;

void printMatrix()
{
    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            cout <<"  "<< matrix[i][j] << "  | ";
        }
            cout <<endl;
    }
}

    void inputData()
{
    int m;
    cin >> m;
    bool inputSuccess = false;
    while(!inputSuccess) {
        if (0 <= m && m <= 9) {
            //rút gọn dùng modulo - chia lấy dư
            if ( m <= 3){
                if (matrix[0][m-1] == 'X' || matrix[0][m-1] == 'O') {
                    cout << "This field has been used, please try again";
                    inputSuccess = false;
                }
                else {
                    matrix[0][m-1] = player;
                    inputSuccess = True;
                }
            } else if ( 3 < m <= 6){
                if (matrix[0][m-1] == 'X' || matrix[0][m-1] == 'O') {
                    cout << "This field has been used, please try again";
                    inputSuccess = false;
                }
                else {
                    matrix[0][m-1] = player;
                    inputSuccess = True;
                }
            } else if ( 6 < m <= 9){
                if (matrix[0][m-1] == 'X' || matrix[0][m-1] == 'O') {
                    cout << "This field has been used, please try again";
                    inputSuccess = false;
                }
                else {
                    matrix[0][m-1] = player;
                    inputSuccess = True;
                }
            }
        }
    }
    moves ++;
}


void playerTurn()
{
    if ( player == 'O'){
        cout << "Player X turn : " << endl;
    } else
    if ( player == 'X'){
        cout << "Player O turn :" << endl;
    }
}

void playerRotation()
{

    if ( player == 'X' )
    {
        player = 'O';
    } else {
        player = 'X';
    }
}

void turn()
{
    cout << "Who will go first ? "<<endl;
    cout << "Press 'x' to become X"<<endl;
    cout << "Press 'o' to become O"<<endl;
    cin >> a;
    if ( a == 'x'){
        player = 'X';
    } else if ( a == 'o'){
        player = 'O';
        playerCheck = true;
    }
}

void winCondition()
{
       if (matrix[0][0] == matrix[0][1] && matrix [0][0] == matrix[0][2]){
        flag = true;
       }
       if (matrix[0][0] == matrix[1][1] && matrix [0][0] == matrix[2][2]){
        flag = true;
       }
       if (matrix[0][0] == matrix[1][0] && matrix [0][0] == matrix[2][0]){
        flag = true;
       }
       if (matrix[1][0] == matrix[1][1] && matrix [1][0] == matrix[1][2]){
        flag = true;
       }
       if (matrix[2][0] == matrix[2][1] && matrix [2][0] == matrix[2][2]){
        flag = true;
       }
       if (matrix[0][2] == matrix[1][1] && matrix [0][2] == matrix[2][0]){
        flag = true;
       }
       if (matrix[0][1] == matrix[1][1] && matrix [0][1] == matrix[2][1]){
        flag = true;
       }
       if (matrix[0][2] == matrix[1][2] && matrix [0][2] == matrix[2][2]){
        flag = true;
       }
}

void winingPlayer()
{
    if ( steps % 2 == 0){
        cout << "       Player O is the wiwner!" << endl;
    } else
    {
        if ( playerCheck == true){
        cout << "       Player O is the wiwner!" << endl;
        } else {
        cout << "       Player X is the wiwner!" << endl;
        }
    }
}

int main()
{
    turn();
    while ( flag == false ){
    printMatrix();
    if ( wrong == false ){
        inputData();
    }
    playerTurn();
    playerRotation();
    winCondition();
    steps ++;
    if ( flag == true)
    {
        winingPlayer();
        printMatrix();
    }
    if ( moves == 9)
    {
        cout << "Out of moves";
        break;
    }
    }
    return 0;
}
