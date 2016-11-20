#Hamming code register (15,11) using SystemC 


this is an implementation of a Hamming code register that can:

* code a 11 bits’ input word into a 15 bits' hamming code word.
* correct a 15 bits’ hamming code word and extract the original 11 bits’ word.


##The hamming code’s register structure 

![Hamming](http://i.imgur.com/XogJSxs.png)


##The test bench and the testing system structure


![System Structure](http://i.imgur.com/oC5zs8w.png)


##Note
the parity bits are added to the end of the word and not to the power of two positions.
