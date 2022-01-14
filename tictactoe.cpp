#include <iostream>
#include<cstdlib>
using namespace std;
char panel_of_game[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char current_pointer;
int present_player;
void drawpanel_of_game()
{
    cout << "\n\t\t " << panel_of_game[0][0] << " | " << panel_of_game[0][1] << " | " << panel_of_game[0][2] << endl;
    cout << "\t\t-----------\n";
    cout << "\t\t " << panel_of_game[1][0] << " | " << panel_of_game[1][1] << " | " << panel_of_game[1][2] << endl;
    cout << "\t\t-----------\n";
    cout << "\t\t " << panel_of_game[2][0] << " | " << panel_of_game[2][1] << " | " << panel_of_game[2][2] << endl; 
}
bool placepointer(int spot)
{
    int row = spot / 3;
    int column;
    if (spot % 3 == 0)
    {
        row = row - 1;
        column = 2;
    }
    else column = (spot % 3) - 1;
    if (panel_of_game[row][column] != '*' && panel_of_game[row][column] != 'O')
    {
        panel_of_game[row][column] = current_pointer;
        return true;
    }
    else return false;

}
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        //row 
        if (panel_of_game[i][0] == panel_of_game[i][1] && panel_of_game[i][1] == panel_of_game[i][2]) return present_player;
        //column
        if (panel_of_game[0][i] == panel_of_game[1][i] && panel_of_game[1][i] == panel_of_game[2][i]) return present_player;
    }
    if (panel_of_game[0][0] == panel_of_game[1][1] && panel_of_game[1][1] == panel_of_game[2][2]) return present_player;
    if (panel_of_game[0][2] == panel_of_game[1][1] && panel_of_game[1][1] == panel_of_game[2][0]) return present_player;
    return 0;
}
void swap_player_and_pointer()
{
    if (current_pointer == '*') current_pointer = 'O';
    else current_pointer = '*';
    if (present_player == 1) present_player = 2;
    else present_player = 1;
}
void game()
{
    cout << "1st Player please choose your letter(*,O): ";
    char pointer_player1;
    cin >> pointer_player1;
    present_player = 1;
    current_pointer = pointer_player1;
    drawpanel_of_game();
    int player_won;
    for (int i = 0; i < 9; i++)
    {
        cout << "\nPlayer" << present_player << "'s turn.Enter your position: ";
        int spot;
        cin >> spot;
        if (spot < 1 || spot >9)
        {
            cout << "Try different move!";
            i--;
            continue;
        }
        if (!placepointer(spot))
        {
            cout << "Occupied by an opponent.Try some other!\n";
            i--;
            continue;
        }
        drawpanel_of_game();
        player_won = winner();
        if (player_won == 1)
        {
            cout << "\n\tCONGRATULATIONS 1st player won!";
            break;
        }
        if (player_won == 2) 
        {
            cout << "\n\tCONGRATULATIONS 2nd player won!";
            break;
        }
        swap_player_and_pointer();
    }
    if (player_won == 0)
        cout << "game tied";
}
int main()
{
    cout << "\t\t\tTIC TAC TOE GAME!" << endl;
    game();
}
