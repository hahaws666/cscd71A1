#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

struct Point {
    double x, y, z;
};

vector<Point> readData(const string& filename) {
    vector<Point> points;
    ifstream fin(filename);
    
    if (!fin.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return points;
    }
    
    double x, y, z;
    while (fin >> x >> y >> z) {
        points.push_back({x, y, z});
    }
    
    fin.close();
    return points;
}

void generateGnuplotScript(const vector<Point>& points) {
    ofstream script("plot_script.gp");
    
    script << "set terminal png size 1200,800\n";
    script << "set output 'lissajous_plot.png'\n";
    script << "set title 'Lissajous Curve: sin(2x) vs cos(3x)' font ',16'\n";
    script << "set xlabel 'sin(2x)' font ',12'\n";
    script << "set ylabel 'cos(3x)' font ',12'\n";
    script << "set grid\n";
    script << "set size ratio -1\n";
    script << "set xrange [-1.1:1.1]\n";
    script << "set yrange [-1.1:1.1]\n";
    
    // Write data to temporary file
    ofstream dataFile("temp_data.txt");
    for (const auto& point : points) {
        dataFile << point.y << " " << point.z << "\n";
    }
    dataFile.close();
    
    script << "plot 'temp_data.txt' with linespoints pointtype 7 pointsize 0.5 linecolor rgb 'blue' title 'Lissajous Curve'\n";
    script << "pause -1\n";
    
    script.close();
}

void generateSimplePlot(const vector<Point>& points) {
    cout << "\n=== Lissajous Curve Data ===\n";
    cout << "x\t\tsin(2x)\t\tcos(3x)\n";
    cout << "----------------------------------------\n";
    
    for (size_t i = 0; i < points.size(); i += 5) { // Print every 5th point
        cout << fixed << setprecision(3) 
             << points[i].x << "\t\t" 
             << points[i].y << "\t\t" 
             << points[i].z << "\n";
    }
    
    cout << "\n=== Summary Statistics ===\n";
    cout << "Total points: " << points.size() << "\n";
    cout << "X range: [" << points.front().x << ", " << points.back().x << "]\n";
    
    // Find min/max for y and z
    double min_y = points[0].y, max_y = points[0].y;
    double min_z = points[0].z, max_z = points[0].z;
    
    for (const auto& point : points) {
        if (point.y < min_y) min_y = point.y;
        if (point.y > max_y) max_y = point.y;
        if (point.z < min_z) min_z = point.z;
        if (point.z > max_z) max_z = point.z;
    }
    
    cout << "Y (sin(2x)) range: [" << min_y << ", " << max_y << "]\n";
    cout << "Z (cos(3x)) range: [" << min_z << ", " << max_z << "]\n";
}

int main() {
    string filename = "lissajous.txt";
    vector<Point> points = readData(filename);
    
    if (points.empty()) {
        cerr << "No data loaded. Make sure " << filename << " exists.\n";
        return 1;
    }
    
    cout << "Loaded " << points.size() << " data points from " << filename << "\n";
    
    // Generate simple text plot
    generateSimplePlot(points);
    
    // Generate gnuplot script
    generateGnuplotScript(points);
    cout << "\nGnuplot script generated as 'plot_script.gp'\n";
    cout << "To create the plot, run: gnuplot plot_script.gp\n";
    cout << "This will generate 'lissajous_plot.png'\n";
    
    return 0;
}
