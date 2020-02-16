#include<bits/stdc++.h>
using namespace std;

#include "Move.cpp"
#include "Board.cpp"
#include "Player.cpp"
#include "Result.cpp"
#include "Game.cpp"


Player* initializePlayer(){
	string name,email;
	char mark;

	cout<<"Enter Name : ";
	cin>>name;

	cout<<"Enter Email : ";
	cin>>email;

	cout<<"Enter single character Mark : ";
	cin>>mark;

	Player*player = new Player(name,email,mark);

	return player;
}

int main(){
	cout<<"Welcome to Tic-Tac-Toe\n\n";
	int gameCount = 0;

	while(1){
		string option;
		cout<<"Do you want to start a game? yes/no: ";
		cin>>option;
		if(option!="yes" && option !="YES"){
			cout<<"GoodBye\n";
			return 0;
		}

		Game *game = new Game();

	
		cout<<"Initializing Player1 : \n";
		Player*player1 = initializePlayer();

		cout<<"Initializing Player 2 : \n";
		Player*player2 = initializePlayer();

		cout<<"Initializing Board...\n\n";
		game->board->initialize();

		Player*currentPlayer = player1;
		Player*opPlayer = player2;

		while(!game->isEnd){
			int row,col;
			cout<<"Showing the current board : \n";
			game->board->showBoard();
			cout<<"Turn for Player "<<game->turn<<endl;
			cout<<"Enter Row (starting from 1) : ";
			cin>>row;
			cout<<"Enter Col (starting from 1) : ";
			cin>>col;

			if(game->board->isValidMove(row,col)){
                game->markMove(currentPlayer->makeMove(row,col));

                // check for win or draw
                game->checkForWin(currentPlayer, opPlayer);

                if(game->turn==1){
                    currentPlayer = player2;
                    opPlayer = player1;
                    game->turn = 2;
                }else{
                    currentPlayer = player1;
                    opPlayer = player2;
                    game->turn = 1;
                }
			}else{
			    cout<<"Invalid Move..\n\n";
			}
		}
	}
}