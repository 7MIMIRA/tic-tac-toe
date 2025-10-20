#include <iostream>
#include <vector>
#include <string>

void begin_game() {
	std::cout << "*********************" << std::endl;
	std::cout << "**** TIC-TAC-TOE ****" << std::endl;
	std::cout << "*********************" << std::endl;
}

void display_game_state(std::vector<std::vector<char>> board) {
	std::vector<char> row1 = board[0];
	std::vector<char> row2 = board[1];
	std::vector<char> row3 = board[2];

	std::cout << std::endl;
	std::cout << "      " << row1[0] << " | " << row1[1] << " | " << row1[2] << std::endl;
	std::cout << "      " << row2[0] << " | " << row2[1] << " | " << row2[2] << std::endl;
	std::cout << "      " << row3[0] << " | " << row3[1] << " | " << row3[2] << std::endl;
	std::cout << std::endl;
}

bool selection_is_invalid(std::string selection) {
	// check if values are just out of range for the tic-tac-toe board
	int row = selection[0] - '0'; // c++ magic to get int 0-9 from chars '0' - '9'
	int col = selection[1] - '0'; // c++ magic to get int 0-9 from chars '0' - '9'
	if (row < 0 || row > 2 || col < 0 || col > 2) {
		return true;
	}
	return false;
}

bool selection_is_unavailable(std::string selection, std::vector<std::vector<char>> board) {
	int row = selection[0] - '0'; // c++ magic to get int 0-9 from chars '0' - '9'
	int col = selection[1] - '0'; // c++ magic to get int 0-9 from chars '0' - '9'
	if (board[row][col] != '-') {
		return true;
	}
	return false;
}

void get_player_input(bool& player_1_turn, std::vector<std::vector<char>>& board) {
	std::string player_number = player_1_turn ? "1" : "2";
	char token = player_1_turn ? 'x' : 'o';
	bool valid_selection_made = false;
	int row;
	int col;

	while (!valid_selection_made) {
		std::string selection;
		std::cout << "Player " << player_number << ", where would you like to place an " << token << ": ";
		std::cin >> selection;

		if (selection_is_invalid(selection)) {
			std::cout << "Invalid selection. Try again.." << std::endl;
			display_game_state(board);
			continue;
		}

		if (selection_is_unavailable(selection, board)) {
			std::cout << "Spot is already taken. Try again.." << std::endl;
			display_game_state(board);
			continue;
		}

		row = selection[0] - '0'; // c++ magic to get int 0-9 from chars '0' - '9'
		col = selection[1] - '0'; // c++ magic to get int 0-9 from chars '0' - '9'
		valid_selection_made = true;
	}

	player_1_turn = !player_1_turn;
	board[row][col] = token;
}

bool characters_are_the_same(char char_1, char char_2, char char_3) {
	if (char_1 == char_2 && char_2 == char_3) {
		return true;
	}
	return false;
}

void check_for_winner(std::vector<std::vector<char>> board, std::string& game_status) {
	// check for tie
	int taken_spaces = 0;
	for (std::vector<char> row : board) {
		for (char current_token : row) {
			if (current_token != '-') {
				taken_spaces ++;
			}
		}
	}
	if (taken_spaces == 9) {
		game_status = "tie";
		return;
	}

	std::string wins_ = "wins_";
	// check rows
	for (std::vector<char> row : board) {
		if (characters_are_the_same(row[0], row[1], row[2]) == true && row[0] != '-') {
			game_status = wins_ += row[0];
			return;
		}
	}

	// check columns
	for (int i = 0; i < 3; i++) {
		if (characters_are_the_same(board[0][i], board[1][i], board[2][i]) == true && board[0][i] != '-') {
			game_status = wins_ += board[0][i];
			return;
		}
	}

	// check major diagonal
	if (characters_are_the_same(board[0][0], board[1][1], board[2][2]) == true && board[1][1] != '-') {
		game_status = wins_ += board[1][1];
		return;
	}

	// check lesser diagonal
	if (characters_are_the_same(board[2][0], board[1][1], board[0][2]) == true && board[1][1] != '-') {
		game_status = wins_ += board[1][1];
		return;
	}

	game_status = "in_progress";
	return;
}

void end_game(std::string game_status) {
	if (game_status == "tie") {
		std::cout << "~~~~~ Game Over ~~~~~" << std::endl;
		std::cout << "         Tie" << std::endl;
		return;
	}
	std::string winner = game_status == "wins_x" ? "Player 1" : "Player 2";
	std::cout << "~~~~~ Game Over ~~~~~" << std::endl;
	std::cout << "Winner:      "<< winner << std::endl;
}
