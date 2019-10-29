/*
 * spinlock.h
 *
 *  Created on: Oct 29, 2019
 *      Author: keith
 *
 *      DO NOT USE SPINLOCKS, USE MUTEXES INSTEAD!
 *
 */

#ifndef SPINLOCK_H_
#define SPINLOCK_H_
#include <atomic>

class SpinLock {

	//inititialize
    std::atomic_flag locked = ATOMIC_FLAG_INIT ;
public:
    void lock() {

    	//Atomically changes the state of a std::atomic_flag to set (true) and returns the value it held before.
        while (locked.test_and_set()) { ; }
    }
    void unlock() {
    	//Atomically changes the state of a std::atomic_flag to clear (false).
        locked.clear();
    }
};



#endif /* SPINLOCK_H_ */
