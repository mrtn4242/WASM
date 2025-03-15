// inspired by 
// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#embind
//
// compile with
// emcc -lembind -o show_primes.js primes.cpp

#include <thread>
#include <vector>
#include <emscripten/bind.h>

using namespace emscripten;

std::vector<int> compute_primes(int max_prime)
{
    // All integers can be factorized into products of primes.
    // Thus, any non-prime must be divisible by some prime, so
    // maintain a list of primes and for each number smaller 
    // than the maximum number to look for, investigate if it
    // is divisible by the known primes.
    std::vector<int> primes = {2};
    for(int i = 3; i < max_prime; i++)
    {
        bool is_prime = true;
        for(int prime : primes)
        {
            if (i%prime == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

std::vector<int> get_primes (int max_prime)
{
    // wait for a bit before computing, so we can verify that 
    // the gui is still active
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::vector<int> primes = compute_primes(max_prime);
    return primes;
}

EMSCRIPTEN_BINDINGS(Module)
{
    register_vector<int>("vector<int>");
    function("get_primes", &get_primes);
}

// ideas:
// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#embind
// https://emscripten.org/docs/porting/pthreads.html
// https://stackoverflow.com/questions/27473959/thread-using-emscripten
// https://github.com/emscripten-core/emscripten/issues/17372