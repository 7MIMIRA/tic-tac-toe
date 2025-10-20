#include <vector>
#include <string>
#include "functions.h"

int main() {
	std::string game_status = "in_progress"; // "wins_x", "wins_o", "tie" , "in_progress"
	std::vector<std::vector<char>> board = {
		{'-', '-', '-'},
		{'-', '-', '-'},
		{'-', '-', '-'}
	};
	bool player_1_turn = true;

	begin_game();
	display_game_state(board);

	while (game_status == "in_progress") {
		get_player_input(player_1_turn, board);
		display_game_state(board);
		check_for_winner(board, game_status);
	}

	end_game(game_status);
}
