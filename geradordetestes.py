f = open('teste2.txt', 'w')
x = 1001
f.write(str(x) + "\n")
for i in range(x):
    f.write(str(i) + " " + str(i) + "\n")
print("DONE")