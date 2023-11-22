#!/bin/bash

RED='\033[0;31m'
GRN='\033[0;32m'
NOC='\033[0m'

TEST=$(ls -R  >&1)
RESULT=$(./uls -R  >&1)

if [[ $RESULT == $TEST ]]
then
  printf "${GRN}✔️ SUCCESS ${NOC}test -R\n"
else
  printf "${RED}✖️ FAILURE ${NOC}test -R\n"
fi
