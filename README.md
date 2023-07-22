# cd30mp3 as hid usb keyboard

Hardware:
- Arduino pro micro
- 2x 104 ceramic capacitor
- 2x 100ohms resistance
- 2x 10kohm resistance
- colored wires

Steps done:
- I've disassembled the panel and I've measured resistance between contacts
- I've soldered 16 colored wires to the panel connector contact points
- I've found on the russian forum drive2 this image to understand fully how leds and rotary encoder works
- More info in the cd30mp3_keyboard.ino file

### colored wires to the panel connector contact points
<img src="https://github.com/Gioee/cd30mp3_keyboard/assets/48024736/86b0b80c-f59a-4a22-a479-239a9194c31b" width="300">

### contact scheme
<img src="https://github.com/Gioee/cd30mp3_keyboard/assets/48024736/5cb8f3ed-896e-4d44-acbd-a43ea1d80ca5" width="300">

### I've used the two 10kohm resistance as pull down resistance for the encoder A and encoder B pins, and the two 104 ceramic capacitor as [filter to clean signal](https://www.arrow.com/en/research-and-events/articles/using-capacitors-to-filter-electrical-noise), the two 100ohms resistance are used between the pulldown resistance and the signal filter to connect them in series
<img src="https://github.com/Gioee/cd30mp3_keyboard/assets/48024736/c453d9f6-32de-4578-b4e0-0582905fd950" width="300">
<img src="https://github.com/Gioee/cd30mp3_keyboard/assets/48024736/220fbf40-086b-4a47-a7bf-d7b8ba2df210" width="300">
<img src="https://github.com/Gioee/cd30mp3_keyboard/assets/48024736/43fbb4fb-03ab-4a6d-af9b-a687e0db3199" width="300">

## FINAL RESULT
<img src="https://github.com/Gioee/cd30mp3_keyboard/assets/48024736/e96e1d49-aae8-496d-837a-a722018118a9" width="300">




Image of the contact scheme taken from: https://www.drive2.ru/l/8687044, all rights reserved.
