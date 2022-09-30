#include <iostream>
#include <windows.h>
#include <thread>
#include <time.h>
#include <stdlib.h>
using namespace std;


int score = 0, lr = 2;
const int ROW = 21, COL = 72;
const int ROW1 = 5, COL1 = 5;
int pacManx = 1, pacMany = 1;
int ghost1X = 9, ghost1Y = 2;
int ghost2X = 19, ghost2Y = 67;
bool gcheck = true;



char grid[ROW][COL] = {
	"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
	"+   . . . .    . . . . .   . . . . o . . .   . . . . . . . . . .      +",
	"+ . ++++++++ . +++++++++ . +++++++++++++++   ++++++++++++++++++++  .  +",
	"+ . +      + . +       + . +             + . +                  +  .  +",
	"+ . +      + . +       + . +             + . +                  +  o  +",
	"+ . +      + . +       + . +             + . +                  +  .  +",
	"+ . +      + . +       + . +             + . +                  +  .  +",
	"+ . ++++++++ . +++++++++   +++++++++++++++   ++++++++++++++++++++  .  +",
	"+ .  . . . .    . . . . .   . .     . . . .   . . . . . . . . . .  .  +",
	"+ . ++++++++++++++++++++++++++++   ++++++++++++++++++++++++++++++  .  +",
	"+ . +                          +   +                            +  .  +",
	"+ . +                          +   +                            +  .  +",
	"+ . +                          +   +                            +  .  +",
	"+ . +                          +   +                            +  .  +",
	"+ o +                          + o +                            +  .  +",
	"+ . +                          +   +                            +  .  +",
	"+ . +                          +   +                            +  .  +",
	"+ . +                          +   +                            +  .  +",
	"+   ++++++++++++++++++++++++++++   ++++++++++++++++++++++++++++++     +",
	"+    . . . .    . . . . .   . . . . . . .    . . . . . . . . . .      +",
	"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" };



void setPacman()
{
	grid[pacManx][pacMany] = 'x';
}

void setGhost1() {

	grid[ghost1X][ghost1Y] = 'g';
}

void setGhost2() {
	grid[ghost2X][ghost2Y] = 'g';
}





void printscr() {

	system("CLS");
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}


}





int scorecalculator(int &score) {

	if (grid[pacManx][pacMany] == '.') {
		score++;
	}
	else if(grid[pacManx][pacMany] == 'o'){
		score = score + 50;
	}

	
	return score;
}

int game(int &lr) {

	if (grid[pacManx][pacMany] == grid[ghost1X][ghost1Y] && lr == 0) {

		gcheck = false;
		return lr;

	}
	else if (grid[pacManx][pacMany] == grid[ghost1X][ghost1Y]) {

		lr--;

		pacManx = 1;
		pacMany = 1;
		return lr;
	}


}




void move(char input) {

	int updater = 1;
	grid[pacManx][pacMany] = ' ';


	switch (input) {
	case 'a':

		if (grid[pacManx][pacMany - 1] != '+') {

			pacMany -= updater;
			game(lr);
			scorecalculator(score);
		}

		break;

	case 'w':

		if (grid[pacManx - 1][pacMany] != '+') {
			pacManx -= updater;
			game(lr);
			scorecalculator(score);
		}
		break;

	case 'd':

		if (grid[pacManx][pacMany + 1] != '+') {
			pacMany += updater;
			game(lr);
			scorecalculator(score);
		}
		break;

	case 's':

		if (grid[pacManx + 1][pacMany] != '+') {
			pacManx += updater;
			game(lr);
			scorecalculator(score);
		}
		break;

	default:;

	}

	setPacman();
	printscr();

}







void   moveghost() {

	srand(time(NULL));
	ghost1X = rand() % 18 + 2;

	ghost2X = rand() % 18 + 2;

	setGhost1();
	setGhost2();





}





int main()
{

	char input;

	int i = 0, j = 0;


	setPacman();


	moveghost();






	printscr();



	cout << "\n" << endl;
	cin >> input;




	while (1)
	{


		if (score == 320) {
			
			system("CLS");
			cout << "          @@@@@@@@@@@@@@@			   " << endl;
			cout << "      @@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "    @@@@@@@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "  @@@@@@@@@@@@@@   @@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@			   " << endl;
			cout << "@@@@@@@@@@@@@@@@			   " << endl;
			cout << "@@@@@@@@@@@@@			   " << endl;
			cout << "@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@					   " << endl;
			cout << "@@@@@@@@@@@@			   " << "PACMAN game completed with score = 125!" << endl;
			cout << "@@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "    @@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "      @@@@@@@@@@@@@@@@@@@@			   " << endl;
			cout << "        @@@@@@@@@@@@@@@@			   " << endl;


			system("pause");
			break;
		}

		if (gcheck == true && lr == 2 || lr == 1) {
			cout << "Lives remaining ==" << lr;
			if (lr == 0) {
				cout << "Lives remaining ==" << lr;
			}

		}

		if (gcheck == true && lr == 0) {
			cout << "Lives remaining =" << lr << endl;

		}

		if (gcheck == false) {
			//cout << "" << endl;
			system("CLS");
			cout << "          @@@@@@@@@@@@@@@			   " << endl;
			cout << "      @@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "    @@@@@@@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "  @@@@@@@@@@@@@@   @@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@			   " << endl;
			cout << "@@@@@@@@@@@@@@@@			   " << endl;
			cout << "@@@@@@@@@@@@@			   " << endl;
			cout << "@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@					   " << endl;
			cout << "@@@@@@@@@@@@			   "<<"    GAME    OVER"  << endl;
			cout << "@@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@		   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "    @@@@@@@@@@@@@@@@@@@@@@@				   " << endl;
			cout << "      @@@@@@@@@@@@@@@@@@@@			   " << endl;
			cout << "        @@@@@@@@@@@@@@@@			   " << endl;
			cout << "You scored :" << scorecalculator(score) << "  points" << endl;
			system("pause");
			break;

		}

		if (GetKeyState('W') & 0x8000)
		{
			input = 'w';

		}
		if (GetKeyState('A') & 0x8000)
		{
			input = 'a';
		}
		if (GetKeyState('S') & 0x8000)
		{
			input = 's';
		}
		if (GetKeyState('D') & 0x8000)
		{
			input = 'd';

		}

		move(input);
		Sleep(15);
	}



	return 0;
}
