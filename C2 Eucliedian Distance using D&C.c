#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double distance(struct Point p1, struct Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double euclidean_distance(struct Point points[], int start, int end) {
    if (start == end) {
        return 0;
    }
    else if (start == end-1) {
        return distance(points[start], points[end]);
    }
    else {
        int mid = (start + end) / 2;
        double left = euclidean_distance(points, start, mid);
        double right = euclidean_distance(points, mid+1, end);
        double d = fmin(left, right);
        struct Point midPoint = points[mid];
        for (int i = start; i <= end; i++) {
            if (fabs(points[i].x - midPoint.x) < d && fabs(points[i].y - midPoint.y) < d) {
                for (int j = i+1; j <= end; j++) {
                    if (fabs(points[j].x - midPoint.x) < d && fabs(points[j].y - midPoint.y) < d) {
                        double dist = distance(points[i], points[j]);
                        if (dist < d) {
                            d = dist;
                        }
                    }
                }
            }
        }
        return d;
    }
}

int main() {
    struct Point points[] = {{1, 2}, {4, 6}, {8, 3}, {10, 12}, {16, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    double result = euclidean_distance(points, 0, n-1);
    printf("Euclidean Distance between Points: %.2f\n", result);
    return 0;
}
