#!/bin/bash

#if [ -f .profile ] && exit 0 || exit 1
if [ -f .profile ] && echo 0 || echo 1
then
    :
fi

exit 0
