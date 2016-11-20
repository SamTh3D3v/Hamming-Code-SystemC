#Hamming code register (15,11) using SystemC 


This is a simple implementation of a basic Hamming code register that can:

* code an 11 bits’ input word into a 15 bits' hamming code word.
* correct a 15 bits’ hamming code word and extract the original 11 bits’ word.


##The hamming code’s register structure 

![Hamming](http://i.imgur.com/XogJSxs.png)


##The testing system structure


![System Structure](http://i.imgur.com/oC5zs8w.png)


##Note
the parity bits are added to the end of the word and not to the power of two positions.

[SystemC envirenement setup on gcc!](http://users.ece.utexas.edu/~gerstl/ee382v_f09/docs/SystemC_setup.pdf)

[About Hamming code!](https://en.wikipedia.org/wiki/Hamming_code)
