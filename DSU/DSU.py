class DSU:
    def __init__(self,n):
        self.parent=[i for i in range(n)]
        self.rank=[0]*n
    def find(self,x):
        if x!=self.parent[x]:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    def union(self,x,y):
        par_x=self.find(x)
        par_y=self.find(y)
        if par_x==par_y:
            return
        elif self.rank[par_x]<self.rank[par_y]:
            self.parent[par_x]=par_y
        elif self.rank[par_y]<self.rank[par_x]:
            self.parent[par_y]=par_x
        else:
            self.parent[par_y]=par_x
            self.rank[par_x]+=1
