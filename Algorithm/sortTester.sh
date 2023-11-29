#!/bin/bash

# Linux
echo -n "1. Positive test : "
$1 `seq 0 0 | shuf | tr "\n" " "`
$1 `seq 0 2 | shuf | tr "\n" " "`
$1 `seq 1 100 | shuf | tr "\n" " "`
$1 `seq 1 100000 | shuf | tr "\n" " "`
$1 `seq 2147480000 2147483647 | shuf | tr "\n" " "`
for _ in {1..50}; do
	$1 `shuf -i 1-10000000 -n 1000 | tr "\n" " "`
done
echo ""

echo -n "2. Negative test : "
$1 `seq -1 -1 | shuf | tr "\n" " "`
$1 `seq -2 0 | shuf | tr "\n" " "`
$1 `seq -100 -1 | shuf | tr "\n" " "`
$1 `seq -99999 -1 | shuf | tr "\n" " "`
$1 `seq -2147483648 -2147473648 | shuf | tr "\n" " "`
for _ in {1..50}; do
	$1 `shuf -i 1-10000000 -n 1000 | tr "\n" "_" | sed 's/_/ -/g'`
done
echo ""

echo -n "3. Integer test : "
$1 `seq -1 1 | shuf | tr "\n" " "`
$1 `seq -3 2 | shuf | tr "\n" " "`
$1 `seq -100 100 | shuf | tr "\n" " "`
$1 `seq -33121 32451 | shuf | tr "\n" " "`
$1 `seq -3 123123 | shuf | tr "\n" " "`
$1 `seq -112312 6 | shuf | tr "\n" " "`
for _ in {1..50}; do
	$1 `shuf -i 1-10000000 -n 1000 | tr "\n" " "` `shuf -i 1-10000000 -n 1000 | tr "\n" "_" | sed 's/_/ -/g'`
done
echo ""