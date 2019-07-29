#include <unistd.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
class Mutex{
friend class Condition;
public:
	Mutex(){
		pthread_mutex_init(&_mutex,NULL);
	}
	~Mutex(){
		pthread_mutex_destroy(&_mutex);
	}
	void lock(){
		pthread_mutex_lock(&_mutex);
	}
	void unlock(){
		pthread_mutex_unlock(&_mutex);	
	}
private:
	pthread_mutex_t _mutex;
};

class Condition{
public:
	Condition(){
		pthread_cond_init(&_cond,NULL);
	}
	~Condition(){
		pthread_cond_destroy(&_cond);
	}
	void wait(Mutex &m){
		pthread_cond_wait(&_cond,&m._mutex);
	}
	void notify(){
		pthread_cond_signal(&_cond);
	}
	void notifyall(){
		pthread_cond_broadcast(&_cond);
	}
private:
	pthread_cond_t _cond;
};

Mutex m;
Condition c;
void* threadFunc(void *args){
	cout << "1. I am children thread.wait mutex." << endl;
	m.lock();
	cout << "2. children thread.mutex lock." << endl;
	c.wait(m);
	cout << "4. children thread waked." << endl;
	m.unlock();
	pthread_exit(NULL);
}
int main(){
	pthread_t thid;
	pthread_create(&thid,NULL,threadFunc,&m);
	sleep(3);
	m.lock();
	cout << "3. mutex lock.I am main thread." << endl;
	m.unlock();
	c.notify();
	pthread_join(thid,NULL);
	cout << "5. pthread_join success." << endl;
	return 0;
}
