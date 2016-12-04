# RPNCalculator
RPN based postfix calculator with trigonometric and logarithmic functions
####**Stack and queue based calculator.**
It's take infix form and turn these to postfix and calculate.

It also has trigonometric and logarithmic functions.

I used stacks for operators. However, I used a `double-ended queue` to do the transaction and sent it back to the transaction queue.
I have specified a letter for the functions. I thought of this as an operator and I processed it.
##NOTE : IF YOU CANT COMPILE IN DEVC++ YOU HAVE TO ADD `-std=c++11` on compiler options	
Because string functions are C++11 standards.

Tools->Compiler Options->`-std=c++11`
