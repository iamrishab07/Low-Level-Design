class Result
{
public:
	Player *winner, *loser;
	
	Result(Player*winner, Player*loser){
		this->winner = winner;
		this->loser = loser;
	}
	
};