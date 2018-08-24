import random

nodeCount = 10
edgeCount = 20

print (nodeCount, edgeCount)

edges = {}

while len(edges) < nodeCount:
    x = len(edges) + 1
    y = random.randint (1, nodeCount)
    if x == y: continue
    #comment the following line if the graph is directed
    if y < x: x, y = y, x
    w = random.randint(1, 100)
    edges [x, y] = w

while len(edges) < edgeCount:
    x = random.randint (1, nodeCount)
    y = random.randint (1, nodeCount)
    if x == y: continue
    #comment the following line if the graph is directed
    if y < x: x, y = y, x
    w = random.randint(1, 100)
    edges [x, y] = w

#just for debug
for (x, y), w in edges.items ():
    print ('{} {} {}'.format (x, y, w) )
