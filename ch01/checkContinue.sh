#!/bin/bash

rm -rf tmpFred*
echo > tmpFred1
echo > tmpFred2
mkdir  tmpFred3
echo > tmpFred4

for file in tmpFred*
do
    if [ -d "$file" ]
    then
        echo "skipping directory $file"
        continue
    fi
    echo file is $file
done

rm -rf tmpFred*

exit 0
