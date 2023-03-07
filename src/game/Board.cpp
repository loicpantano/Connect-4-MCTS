
#include "../../include/game/Board.hpp"

#include <ostream>


//constructor
Board::Board(){
	reset();
}

bool Board::isFull() const
{
	bool full = true;
	for (std::array<Color, height> tmp : board)
		if(tmp.at(height-1) == NO) full = false;
	return full;
}

bool Board::placeJeton(int column, Color color)
{
	if(column < 0 || column > width - 1) return false;

	for (int i = 0; i < height; i++)
	{
		auto& tmp = board[column];
		if(board.at(column).at(i) == NO)
		{
			board.at(column).at(i) = color;
			return true;
		}
	}
	return false;
}

void Board::reset()
{
	    for (auto& row : this->board)
        row.fill(NO);
}

bool Board::checkWin()
{
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			if(board.at(i).at(j) != NO){
				if(i < width - 3){
					if(board.at(i).at(j) == board.at(i+1).at(j) && board.at(i).at(j) == board.at(i+2).at(j) && board.at(i).at(j) == board.at(i+3).at(j))
						return true;
				}
				if(j < height - 3)
				{
					if(board.at(i).at(j) == board.at(i).at(j+1) && board.at(i).at(j) == board.at(i).at(j+2) && board.at(i).at(j) == board.at(i).at(j+3))
						return true;
				}
				if(i < width - 3 && j < height - 3)
				{
					if(board.at(i).at(j) == board.at(i+1).at(j+1) && board.at(i).at(j) == board.at(i+2).at(j+2) && board.at(i).at(j) == board.at(i+3).at(j+3))
						return true;
				}
				if(i < width - 3 && j > 2)
				{
					if(board.at(i).at(j) == board.at(i+1).at(j-1) && board.at(i).at(j) == board.at(i+2).at(j-2) && board.at(i).at(j) == board.at(i+3).at(j-3))
						return true;
				}
			}
		}
	}
	return false;
}




std::ostream& operator<<(std::ostream& os, const Board& obj)
{
	os << "Board:" << std::endl;
	for(int i = Board::height - 1; i >= 0; i--)
	{
		for(int j = 0; j < Board::width; j++)
		{
			Color c = obj.board.at(j).at(i);
			switch (c)
			{
				case RED:
					os << "R ";
					break;
				case YELLOW:
					os << "Y ";
					break;
				default:
					os << "_ ";
					break;
			}
		}
		os << std::endl;
	}

	return os;
}

bool Board::isTerminal() {
    return isFull() || checkWin();
}
