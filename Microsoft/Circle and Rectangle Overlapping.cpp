class Solution {
public:
    double distance(int x1, int y1, int x2, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    
    bool checkOverlap(int radius, int xC, int yC, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = std::max(x1, std::min(xC, x2));
        int closestY = std::max(y1, std::min(yC, y2));
        
        // Calculate the distance from the circle's center to this closest point
        double distanceToClosestPoint = distance(xC, yC, closestX, closestY);
        
        // Check if this distance is less than or equal to the radius
        return distanceToClosestPoint <= radius;
    }
};
