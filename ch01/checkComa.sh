#!/bin/bash

rm -f tmpFred
if [ -f tmpFred ]
then
    :
else
    echo file fred did not exist
    echo "make new one "
    touch tmpFred
fi

exit 0
