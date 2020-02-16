class Player
{
public:
	string name,email;
//	static int new_uid;
	char mark;
	long long int uid;

	Player(string name, string email, char mark){
//		this->uid = Player::new_uid;
//        Player::new_uid++;
		this->name = name;
		this->email = email;
		this->mark = mark;
	}

	Move* makeMove(int row, int col){
		Move*move = new Move(row,col,mark);
		return move;
	}
	
};