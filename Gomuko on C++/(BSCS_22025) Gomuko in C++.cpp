
// Gomuko on c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;
#define capacity 100


void input(char brd[][capacity], char Sym[], int& dim, char Pla_name[], int& nop, int& Turn, int& Win_num, string mode) {
	// Taking dimension from user
	do {
		cout << "In how many rows and columns you want to play it shold be max 19 and min 3 (according to number of grids in gomuko)" << endl;
		cin >> dim;
	} while (dim > 19 || dim < 3);
	// Initializing grids with dash ('_')
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			brd[i][j] = '_';



		}
	}

	 //Asking number of Players from user who want to play
	//cout << "How many players are playing with computer?" << endl;
	if(mode=="1vC") {
		nop = 2;
		cout << "Number of players are 2, one is Computer and 2nd is you" << endl;
		// Asking names and symbols of players
		int i = 0;
		for (i = 0; i < nop - 1; i++) {
			//string x;
			cout << "What is the " << i + 1 << " player's name" << endl;
			//cin >> x;
			cin >> Pla_name[i];
			cout << "What is the " << i + 1 << " players symbol?" << endl;
			cin >> Sym[i];
			// size++;`
		}
		for (i; i < nop; i++) {
			Pla_name[i] = 'C';
			cout << "What symbol you want to assign the computer... I would recommend 'c'" << endl;
			cin >> Sym[i];
		}
	}
	if (mode == "1v1") {
		cout << "How many players are playing?" << endl;
		cin >> nop;
		for (int i = 0; i < nop; i++) {
			cout << "What's the name of player " << i + 1<<endl;
			cin >> Pla_name[i];
			cout << "What is the symbol of player " << i + 1<<endl;
			cin >> Sym[i];
		
		}
	
	
	}
	cout << "Please enter number of symbols you want consecutively placed in order to win..\n number must be atleast 3 and max 19 " << endl;
	do {
		cin >> Win_num;
	} while (Win_num > 19 || Win_num < 3);

	Turn = rand() % nop;// Generating random turn

}
bool is_valid(char B[][capacity],int cen_x,int cen_y,int dim) {
	if (cen_x >= dim || cen_y >= dim || cen_x < 0 || cen_y < 0) {
		return false;
	}
	
	if (B[cen_y][cen_x] != '_') {
		return false;
	
	}
	return true;
}
void print_grid(char brd[][capacity], int dim) {
	system("cls");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << brd[i][j];

		}
		cout << endl;
	}



}
// This only gets the rows and cols where the players wants to put his sigh
void get_move(char B[][capacity],int& cen_x, int& cen_y, char aik_name, int dim) {
	
	do {
		cout << aik_name << " 's move\n\n";
		cout << "Enter your row b/w 1 and " << dim << endl;
		cin >> cen_y;
		// deducting one kionka index number 0 sa shoru hota ha mgr player 1 sa moves dala ga
		cen_y--;
		cout << "Enter your column b/w 1 and " << dim << endl;
		cin >> cen_x;
		// deducting one kionka index number 0 sa shoru hota ha mgr player 1 sa moves dala ga
		cen_x--;
	} while (!is_valid(B, cen_x, cen_y,dim));
}

void move_placer(char B[][capacity], int cen_x, int cen_y, char sym) {
	B[cen_y][cen_x] = sym;
}

