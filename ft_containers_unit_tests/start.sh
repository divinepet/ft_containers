#!/bin/bash

trap 'rm -f a.out test1 ; echo -e "\n"See "\033[1mlogs.txt\033[0m" for more information' EXIT
cd sources/system/
if [[ $1 = -m || $1 = --map ]]
then
  cat header
  clang++ map_run.cpp && ./a.out
elif [[ $1 = -v || $1 = --vector ]]
then
  cat header
  clang++ vector_run.cpp && ./a.out
elif [[ $1 = -s || $1 = --set ]]
then
  cat header
  echo set tests are unavalibe now
elif [[ $1 = '' ]]
then
  cat header
  echo full test will run
elif [[ $1 = --help || $1 = -h ]]
then
  echo -e "-v, --vector \t\t Run VECTOR tests\n" \
          "-m, --map \t\t Run MAP tests\n" \
          "-s, --set \t\t Run SET tests\n" \
          "Run ./start.sh without arguments to run ALL tests"
else
  echo Uknown command. Use --help or -h for command list
fi
rm -f a.out test1