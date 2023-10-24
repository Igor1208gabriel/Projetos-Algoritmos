#!/usr/bin/bash

for i in teste*.txt
do
    echo "[INFO] Testing file $i"
    ./lista < $i 2>> tabela.csv
done