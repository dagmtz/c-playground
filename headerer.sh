#! /bin/bash

HEADER="header.c"
TMP=".header"

if [[ $# -eq 0 ]] ; then
    echo 'No input files provided, expected one file.'
    exit 1
elif [[ $# -gt 1 ]] ; then
    echo 'Too many input files, expected one file.'
    exit 1
fi

    MODIFIED=$(date -r $1)

# find . -type f  -name main.c -exec ./headerer.sh  {} \;

cp $HEADER $TMP
echo sed -i "s/$__NAME__/$1/g" $TMP
echo sed -i "s/$__NAME__/$1/g" $TMP