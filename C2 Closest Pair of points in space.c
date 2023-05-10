#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

int cmpx(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}

int cmpy(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y > p2->y) - (p1->y < p2->y);
}

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double brute_force(Point P[], int n) {
    double min = INFINITY;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = distance(P[i], P[j]);
            if (d < min) {
                min = d;
            }
        }
    }
    return min;
}

double closest_pair(Point Px[], Point Py[], int n) {
    if (n <= 3) {
        return brute_force(Px, n);
    }
    int mid = n / 2;
    Point mid_point = Px[mid];
    Point Pyl[mid + 1], Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
        if (Py[i].x <= mid_point.x) {
            Pyl[li++] = Py[i];
        } else {
            Pyr[ri++] = Py[i];
        }
    }
    double dl = closest_pair(Px, Pyl, mid);
    double dr = closest_pair(Px + mid, Pyr, n - mid);
    double d = fmin(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(Py[i].x - mid_point.x) < d) {
            strip[j++] = Py[i];
        }
    }
    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k
