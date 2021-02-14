# 3. Computer-Controlled Cutting

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group assignment: characterize your lasercutter's focus, power, speed, rate, kerf, joint clearance and types. </li>
    <li> Cut something on the vinylcutter.</li>
    <li>  Design, lasercut and document a parametric construction kit, accounting for the lasercutter kerf whiuch can be assembled in multiple ways.</li>
    <li> Try to include elements which aren't flat.</li>
  </ul>
</div>

<div class="dottedLine"></div>

This week is about computer-controlled cutting, meaning that we get to cut and slice things using digitally-controlled tools such as a laser or vinyl cutter.

This is very much linked with previous week's class as now, I'll have no other choice than to use CAD tools to make my design and then export them to the cutting tools.

I'll have 3 objectives this week.

- I would like to make a very small electronics circuit using copper tape and the vinyl cutter. I don't expect very nice results with it but if it works sufficiently well, then it might an extremely quick way to make some traces without the need to order a PCB or make using a CNC or chemical processes. Moreover, that makes for easy flexible circuits if I ever need some.

- Before this, I want to get some experiments using the vinyl cutter by simply slicing some stickers with some logos or customize a t-shirt using heat transfer!

- Finally, I have relatively big desk at work but just like every desk, it gets clumped with all sorts of stuff. My biggest issue is that my laptop rests on a cardboard box (so that it sits at eye-level) and sometimes when I need to takes notes during online meetings, I don't have enough room in front of my laptop because of this huge cardboard box. So I want to make a press-fit kit like a small table where I can leave my laptop on and slide my keyboard underneath.


## 1. Tools
Multiple tools exist to cut things. Some are more expensive, some are easier to use, some a safer but mainly it depends on what you want to do and especially the machines that you have available at your Fablab.

Among these:

### Knifes Tools
By knife tools I mean the tools that use a piece of metal like a knife to cut through paper (in 2D of course). The vinyl cutter is a perfect example of it.
At the Fablab ULB we have the Silhouette Camo 3 that uses a small blade to cut paper, cardboard ou textiles up to 30cm width and 3 meters long !
Cool feature: the blade can be replaced with a pen to make dashed lines and can locate itself on the paper using pattern images.

<figure> <center>
  <img src="./../../img/mod03/silhouetteCamo.jpg" alt="inkscape text" width="80%" />
  <figcaption> Our vinyl cutter</figcaption>
</figure>

There are multiple other types of knife tools that can punch, roll, shear paper... But those are super expensive and we don't have these kinds at the ULB.

Some cutters use ultrasonic energy to melt plastic or burn wood at the same time of cutting ! I would love to try one of these a day.


