#!/bin/bash

for ((i=378;i<390;i++))
do
	./dif x0_moretime_g$i.dat x0_moretime_xm04_g$i.dat $i 1000
done

