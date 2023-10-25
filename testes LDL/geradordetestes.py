from random import randint as rd
for i in range (1, 11):
    f = open(f'teste{i:02d}.txt', 'w')

    f.write("1000" + "\n")
    for j in range(500):
        f.write(f"{rd(10000, 100000)}\n")
print("DONE")