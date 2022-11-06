   
#include <bits/stdc++.h>
using namespace std;

   
struct Rectangle {
    int x1, y1, x2, y2;   
};

int intersectingRectangles(vector<Rectangle>& rectangles) {
    int count = 0;
    for (int i = 0; i < rectangles.size(); i++)
    {
        Rectangle rect1 = rectangles[i];
        for (int j = i + 1; j < rectangles.size(); j++)
        {   
            
            Rectangle rect2 = rectangles[j];

            if (((rect1.x1 < rect2.x2) && (rect1.x2 > rect2.x1)) && ((rect1.y1 < rect2.y2) && (rect1.y2 > rect2.y1))) count++;
        }
        
    }
    return count;  
}
   
int main() {
    int N;
    cin >> N;
    vector<Rectangle> rectangles;
    for (int i = 0; i < N; ++i) {
        Rectangle rect;
        cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2; 
        rectangles.push_back(rect);
    }
    
    cout << intersectingRectangles(rectangles) << "\n";
    return 0;
}
