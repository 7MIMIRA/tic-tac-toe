#include <vector>
#include <string>

void begin_game();
void display_game_state(std::vector<std::vector<char>>);
void get_player_input(bool&, std::vector<std::vector<char>>&);
void check_for_winner(std::vector<std::vector<char>>, std::string&);
void end_game(std::string);
