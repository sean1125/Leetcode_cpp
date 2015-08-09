// leetcode 149 Max Points on a Line.cpp

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> & points, int start) {

        int i, num = 1, size = points.size();
        map<float, int> slop;

        for (i = start + 1; i < size; i++) {
            if (points[i].x == points[start].x && points[i].y == points[start].y) num++;
            else if (points[i].x == points[start].x && points[i].y != points[start].y) slop[INT_MAX]++;
            else slop[(float)(points[i].y - points[start].y) / (float)(points[i].x - points[start].x)]++;
        }

        int max = 0;
        map<float, int>::iterator it;

        for (it = slop.begin(); it != slop.end(); it++) max = max < it->second ? it->second : max;

        return num + max;
    }

    int maxPoints(vector<Point>& points) {

        int i, num, max = 0, size = points.size();

        for (i = 0; i < size; i++) {
            num = maxPoints(points, i);
            max = max < num ? num : max;
        }

        return max;
    }
};
