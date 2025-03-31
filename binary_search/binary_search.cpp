#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>


using namespace std;

int search(vector<int>& nums, int target);

int main(int argc, char ** argv)
{
	vector<int> vec(10000);

	for (int data{ 0 }; auto& it: vec)
	{
		while (rand() % 4 == 0) ++data;
		it = ++data;
	}

	cout << search(vec, 555) << endl;

	cout << search(vec, 556) << endl;

	cout << search(vec, 557) << endl;

	cout << search(vec, 558) << endl;

	cout << search(vec, 559) << endl;

	cout << search(vec, 560) << endl;

	return 0;
}

int search(vector<int>& nums, int target)
{
	int _l = -1 , _c = nums.size() / 2, _r = nums.size();
	size_t _count{ 0 };

	while (true)
	{
		if (_c >= _r || _c <= _l) return -1;

		_count++;

		if (auto _d = nums[_c] - target; _d == 0)
		{
			return _c;
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
