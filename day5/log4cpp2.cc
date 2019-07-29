#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <iostream>
using namespace log4cpp;
int main(){
	//布局1
	PatternLayout *ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d %c [%p] %m%n");
	//布局2
	PatternLayout *ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d %c [%p] %m%n");
	//创建 目的地对象1，并设置 布局1
	Appender *appender1 = new OstreamAppender("ostreamAppender", &std::cout);
	appender1->setLayout(ptnLayout1);
	//创建 目的地对象2，并设置 布局2
	Appender *appender2 = new FileAppender("fileAppender", "wangdao.log");
	appender2->setLayout(ptnLayout2);

	Category &root = Category::getRoot();//创建种类
	root.setPriority(Priority::DEBUG);//设置优先级
	root.addAppender(appender1);//添加目的地对象1
	root.addAppender(appender2);//添加目的地对象2

	root.alert("this is a alert message.");
	root.crit("this is a crit message.");
	root.error("this is error message.");
	root.warn("this is warn message.");
	root.info("this is info message.");
	root.notice("this is notice message.");
	Category::shutdown();
	return 0;
}
