


#include <mutex>
#include <memory>
#include <iostream>
template<typename T, bool THREAD_SAFE> class subject;

struct base{};

template<typename T, typename E>
class observer : std::enable_shared_from_this<observer<T,E>>
{
    friend subject<T,true>;
    friend subject<T,false>;
    
public:
    static constexpr bool is_thread_safe = false;
    observer(): std::enable_shared_from_this<observer<T,E>>::enable_shared_from_this(), _sbj(nullptr){}
    
    virtual ~observer() {if(_sbj != nullptr){_sbj->detach(*this);}}
    
    T* subject() const {return this->_sbj;}
    
protected:
    virtual void update(T& sbj, const E& e)=0;
private:
    T* _sbj;
    void link(T& sbj) { this->_sbj = &sbj; }

    //void link(T* sbj) __attribute__((unused)) { if(sbj) this->_sbj = sbj; }

    void unlink() { this->_sbj = nullptr; }
};

template<typename T, bool THREAD_SAFE = true>
class subject
{
public:
    static constexpr bool is_thread_safe = THREAD_SAFE;
    subject () {}
    virtual ~subject() {}
    
    template<typename E>
    void attach(observer<T,E> &o)
    {
        std::unique_lock<std::mutex> l(_lock,std::defer_lock);
        if(THREAD_SAFE) l.lock();
        objects<E>().push_back(&o);
        o.link(*static_cast<T*>(this));
    }
    template<typename E>
    void attach(observer<T,E> *o)
    {
        if(o) attach<E>(*o);
    }
    
    template<typename E>
    void detach()
    {
        while(!objects<E>().empty())
        {
            detach(*objects<E>().begin());
            
        }
    }
    
    template<typename E>
    void detach(observer<T,E> &o)
    {
        std::unique_lock<std::mutex> l(_lock,std::defer_lock);
        if(THREAD_SAFE) l.lock();
        
        for(typename std::vector<observer<T,E> *>::iterator i = objects<E>().begin(); i!=objects<E>().end();i++){
            if(*i ==&o)
            {
                o.unlink();
                objects<E>().erase(i);
                return;
            }
        }
    }
    
    template<typename E>
    void detach(observer<T,E> *o)
    {
        if(o) detach<E>(*o);
    }
    
    
    template<typename E>
    void notify(const E& e = E{ })
    {
        std::unique_lock<std::mutex> l(_lock, std::defer_lock);
        if(THREAD_SAFE) l.lock();
        // for_each(objects<E>().begin(), objects<E>().end(), [&](observer<T, E> *o) { if(o && o->subject()) o->update(*static_cast<T*>(this), e); });
        for(auto o : objects<E>())
            if(o && (o->subject() == this)) o->update(*static_cast<T*>(this), e);
    }

private:
    template<typename E>
    std::vector<observer<T, E>*>& objects() {
        static std::vector<observer<T, E>*> _objs;
        return _objs;
    }

    std::mutex _lock;
};


int main()
{

    subject<int> s;

    return 0;
}