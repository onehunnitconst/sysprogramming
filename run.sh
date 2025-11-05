#!/bin/bash

FILENAME=$1

gcc -o ${FILENAME}.out ${FILENAME}.c
./${FILENAME}.out
rm -r ${FILENAME}.out