bool win_condition_checker(char B[][capacity], int cen_x, int cen_y, int dim, int Win_num, char sym) {
	int count = 0;
	int i = 0, j = 0,k=0;
	    // Checking sides for Winning condition
			  // From point to right
	for (i = cen_x,j=0; j < Win_num && i < dim;j++, i++) {
		if (B[cen_y][i] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	count = 0;
	// From point to left
	for (i = cen_x, j = 0; j < Win_num && i >= 0; j++, i--) {
		if (B[cen_y][i] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	count = 0;
	// From point to down
	for ( i = cen_y,j=0; j < Win_num && i < dim; i++,j++) {
		if (B[i][cen_x] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num ) {
		return true;
	}
	count = 0;
	// From point to up
	for (i = cen_y, j = 0; j < Win_num && i >= 0; j++, i--) {
		if (B[i][cen_x] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	count = 0;

	// Checking diagnols for Winning condition
		// From point to bottom right corner
	for (i = cen_x, j = cen_y, k = 0; i < dim && j < dim && k < Win_num; i++, j++, k++) {
		if (B[j][i] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	count = 0;
	// From point to bottom left corner
	for ( i = cen_x, j = cen_y, k = 0; i >= 0 && j < dim && k < Win_num; i--, j++, k++) {
		if (B[j][i] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	count = 0;
	// From point to top right corner
	for ( i = cen_x, j = cen_y, k = 0; i < dim && j >= 0 && k < Win_num; i++, j--, k++) {
		if (B[j][i] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	count = 0;
	// From point to top left corner
	for (i = cen_x, j = cen_y, k = 0; i >= 0 && j >= 0 && k < Win_num; i--, j--, k++) {
		if (B[j][i] == sym) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == Win_num) {
		return true;
	}
	
	return false;


}
void computer_move(char B[][capacity],int dim,int &P_x, int& P_y,char P_sym,char H_sym,int Win_num) {
	int Win = Win_num;
	
	
		// This loop is for checking winning condition with respect to computer's symbol
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				P_y = i;
				P_x = j;
				if (is_valid(B, P_x, P_y, dim)) {
					B[P_y][P_x] = P_sym;
					bool x = win_condition_checker(B, P_x, P_y, dim, Win_num, P_sym);
					if (x == true) {
						B[P_y][P_x] = '_';
						return;
					}
					else {
						B[P_y][P_x] = '_';
					}

				}

			}
		}
	
	// This loop is for checking winning condition with respect to Human's symbol
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			P_y = i; // Now these are coordinates of human
			P_x = j;
			if (is_valid(B, P_x, P_y, dim)) {
				B[P_y][P_x] = H_sym;
				bool y = win_condition_checker(B, P_x, P_y, dim, Win_num, H_sym);
				if (y == true) {
					B[P_y][P_x] = '_';
					return ;
				}
				else {
					B[P_y][P_x] = '_';
				}

			}

		}
	}
	
	do{
		
		P_y = rand() % dim;
		P_x = rand() % dim;


	} while (!is_valid(B, P_x, P_y, dim));
	return;
}

int main()
{
	srand(time(0));
	char brd[capacity][capacity], Sym[capacity], Pla_name[capacity];
	int dim = 0, Turn = 0, nop = 0, cen_x, cen_y, Win_num;
	int Win_confirm = 0, Draw_confirm = 0;
	string mode;
	cout << "You want to play '1v1' or '1vC'... C stands for computer" << endl;
	cin >> mode;
	
	input(brd, Sym, dim, Pla_name, nop, Turn, Win_num,mode);
	cout << endl << endl;
	print_grid(brd, dim);
	cout << endl << endl;
	while (Draw_confirm != dim * dim) { // The board has dim x dim cells so when they are full it will break the loop
		
		if (mode == "1v1") {
			do {
				get_move(brd, cen_x, cen_y, Pla_name[Turn], dim);
			} while (cen_x >= dim || cen_y >= dim || cen_x < 0 || cen_y < 0);
		}
		
		if (mode == "1vC") {
			if (Turn == 0) {
				do {
					get_move(brd, cen_x, cen_y, Pla_name[Turn], dim);
				} while (cen_x >= dim || cen_y >= dim || cen_x < 0 || cen_y < 0);
			}
			if (Turn == 1) {
				computer_move(brd, dim, cen_x, cen_y, Sym[1], Sym[0], Win_num);


			}
		}

		move_placer(brd, cen_x, cen_y, Sym[Turn]);
		cout << endl << endl;
		print_grid(brd, dim);
		cout << endl << endl;
		bool x = win_condition_checker(brd, cen_x, cen_y, dim, Win_num, Sym[Turn]);
		if (x == true) {
			Win_confirm = 1;
			break;
		}
		Turn = (Turn + 1) % nop;
		Draw_confirm++;
	}
	if (Win_confirm == 1) {
		cout << "Player '" << Pla_name[Turn] << "' has won" << endl;
	}
	else {
		cout << "It is a draw";

	}

}