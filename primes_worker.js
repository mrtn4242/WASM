// Inspired by:
// https://niekdeschipper.com/projects/emscripten.html

importScripts("./show_primes.js")

Module.onRuntimeInitialized = () => {
    console.log("Worker module runtime initialized");
    var primes_cpp = Module.get_primes(5000);
    console.log("Found " + primes_cpp.size() + " primes");
    
    // Copy to js array prior to posting the message
    // as the receiver had trouble opening it.
    const primes_js = new Array(primes_cpp.size());
    for (var i = 0; i < primes_cpp.size(); i++) {
        primes_js[i] = primes_cpp.get(i);
    }
    self.postMessage(primes_js);
}