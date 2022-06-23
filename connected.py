#!/usr/bin/env python
 
import numpy as np
from numpy import loadtxt
import networkx as nx

r=1500
s=1


for g in np.arange(1,r+1,s):

	G=nx.read_edgelist('graph_g{}.edgelist'.format(g), nodetype=int, create_using=nx.DiGraph())
	
	print(nx.is_strongly_connected(G))
	
	#print(nx.is_weakly_connected(G))
