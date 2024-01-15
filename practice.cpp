#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
char check_winner(char choice[][3]);
void clear_screen();
char check_comp_win(char choice [][3]);
void board(char choice[][3]){
    cout << "\033[37m" << "        |        |" << endl;
    cout << "    " << "\033[32m" << choice[0][0] << "\033[37m" << "   |   " << "\033[32m" << choice[0][1]  << "\033[37m" <<  "    |   " << "\033[32m" << choice[0][2] << endl;
    cout << "\033[37m" << "________|________|________" << endl;
    cout << "        |        |"<< endl;
    cout << "    " << "\033[32m" << choice[1][0] << "\033[37m" << "   |   " << "\033[32m" << choice[1][1]  << "\033[37m" <<  "    |   " << "\033[32m" << choice[1][2] << endl;
    cout << "\033[37m" << "________|________|________" << endl;
    cout << "        |        |" << endl;
    cout << "    " << "\033[32m" << choice[2][0] << "\033[37m" << "   |   " << "\033[32m" << choice[2][1]  << "\033[37m" <<  "    |   " << "\033[32m" << choice[2][2] << endl;
    cout << "\033[37m" << "        |        |" << endl;
    cout << "\033[37m" << "    \nPick a number to play\n" << endl;

    cout << "Choice:";


}

bool check_draw(char choice[][3]){
    int counter = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(choice[i][j] == 'X' || choice[i][j] == 'O'){
                counter++;
            }
        }
    }
    if(counter == 9){
        return true;
    }
    return false;
}
void get_indexes(char choice[][3], int &player_x, int &player_y, int &computer_x, int &computer_y, int &computer, int &temp){
    int check = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            check++;
            if(check == computer){
                computer_x = i, computer_y = j;
            }
            if(check == temp){
                player_x = i, player_y = j;
            }
        }

    }

}

void computer_choice(char choice[][3], int size, int counter){
    int x = time(0);
    srand(x);
    int computer = 1 + (rand() % 9);
    int player_x, player_y, computer_x, computer_y;
    char player = 'X';
    char y;
    int temp;

    if(counter >= 3){
        char winner = check_winner(choice);
        if(winner == 'O' || winner == 'X'){
            cout << endl << winner << " won the game!" << endl;
            return;
        }
    }


    if(counter >= 5){
        bool draw = check_draw(choice);
        if(draw){
            cout << endl << "It was a Draw" << endl;
            exit(0);
        }
    }
    do{
        y = getchar();
        temp = (y - '0');
        get_indexes(choice, player_x, player_y, computer_x, computer_y, computer, temp);
        if(counter >= 1 && choice[player_x][player_y] == 'X' || choice[player_x][player_y] == 'O' ){
            clear_screen();
            board(choice);
            computer_choice(choice, size, counter);
        }

    } while(choice[player_x][player_y] == 'X' || choice[player_x][player_y] == 'O');

    if(counter <= 3){
        if(counter >= 1){
            choice[player_x][player_y] = 'X';
            int computer_play = (check_comp_win(choice) - '0');
            y = temp + 48;
            choice[player_x][player_y] = y;

            get_indexes(choice, player_x, player_y, computer_x, computer_y, computer_play, temp);
        }

        while(choice[computer_x][computer_y] == 'X' || choice[computer_x][computer_y] == 'O' || choice[computer_x][computer_y] == choice[player_x][player_y]){
            computer = 1 + (rand() % 9);
            get_indexes(choice,player_x, player_y, computer_x, computer_y, computer, temp);
        }
    }

    else{
        while(choice[computer_x][computer_y] == 'X' || choice[computer_x][computer_y] == choice[player_x][player_y]){
            computer = 1 + (rand() % 9);
            get_indexes(choice,player_x, player_y, computer_x, computer_y, computer, temp);
        }

    }



    if(y == choice[0][0]){
        choice[0][0] = 'X', choice[computer_x][computer_y] = 'O';
    }
    if(y == choice[0][1]){
        choice[0][1] = 'X', choice[computer_x][computer_y] = 'O';
    }
    if(y == choice[0][2]){
        choice[0][2] = 'X', choice[computer_x][computer_y] = 'O';
    }
    if(y == choice[1][0]){
        choice[1][0] = 'X', choice[computer_x][computer_y]= 'O';
    }
    if(y == choice[1][1]){
        choice[1][1] = 'X', choice[computer_x][computer_y]= 'O';
    }
    if(y == choice[1][2]){
        choice[1][2] = 'X', choice[computer_x][computer_y] = 'O';
    }
    if(y == choice[2][0]){
        choice[2][0] = 'X', choice[computer_x][computer_y] = 'O';
    }
    if(y == choice[2][1]){
        choice[2][1] = 'X', choice[computer_x][computer_y] = 'O';
    }
    if(y == choice[2][2]){
        choice[2][2] = 'X', choice[computer_x][computer_y] = 'O';
    }

    while (getchar() != '\n');
    clear_screen();
    board(choice);
    computer_choice(choice, size, ++counter);


}

