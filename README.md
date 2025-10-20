# Tic Tac Toe
Terminal based two player Tic-Tac-Toe game written in C++  
<img src="./tic-tac-toe.svg" width="90%">  

## Building the project
### Clone the repository
Clone the repo using your preferred method.  
*I suggest using a method that works.*

### Compile
Run the following at the root of the project  
```bash
g++ *.cpp
```
*This compiles all available .cpp files in the directory and creates the `a.out` binary*

### Run
After compiling the project, execute the `a.out` binary that was created by running
```bash
./a.out
```

## How to play
When entering a spot to place an X or an O you must enter the row and column locations per the following graphic:  
|       | Col 1  | Col 2  | Col 3  |
| :---: | :----: | :----: | :----: |
| row 1 |   00   |   01   |   02   |
| row 2 |   10   |   11   |   12   |
| row 3 |   20   |   21   |   22   |

So if you want to place your piece on the top left you would enter in **00** when prompted.  
**11** would place it in the center.  
**20** would place it on the bottom left.  

The game currently handles row, column, major and minor diagonal win conditions for both players as well as ties.

## Possible Improvements:
- Update input to not require row/col selection
  - Possibly prefill open spots with characters so valid inputs could look like
 
  |       | Col 1 | Col 2 | Col 3 |
  | :---: | :---: | :---: | :---: |
  | row 1 |   a   |   b   |   c   |
  | row 2 |   d   |   e   |   f   |
  | row 3 |   g   |   h   |   i   |
