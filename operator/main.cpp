#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> add(vector<int> num1, vector<int> num2){
	if (num1.size() < num2.size())
		return add(num2, num1);
	int dec = 0;
	vector<int> ans;
	for (int i = 0; i < num1.size(); i++){
		dec += num1[i];
		if (i < num2.size())
			dec += num2[i];
		ans.push_back(dec % 10);
		dec /= 10;
	}

	if (dec)
		ans.push_back(1);

	return ans;
}

bool cmp(vector<int> a, vector<int> b){
	if (a.size() != b.size())
		return a.size() > b.size();
	for (int i = a.size() - 1; i >= 0; i++)
		if (a[i] != b[i])
			return a[i] > b[i];
	
	return true;
}

vector<int> sub(vector<int> a, vector<int> b){
	vector<int> ans;
	
	for (int i = 0, dec = 0; i < a.size(); i++){
		dec = a[i] - dec;
		if (i < b.size()) dec -= b[i];

		ans.push_back((dec + 10) % 10);
		if (dec < 0) dec = 1;
		else dec = 0;
	}

	while (ans.size() > 1 && ans.back() == 0) ans.pop_back();

	return ans;
}


vector<int> mul(vector<int> a, int b){
	int t = 0;
	
	vector<int> ans;
	for (int i = 0; i < a.size() || t; i++){
		if (i < a.size())	 t += (a[i] * b);
		ans.push_back(t % 10);
		t /= 10;
	}
	while (ans.size() > 1 && ans.back() == 0) ans.pop_back();

	return ans;
}

vector<int> div(vector<int> a, int b, int &r){

	r = 0;
	vector<int> ans;
	
	for (int i = a.size() - 1; i >= 0; i--){
		r = r * 10 + a[i];
		ans.push_back(r / b);
		r %= b;
	}

	reverse(ans.begin(), ans.end());

	while (ans.size() > 1 && ans.back() == 0) ans.pop_back();

	return ans;
}

int main(void){
	// string a, b;
	// cin >> a >> b;
	string a;
	int b;
	cin >> a >> b;

	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--)
		A.push_back(a[i] - '0');

	// vector<int> num1, num2;
	// for (int i = a.size() - 1; i >= 0; i--) num1.push_back(a[i] - '0');
	// for (int i = b.size() - 1; i >= 0; i--) num2.push_back(b[i] - '0');

	// auto ans = add(num1, num2);

	// for (int i = ans.size() - 1; i >= 0; i--)
	// 	cout << ans[i];
	// cout << endl;

	// vector<int> ans;
	// if (cmp(num1, num2)){
	// 	ans = sub(num1, num2);
	// } else {
	// 	cout << '-';
	// 	ans = sub(num2, num1);
	// }

	// for (int i = ans.size() - 1; i >= 0; i--)
	// 	cout << ans[i];
	// cout << endl;

	//auto ans = mul(A, b);
	int r;
	auto ans = div(A, b, r);
	for (int i = ans.size() - 1; i >= 0; i--)
		printf("%d", ans[i]);
	cout << endl<< r<< endl;


	return 0;
}
