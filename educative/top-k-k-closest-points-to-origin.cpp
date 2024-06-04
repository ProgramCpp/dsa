/*
suggested solution:
- push k points to heap
- Calculate the distance between the origin and each point.
- Compare the distance of the point with the distance of the top of the heap.
- Push and pop the point from the heap.
- Return the points from the heap.
time: O(n log k)
space: O(k)


my soln:
- push all points into min- heap as per distance
- return top k points
time: O(n log n)
space: O(n)
*/

class Point {
  public:
    int x;
    int y;
    int distance;
    
    Point(int x, int y):x(x),y(y){
        distance = pow(x, 2) + pow(y, 2);
    }
    bool operator<(const Point & other) const{
        // note, greater operator for min-heap
        return distance > other.distance;
    }
};

vector<Point> KClosest(vector<Point> locations, int k) 
{
    priority_queue<Point> points;
    
    for(vector<Point>::iterator i = locations.begin(); i != locations.end(); i++){
        points.push(*i);
    }

    vector<Point> result;

    for (int i = 0; i < k; i++){
        result.push_back(points.top());
        points.pop();
    }

    return result;
}
