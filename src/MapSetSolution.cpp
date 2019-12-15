#include "MapSetSolution.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

namespace Phoenix
{
    void MapSetSolution::RunTestCase(MapSetSolutionEnum solutionType)
    {
        switch (solutionType)
        {
        case MapSetSolutionEnum::TwoSum:
        {
            vector<int> num = {3,7,4,6};
            vector<int> res = twoSum(num, 9);
            cout << res[0] << "," << res[1] << endl;
            break;
        }
        case MapSetSolutionEnum::ThreeSum:
        {
            vector<int> num = {-1, 0, 1, 2, -1, -4};
            vector<vector<int>> res = threeSum(num);
            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i][0] << "," << res[i][1] << "," << res[i][2] << endl;
            }
            break;
        }
        case MapSetSolutionEnum::KSum:
        {
            vector<int> num = {1,-2,-5,-4,-3,3,3,5};
            vector<vector<int>> res = KSum(num, 4, -11);
            for (int i = 0; i < res.size(); i++)
            {
                for (int j = 0; j < res[i].size(); j++)
                {
                    cout << res[i][j] << ",";
                }
                cout << endl;
            }
            break;
        }
        default:
            break;
        }
    }

    vector<int> MapSetSolution::twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        // key: 数组值, value: 下标
        unordered_map<int, int> mapHelper;
        for (int i = 0; i < nums.size(); i++)
        {
            int var = nums[i];
            if (mapHelper.find(target - var) != mapHelper.end())
            {
                res.push_back(mapHelper[target - var]);
                res.push_back(i);
                return res;
            }
            else
            {
                mapHelper[var] = i;
            }
        }
        return res;
    }

    vector<vector<int>> MapSetSolution::threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
        {
            return result;
        }
        // 先排个序
        sort(nums.begin(), nums.end());
        int l, r, sum;
        // 最外层循环，遍历到倒数第三个数就可以了
        for (int i = 0; i < nums.size() - 2; i++)
        {
            // 有序的，当nums[i]>0，说明后面都大于0了
            if (nums[i] > 0)
            {
                break;
            }
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    // 记录结果
                    vector<int> element = {nums[i], nums[l], nums[r]};
                    result.push_back(element);
                    // 把相邻相同元素就可以略过了
                    while (l+1 < nums.size() && nums[l] == nums[l+1])
                    {
                        l++;
                    }
                    while (r-1 >= 0 && nums[r] == nums[r-1])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
            // 去重，执行过都数字，后面相同都就不需要再执行了
            while (i + 1 < nums.size() - 2 && nums[i] == nums[i+1])
            {
                i++;
            }
        }
        return result;
    }

    vector<vector<int>> MapSetSolution::KSumHelper(vector<int>& nums, int k, int target, int left) 
    {
        vector<vector<int>> result;
        // 递归到2截止
        if (k == 2)
        {
            int sum;
            int right = nums.size()-1;
            while (left < right)
            {
                sum = nums[left] + nums[right];
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    vector<int> element = {nums[left], nums[right]};
                    result.push_back(element);
                    // 去重
                    while (left < right && nums[left] == nums[left+1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
            return result;
        }

        for (int i = left; i <= nums.size() - k; i++)
        {
            // 下面的剪枝逻辑一定得是在nums[i]非负的情况下才正确，因为nums和target可能是负数，后面如果是负数，那么目标值还是会减少的
            if (nums[i] >= 0 && nums[i] > target)
            {
                break;
            }
            vector<vector<int>> tmp = KSumHelper(nums, k-1, target - nums[i], i+1);
            for (auto it = tmp.begin(); it != tmp.end(); it++)
            {
                vector<int> element;
                element.push_back(nums[i]);
                for (auto itElement = it->begin(); itElement != it->end(); itElement++)
                {
                    element.push_back(*itElement);
                }
                result.push_back(element);
            }
            // 去重
            while (i+1 <= nums.size() - k && nums[i] == nums[i+1])
            {
                i++;
            }
        }
        return result;
    }

    vector<vector<int>> MapSetSolution::KSum(vector<int>& nums, int k, int target) 
    {
        vector<vector<int>> result;
        if (nums.size() < k)
        {
            return result;
        }
        // 先排个序
        sort(nums.begin(), nums.end());
        result = KSumHelper(nums, k, target, 0);
        return result;
    }
} // namespace Phoenix