# include <pthread.h>

//------------------------------------------------------------------------------------------------------------//
/*
    --> Used to create a thread.

    --> Returns 0 on success, or a + error number on error.

    (<---Judicious Casting---> in threads refers to the practice
    of choosing the appropriate data types for variables that are shared
    across multiple threads AKA int j == (int) ((void *) j) but there might be
    some problems if u try to cast the return value of pthread_create() when using pthread_join()).
*/
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
/*
    --> (pthread_t) Thread identifier, is a data type that represents a thread ID nd it is usually implemented as an unsigned integer type.
*/

// How can I end a thread ?

/*
    The thread’s start_routine function performs a return specifying a return value for the
    this specific thread.
*/
//------------------------------------------------------------------------------------------------------------//
int pthread_join(pthread_t thread, void **value_ptr);
/*
    --> Used to join a thread.

    --> Returns 0 on success, or a + error number on error.

    --> (thread) is the ID of the thread to wait for.

    --> (value_ptr) is the pointer that stores the return value of the start_routine().

            (We use the term JOINABLE to describe this thread)
*/
//------------------------------------------------------------------------------------------------------------//
pthread_t pthread_self(void);
/*
    --> Returns the thread ID of the calling thread.
*/
//------------------------------------------------------------------------------------------------------------//
int pthread_equal(pthread_t t1, pthread_t t2);
/*
    --> Returns nonzero value if t1 and t2 are equal, otherwise 0.
*/
//------------------------------------------------------------------------------------------------------------//
int pthread_detach(pthread_t thread);
/*
    --> Returns 0 on success, or a + error number on error.
    --> Used to clean up and remove the thread when it terminates means we do not care about its retunr status.
    NOTE:
        --> Once a thread has been detached, it is no longer possible to use pthread_join() to
            obtain its return status, and the thread can’t be made joinable again.
                    (We use the term DETACHED to describe this thread)

        --> Detaching a thread doesn’t make it immune to a call to exit() in another thread
            or a return in the main thread. In such an event, all threads in the process are immediately terminated, 
            regardless of whether they are joinable or detached.
        
        --> It simply controls what happens after a thread terminates, not how or when it terminates.
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                            //MUTEX

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
        One of the principal advantages of threads is that they can share information via
        global variables. However, this easy sharing comes at a cost: we must take care that
        multiple threads do not attempt to modify the same variable at the same time, or
        that one thread doesn’t try to read the value of a variable while another thread is
        modifying it.
*/

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
/*
    --> Initialize a mutex with specified attributes.
*/
int pthread_mutex_lock(pthread_mutex_t *mutex);
/*
    --> Lock a mutex and block until it becomes available.
*/
int pthread_mutex_unlock(pthread_mutex_t *mutex);
/*
    --> Unlock a mutex.
*/
int pthread_mutex_destroy(pthread_mutex_t *mutex);
/*
    --> Destroy a mutex.
*/