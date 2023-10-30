#!/usr/bin/bash

# for j in $(seq 1 200)
# do
for i in teste*.txt
do
    echo "[INFO] Testing file $i"
    ./vetor < $i 2>> tabela.csv
done
#done