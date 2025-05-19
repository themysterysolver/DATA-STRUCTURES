import matplotlib.pyplot as plt
if __name__=="__main__":
    print('THE KNIGHT TOUR PROBLEM')
    print('computing........')
    path=[]
    start=(0,0)
    visited=set()
    board_size=7

    def knight_moves(cell,visited,board_size):
        pos=[]
        x,y=cell
        directions=[(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]
        for dx,dy in directions:
            nx,ny=x+dx,y+dy
            if nx<0 or ny<0 or nx>=board_size or ny>=board_size or (nx,ny) in visited:
                continue
            else:
                pos.append((nx,ny))
        return pos
    
    def backtrack(curr):
        path.append(curr)
        visited.add(curr)
        if len(path) == board_size*board_size:
            return True
        for new in knight_moves(curr,visited,board_size):
            if backtrack(new):
                return True
        visited.remove(curr)
        path.pop()
        return False
    def visualise(path, board_size):
        fig, ax = plt.subplots()
        ax.set_xlim(-0.5, board_size - 0.5)
        ax.set_ylim(-0.5, board_size - 0.5)
        ax.set_xticks([])
        ax.set_yticks([])
        ax.invert_yaxis()

        # Draw chessboard squares
        for i in range(board_size):
            for j in range(board_size):
                color = 'lightgray' if (i + j) % 2 == 0 else 'white'
                ax.add_patch(plt.Rectangle((j - 0.5, i - 0.5), 1, 1, color=color))

        for i in range(len(path) - 1):
            x1, y1 = path[i][1], path[i][0]
            x2, y2 = path[i + 1][1], path[i + 1][0]
            ax.annotate("",
                        xy=(x2, y2),
                        xytext=(x1, y1),
                        arrowprops=dict(arrowstyle="->", color='blue', lw=2))

        for idx, (x, y) in enumerate(path):
            ax.text(y, x, str(idx + 1), ha='center', va='center', fontsize=8, color='black')

        plt.title("Knight's Tour with Arrows")
        plt.show()

    if backtrack(start):
        board=[[-1]*board_size for _ in range(board_size)]
        for idx,(x,y) in enumerate(path):
            board[x][y]=idx+1
        for row in board:
            print(row)
        visualise(path, board_size)
    else:
        print("No path exist")
