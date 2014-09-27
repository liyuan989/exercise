#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, vector<pair<string, string> > > check_name;
	vector<string> fname_input;
	string f_name;
	string c_name;
	string c_birth;
	while(cout << "please input the family name, name of child and his birthday: " << endl, cin >> f_name)
	{
		vector<pair<string, string> > child;
		while(cin >> c_name)
		{
			if (c_name == "#")
			{
				break;
			}
			cin >> c_birth;
			child.push_back(make_pair(c_name, c_birth));
		}
		check_name.insert(make_pair(f_name, child));
		fname_input.push_back(f_name);
	}
	cout << "you have input family name of all:" << endl;
	vector<string>::iterator it = fname_input.begin();
	while(it != fname_input.end())
	{
		cout << *it++ << ",";
	}
	cout << endl;
	cout << "the checking result: " << endl;
	/*    by iterator
	for (vector<string>::iterator iter_fn = fname_input.begin(); iter_fn != fname_input.end(); ++iter_fn)
	{
		cout << *iter_fn << ":" << endl;
		map<string, vector<pair<string, string> > >::iterator it_ch = check_name.find(*iter_fn);
		for (vector<pair<string, string> >::iterator it = it_ch->second.begin(); it != it_ch->second.end(); ++it)
		{
			cout << it->first << ", " <<it->second << endl;
		}
	}
	*/
	// by subscript
	for (int ivec_n = 0; ivec_n != fname_input.size(); ++ivec_n)
	{
		cout << fname_input[ivec_n] << ":" << endl;
		for(int ivec_ch = 0; ivec_ch != check_name[fname_input[ivec_n]].size(); ++ivec_ch)
		{
			cout << (check_name[fname_input[ivec_n]])[ivec_ch].first << "," <<(check_name[fname_input[ivec_n]])[ivec_ch].second << endl;
		}

	}
	return 0;
}