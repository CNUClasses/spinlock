//============================================================================
// Name        : spinlock.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include "spinlock.h"
using namespace std;
//DO NOT USE SPINLOCKS, USE MUTEXES INSTEAD!

//a poor substitute for a mutex
SpinLock lck;
//mutex lck;

//void thrdfunc(int i){
void thrdfunc(){
	//lets get this threads id
	 std::thread::id this_id  = std::this_thread::get_id();
	 std::cout<<"	Thread:"<<this_id<<" trying to get lock..."<<std::endl;
	 lck.lock();
	std::cout<<"		Thread:"<<this_id<<"Got Lock! exiting"<<std::endl;
	lck.unlock();
}


int main() {

		std::cout<<"MAIN Thread: locking lock"<<std::endl;
		//why lock here instead of after next line?
		lck.lock();

		// constructs thread and runs it
		std::thread  t1(thrdfunc);

		//let em run a bit
		//look at system monitor, you will see a spike in CPU usage for 1 thread
		//thats the thread in thrdfunc spinning
		std::this_thread::sleep_for(std::chrono::milliseconds(9000));
		std::cout<<"MAIN Thread: unlocking lock"<<std::endl;
		lck.unlock();

		// wait for thread to finish execution,
		t1.join();

		std::cout<<"finished  everything"<<std::endl;
}
