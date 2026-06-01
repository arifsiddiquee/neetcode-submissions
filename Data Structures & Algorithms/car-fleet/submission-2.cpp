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
        sort(cars.rbegin(), cars.rend(), comp);
    
        stack<double> fleet;

        for (auto& car : cars) {
            double time_to_target = (target - car.position) * 1.0 / car.speed;
            if (fleet.empty() || time_to_target > fleet.top()) {
                fleet.push(time_to_target);
            }
        }

        return fleet.size();
    }
};
