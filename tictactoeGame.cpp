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

void playerTurnNoti()
{
        if ( player == 'O'){
        cout << "Player O turn : " << endl;
    } else
    if ( player == 'X'){
        cout << "Player X turn :" << endl;
    }
}

void printMatrix()
{
    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            cout <<"  "<< matrix[i][j] << "  |  ";
        }
            cout <<endl;
    }
}

    void inputData()
{
    int m;
    cin >> m;
    bool inputSuccess = false;
    int r = ( m - 1 ) / 3;
    int c = ( m - 1 ) % 3;
    if ( matrix[r][c] == 'X' || matrix[r][c] == 'O'){
        cout << "This field has been used, please try again !";
    } else {
        matrix[r][c] = player;
        inputSuccess = true;
    }
    moves ++;
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

bool winCondition()
{
    for ( int i = 0 ; i < 3 ; i++){
        if ( matrix[i][0] == matrix[i][1] && matrix [i][0] == matrix[i][2] ){
            return flag = true;                                     // kiểm tra xem đã đạt điều kiện thắng chưa ?
            }
        if ( matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]){
            return flag = true;
        }
    }
       if (matrix[0][0] == matrix[1][1] && matrix [0][0] == matrix[2][2]){
        return flag = true;
       }
       if (matrix[0][2] == matrix[1][1] && matrix [0][2] == matrix[2][0]){
        return flag = true;
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
        playerTurnNoti();
        printMatrix();
        inputData();
        playerRotation();
        winCondition();
        steps ++;
    if ( flag == true)
    {
        winingPlayer();
        printMatrix();
    }
    if ( moves == 9 && flag == true)
    {
        break;
    } else if ( moves == 9){
        cout << "Out of moves";
        }
    }
    return 0;
}
