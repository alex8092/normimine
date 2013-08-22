#!/bin/sh

echo "lancement du script de check des espaces et tabulations : "$0
echo "=> Test sur le fichier : "$1

finds_spaces=`cat $1 | grep -nE "( |	)$"`
find_space_tab=$finds_spaces
len_find_spaces=$(echo $fins_spaces | wc -l)

echo $len_find_spaces

if [ $len_find_spaces -gt 0 ]; then
	echo ""
	for index in `cat $1`; do
		echo $index
	done
fi
