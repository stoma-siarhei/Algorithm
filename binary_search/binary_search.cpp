#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <tuple>


using namespace std;

tuple<int, size_t> search(vector<int>& nums, int target);

int main(int argc, char ** argv)
{
	vector<int> vec;
	vec.resize(100000);

	for (int data{ 0 }; auto& it: vec)
	{
		while (rand() % 4 == 0) ++data;
		it = ++data;
	}


	return 0;
}

/**	
*	Given an array of integers nums which is sorted in ascending order, 
*	and an integer target, write a function to search target in nums. 
*	If target exists, then return its index. Otherwise, return -1.
*
*	You must write an algorithm with O(log n) runtime complexity.
*/

tuple<int, size_t> search(vector<int>& nums, int target)
{
	tuple<int, int, int> _window{ -1, nums.size() / 2, nums.size() };
	size_t _count{ 0 };
	auto& [_l, _c, _r] = _window;

	while (true)
	{
		if (_c >= _r || _c <= _l) return { - 1, _count };

		_count++;

		if (auto _d = nums[_c] - target; _d == 0)
		{
			return { _c, _count };
		}
		else if (_d < 0)
		{
			_l = _c;
			_c += (_r - _c) / 2;
		}
		else
		{
			_r = _c;
			_c -= (_c - _l) / 2;
		}
	}
}

/*
*	There is an integer array nums sorted in ascending order (with distinct values).
*
*	Prior to being passed to your function, nums is possibly rotated 
*	at an unknown pivot index k (1 <= k < nums.length) such that 
*	the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
*	For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
*
*	Given the array nums after the possible rotation and an integer target, 
*	return the index of target if it is in nums, or -1 if it is not in nums.
*
*	You must write an algorithm with O(log n) runtime complexity.
*/
