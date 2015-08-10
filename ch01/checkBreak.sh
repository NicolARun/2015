#!/bin/bash

rm -rf tmpFred*
echo > tmpFred1
echo > tmpFred2
mkdir tmpFred3
echo > tmpFred4

for file in tmpFred*
do
    if [ -d "$file" ]
    then
        break;
    fi
done

echo first directory starting tmpFred was $file
rm -rf tmpFred*

exit 0