char check_comp_win(char choice [][3]){
    char temp = '1';
    for(int i = 0; i < 3; i++){ //Make 'O' priority so computer can win instead of block player
        if(choice[i][0] == choice[i][1] || choice[i][2] == choice[i][1] || choice[i][0] == choice[i][2]){
            if(choice[i][0] != 'O' && choice[i][0] != 'X' ){ // Make sure it is O and not 0 for all checks
                if(choice[i][1] == 'X' || choice[i][2] == 'X'){
                    temp = choice[i][0];
                }
                else{
                    return choice[i][0];
                }
            }

            if(choice[i][1] != 'O' && choice[i][1] != 'X'){
                if(choice[i][0] == 'X' || choice[i][2] == 'X'){
                    temp = choice[i][1];
                }
                else{
                    return choice[i][1];
                }
            }

            if(choice[i][2] != 'O' && choice[i][2] != 'X'){
                if(choice[i][0] == 'X' || choice[i][1] == 'X'){
                    temp = choice[i][2];
                }
                else{
                    return choice[i][2];
                }
            }

        }
    }

    if(choice[0][0] == choice[1][1] || choice[0][0] == choice[2][2] || choice[2][2] == choice[1][1]){
        for(int i = 0; i < 3; i++){
            if(choice[i][i] != 'O' && choice[i][i] != 'X'){
                if(choice[0][0] == 'X' || choice[1][1] == 'X' || choice[2][2] == 'X'){
                    temp = choice[i][i];
                }
                else{
                    return choice[i][i];
                }

            }
        }


    }
    if(choice[0][2] == choice[1][1]  || choice[0][2] == choice[2][0] || choice[2][0] == choice[1][1]){
        if(choice[0][2] != 'O' && choice[0][2] != 'X'){
            if(choice[1][1] == 'X' || choice[2][0] == 'X'){
                temp = choice[0][2];
            }
            else{
                return choice[0][2];
            }
        }
        if(choice[2][0] != 'O' && choice[2][0] != 'X'){
            if(choice[0][2] == 'X' || choice[1][1] == 'X'){
                temp = choice[2][0];
            }
            else{
                return choice[2][0];
            }
        }
        if(choice[1][1] != 'O' && choice[1][1] != 'X'){
            if(choice[0][2] == 'X' || choice[2][0] == 'X'){
                temp = choice[1][1];
            }
            else{
                return choice[1][1];
            }

        }

    }

    for(int i = 0; i < 3; i++){
        if(choice[0][i] == choice[1][i] || choice[0][i] == choice[2][i] || choice[2][i] == choice[1][i]) {
            if(choice[0][i] != 'O' && choice[0][i] != 'X'){
                if(choice[1][i] == 'X' || choice[2][i] == 'X'){
                    temp = choice[0][i];
                }
                else{
                    return choice[0][i];
                }
            }

            if(choice[1][i] != 'O' && choice[1][i] != 'X'){
                if(choice[0][i] == 'X' || choice[2][i] == 'X'){
                    temp = choice[1][i];
                }
                else{
                    return choice[1][i];
                }
            }

            if(choice[2][i] != 'O' && choice[2][i] != 'X'){
                if(choice[0][i] == 'X' || choice[1][i] == 'X'){
                    temp = choice[2][i];
                }
                else{
                    return choice[2][i];
                }

            }

        }
    }


    if(temp != '1'){
        return temp;
    }
}
void clear_screen(){
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
char check_winner(char choice[][3]){
    char temp = '\0';
    //Horizontal check
    for(int i = 0; i < 3; i++){
        if(choice[i][0] == choice[i][1] && choice[i][0] == choice[i][2]){
            if(choice[i][0] != 'X'){
                temp = choice[i][0];
            }
            else{
                return choice[i][0];
            }
        }
        if(i == 2 && temp == 'O'){
            return temp;
        }
    }
    //Vertical check
    for(int i = 0; i < 3; i++){
        if(choice[0][i] == choice[1][i] && choice[0][i] ==choice[2][i]){
            if(choice[0][i] != 'X'){
                temp = choice[0][i];
            }
            else{
                return choice[0][i];
            }
        }
        if(i == 2 && temp == 'O'){
            return temp;
        }
    }
    //Diagonal check
    if(choice[0][0] == choice[1][1] && choice[0][0] == choice[2][2]){
        return choice[0][0];

    }
    if(choice[0][2] == choice[1][1] && choice[0][2] == choice[2][0]){
        return choice[0][2];

    }

    return 'N';

}
int main()
{

    vector < vector < int >> a1(3, vector <int> (3, 0));
    char choice[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int size = sizeof(choice);
    board(choice);
    computer_choice(choice, size, 0);


    return 0;
}
