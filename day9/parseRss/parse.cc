#include "tinyxml2.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace tinyxml2;

class RssItem{
public:
	RssItem(const char *title,const char *link,
		//	const char *description,const char *content)
			const char *description)
	: _title(title)
	, _link(link)
	, _description(description)
	//, _content(content)
	{}
	void print(){
		cout << "title = " << _title << endl;
		cout << "link = " << _link << endl;
		cout << "description = " << _description << endl;
		//cout << "content = " << _content << endl;
	}
	string _title;
	string _link;
	string _description;
	//string _content;
};
class RssReader{
public:
	RssReader() = default;
	void parseRss(const char *xmlPath);//解析
	void dump(const string &fileName);//输出
private:
	vector<RssItem> _rss;
};
void RssReader::parseRss(const char *xmlPath){
	XMLDocument doc;
	if( doc.LoadFile(xmlPath) ){
		cout << "Load file failed.\n" << endl;
		cout << "xmlPath = " << xmlPath << endl;
		exit(0);
	}
	XMLElement *root = doc.RootElement();
	XMLElement *channel = root->FirstChildElement("channel");
	XMLElement *item = channel->FirstChildElement("item");
	XMLElement *title = nullptr;
	XMLElement *link = nullptr;
	XMLElement *description = nullptr;
	//XMLElement *content = nullptr;

	printf("item = %p\n",item);
	while(item != NULL){
		title = item->FirstChildElement("title");
		link = item->FirstChildElement("link");
		description = item->FirstChildElement("description");
		//content = item->FirstChildElement("conten:encoded");

#if 0	//存有content字段版本
		_rss.push_back(
				RssItem(title->GetText(),link->GetText(),
						description->GetText(),content->GetText()));
#endif
#if	1	//删除content
		_rss.push_back(
				RssItem(title->GetText(),link->GetText(),
						description->GetText()));
#endif
		item = item->NextSiblingElement();
	}
}
void RssReader::dump(const string &fileName){
	static int id = 1;
	char id_arr[10];
	XMLDocument doc;
	XMLElement *root = nullptr;
	XMLElement *docid = nullptr;
	XMLElement *title = nullptr;
	XMLElement *link = nullptr;
	XMLElement *description = nullptr;
	//XMLElement *content = nullptr;

	for(auto &i : _rss){
		sprintf(id_arr,"%d",id++);
		root = doc.NewElement("doc");
			//docid
			docid = doc.NewElement("docid");
			docid->InsertEndChild(doc.NewText(id_arr));
			root->InsertEndChild(docid);
			//title
			title = doc.NewElement("title");
			title->InsertEndChild(doc.NewText(i._title.c_str()));
			root->InsertEndChild(title);
			//link
			link = doc.NewElement("link");
			link->InsertEndChild(doc.NewText(i._link.c_str()));
			root->InsertEndChild(link);
			//description
			description = doc.NewElement("description");
			description->InsertEndChild(doc.NewText(i._description.c_str()));
			root->InsertEndChild(description);
			//content
			//content = doc.NewElement("content");
			//content->InsertEndChild(doc.NewText(i._content.c_str()));
			//root->InsertEndChild(content);
		doc.InsertEndChild(root);
	}
	doc.SaveFile(fileName.c_str());
}

int main(){
	const char *xmlPath = "/home/chenlei/documents/coolshell.xml";
	string fileName = "./pagelib.dat";
	RssReader rs;
	rs.parseRss(xmlPath);
	rs.dump(fileName);
	return 0;
}

