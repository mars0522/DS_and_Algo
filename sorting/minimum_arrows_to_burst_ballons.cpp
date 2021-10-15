bool fun(vector<int>& v1, vector<int>& v2)
{
    return v1[1] < v2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {


        sort(points.begin(), points.end(), fun);
        int arrows = 1;
        int i = 1;
        int target_point = points[0][1];

        while (i < points.size())
        {
            if (target_point >= points[i][0] and target_point <= points[i][1])
                i++;
            else
            {
                arrows++;
                target_point = points[i][1];
                i++;
            }
        }

        return arrows;
    }
};