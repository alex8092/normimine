#!/bin/sh

echo '';
cat $1 | grep -E -n ' $' | xargs echo;
echo "## Espace en fin de ligne ##\n";
cat $1 | grep -E -n '	$' | xargs echo;
echo "## Tab en fin de ligne ##\n";
