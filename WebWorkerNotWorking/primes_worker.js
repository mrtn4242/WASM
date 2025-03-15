// https://www.geeksforgeeks.org/how-to-run-a-function-in-a-separate-thread-by-using-a-web-worker-in-javascript/
self.onmessage = (e) => {
    console.log("Worker: Message received from main script");
    const func = new Function( 
        "return" + e.function
    )(); 
    
    var primes = func(e.data[0])
    console.log("Worker: Posting primes back to main script");
    postMessage(primes)
}