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
We have a [CO2 EPILOG FUSION PRO](https://www.epiloglaser.fr/machines-laser/fusion-pro-laser-series.htm) with a working surface of 30x60cm and that is interfaced with CorelDraw. The CO2 pârt means that the gain medium is actually CO2 ! The medium will change the light frequency of the laser and given that materials don't absorb all frequencies at the same level, the laser frequency will influence the type of material it can cut.

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
Getting a design is one thing but then you need to "inject" your design in the cutting machine. Each machine has its own drivers so this is one way of doing it. But other tools exist like [Deepnest](https://deepnest.io/). Deepnest is an open-source software that will optimize the cuts and the parts so waste the least amount of material and time (merging common lines and so on). This also will improve quality of the final results by avoiding heat warping (distortion in the material due to the heat of the laser) with every subsequent laser pass

## 2. My Vynil cutter design

So I used my newly acquired skill to slightly adjust the logo of my last year promotion.
<figure> <center>
  <img src="./../../img/mod03/logoInitial.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I first adjusted the colors in Photoshop to make the background black, then I selected the main center logo using the lasso tool before inverting the selection and removing the rest.

I was left with some unwanted pixels (due to the image rasterization) that I quickly painted in white (Locking the layer alpha channel and simply applying a white brush on inaccurate edges).

And that's it !
<figure> <center>
  <img src="./../../img/mod03/logoBiomed.png" alt="logo text" width="80%" />
  <figcaption> The adapated logo !</figcaption>
</figure>


### test cut to dial the cutter (highly dependant )
transfer of copper sheet to an epoxy film to make it stiffer and get a better resolution.


## 3. My laser cutter design
note: need chamfer on slots to help fitting it in and compress it so that it gets inside and stays there.
flexure in cardboard to make it flex for soft corners, curves...

kerf is the fact that the laser has a finite width and therefore we need to offset the laser path a bit on the external side to ensure the cutting happens actually on the chosen path.


## Mechanical iris in cardboard ?
