#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
#define vi vector<int>
const int INF = (int)1e9;

class Solution
{
public:
    // return  0:一数组为空   1:二数组为空 2：都不空
    int op_insert(int &idx_x, int &idx_y, double &z, vi &x, vi &y)
    {
        int res = 2;
        if (idx_x < x.size() && idx_y < y.size())
        {
            z = x[idx_x] <= y[idx_y] ? x[idx_x] : y[idx_y];
            if (z == x[idx_x])
                idx_x++;
            else
                idx_y++;
        }
        else if (idx_x < x.size())
        {
            z = x[idx_x];
            idx_x++;
            res = 1;
        }
        else if (idx_y < y.size())
        {
            z = y[idx_y];
            idx_y++;
            res = 0;
        }

        return;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int num1_idx = 0;
        int num2_idx = 0;
        bool isodd = (nums1.size() + nums2.size()) % 2;
        int half_totle = (nums2.size() + nums1.size()) / 2;
        double res = 0;

        // int median;
        if (half_totle == 0)
        {
            if (nums2.size())
                return nums2[0];
            else
                return nums1[0];
        }

        for (;;)
        {
            // each numbers neither empty ,or inserted numbers take half size
            int temp;
            if ((op_insert(num1_idx,num2_idx,res,nums1,nums2) == 2) && ((num1_idx + num2_idx) != half_totle))
            {
                
            }
          
            if (num1_idx < nums1.size())
            {
                if ((num1_idx + num2_idx) == half_totle)
                {
                    if (isodd)
                        res = nums1[half_totle - num2_idx];
                    else
                    {
                        res = ((double)(res + nums1[num1_idx])) / 2;
                    }
                    return res;
                }
                res = nums1[num1_idx];
                num1_idx++;
            }
            else if (num2_idx < nums2.size())
            {
                if ((num1_idx + num2_idx) == half_totle)
                {
                    if (isodd)
                        res = nums2[half_totle - num1_idx];
                    else
                    {
                        res = ((double)(res + nums2[num2_idx])) / 2;
                    }
                    // cout<<"res2 :"<<res<<endl;
                    return res;
                }
                res = (nums2[num2_idx]);
                num2_idx++;
            }
        }
    }
};