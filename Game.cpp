class Game
{
public:
	Board* board;
	Player *player1,*player2;
	string state;
	Result *result;
	vector<Move*> moves;
	bool isEnd = false;
	short turn = 1;

	Game(){
		this->board = new Board();
		this->state = "PLAYING";
		this->result = NULL;
	}

	void setState(string state){
		this->state = state;
	}

	void markMove(Move*move){
		this->moves.push_back(move);
		this->board->markOnBoard(move);
	}

	bool checkForWin(Player*winner, Player*loser){
		// check board for win 
		bool win = this->board->checkForBoardMatch();
		if(win){
			this->result = new Result(winner, loser);
			cout<<"Player "<<this->turn<<" has won the game...\n\n";
			this->state = "WIN";
			this->isEnd = true;
			return true;
		}


		if(this->moves.size() == this->board->size){ // Draw case
			this->result = new Result(NULL, NULL);
			cout<<"Match is draw..\n\n";
			this->state = "DRAW";
			this->isEnd = true;
			return true;
		}

		return false;
	}

};