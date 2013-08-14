#!/bin/sh
echo ""

cat $1 | grep -E -n "(if|while|else if)[^ ]*" | xargs echo; echo "## Espace qui manque avant '(' ##";

