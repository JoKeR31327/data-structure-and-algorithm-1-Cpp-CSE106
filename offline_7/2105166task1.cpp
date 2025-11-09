#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Point
{
public:
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void print()
    {
        cout << x << " " << y << endl;
    }
};

class Convo
{
public:
    vector<Point> AP;
    Convo(vector<Point>& obj)
    {
        AP = obj;
    }
    vector<Point> Convex()
    {
        vector<Point> hull = dividing(AP);
        return hull;
    }

    vector<Point> dividing(vector<Point>& points)
    {
       if (points.size() <= 1)
    {
        return points;
    }

    int mid = points.size() / 2;
    
    vector<Point> leftPoints;
    for (int i = 0; i < mid; i++) {
        leftPoints.push_back(points[i]);
    }
    
    sort(leftPoints.begin(), leftPoints.end(), [](Point& a, Point& b)
    {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });

    vector<Point> rightPoints;
    for (int i = mid; i < points.size(); i++) {
        rightPoints.push_back(points[i]);
    }
    
    sort(rightPoints.begin(), rightPoints.end(), [](Point& a, Point& b)
    {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });
    dividing(leftPoints);
    dividing(rightPoints);
    return merging(leftPoints, rightPoints);
    }

    vector<Point> merging(vector<Point>& leftside, vector<Point>& rightside)
    {
        vector<Point> merged = leftside;
           for (int i = 0; i < rightside.size(); i++) {
            merged.push_back(rightside[i]);
    }
    
        int index = 0;
        if((leftside[0].y<rightside[0].y)||(leftside[0].y == rightside[0].y && leftside[0].x < rightside[0].x)){
            index=0;
        }
        else index=leftside.size();
        
        Point lowest = merged[index];
        sort(merged.begin(), merged.end(), [&lowest](Point& a, Point& b)
        {
            double alpha = atan2(a.y - lowest.y, a.x - lowest.x);
            double beta = atan2(b.y - lowest.y, b.x - lowest.x);
            if (alpha != beta)
                return alpha < beta;
            return a.x < b.x;
        });

        
        vector<Point> polygon;
        polygon.push_back(merged[0]);
        polygon.push_back(merged[1]);

        for (int i = 2; i < merged.size(); i++)
        {
            while (polygon.size() > 1)
            {
                int top = polygon.size() - 1;
                if (didcross(polygon[top - 1], polygon[top], merged[i]) <= 0)
                    polygon.pop_back();
                else
                    break;
            }
            polygon.push_back(merged[i]);
        }

        return polygon;
    }

    double didcross(Point& A, Point& B, Point& C)
    {
        return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("outed.txt", "w", stdout);
    int n, x, y;
    vector<Point> Points;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        Points.push_back(Point(x, y));
    }

    Convo a(Points);
    vector<Point> convex = a.Convex();

    if(convex.size()<3){
        cout<<"Fencing not possible"<<endl;
    }
    else{
    //cout<<"the fence points"<<endl;
    for (Point p : convex)
    {
        p.print();
    }
    }
    return 0;
}
