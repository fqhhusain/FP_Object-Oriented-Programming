#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Building {
private:
    string name;
    string type;

public:
    Building(const string& name, const string& type) : name(name), type(type) {}

    string getName() const { return name; }

    void printDetails() const {
        cout << "Name: " << name << ", Type: " << type << endl;
    }
};

// Abstraksi dengan kelas dasar
class HealthcareFacility {
protected:
    string name;
    string type;

public:
    HealthcareFacility(const string& name, const string& type) : name(name), type(type) {}

    virtual void provideService() const = 0; // Metode virtual murni

    string getName() const { return name; }
    string getType() const { return type; }

    virtual ~HealthcareFacility() {}
};

// Kelas turunan yang mengoverride metode provideService
class Hospital : public HealthcareFacility {
private:
    int numBeds;
    int numDoctors;

public:
    Hospital(const string& name, int numBeds, int numDoctors)
        : HealthcareFacility(name, "Hospital"), numBeds(numBeds), numDoctors(numDoctors) {}

    void provideService() const override {
        cout << "Providing hospital services: inpatient, surgery, emergency." << endl;
        cout << "Number of beds: " << numBeds << ", Number of doctors: " << numDoctors << endl;
    }
};

class Clinic : public HealthcareFacility {
private:
    int numConsultationRooms;
    int numNurses;

public:
    Clinic(const string& name, int numConsultationRooms, int numNurses)
        : HealthcareFacility(name, "Clinic"), numConsultationRooms(numConsultationRooms), numNurses(numNurses) {}

    void provideService() const override {
        cout << "Providing clinic services: consultations, check-ups." << endl;
        cout << "Number of consultation rooms: " << numConsultationRooms << ", Number of nurses: " << numNurses << endl;
    }
};

class Pharmacy : public HealthcareFacility {
private:
    int numPharmacists;
    int numMedicines;

public:
    Pharmacy(const string& name, int numPharmacists, int numMedicines)
        : HealthcareFacility(name, "Pharmacy"), numPharmacists(numPharmacists), numMedicines(numMedicines) {}

    void provideService() const override {
        cout << "Providing pharmacy services: medicine dispensing, pharmacist consultations." << endl;
        cout << "Number of pharmacists: " << numPharmacists << ", Number of medicines: " << numMedicines << endl;
    }
};

class Edge {
private:
    Building building1;
    Building building2;
    int distance;

public:
    Edge(const Building& building1, const Building& building2, int distance)
        : building1(building1), building2(building2), distance(distance) {}

    Building getBuilding1() const { return building1; }
    Building getBuilding2() const { return building2; }
    int getDistance() const { return distance; }

    void setDistance(int distance) { this->distance = distance; }
};

class Graph {
private:
    unordered_map<string, vector<pair<Building, int>>> adjList;

public:
    Graph() {}

    void addEdge(const Building& building1, const Building& building2, int distance) {
        adjList[building1.getName()].emplace_back(building2, distance);
        adjList[building2.getName()].emplace_back(building1, distance);
    }

    void addBuildingConnection(const Building& building1, const Building& building2, int distance) {
        adjList[building1.getName()].emplace_back(building2, distance);
        adjList[building2.getName()].emplace_back(building1, distance);
    }

    void addBuildingConnections(const vector<Edge>& edges) {
        for (const auto& edge : edges) {
            addBuildingConnection(edge.getBuilding1(), edge.getBuilding2(), edge.getDistance());
        }
    }

    void printGraph() const {
        for (const auto& building : adjList) {
            cout << building.first << " -> ";
            for (const auto& neighbor : building.second) {
                cout << "(" << neighbor.first.getName() << ", " << neighbor.second << " m) ";
            }
            cout << endl;
        }
    }

    void dijkstra(const string& src, unordered_map<string, int>& dist, unordered_set<string>& unreachable) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        
        for (const auto& building : adjList) {
            dist[building.first] = INT_MAX;
            unreachable.insert(building.first);
        }
        dist[src] = 0;
        unreachable.erase(src);

        pq.emplace(0, src);

        while (!pq.empty()) {
            string u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjList[u]) {
                string v = neighbor.first.getName();
                int weight = neighbor.second;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                    unreachable.erase(v);
                }
            }
        }
    }

    void printSolution(const unordered_map<string, int>& dist, const unordered_set<string>& unreachable, const Building& src) const {
        cout << "Shortest distances from " << src.getName() << " to other buildings:" << endl;
        for (const auto& building : dist) {
            if (unreachable.find(building.first) != unreachable.end()) {
                cout << building.first << " : no path" << endl;
            } else {
                cout << building.first << " : " << building.second << " m" << endl;
            }
        }
    }

    void findNearestMedicalFacility(const string& src) {
        unordered_map<string, int> dist;
        unordered_set<string> unreachable;
        dijkstra(src, dist, unreachable);

        string nearestFacility = "";
        int minDistance = INT_MAX;

        for (const auto& entry : dist) {
            string buildingName = entry.first;
            int distance = entry.second;

            if (buildingName.find("Klinik") == 0 || buildingName.find("Rumah Sakit") == 0) {
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestFacility = buildingName;
                }
            }
        }

        if (nearestFacility.empty()) {
            cout << "There are no medical facilities in your area." << endl;
        } else {
            cout << "The nearest medical facility from " << src << " is " << nearestFacility << " with a distance of " << minDistance << " m." << endl;
        }
    }
    
    // Method to edit an edge
    void editEdge(const string& building1, const string& building2, int newDistance) {
        for (auto& neighbor : adjList[building1]) {
            if (neighbor.first.getName() == building2) {
                neighbor.second = newDistance;
            }
        }
        for (auto& neighbor : adjList[building2]) {
            if (neighbor.first.getName() == building1) {
                neighbor.second = newDistance;
            }
        }
    }

    // Method to remove an edge
    void removeEdge(const string& building1, const string& building2) {
        adjList[building1].erase(
            remove_if(adjList[building1].begin(), adjList[building1].end(),
                      [&building2](const pair<Building, int>& neighbor) { return neighbor.first.getName() == building2; }),
            adjList[building1].end());

        adjList[building2].erase(
            remove_if(adjList[building2].begin(), adjList[building2].end(),
                      [&building1](const pair<Building, int>& neighbor) { return neighbor.first.getName() == building1; }),
            adjList[building2].end());
    }
};

