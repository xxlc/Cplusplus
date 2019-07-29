#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using namespace log4cpp;
int main(){
	//创建 目的地对象，并设置 布局
	Appender *appender1 = new OstreamAppender("ostreamAppender", &std::cout);
	appender1->setLayout(new BasicLayout());

	Category &root = Category::getRoot();//创建种类
	root.setPriority(Priority::CRIT);//设置优先级
	root.addAppender(appender1);//添加目的地对象

	root.alert("this is a alert message.");
	root.crit("this is a crit message.");
	root.error("this is error message.");
	root.warn("this is warn message.");
	root.info("this is info message.");
	root.notice("this is notice message.");

	Category::shutdown();
	return 0;
}
