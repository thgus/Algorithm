import queue

n,m,v=map(int,input().split());

arr=[[0 for i in range(n+1)] for i in range(n+1)];

for i in range(m):
 a,b=map(int,input().split());
 arr[a][b]=1;
 arr[b][a]=1;

dfs_visited=[0 for i in range(n+1)];
def dfs(s):
  print(str(s),end=" ");
  for i in range(n+1):
    if arr[s][i]==0:
      continue;

    if dfs_visited[i]==0:
      dfs_visited[i]=1;
      dfs(i);

dfs_visited[v]=1;
dfs(v);
print();

bfs_visited=[0 for i in range(n+1)];
bfs_visited[v]=1;

q = queue.Queue()
q.put(v);

while  (not q.empty()):
  s=q.get();
  print(str(s),end=" ");
  for i in range(n+1):
    if arr[s][i]==0:
      continue;

    if bfs_visited[i]==0:
      bfs_visited[i]=1;
      q.put(i);
  
    
