#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>

class simple : public std::enable_shared_from_this< simple >
{
public:
    static auto create()
    {
        return std::shared_ptr< simple >( new simple );
    }

    void call( void* context, std::function< void( void* ) > callback )
    {
        std::thread( [callback, context]() {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for( 5s );
            callback( context );
        } ).detach();
    }

    void safe_call()
    {
        std::weak_ptr< simple > weak_ptr = shared_from_this();
        call( this, [=]( void* context ) {
            if ( auto self = weak_ptr.lock() ) {
                std::cout << self << std::endl;
            }
        } );
    }

private:
    simple() = default;
};

int main()
{
    {
        auto s = simple::create();
        s->safe_call();
    }
    using namespace std::chrono_literals;
    std::this_thread::sleep_for( 10s );
    return 0;
}
