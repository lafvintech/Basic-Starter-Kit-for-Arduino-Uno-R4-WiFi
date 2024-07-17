# LED

Just as printing “Hello, world!” is the first step in learning to program, using a program to drive an LED is the traditional introduction to learning physical programming.

## Wiring

<<<<<<< Updated upstream
[![](https://docs.sunfounder.com/projects/elite-explorer-kit/en/latest/_images/10-led_bb.png)](https://docs.sunfounder.com/projects/elite-explorer-kit/en/latest/_images/10-led_bb.png)

## Schematic Diagram

[![../_images/10_led_schematic.png](https://docs.sunfounder.com/projects/elite-explorer-kit/en/latest/_images/10_led_schematic.png)](https://docs.sunfounder.com/projects/elite-explorer-kit/en/latest/_images/10_led_schematic.png)
=======
![](./img/RGB_wiring.png)
>>>>>>> Stashed changes

## Code

> **Note:**
>
<<<<<<< Updated upstream
> * You can open the file `10-led.ino` under the path of `elite-explorer-kit-main\basic_project\10-led`.
=======
> * You can open the file `10-led.ino` under the path of `Basic-Starter-Kit-for-Arduino-Uno-R4-WiFi-main\10-led`.
>>>>>>> Stashed changes

<div style="border: 1px solid #f0f0f0; padding: 10px; background-color: #e6ffe6;">
  <strong>Note:</strong> This is a note box created using HTML.
</div>

## Code Analysis

Here, we connect the LED to the digital pin 9, so we need to declare an `int` variable called `ledpin` at the beginning of the program and assign a value of 9.

constintledPin=9;
Now, initialize the pin in the `setup()` function, where you need to initialize the pin to `OUTPUT` mode.

```cpp
voidsetup()
{
pinMode(ledPin,OUTPUT);
}
```

In `loop()`, `digitalWrite()` is used to provide 5V high level signal for ledpin, which will cause voltage difference between LED pins and light LED up.

```cpp
digitalWrite(ledPin,HIGH);
```

If the level signal is changed to LOW, the ledPin’s signal will be returned to 0 V to turn LED off.

```cpp
digitalWrite(ledPin,LOW);
```

An interval between on and off is required to allow people to see the change, so we use a `delay(1000)` code to let the controller do nothing for 1000 ms.

```cpp
delay(1000);
```
