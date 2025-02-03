#leetcode 2126

class Solution {
public:
    bool asteroidsDestroyed(int initialMass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long mass = static_cast<long>(initialMass);

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > mass) {
                return false;
            } else {
                mass += asteroids[i];
            }
        }

        return true;
    }
};
