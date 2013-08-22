#!/bin/sh

test=$(cat $1 | grep -E -n ' $');

echo $test;
