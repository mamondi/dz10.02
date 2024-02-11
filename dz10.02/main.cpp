#include "else.h"

int main() {
    RailwayStation station;

    station.addTrain(Train(123, "10:00", "Kyiv"));
    station.addTrain(Train(456, "12:00", "Lviv"));
    station.addTrain(Train(789, "14:00", "Odesa"));

    cout << "All trains:" << endl;
    station.printAllTrains();

    cout << "Train with number 456:" << endl;
    station.printTrainByNumber(456);

    return 0;
}