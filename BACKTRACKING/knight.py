import copy
def display(mat):
    for row in mat:
        print(row)
    print('----------')

initial=[
    ['.','W','.','.'],
    ['.','-','-','.'],
    ['.','-','W','-'],
    ['B','-','B','-']
]

directions=[[2,1],[2,-1],[-2,1],[1,2],[1,-2],[-1,2],[-2,-1],[-1,-2]]

final=[
    ['.','B','.','.'],
    ['.','-','-','.'],
    ['.','-','B','-'],
    ['W','-','W','-']
]
#display(initial)
#display(final)

def is_safe(grid,nx,ny):
    if nx<0 or ny<0 or nx>=4 or ny>=4 or grid[nx][ny]=='.' or grid[nx][ny]=='B' or grid[nx][ny]=='W':
        return False
    return True

state=set()


def state_to_string(grid):
    string=""
    for row in grid:
        for charc in row:
            string+=charc
    return string

#state.add(state_to_string(initial))
#def backtrack()

#print(state_to_string(initial))
path=[]
result=[]

def backtrack(curr,path,result):
    #display(curr)
    #print(state)
    if state_to_string(curr) not in state:
        state.add(state_to_string(curr))
        if state_to_string(curr)==state_to_string(final):
            result[:]=copy.deepcopy(path)
            return True
        else:
            for i in range(4):
                for j in range(4):
                    if curr[i][j]=='W' or curr[i][j]=='B':
                        x,y=i,j
                        for dx,dy in directions:
                            nx,ny=x+dx,y+dy
                            if is_safe(curr,nx,ny):
                                temp=curr[i][j]
                                curr[nx][ny]=curr[i][j]
                                curr[i][j]='-'
                                path.append(copy.deepcopy(curr))
                                if backtrack(curr,path,result):
                                    return True
                                path.pop()
                                curr[nx][ny]='-'
                                curr[i][j]=temp
    else:
        return False
                                
    
print(backtrack(initial,path,result))
print(len(result))
#print(len(set(map(tuple,result)))==len(result))
for matrix in result:
    display(matrix)

