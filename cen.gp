#!/bin/gnuplot
set term pngcairo
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
set ylabel 
set xlabel 


plot 'closeness_centrality_g379.dat'
replot 'closeness_centrality_nutg379.dat' linetype 7
set output 'closeness_cenN10001_g379.png'
replot
plot 'closeness_centrality_g380.dat'
replot 'closeness_centrality_nutg380.dat' linetype 7
set output 'closeness_cenN10001_g380.png'
replot
plot 'closeness_centrality_g381.dat'
replot 'closeness_centrality_nutg381.dat' linetype 7
set output 'closeness_cenN10001_g381.png'
replot
plot 'closeness_centrality_g382.dat'
replot 'closeness_centrality_nutg382.dat' linetype 7
set output 'closeness_cenN10001_g382.png'
replot
plot 'closeness_centrality_g383.dat'
replot 'closeness_centrality_nutg383.dat' linetype 7
set output 'closeness_cenN10001_g383.png'
replot
plot 'closeness_centrality_g384.dat'
replot 'closeness_centrality_nutg384.dat' linetype 7
set output 'closeness_cenN10001_g384.png'
replot
plot 'closeness_centrality_g385.dat'
replot 'closeness_centrality_nutg385.dat' linetype 7
set output 'closeness_cenN10001_g385.png'
replot
plot 'closeness_centrality_g386.dat'
replot 'closeness_centrality_nutg386.dat' linetype 7
set output 'closeness_cenN10001_g386.png'
replot
plot 'closeness_centrality_g387.dat'
replot 'closeness_centrality_nutg387.dat' linetype 7
set output 'closeness_cenN10001_g387.png'
replot
plot 'closeness_centrality_g388.dat'
replot 'closeness_centrality_nutg388.dat' linetype 7
set output 'closeness_cenN10001_g388.png'
replot
