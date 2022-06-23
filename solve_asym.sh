#!/bin/bash

for ((i=378;i<390;i++))
do
	./solve_asym_sumR $i $i 0 80000 0 > sumR_xm04_g$i.dat
done

for ((i=378;i<390;i++))
do
	cp sumR_xm04_g$i.dat sumR_xm04_g$i.dat.tmp
	sed '$ d' sumR_xm04_g$i.dat.tmp > sumR_xm04_g$i.dat
	rm -f sumR_xm04_g$i.dat.tmp
done
