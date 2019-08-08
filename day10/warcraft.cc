// warcraft.cc
// 3：魔兽世界之二：装备
// 题源：http://cxsjsxmooc.openjudge.cn/2018t3springw5/3/
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

// 武士：
//		- 状态：编号，生命值
//		- 行为：暂无。
class Knight{
public:
	Knight(int id, int hp)
	: _id(id)
	, _hp(hp){
	#ifdef DEBUG
		cout << "Knight(int, int)" << endl;
	#endif
	}

private:
	int _id;
	int _hp;
};

// 武器：
//		- 状态：编号，攻击力
//		- 行为（附带技能）：暂无。
class Weapon{

private:
	string _weaName;

};

// Dragon：
//		- 状态：编号，生命值
//		- 行为：暂无。

// Ninja：
//		- 状态：编号，生命值
//		- 行为：暂无。


// iceman：
//		- 状态：编号，生命值
//		- 行为：暂无。


// lion：
//		- 状态：编号，生命值
//		- 行为：暂无。


// wolf：
//		- 状态：编号，生命值
//		- 行为：暂无。


int main(){
	
	return 0;
}
