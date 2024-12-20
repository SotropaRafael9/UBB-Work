board = [
    [7, 8, 0, 4, 0, 0, 1, 2, 0],
    [6, 0, 0, 0, 7, 5, 0, 0, 9],
    [0, 0, 0, 6, 0, 1, 0, 7, 8],
    [0, 0, 7, 0, 4, 0, 2, 6, 0],
    [9, 0, 4, 0, 6, 0, 0, 0, 5],
    [0, 7, 0, 3, 0, 0, 0, 1, 2],
    [1, 2, 0, 0, 0, 7, 4, 0, 0],
    [0, 4, 9, 2, 0, 6, 0, 0, 7]
]

def solve(board):
    #print(board)
    find  = search_empty(board)
    if not find:
        return True
    else:
        row,col=find
    
    for i in range (1, 10):
        if valid(board, i, (row, col)):
            board[row][col] = i

            if solve(board):
                return True

            board[row][col]= 0
    return False



def valid(board, number, position):

    # Check row
    for i in range (len(board[0])):
        if board[position[0]][i] == number and position[1] == i:
            return False

    # Check col
    for i in range (len(board)):
        if board[i][position[1]] == number and position[0] == i:
            return False
    
    box_x = position[1] // 3 # for exemple in the first 3 boxes we count as 1.0 , 1.1, 1.2 
    box_y = position[0] // 3 # same as first 0.1, 0.2, 0.3

    for i in range (box_x * 3, box_y * 3 + 3): # goes from position 1 to 3  
        for j in range (box_x * 3, box_y * 3 + 3):
            if board[i][j] == number and (i, j) != position:
                return False
    return True


def print_board(board):
    for i in range (len(board)):
        if i % 3 == 0 and i != 0:
            print ("- - - - - - - - - - - - ")

        for j in range (len(board[0])):
            if j % 3 == 0 and j != 0:
                print (" | ", end="")

            if j == 8:
                print (board[i][j])
            else:
                print(str(board[i][j])+ " ", end="")


def search_empty(board):

    for i in range (len(board)):
        for j in range (len(board)):
            if board[i][j] == 0:
                return (i, j) # row, col
    
    return None
    
solve(board)
print ("__________________________")
print_board(board)