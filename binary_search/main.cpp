#include <iostream>
#include <vector>

using namespace std;

// 第一个大于等于x的数
int search_right1(vector<int> &nums, int x){
    int l = 0, r = nums.size();

    while (l < r){
        int mid = l + r >> 1;
        if (nums[mid] >= x) r = mid;
        else l = mid + 1;
    }
    
    return l;
}

// 第一个大于x的数
int search_right2(vector<int> &nums, int x){
    int l = 0, r = nums.size();

    while (l < r){
        int mid = l + r >> 1;
        if (nums[mid] > x) r = mid;
        else l = mid + 1;
    }
    
    return l;
}

// 第一个小于等于x的数
int search_left1(vector<int> &nums, int x){
    int l = 0, r = nums.size();

    while (l < r){
        int mid = l + r + 1 >> 1;
        if (nums[mid] <= x) l = mid;
        else r = mid - 1;
    }
    
    return l;
}

// 第一个小于x的数
int search_left2(vector<int> &nums, int x){
    int l = 0, r = nums.size();

    while (l < r){
        int mid = l + r + 1 >> 1;
        if (nums[mid] < x) l = mid;
        else r = mid - 1;
    }
    
    return l;
}

int main(void){
    vector<int> nums = {0, 1, 2, 3, 4 ,5, 6, 7, 8, 9};
    cout << "nums: ";
    for (const auto &x : nums)
        cout << x << "  ";
    cout << endl;

    cout << "第一个小于等于4的数: " << search_left1(nums, 4) <<  endl;
    cout << "第一个小于4的数: "     << search_left2(nums, 4) <<  endl;
    cout << "第一个大于等于4的数: " << search_right1(nums, 4)<<  endl;
    cout << "第一个大于4的数: "    <<  search_right2(nums, 4) << endl;

    return 0;
}