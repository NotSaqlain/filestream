#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int array[20];

    ifstream file("input.txt");
    if(!file) {
        cout << "File not found";
        return 1;
    }

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        file >> array[i];
    }

    file.close();
    
    ofstream output("output.txt");

    output << "Random Nums:" << endl;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        output << array[i] << " | ";
    }
    output << "\n" << endl;

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        for (int j = i + 1; j < sizeof(array) / sizeof(array[0]); j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
    int min, max;
    int somma = 0;
    min = max = array[0];
    for (int i = 1; i < sizeof(array) / sizeof(array[0]); i++) {
        somma += array[i];
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }    

    output << "SOMMA: " << somma << endl;
    output << "MIN: " << min << endl;
    output << "MAX: " << max << "\n" << endl;


    output << "sorted:" << endl;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        output << array[i] << " | ";
    }

    output.close();

    cout << "Check Output.txt for results!" << endl;
    return 0;
}