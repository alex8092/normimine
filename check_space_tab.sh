#!/bin/sh

search_space=$(cat $1 | grep -E -n ' $');
search_tab=$(cat $1 | grep -E -n '	$');
search_tab_count=$(echo $search_tab | wc -l);

for index in "$search_space"
do
	echo "in file : "$1" => "$index" <== Espace en trop en fin de ligne";
done

if [ "$search_tab_count" -gt "0" ]; then
	for index_bis in "$search_tab"
	do
		echo "in file : "$1" => "$index_bis" <== Tabulation en trop en fin de ligne";
	done
fi
