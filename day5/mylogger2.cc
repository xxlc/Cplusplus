#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <iostream>
using namespace log4cpp;
using std::cout;
using std::endl;
//使用单例模式封装一个日志系统类
class Mylogger{
public:
	static Mylogger* getInstance(){
		if(nullptr == _pInstance){
			_pInstance = new Mylogger();
		}
		return _pInstance;
	}	
	//函数接口
	void warn(const char *msg){
		_myCategory.warn(msg);
	}
	void error(const char *msg){
		_myCategory.error(msg);
	}
	void debug(const char *msg){
		_myCategory.debug(msg);
	}
	void info(const char *msg){
		_myCategory.info(msg);
	}
private:
	Mylogger()
	: _myCategory(Category::getRoot())
	{
		//设定目的地布局
		PatternLayout *_coutLayout = new PatternLayout();
		PatternLayout *_fileLayout = new PatternLayout();
		PatternLayout *_rollingFileLayout = new PatternLayout();
		_coutLayout->setConversionPattern("%d %c [%p] %m%n");
		_fileLayout->setConversionPattern("%d %c [%p] %m%n");
		_rollingFileLayout->setConversionPattern("%d %c [%p] %m%n");
		
		
		Appender *_coutAppender = new OstreamAppender("_coutAppender",&cout);
		Appender *_fileAppender = new FileAppender("_fileAppender","wangdao.log");
		Appender *_rollingFileAppender = \
			new RollingFileAppender("_rollingFileAppender","rollwangdao.log",1024,5);
		_coutAppender->setLayout(_coutLayout);
		_fileAppender->setLayout(_fileLayout);
		_rollingFileAppender->setLayout(_rollingFileLayout);
		//设置优先级并添加目的地
		_myCategory.setPriority(Priority::DEBUG);
		_myCategory.addAppender(_coutAppender);
		_myCategory.addAppender(_fileAppender);
		_myCategory.addAppender(_rollingFileAppender);
	
	}

	~Mylogger(){	Category::shutdown();	}
private:
	static Mylogger* _pInstance;
	//日志系统私有变量
	Category &_myCategory;

};
Mylogger* Mylogger::_pInstance = nullptr;

int main(){
	Mylogger *log = Mylogger::getInstance();
	log->warn("hello warn");
	log->info("hello info");
	log->error("hello error");
	log->debug("hello debug");
	return 0;
}
