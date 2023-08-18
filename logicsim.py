#19D070029---Kartikeya Chandra:
#defining gates operations
def and_gat(x):
    ans = 1
    for i in x:
        ans = (ans and i)
    return ans

def or_gat(x):
    ans = 0
    for i in x:
        ans = (ans or i)
    return ans

def not_gate(x):
    ans = int(not x)
    return ans

def dfs(node, vect, adj, stop, funcs):
    if((funcs[node]=='i') or (stop[node])):
        return
    stop[node] = True
    inputs = []
    for i in adj[node]:
        dfs(i, vect, adj, stop, funcs)
        inputs.append(vect[i])
    if(funcs[node] == 'or'):
        vect[node] = or_gat(inputs)
    elif(funcs[node] == 'and'):
        vect[node] = and_gat(inputs)
    elif(funcs[node] == 'not'):
        vect[node] = not_gate(inputs[0])
    else:
        print("Incorrect character entered")
    return

(n,m) = map(int,input().split())
funcs = ['i' for i in range(m+n)]
vect = [int(i) for i in list(input())] + [0 for i in range(m)]
adj = [[] for i in range(m+n)]
inp_taken = [True for i in range(n)] + [False for i in range(m)]
for i in range(m):
    x = input().split()
    node = int(x[2])
    if inp_taken[node]:
        print('Incorrect Input givecten, pls try again')
        break
    inp_taken[node] = True
    funcs[node] = x[0]
    adj[node] = [int(i) for i in x[3:]]
stop = [False for i in range(n+m)]
for i in range(n+m-1,-1,-1):
    dfs(i,vect,adj,stop,funcs)
out_num = int(input())
nodes_out = [int(i) for i in input().split()]
for i in nodes_out:
    print(vect[i], end='')
