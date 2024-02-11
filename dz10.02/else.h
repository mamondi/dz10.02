#include <iostream>
#include <vector>

using namespace std;

class Train {
private:
    int number;
    string departureTime;
    string destinationStation;

public:
    Train() {}
    Train(int number, string departureTime, string destinationStation) {
        this->number = number;
        this->departureTime = departureTime;
        this->destinationStation = destinationStation;
    }

    void setNumber(int number) { this->number = number; }
    int getNumber() { return number; }

    void setDepartureTime(string departureTime) { this->departureTime = departureTime; }
    string getDepartureTime() { return departureTime; }

    void setDestinationStation(string destinationStation) { this->destinationStation = destinationStation; }
    string getDestinationStation() { return destinationStation; }

    void printInfo() {
        cout << "Train number: " << number << endl;
        cout << "Departure time: " << departureTime << endl;
        cout << "Destination station: " << destinationStation << endl;
    }
};

class RailwayStation {
private:
    vector<Train> trains;

public:
    void addTrain(Train train) { trains.push_back(train); }

    void printAllTrains() {
        for (Train train : trains) {
            train.printInfo();
            cout << endl;
        }
    }

    void printTrainByNumber(int number) {
        bool found = false;
        for (Train train : trains) {
            if (train.getNumber() == number) {
                train.printInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found." << endl;
        }
    }
};