### Laser cutters
We have a [CO2 EPILOG FUSION PRO](https://www.epiloglaser.fr/machines-laser/fusion-pro-laser-series.htm) with a working surface of 30x60cm and that is interfaced with CorelDraw. The CO2 part means that the gain medium is actually CO2 ! The medium will change the light frequency of the laser and given that materials don't absorb all frequencies at the same level, the laser frequency will influence the type of material it can cut.

<figure> <center>
  <img src="./../../img/mod03/epilog.jpg" alt="epilog" width="80%" />
  <figcaption>Our epilog !</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/exhaust.jpg" alt="exhaust" width="80%" />
  <figcaption>And it's exhaust, an extremely important part !</figcaption>
</figure>

CO2 lasers are cheap and efficient but are limited to cardboard, wood and acrylic mainly. Fibers lasers can cut metals !

### And the rest !
Plasma cutters are for metal cutting by melting the metal (extremely hot plume). Waterjet cutters basically outputs water at supersonic speed that cuts through metal sheets, stones and almost everything (way more things than a laser cutter) and are mostly used in the industry. Hot wire cutters can be used to make artistical shapes in foam with a heating resistor a voltage on its ends. The end result is extremely smooth and the minimum diameter is of the wire itself which can be extremely low.

## To parametric design !
So in order to do a cardboard design using the laser cutter, we'll basically need to set the width of the slots and their depth. The width depends only on the cardboard thickness (and a margin) but can be therefore set in a parametric manner in the CAD tool (meaning that a simple change of the parameter variable will change the whole design).

### CAD tools
Basically we can use most of the tools described last week.
Inkscape for example has multiple [extension](https://inkscape.org/gallery/=extension/) that can be used to make it more parametric. It's fairly limited (we need to use clone parts so that they are linked) but still a possibility for laser cutting.
We also discussed other possibilities last week like Rhino and the Grasshopper extension.

There are also specifically designed tools for laser cutting, like [FlatLab](http://flatfab.com/) that I will maybe use at the end of the week to design an animal or something.

To complete my objective, I will personally be using FreeCAD (in sketcher workbench mode) that I learned last week and Solidworks as I know it well.
Execuc made a nice [module for FreeCAD](https://github.com/execuc/LCInterlocking) available on Github that can create interlocking cut parts from a 3D model, as 2D SVG ! I will try to use it but I need to understand the basics myself first.

### The ~~horse~~ machine whisperer
Getting a design is one thing but then you need to "inject" your design in the cutting machine. Each machine has its own drivers so this is one way of doing it. But other tools exist like [Deepnest](https://deepnest.io/). Deepnest is an open-source software that will optimize the cuts and the parts so waste the least amount of material and time (merging common lines and so on). This also will improve quality of the final results by avoiding heat warping (distortion in the material due to the heat of the laser) with every subsequent laser pass.

## 2. Machine setup and characterization
As part of the group assignment, [Jason](http://fabacademy.org/2021/labs/ulb/students/jason-pettiaux/) and I had  to characterize the laser cutter we were going to use.
We wanted to check a few things:
1. Check the focus
1. Measure kerf
2. Play with the power/speed ratio to find the good settings for our material for both cutting and engraving.

### Focus

For the focus it's actually quite simple. The Epilog as an automatic focus settings that uses a plunge to measure the material height and adjust the focus. It is however not to be used with soft materials as it will bump into it may leave traces ! Hopefully for us, the length of the waist of our laser cutter is quite long so it's hard to be really out of focus. Once the focus is done, no need to touch it again for the same material.
We couldn't test it but we suppose that if dramatically out-of-focus, then the power would be more dissipated in the material and it may be actually better for engraving?


### Kerf

To measure the kerf, we just need to cut a square and measure the difference between the expected width and measured width. Since we "lose" half a kerf unit on each laser pass, we lose a full kerf unit per square. To enhance the accuracy of the measurement, we cut 10 squares and placed them together: our result was therefore 10 times more accurate.

<figure> <center>
  <img src="./../../img/mod03/kerfMeasurement.jpg" alt="kerf" width="80%" />
  <figcaption> 96.7mm measured width from an expected 100mm</figcaption>
</figure>

We measured a kerf of 3.3mm for the 10 squares, therefore we have a kerf unit = 0.33mm. It is actually twice what we expected (the lasersaur that our Lab uses usually has a mean kerf of about 0.17mm) so it's a good thing we actually measured it before cutting parts of our construction kits.

### Power and speed

Finally to find the good speed and power ratio for our material, we prepared an SVG file with multiple squares of different colors that we could link to actual parameters in the Epilog software. Sometimes there is no need to reinvent the wheel so we just used the design of our predecessors but this time with the intent to test it on the Epilog and test the engraving capabilities.

<figure> <center>
  <img src="./../../img/mod03/laserCutterInkscape.png" alt="powerSpeedRatio" width="80%" />
  <figcaption></figcaption>
</figure>

What we could observe is that, as expected, the ratio of speed and power outputs the same result. It is quite logical as the slower the pass is, the more power is delivered to the material to ignite it and the more it pierces through the material.
That means that the energy given to the material is equal to the power delivered by the laser divided by the speed.


By varying the speed and power, we can also engrave different color gradation:
<video width="640" height="480" autoplay loop>
  <source src="./../../img/mod03/laserEngraving.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

The Epilog also has a "frequency" settings but even though playing with it, it did not yield visible result. It is still an unknown and is left at 100%.

### Lasersaur mirror aligning

We also tried to repair the [Lasersaur](https://www.lasersaur.com/) in our lab that was unfortunately out of order. We therefore spent quite a lot of time aligning the mirrors.

<figure> <center>
  <img src="./../../img/mod03/alignement1.jpg" alt="lasersaur" width="80%" />
  <figcaption>A white tape on the mirror and single laser pulse allows to align the mirror through trial and error</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/alignement2.jpg" alt="lasersaur" width="80%" />
  <figcaption> First point at small distance from the laser output: the point is slightly off-center</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/alignement3.jpg" alt="lasersaur" width="80%" />
  <figcaption> At greater distance, the offset is amplified and we can start aligning the mirror through trial and error</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/lasersaurInterface.jpg" alt="lasersaur" width="80%" />
  <figcaption> A simple small square is used as the cutting shape and allows for a small duration laser pulse</figcaption>
</figure>


## 2. My Vynil cutter design

So I used my newly acquired skill to slightly adjust the logo of my last year promotion.
<figure> <center>
  <img src="./../../img/mod03/logoInitial.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I first adjusted the colors in Photoshop to make the background black, then I selected the main center logo using the lasso tool before inverting the selection and removing the rest.

I was left with some unwanted pixels (due to the image rasterization) that I quickly painted in white (Locking the layer alpha channel and simply applying a white brush on inaccurate edges).

I then had to vectorize my image for the Vynil cutter software to cut it. I launched inkscape then "Path -> Trace bitmap" and used multiple scans and tweaked some parameters to end up with a nice vectorized image !

<figure> <center>
  <img src="./../../img/mod03/logoBiomed.png" alt="logo text" width="80%" />
  <figcaption> The adapated logo !</figcaption>
</figure>


Then I realized that to import it in Silhouette Studio, I needed a .dxf file so I tried to convert my SVG to it and ended up with a 30MB file that Silhouette never succeeded importing...

Anwyay I found out that I could simply import my PNG and it would vectorize inside the software !
By choosing "Select Trace Area" and tweaking the settings I had a nice trace for the machine to cut.




<figure> <center>
  <img src="./../../img/mod03/silhouettepng.jpg" alt="logo text" width="80%" />
  <figcaption> The PNG inside the Silhouette software</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod03/silhouettetrace.jpg" alt="logo text" width="80%" />
  <figcaption> Trace settings</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/silhouetteresult.jpg" alt="logo text" width="80%" />
  <figcaption> The output trace</figcaption>
</figure>

Then by clicking the Send button in the upper-right corner, you can change the settings of the blade and just cut your design.

### test cut to dial the cutter (highly dependant )
transfer of copper sheet to an epoxy film to make it stiffer and get a better resolution.


### Trying to make a flexible circuit
I wanted to test the capabilities of the copper sheets, sliced with the vynil cutter to make a small, flexible PCB. I used some copper sheet that I found at the lab and made a quick simple circuit in Altium. I also wanted to avoid a power source if possible so I tried to make some loops to act as a coil so that I could use an inductive link to power my circuit. Since the current will be AC, I use 4 schottky diodes to make a full-bridge rectifier. Finally, I chose a red LED as these require the less voltage to light up. All SMD components were found at my lab and are 1206.

One of the main requirements though was to avoid sharp corners as much as possible as sharp corners will cause reflection issues when working at high frequency (as with inductive link powering).

<figure> <center>
  <img src="./../../img/mod03/schematic.jpg" alt="schematic" width="80%" />
  <figcaption> A simple full-bridge rectifier and an LED</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/pcb.jpg" alt="logo text" width="80%" />
  <figcaption> The PCB design </figcaption>
</figure>

I exported it in a PDF from Altium and then vectorized it in Inkscape just like for my logo.

<figure> <center>
  <img src="./../../img/mod03/traceBitmap.jpg" alt="logo text" width="80%" />
  <figcaption> Edge detection to vectorize the bitmap image</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/printout.jpg" alt="logo text" width="80%" />
  <figcaption> The vectorized drawing for the vynil cutter </figcaption>
</figure>

The only thing that I had to look for was the actual scaling of my picture. I had to manually scale it so that the measurement on my PCB are the same as the distance on the vectorized image. The dimensions of my PCB are 78.74mmx76.2mm.

### How it (should) work

So the main idea is that power is transmitted from a primary to a secondary (my circuit). The device should work on the principle of mutual induction between the two coils. The magnetic flux generated by the emitter coil gets linked to the secondary and a voltage is generated in the secondary (also called EMF (electromotor force)).

The EMF is directly proportional to the derivative of the current in the primary (E = -d(phi)/dt, with phi the magnetic flux capted by the secondary which depends itself of the number of coils).

So basically, on the primary I will need a fast-switching current. Common AC voltage is 50Hz, which is absolutely not enough. The idea is therefore to use a class E amplifier which can translate DC current into alternative current with minimal loss (an oscillator circuit).

<figure> <center>
  <img src="./../../img/mod03/classE.jpg" alt="logo text" width="80%" />
  <figcaption> A classic class E </figcaption>
</figure>

Now I won't be making one, hopefully, I have a similar class E and coil available at my lab that is working at 300kHz. µ

By injecting 9V at the primary, I hope to be able to get at least a few volts after my full-wave rectifier to light up my LED (about 2V).

## 3. My laser cutter design
To make a parametric design in Solidworks, I had to make a basic sketch then go to "Tools -> Equations" and there I could add my variables. In my sketch dimension I could then refer to those variables.

<figure> <center>
  <img src="./../../img/mod03/variable.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/jointTester.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

I then made a drawing of my object and exported it in a TIF file. Back in Inkscape I can trace the bitmap and scale it to the correct dimensions. The red contour is so that in the Epilog software we can set it as a cut while black is the engraving of the numbers.

<figure> <center>
  <img src="./../../img/mod03/drawing.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod03/inkscapeComb.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


note: need chamfer on slots to help fitting it in and compress it so that it gets inside and stays there.
flexure in cardboard to make it flex for soft corners, curves...

kerf is the fact that the laser has a finite width and therefore we need to offset the laser path a bit on the external side to ensure the cutting happens actually on the chosen path.


## Mechanical iris in cardboard ?
maybe for machine day, to open it on the wire shelf... ?
