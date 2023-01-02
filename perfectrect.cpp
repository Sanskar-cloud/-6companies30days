#include <bits/stdc++.h>
using namespace std;

int perfectRectangle(vector<vector<int>> &rectangles)
{

    
    int totalArea = 0;

    
    set<pair<int, int>> corners;

    for (vector<int> &rect : rectangles)
    {
        pair<int, int> currentCorners[4] = {{rect[0], rect[1]}, {rect[2], rect[3]}, {rect[0], rect[3]}, {rect[2], rect[1]}};

        totalArea += (rect[2] - rect[0]) * (rect[3] - rect[1]);

        
        for (int i = 0; i < 4; i++)
        {
            if (corners.count(currentCorners[i]) > 0)
            {
                corners.erase(currentCorners[i]);
            }
            else
            {
                corners.insert(currentCorners[i]);
            }
        }
    }

    
    if (corners.size() != 4)
    {
        return 0;
    }

    
    pair<int, int> firstCorner = *corners.begin(), lastCorner = *corners.rbegin();

    int desiredArea = (lastCorner.second - firstCorner.second) * (lastCorner.first - firstCorner.first);

    
    if (totalArea != desiredArea)
    {
        return 0;
    }

    return 1;
}
int main(){
    vector<vector<int>> rectangles={{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    int c= perfectRectangle(rectangles);
    cout<<c;
}
  