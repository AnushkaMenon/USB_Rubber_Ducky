#! /bin/sh

while :
do
    nc 192.168.20.5 1234 < logged_text.txt
    sleep 30
done