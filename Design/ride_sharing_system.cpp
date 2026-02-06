#include<bits/stdc++.h>
using namespace std;

/**Leetcode Medium
 * Problem - 3829. Design Ride Sharing System
 * Link -> https://leetcode.com/problems/design-ride-sharing-system/description/
 */

class RideSharingSystem {
public:
    queue<int> drivers;
    queue<int> riders;
    unordered_set<int> waiting;
    unordered_set<int> cancelled;

    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push(riderId);
        waiting.insert(riderId);
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        while (!riders.empty() && cancelled.count(riders.front())) {
            int rid = riders.front();
            riders.pop();
            cancelled.erase(rid);
            waiting.erase(rid);
        }

        if (!riders.empty() && !drivers.empty()) {
            int did = drivers.front(); drivers.pop();
            int rid = riders.front(); riders.pop();
            waiting.erase(rid);
            return {did, rid};
        }

        return {-1, -1};
    }

    void cancelRider(int riderId) {
        if (waiting.count(riderId)) {
            cancelled.insert(riderId);
        }
    }
};