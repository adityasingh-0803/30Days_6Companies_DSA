##Leetcode 1401

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the center of the circle
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Calculate the squared distance between the center of the circle and the closest point on the rectangle
        int distanceSq = (closestX - xCenter) * (closestX - xCenter) + (closestY - yCenter) * (closestY - yCenter);
        
        // If the distance is less than or equal to the radius squared, there's an overlap
        return distanceSq <= radius * radius;
    }
};
