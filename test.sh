#!/bin/bash

args=("julia" "juliaaa" "jusdf2" "julia a")
j="julia"
arg="$1"
if [ "$arg" = "$j" ]
then
	for i in ${args[@]}
	do
		echo $i
	done
else
	echo "Erro command"
fi
