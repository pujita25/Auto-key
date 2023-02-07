***Autokey Cipher - Description***

* The Autokey cipher is a polyalphabetic substitution cipher, in which the key is based on the plaintext itself. In an autokey cipher, the plaintext is first used as a key to encrypt subsequent plaintext letters. The result is that the ciphertext depends not only on the key, but also on the plaintext message being encrypted, making it more secure than a simple substitution cipher.

***Documentation***
* The main code "auto-cipher.c" mainly consists of two functions - autp_encrypt and auto_decrypt.
* Once the user gives input in the terminal with 4 arguments which include a file with the text that has to be encrypted or decrypted another file to store the value of final encryption or decryption, a key and 1 or 0 to consider encryption(1) or decryption (0).
* Based on the input if the value 1 is given, the input will be encrypted and stored in the output file or if the value is 0 then the decrypt the key and store in the output file.
* The formula used to generate the encrypted key or decrypted key is done using polyalphabetic substitution cipher.
![image](https://user-images.githubusercontent.com/41941282/217128618-6598f9a1-742d-4acf-a646-04f7c5420a6c.png)

***Input/Output***

* when given the input "bewareattackisgonnahappenonsunday" the output generated is "tiyuimtrueykzwghgncrihvsabnzucsel"



***Steps to execute the program:***
* gcc -o auto-cipher auto-cipher.c
* ./auto inp.txt out.txt security 1 (for encryption)
* ./auto out.txt inp1.txt security 0 (for decryption)
