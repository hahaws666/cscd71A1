set terminal png size 1200,800
set output 'lissajous_plot.png'
set title 'Lissajous Curve: sin(2x) vs cos(3x)' font ',16'
set xlabel 'sin(2x)' font ',12'
set ylabel 'cos(3x)' font ',12'
set grid
set size ratio -1
set xrange [-1.1:1.1]
set yrange [-1.1:1.1]
plot 'temp_data.txt' with linespoints pointtype 7 pointsize 0.5 linecolor rgb 'blue' title 'Lissajous Curve'
pause -1
