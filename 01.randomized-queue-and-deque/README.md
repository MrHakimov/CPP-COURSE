# EN | Short description of implementation
To implement the interface of randomized queue I used vector:
* ```cpp
empty()
```
returns `ourVector.empty()`
* `size()` returns `ourVector.size()`
* `enqueue(x)` simply pushes element `x` to the end of our vector - `ourVector.push_back(x)`
* `sample()` returns random element from our vector
* `dequeue()` gives an element at random position, swaps it with the last element at our vector and removes the last element from our vector