Graph g;

void addDatabase() {
    vector<Edge> edges = {
        Edge(Building("Sekolah", "School"), Building("Klinik Harapan Bersama", "Clinic"), 300),
        Edge(Building("Sekolah", "School"), Building("Masjid", "Mosque"), 200),
        Edge(Building("Klinik Harapan Bersama", "Clinic"), Building("Pasar", "Market"), 100),
        Edge(Building("Masjid", "Mosque"), Building("Gym", "Gym"), 150),
        Edge(Building("Pasar", "Market"), Building("Gym", "Gym"), 400),
        Edge(Building("Perumahan", "Housing"), Building("Taman Kota", "Park"), 350),
        Edge(Building("Gym", "Gym"), Building("Taman Kota", "Park"), 200),
        Edge(Building("Pasar", "Market"), Building("Taman Kota", "Park"), 250),
        Edge(Building("Kantor Polisi", "Police Station"), Building("Rumah Makan", "Restaurant"), 450),
        Edge(Building("Rumah Makan", "Restaurant"), Building("Bengkel", "Workshop"), 200),
        Edge(Building("Bengkel", "Workshop"), Building("Supermarket", "Supermarket"), 300),
        Edge(Building("Klinik Harapan Bersama", "Clinic"), Building("Rumah Sakit Umum", "Hospital"), 200),
        Edge(Building("Supermarket", "Supermarket"), Building("Taman Kota", "Park"), 250)
    };

    g.addBuildingConnections(edges);
}

int main() {
    int opsi;

    while (true) {
        cout << "\nSelect an option:\n";
        cout << "1. Add an edge\n";
        cout << "2. Edit an edge\n";
        cout << "3. Remove an edge\n";
        cout << "4. Add database\n";
        cout << "5. Print graph\n";
        cout << "6. Find shortest distance from a building\n";
        cout << "7. Find nearest medical facility\n";
        cout << "8. Demonstrate Healthcare Services\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> opsi;

        if (opsi == 1) {
            string b1, b2;
            int dist;
            cout << "Enter the name of the first building: ";
            cin >> b1;
            cout << "Enter the name of the second building: ";
            cin >> b2;
            cout << "Enter the distance: ";
            cin >> dist;
            g.addEdge(Building(b1, "Generic Building"), Building(b2, "Generic Building"), dist);
            cout << "Edge between " << b1 << " and " << b2 << " with distance " << dist << " meters has been added." << endl;
        } else if (opsi == 2) {
            string b1, b2;
            int dist;
            cout << "Enter the name of the first building: ";
            cin >> b1;
            cout << "Enter the name of the second building: ";
            cin >> b2;
            cout << "Enter the new distance: ";
            cin >> dist;
            g.editEdge(b1, b2, dist);
            cout << "Edge between " << b1 << " and " << b2 << " with new distance " << dist << " meters has been updated." << endl;
        } else if (opsi == 3) {
            string b1, b2;
            cout << "Enter the name of the first building: ";
            cin >> b1;
            cout << "Enter the name of the second building: ";
            cin >> b2;
            g.removeEdge(b1, b2);
            cout << "Edge between " << b1 << " and " << b2 << " has been removed." << endl;
        } else if (opsi == 4) {
            addDatabase();
            cout << "Building database has been added." << endl;
        } else if (opsi == 5) {
            g.printGraph();
        } else if (opsi == 6) {
            string srcName;
            cout << "Enter the name of the building: ";
            cin >> srcName;

            // Create a Building object (for simplicity, consider it as the source building)
            Building srcBuilding(srcName, "Generic Building");

            unordered_map<string, int> dist;
            unordered_set<string> unreachable;
            g.dijkstra(srcName, dist, unreachable);
            g.printSolution(dist, unreachable, srcBuilding);
        } else if (opsi == 7) {
            string src;
            cout << "Enter the name of the building: ";
            cin >> src;
            g.findNearestMedicalFacility(src);
        } else if (opsi == 8) {
            vector<HealthcareFacility*> facilities;
            facilities.push_back(new Hospital("Rumah Sakit Umum", 150, 30));
            facilities.push_back(new Clinic("Klinik Harapan Bersama", 10, 5));
            facilities.push_back(new Pharmacy("Apotek Sehat", 3, 1000));

            for (const auto& facility : facilities) {
                cout << facility->getName() << " (" << facility->getType() << "): ";
                facility->provideService();
                delete facility; // Membersihkan memori
            }
        } else if (opsi == 0) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
