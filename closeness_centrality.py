#!/usr/bin/env python

import networkx as nx
import numpy as np

r=388
s=1

for g in np.arange(379,r+1,s):

	f=open('closeness_centrality_g{}.dat'.format(g), 'w')

	G=nx.read_edgelist('graph_g{}.edgelist'.format(g),nodetype=int,create_using=nx.DiGraph())

	for i in sorted(G.nodes()):
		f.write('{0}\t{1}\n'.format(i,nx.closeness_centrality(G.reverse(),i)))
	
