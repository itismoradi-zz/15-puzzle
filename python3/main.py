

from time import sleep


class Board:
    def __init__(self):
        self.board = [[1, 2, 3, 4],
                      [5, 6, 7, 8],
                      [9, 10, 11, 12],
                      [13, 14, 15, '  ']]

    def swap_up(self, x, y):
        if x > 0 and y > 0:
            self.board[x][y], self.board[x - 1][y] = self.board[x - 1][y], self.board[x][y]
        return self.board
    
    def swap_down(self, x, y):
        if y < 3:
            self.swap_up(x, y+1)
        
    def swap_left(self, x, y):
        self.board[x][y], self.board[x][y - 1] = self.board[x][y - 1], self.board[x][y]
        return self.board
    
    def swap_right(self, x, y):
        if x < 3:
            self.swap_left(x+1, y)
        
    def shuffle(self):
        from random import randint, choice
        for i in range(100):
            func = choice([self.swap_up, self.swap_down, self.swap_left, self.swap_right])
            func(randint(0, 3), randint(0, 3))
        return self.board
    
    def display(self):
        length_of_table = 21
        from os import system
        system(command='cls')
        for i in range(4):
            print('-' * length_of_table)
            for j in range(4):
                print(f'|  {self.board[i][j]} ' if (
                    self.board[i][j] is not '  ' and self.board[i][j] < 10) else f'| {self.board[i][j]} ', end='')
            print('|')
        print('-' * length_of_table)
    def find_empty(self):
        for row in range(4):
            if '  ' in self.board[row]:
                return row, self.board[row].index('  ')

def move(b, direction):
    x, y = b.find_empty()
    dirs = {'w': b.swap_up, 's': b.swap_down, 'a': b.swap_left, 'd': b.swap_right}
    dirs[direction](x, y)
    
b = Board()
b.shuffle()
b.display()
move(b, 'w')
sleep(2)
b.display()