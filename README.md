# binary-counter
Arduino LED based binary counter.

The setup is super easy, each LED is plugged into an arduino pin and they are all grounded. All the LEDs have a 330 ohm resistor on it as well. See the picture below on how to hook it up.

Changing the variables, the pins need to be in __sequential order__ e.g. 9-12 or 5-7. you edit the pinMin and pinMax variables, you also want to edit the loopMax variable, the code will not display any numbers that aren't possible to display on the given pins via the `pinMin` and `pinMax` variables.

Happy coding!

![IMG_5197](https://github.com/n-tdi/binary-counter/assets/79174456/6813790d-8349-4a62-9f0c-bfc00f839a65)
