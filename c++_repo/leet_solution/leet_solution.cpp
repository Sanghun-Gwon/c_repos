﻿// leet_solution.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int>::iterator ptr;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutive = 0;
        int max_consecutive = 0;
        for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
            if (*ptr) {
                consecutive += *ptr;
            }
            else {
                if (max_consecutive < consecutive) {
                    max_consecutive = consecutive;
                }
                consecutive = 0;
            }
        }
        if (max_consecutive < consecutive) {
            max_consecutive = consecutive;
        }
        return max_consecutive;
    }
    
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
            if (!(to_string(*ptr).length() % 2)) cnt++;
        }
        return cnt;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
            *ptr = pow(*ptr, 2);
        }
    
        sort(nums.begin(), nums.end());

        return nums;
    }
};


class LeetCode_Week1_Solution {
public:
    int distributeCandies(vector<int>& candyType) {

    }
}LeetCode_1_Solution;


int main()
{
    Solution solution{};

    vector<int> nums = { -7,-3,2,3,11 };

    vector<int> output = solution.sortedSquares(nums);
    
    vector<int>::iterator ptr;

    for (ptr = output.begin(); ptr != output.end(); ptr++) {
        cout << *ptr << " ";
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
