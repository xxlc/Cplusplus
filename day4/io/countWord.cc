#include <ctype.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::ofstream;
/*
   统计词频 0.1版
   利用单例模式创建一个词库类，词库中唯一的存储一个单词
   及单词的属性（此时属性就是单词出现的频率）。
   词库类中提供 addWord() 函数
*/
struct Word{
	Word(const string &w, int n)
	:word(w)
	,cnt(n){}

	string word;
	int cnt;
};

class WordLibrary{
public:
	//创建一个词库，或取得词库
	static WordLibrary *getInstance(){
		if(nullptr == _pInstance){
			_pInstance = new WordLibrary();
		}
		return _pInstance;
	}
	//销毁词库
	static void destroy(){
		if(_pInstance){
			delete _pInstance;
		}
	}
	//addWord()
	void addWord(const string &word){
		if(false == _query(word)){
			//查找失败则添加进去
			_add(word);
		}
	}
	//打印词库
	void  print(ofstream &ofs){
		for(auto &i : _lib){
			ofs << i.word << "   " << i.cnt << "\n";
		}
	}
	vector<Word>& print(){
		return _lib;
	}
private:
	WordLibrary(){}
	~WordLibrary(){}
	void _add(const string &word){
		_lib.push_back(Word(word, 1));
	}
	//查找，查找成功则计数 +1 并返回true，失败则返回 false
	bool _query(const string &word){
		for(auto &i : _lib){
			if(i.word == word){
				i.cnt++;
				return true;
			}
		}
		return false;
	}
private:
	static WordLibrary *_pInstance;
	//词库变量
	vector<Word> _lib;
};
WordLibrary* WordLibrary::_pInstance = nullptr;


int main(){
	WordLibrary* pLib = WordLibrary::getInstance();
	//打开文件
	string fileName = "./The_Holy_Bible.txt";
	ifstream ifs(fileName);
	//读取文件并添加单词
	string word,line;
	while(getline(ifs, line)){
		istringstream iss(line);
		while(!iss.eof()){
			iss >> word;
			if( isalpha(word[0]) ){
				pLib->addWord(word);
			}
		}
	}
	//输出结果
	ofstream ofs("text", std::ios::app);
	for( auto &i : pLib->print() ){
		ofs << i.word << "   " << i.cnt << "\n";
	}
	ofs.close();
	pLib->destroy();
	return 0;
}
