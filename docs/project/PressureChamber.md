# Pressure chamber

To model the detrusor pressure, some researchers developped a pressure chamber in which they can control the inside pressure.
<figure> <center>
  <img src="./../../img/finalProject/pressureBox.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Existing pressure chamber</figcaption>
</figure>


It is very basic and I would try to re-do it while adding some features.

## Objective
The objective is to have an hermetic box connected to a pressure sensor and a pump and be able to reach 1.5atm of pressure inside the chamber. A nice addition would be to be able to suddenly open a valve to have a very fast increase of pressure but this has not been done (yet !).

## The mechanical design

The design is very simple, a rectangular box in plexiglass (PMMA) with some inputs and outputs. To make sure these outputs are sealed and airtight, I use a D-sub 25 connector for the electronics with additional flange and screw kit for sealing, and I apply a silicone sealing around each fluidic connector (barbed and Luer locks connectors).

The dimensions are: 250x300x350mm

I use wood for the bottom plate in order to have a stable base that is high enough to be able to screw things in it.

### Plexiglass
The plexiglass is recycled from other various projects so there are multiple colors and multiple width.

<figure> <center>
  <img src="./../../img/finalProject/plexi1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>The plexiglass I found</figcaption>
</figure>

I cut it using the laser cutter (and Inkscape basic shapes like rectangles and arcs).

<figure> <center>
  <img src="./../../img/finalProject/plexi2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/plexi2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/plexi.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Some power and speed tests</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/plexi2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/plexi3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Before</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/plexi2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>After</figcaption>
</figure>

To hold it all together, I designed and 3D-printed some very simple holders with chamfers in which to slide the sheets and used the Acrifix192 glue which is made for PMMA.

<figure> <center>
  <img src="./../../img/finalProject/holder.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

The glue cures with UV light (about 20min outside in the sun). I tried to use a UV light machine to make it cure faster but it doesn't really work out because the UV spot is too small to be useful and because the light diffuses in the plexiglass.

<figure> <center>
  <img src="./../../img/finalProject/acrifix1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/acrifix2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/acrifix3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/acrifix4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/collage0.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/collage1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/collage2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

I succeeded in finding a sheet of transparent plexiglass but it is 5mm thick instead of 3 so it is a bit hard to glue with the others.

<figure> <center>
  <img src="./../../img/finalProject/collage3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


Once everything is glued together, here is the final result
<figure> <center>
  <img src="./../../img/finalProject/collage4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

### Plexiglass window
To be able to quickly change the connectors if needed and connect some wires, I made a window that is easily removable and airtight with some silicone. For the electronics, I use a D-sub 25 connector with its sealing kit so I will need to draw it in my design. I also add some holes for the fluidic connectors and tubes.

<figure> <center>
  <img src="./../../img/finalProject/dSubSealing.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>The sealing kit uses a specific IP-67 seal, some specific washers and some nuts</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/dsub.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/windowPlexi.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

I cut it using the laser cutter as well (20% speed, 100% power) and made a slight channel to pour silicone in, using the engraving method (resolution = 500, speed = 40%, power = 100%).

<video width="700" height="480" autoplay loop>
  <source src="./../../img/finalProject/plexiWindow1.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<video width="700" height="480" autoplay loop>
  <source src="./../../img/finalProject/plexiWindow2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<figure> <center>
  <img src="./../../img/finalProject/plexiWindowCut.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/windowPlexi2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Before assembly</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/windowPlexi3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>After assembly</figcaption>
</figure>


### Wood
For the wood, I recycled a piece used for other projects, cut it and then I used the CNC (6mm flat end mill bit) to cut a channel in which the PMMA will slide.

<figure> <center>
  <img src="./../../img/finalProject/wood1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/wood2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/wood3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/wood4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/wood5.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/wood6.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


## Assembly of the chamber
Once everything is glued together, here is the final result:
<figure> <center>
  <img src="./../../img/finalProject/collage4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


## Final result

With everything in place: electronics, the phantom, the chamber, here is how it looks like:
<figure> <center>
  <img src="./../../img/finalProject/collage4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/final1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/final2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/final3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/final4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/final5.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/final6.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


<video width="700" height="480" autoplay loop>
  <source src="./../../img/finalProject/completeChamber.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>
