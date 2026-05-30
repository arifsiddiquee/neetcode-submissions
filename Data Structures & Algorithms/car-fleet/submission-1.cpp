struct Car {
    int position;
    int speed;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i].position = position[i];
            cars[i].speed = speed[i];
        }

        auto comp = [](const Car& a, const Car& b) {
            return a.position < b.position;
        };
        sort(cars.begin(), cars.end(), comp);
    
        stack<Car> fleet;

        auto willCollide = [&target](const Car& a, const Car& b) {
            if (a.speed == b.speed) return false;

            int dist = b.position - a.position;
            int speed_diff = a.speed - b.speed;

            if ((dist >= 0) == (speed_diff >= 0)) {
                if (target * speed_diff - dist * a.speed - a.position * speed_diff >= 0) {
                    return true;
                }
            }

            return false;
        };

        for (auto& car : cars) {
            if (fleet.empty()) {
                fleet.push(car);
            } else {
                while (!fleet.empty() && willCollide(fleet.top(), car)) {
                    car.speed = min(car.speed, fleet.top().speed);
                    fleet.pop();
                }
                fleet.push(car);
            }
        }

        return fleet.size();
    }
};
