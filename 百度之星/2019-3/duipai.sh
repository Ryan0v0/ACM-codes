#!/bin/bash
while true; do
./data > data.txt
./std < data.txt
./me < data.txt
if diff me.txt std.txt; then
printf AC
else
echo WA
exit 0
fi
sleep 1
done
