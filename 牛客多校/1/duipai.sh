#!/bin/bash
while true; do
./data > data.txt
./force < data.txt
./me < data.txt
if diff me.txt force.txt; then
printf AC
else
echo WA
exit 0
fi
sleep 1
done
