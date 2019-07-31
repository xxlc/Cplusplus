#include "tinyxml2.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using namespace tinyxml2;

class User{
public:
	User(const string& userName,const string &passWord,\
		 const string &mobile,const string &email,string gender)
	: _userName(userName)
	, _passWord(passWord)
	, _mobile(mobile)
	, _email(email)
	, _gender(gender){}

	string _userName;
	string _passWord;
	string _mobile;
	string _email;
	string _gender;
};

// 创建一个XML文件
int createXML(const char *xmlPath){
	const char *declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
	XMLDocument doc;
	doc.Parse(declaration);
	//添加声明可以使用下面两行
	//XMLDeclaration *declaration=doc.NewDeclaration();
	//doc.InsertFirstChild(declaration);
	
	XMLElement *root = doc.NewElement("DBUSER");
	doc.InsertEndChild(root);
	return doc.SaveFile(xmlPath);
}
// 增加XML文件的节点
int insertXMLNode(const char *xmlPath, const User &user){
	XMLDocument doc;
	int ret = doc.LoadFile(xmlPath);
	cout << "ret = " << ret << endl;
	XMLElement *root = doc.RootElement();

	XMLElement *userNode = doc.NewElement("User");
	userNode->SetAttribute("Name",user._userName.c_str());
	userNode->SetAttribute("Password",user._passWord.c_str());
	root->InsertEndChild(userNode);

	XMLElement *genderNode = doc.NewElement("Gender");
	XMLText *genderText = doc.NewText(user._gender.c_str());
	genderNode->InsertEndChild(genderText);
	userNode->InsertEndChild(genderNode);

	XMLElement *mobileNode = doc.NewElement("Mobile");
	XMLText *mobileText = doc.NewText(user._mobile.c_str());
	mobileNode->InsertEndChild(mobileText);
	userNode->InsertEndChild(mobileNode);

	XMLElement *emailNode = doc.NewElement("Email");
	XMLText *emailText = doc.NewText(user._email.c_str());
	emailNode->InsertEndChild(emailText);
	userNode->InsertEndChild(emailNode);

	return doc.SaveFile(xmlPath);
}
//查询XML文件的指定节点
XMLElement* queryUserNodeByName(XMLElement *root,const string &userName){
	XMLElement *userNode = root->FirstChildElement("User");
	while(userNode != NULL){
		if(userNode->Attribute("Name") == userName){
			break;
		}
		userNode = userNode->NextSiblingElement();//下一个兄弟节点
	}
	return userNode;
}
//修改XML文件的指定节点


int main(){
	const char* xmlPath = "./xml";
	createXML(xmlPath);
	User user("user name","password","mobile","email","gender");
	insertXMLNode(xmlPath,user);
	return 0;
}
