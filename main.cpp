#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/octagon.h"


using namespace std;


void removeFigure(Figure ** figures, int & count, int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    delete figures[index];
    for (int i = index; i < count - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    figures[count - 1] = nullptr;
    --count;
}

double totalArea(Figure ** figures, int count) {
    double areaSum = 0.0;
    for (int i = 0; i < count; ++i) {
        areaSum += static_cast<double>(*figures[i]);
    }
    return areaSum;
}

void displayAllFigures(Figure ** figures, int count) {
    cout << "\n\n\n=== SHAPE INFORMATION ===";

    for (int i = 0; i < count; ++i) {
        cout << "\n[ Figure #" << i + 1 << " ]\n";
        cout << "Points:\n" << *figures[i] << "\n"; 
        
        Point center = figures[i]->centre_figure();
        cout << "   Geometric center: (" << center.x << ", " << center.y << ")\n";
        
        double area = static_cast<double>(*figures[i]);
        cout << "   Area: " << area << "\n";
    }

    cout << "\nTOTAL AREA OF ALL FIGURES: " << totalArea(figures, count) << "\n";
}

void runProgram() {
    int shapeCounts[3];
    cout << "Enter number of pentagons: ";
    cin >> shapeCounts[0];

    cout << "Enter number of hexagons: ";
    cin >> shapeCounts[1];

    cout << "Enter number of octagons: ";
    cin >> shapeCounts[2];

    int totalFigures = shapeCounts[0] + shapeCounts[1] + shapeCounts[2];
    Figure ** figures = new Figure*[totalFigures];
    int currentIndex = 0;

    cout << "\n=== Enter pentagons (points in clockwise order) ===\n";
    for (int i = 0; i < shapeCounts[0]; ++i) {
        auto * p = new Pentagon();
        cin >> *p;
        figures[currentIndex++] = p;
    }

    cout << "\n=== Enter hexagons (points in clockwise order) ===\n";
    for (int i = 0; i < shapeCounts[1]; ++i) {
        auto * h = new Hexagon();
        cin >> *h;
        figures[currentIndex++] = h;
    }

    cout << "\n=== Enter octagons (points in clockwise order) ===\n";
    for (int i = 0; i < shapeCounts[2]; ++i) {
        auto * o = new Octagon();
        cin >> *o;
        figures[currentIndex++] = o;
    }

    displayAllFigures(figures, totalFigures);

    cout << "\n\n\nRemoving the figure at index 0...\n";
    removeFigure(figures, totalFigures, 0);

    displayAllFigures(figures, totalFigures);

    cout << "\n\n\n=== FIGURE COMPARISON RESULTS ===\n";
    for (int i = 0; i < totalFigures; ++i) {
        for (int j = 0; j < totalFigures; ++j) {
            cout << "Compare figure #" << i + 1 
                 << " with figure #" << j + 1 
                 << "   Result: " << ((*figures[i] == *figures[j]) ? "Equal" : "Different") 
                 << "\n";
        }
    }

    for (int i = 0; i < totalFigures; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

int main() {
    try {
        runProgram();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
