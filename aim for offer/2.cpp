/*
实现singleton模式
*/

// C++11下最佳版本
template<typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T value;
        return value;
    }

private:
    Singleton();
    ~Singleton();
};

// 旧版本C++下，DCL写法需要加内存屏障，或者需要2个原子计数

// DCL
template<typename T>
class Singleton
{
public:
    static T& getInstamce()
    {
        if (!value_)
        {
            MutexLockGuard guard(mutex_);
            if (!value_)
            {
                T* tmp = new T;
                // insert memory barrier
                value_ = tmp; // rcu
                return *value_;
            }
        }
    }

private:
    Singleton();
    ~Singleton();

    static T*     value_;
    static Mutex  mutex_;
};

template<typename T>
T* Singleton<T>::value_ = NULL;

template<typename T>
Mutex Singleton<T>::mutex_;


// atomic
template<typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        while (true)
        {
            if (ready_.get())
            {
                return *value_;
            }
            else
            {
                if (initializing_.getAndSet(true))
                {
                    // wait for other thread initialize.
                }
                else
                {
                    value_ = new T;
                    ready_.set(true);
                    return *value_;
                }
            }
        }
    }

private:
    Singleton();
    ~Singleton();

    static T*            value_;
    static Atomic<bool>  ready_;
    static Atomic<bool>  initializing_;
};

template<typename T>
T* Singleton<T>::value_ = NULL;

template<typename T>
Atomic<bool> Singleton<T>::ready_;

template<typename T>
Atomic<bool> Singleton<T>::initializing_;

// linux下可用pthread_once安全的实现singleton
template<typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        pthread_once(&once_, init);
        return *value_;
    }

private:
    Singleton();
    ~Singleton();

    static void init()
    {
        value_ = new T;
    }

    static pthread_once_t  once_;
    static T*              value_;
};

template<typename T>
pthread_once_t Singleton<T>::once_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = NULL;
