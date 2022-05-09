

from time import sleep


class Board:
    def __init__(self):
        self.board = [[1, 2, 3, 4],
                      [5, 6, 7, 8],
                      [9, 10, 11, 12],
                      [13, 14, 15, '  ']]

    def swap_up(self, x, y):
        if x != 0:
            self.board[x][y], self.board[x - 1][y] = self.board[x - 1][y], self.board[x][y]
            return True
        return False   
    def swap_down(self, x, y):
        if x < 3:
            self.board[x + 1][y], self.board[x][y] = self.board[x][y], self.board[x + 1][y]
            return True
        return False        
    def swap_left(self, x, y):
        if y != 0:
            self.board[x][y], self.board[x][y - 1] = self.board[x][y - 1], self.board[x][y]
            return True
        return False    
    def swap_right(self, x, y):
        if y < 3:
            self.board[x][y+1], self.board[x][y] = self.board[x][y], self.board[x][y+1]
            return True
        return False            
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
    dirs = {'s': b.swap_up, 'w': b.swap_down, 'd': b.swap_left, 'a': b.swap_right}
    try:
        x, y = b.find_empty()
        return dirs[direction](x, y)
    except KeyError:
        return False
def validate(b):
    return b.board == [[1, 2, 3, 4],
                      [5, 6, 7, 8],
                      [9, 10, 11, 12],
                      [13, 14, 15, '  ']]
def main():
    b = Board()
    b.shuffle()
    b.display()
    total_moves = 0
    while not validate(b):
        _inp = input('Enter direction: ')
        total_moves += move(b, _inp)
        b.display()
    print('You win!')
    print(f'Total moves: {total_moves}')
    
def random_solve():
    b = Board()
    b.shuffle()
    b.display()
    total_moves = 0
    import random
    while not validate(b) and total_moves < 100000:
        _inp = random.choice(['s', 'w', 'd', 'a'])
        total_moves += move(b, _inp)
        b.display()
    if total_moves < 100000:
        print('This puzzled solved by random moves!')
        print(f'Total moves: {total_moves}')
    else:
        print('You actually cannot solve this by random moves!')

main()
# random_solve()