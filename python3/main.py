

class Board:
    def __init__(self):
        self.board = [[1, 2, 3, 4],
                 [5, 6, 7, 8],
                 [9, 10, 11, 12],
                 [13, 14, 15, '  ']]

    def shuffle(self):
        1

    def swap(self, x, y, z, w):
        self.board[x][y], self.board[z][w] = self.board[z][w], self.board[x][y]
        return self.board
    
    def display(self):
        length_of_table = 21 
        from os import system
        system(command='cls')
        for i in range(4):
            print('-' * length_of_table)
            for j in range(4):
                print(f'|  {self.board[i][j]} ' if (self.board[i][j] is not '  ' and self.board[i][j] < 10) else f'| {self.board[i][j]} ', end='')
            print('|')
        print('-' * length_of_table)

b = Board()
b.display()