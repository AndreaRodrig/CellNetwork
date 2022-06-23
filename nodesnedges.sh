#!/bin/bash

for((i=1;i<1501;i++))
do
	./nodes x0_$i.dat graph_g$i.edgelist_copy 250 > nodes_g$i.dat
	./edges x0_$i.dat graph_g$i.edgelist_copy 250 > edges_g$i.dat
done
