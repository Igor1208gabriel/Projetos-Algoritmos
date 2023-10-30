from random import randint as rd
for i in range (1, 101):
    f = open(f'teste{i:02d}.txt', 'w')

    f.write(f"{i*100}\n")
    for j in range(i*100):
        f.write(f"{i}\n")
print("DONE")