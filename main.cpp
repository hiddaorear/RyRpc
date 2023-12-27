//#include <iostream>
//#include "glog/logging.h" 
#include "event_manage.h"
#include "co_routine.h"
#include <iostream>
using namespace std;
jmp_buf jmp_;
// The jmp_buf type is an array type suitable for storing information to restore a calling environment.
// jmp_buf是debug用的么？调用的地方已被删除

int test(void* attr) {
    char* text = (char*)attr;
    cout << "task test" << attr << endl;
    return 0;
}


int main(int argc, char* argv[]) {
    google::InitGoogleLogging((const char *)argv[0]);
    google::SetLogDestination(google::GLOG_INFO,"./"); 
    cout << "1" << endl;
    // 启动事件监听
    if (EventManager::Instance().Init("127.0.0.1", 12346) != EC_OK) {
        cout << "init err" << endl;
        return 0;      
    }
    cout << "2" << endl;
    // 添加任务
    EventManager::Instance().AddTask(1000, test, (void*)"1234");
    //cout << "3" << endl;
    EventManager::Instance().Start();
    cout << "4" << endl;
    
    /*
    foo();
    switch2();
    cout << "exit" << endl;
    */
    return 0;
}