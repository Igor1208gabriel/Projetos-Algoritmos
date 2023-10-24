for i in range (1, 10001):
    f = open(f'teste{i:010d}.txt', 'w')

    x = i
    f.write(str(x) + "\n")
    for j in range(x):
        f.write(str(j) + "\n")
print("DONE")