# 11. Molding and Casting

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group Assignment: Review the safety data sheets for each of your molding and casting materials. </li>
    <li> Group Assignment: Make and compare test casts with each of them</li>
    <li> Design a 3D mould around the stock and tooling that you'll be using, mill it (rough cut + (at least) three-axis finish cut), and use it to cast parts.</li>
  </ul>
</div>
<div class="dottedLine"></div>

## Group assignment
Jason and I [reviewed the safety datasheets and we made some test casts](http://fabacademy.org/2021/labs/ulb/assignments/week11/) with each molding material (or at least each family). This is recapped below:

### Safety
In particular, we tested (with the datasheets linked):

- [Sylgard 184 PDMS](https://www.wpiinc.com/media/wysiwyg/pdf/SDS/sylgard184-curing-agent.pdf)
- [Oomoo-30](https://www.smooth-on.com/msds/files/BD_DS_Eco_Equ_EZB_EZS_Psy_MS_OOMOO_Reb_ST_SS_Soma_Sol_Sorta.pdf)
- [Ecoflex 00-30](https://www.smooth-on.com/msds/files/BD_DS_Eco_Equ_EZB_EZS_Psy_MS_OOMOO_Reb_ST_SS_Soma_Sol_Sorta.pdf)
- [Elite Double 8](https://www.amtouch.com/images/ZHM-C400836.pdf)
- [Xencast PX90](https://3937524.app.netsuite.com/core/media/media.nl?id=55472&c=3937524&h=c841bef244b6c376b5be&_xt=.pdf)
- [SuperSap CLV bio-epoxy](https://3937524.app.netsuite.com/core/media/media.nl?id=42567&c=3937524&h=c38c9b00692bfe9898c3&_xt=.pdf)

We noticed that all datasheets are talking about gloves, long sleeves, ventilated area ("room size" ventialtion) and safety glasses. Because of this, we made to always work nitrile or latex gloves, lab coats, glasses and under a vent in the lab.

### Types and usages
Having a look at the various datasheets, we can see that some of them are bio-compatible (Elite double 8 for example, which is used for dental work). The materials are categorized according to their final hardness (shore), pot life and curing time, material, ...

<figure> <center>
  <img src="./../../img/mod11/dental1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod11/dental2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

_examples of instructions for use (Elite double 8):_

   0. Before using Elite Double, check that the model to be duplicated is perfectly clean. If it needs milling, be sure to remove any oily residues; use of a solvent such as acetone is recommended. Wait for steam to evaporate, if used, and make sure that the model is perfectly dry. Select a flask of appropriate size, then anchor the model onto its base with wax
   1. Measure or weight equal amounts of Catalyst (white) and Base (coloured) in a graduated container.
   2. Mix the two components well, until colour is even.
   3. slowly pour Elite Double, preferably from a height of about 30cm above the flask. If the quantity measured out is not sufficient to complete the process, wait until the silicone has hardened completely and then add more material the same way. The material will bind perfectly and the addition will have no effect on the final result. Use a jet of compressed air between the model and the mould created. Do not use mechanical force with a knife or other implement, and do not pull it away from the flask, or you may deform the mould

### Test casts
We used Petri dishes to test the different materials. We made sure to pour about 10g of each material, while respecting the mix prescribed by the manufacturer.

<figure> <center>
  <img src="./../../img/mod11/testCasts.jpg" alt="logo text" width="80%" />
  <figcaption>Preparing our materials</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod11/recap.jpg" alt="logo text" width="80%" />
  <figcaption>A recap list we made</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/vaccumVent.jpg" alt="logo text" width="80%" />
  <figcaption>Vacuum bell and vent</figcaption>
</figure>

We also played around with some pigments:
<figure> <center>
  <img src="./../../img/mod11/color.jpg" alt="logo text" width="80%" />
  <figcaption>Adding color</figcaption>
</figure>

and used the vacuum bell:
<figure> <center>
  <img src="./../../img/mod11/pdms1.jpg" alt="logo text" width="80%" />
  <figcaption>PDMS before vacuum</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/vacuum1.jpg" alt="logo text" width="80%" />
  <figcaption>Using the vacuum bell</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/vacuum2.jpg" alt="logo text" width="80%" />
  <figcaption>Bubbles are released</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/pdms2.jpg" alt="logo text" width="80%" />
  <figcaption>No more bubbles !</figcaption>
</figure>

Same goes for other materials:
<figure> <center>
  <img src="./../../img/mod11/oomoo.jpg" alt="logo text" width="80%" />
  <figcaption>The Oomoo 30</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod11/dental.jpg" alt="logo text" width="80%" />
  <figcaption>Elite double 8</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/px90.jpg" alt="logo text" width="80%" />
  <figcaption>PX90</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/epoxy.jpg" alt="logo text" width="80%" />
  <figcaption>Bio-epoxy with green pigments</figcaption>
</figure>


Our test casts:
<figure> <center>
  <img src="./../../img/mod11/result.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/result2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


## First project: repairing a broken glass
A friend of mine recently told me he broke a glass and wanted to repair it but didn't know how. Let's try to repair it this week.

The bottom of it was completely broken so I thought about making a quick 3D-printed mold and then pour some (coloured) epoxy on top of it. So I started designing a mold in Solidworks, that looks more or less like a bike wheel:
<figure> <center>
  <img src="./../../img/mod11/glass1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I made sure to add some chamfers in the design to help remove the mold (spoiler alert: it didn't !).

<figure> <center>
  <img src="./../../img/mod11/glass2.jpg" alt="logo text" width="80%" />
  <figcaption>Once 3D-printed</figcaption>
</figure>

I then applied a lot of mold release agent:
<figure> <center>
  <img src="./../../img/mod11/glass3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then prepared the epoxy and added some green pigments before pouring it into the mold.
<figure> <center>
  <img src="./../../img/mod11/glass4.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then end result is pretty nice !
<figure> <center>
  <img src="./../../img/mod11/glass5.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
But I can't seem to remove the mold. Next time, I'll use a soluble filament (PVA) so that I can easily dissolve the mold !

## Second project: remaking a chess piece
That same friend recently brought a chess board at work but he unfortunately lost a few pieces in the past years. The pieces themselves are quite artistic and would be extremely difficult to reproduce by 3D-printing or any other method ! It's perfect for molding !

<figure> <center>
  <img src="./../../img/mod11/chess1.jpg" alt="logo text" width="80%" />
  <figcaption>The original piece</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/chess2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I placed it in a container but because I was afraid it the bottom would fill, I made sure to make a vent at the top (in the end it wasn't necessary though).
<figure> <center>
  <img src="./../../img/mod11/chess3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I placed it in a pyrex container (bad idea !)
<figure> <center>
  <img src="./../../img/mod11/chess4.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

And then prepared the silicone mix. I used the Oomoo-30 as it was the most recommended one to make mold and the only one I had at hand at this moment.

<figure> <center>
  <img src="./../../img/mod11/chess5.jpg" alt="logo text" width="80%" />
  <figcaption>Vacuuming</figcaption>
</figure>

I then filled my container with it but... I didn't prepare enough... Okay let's raise the silicone level by inserting some Play-doh inside.

<figure> <center>
  <img src="./../../img/mod11/chess6.jpg" alt="logo text" width="80%" />
  <figcaption>Not beautiful but I had no time to prepare a new batch</figcaption>
</figure>


### The day after
So I came back the day after with the expectation to unmold that pretty easily... Oh was I so wrong !
<figure> <center>
  <img src="./../../img/mod11/chess7.jpg" alt="logo text" width="80%" />
  <figcaption>Cured silicone</figcaption>
</figure>

It just sticked so much to the container I had to try to unmold it for a few tens of minutes with a scalpel, a screwdriver and anything else I could find. Looking back, I never should have done it inside this container !

I finally did it but the mold really took a hit.
<figure> <center>
  <img src="./../../img/mod11/chess8.jpg" alt="logo text" width="80%" />
  <figcaption>Victory !</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/chess9.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/chess10.jpg" alt="logo text" width="80%" />
  <figcaption>How am I going to clean that ??</figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod11/chess11.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


### The new piece
Now that I have a mold, I can pour epoxy in it and get a nice copy of my piece.
<figure> <center>
  <img src="./../../img/mod11/chess12.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod11/chessBis.jpg" alt="logo text" width="80%" />
  <figcaption>The inside of the mold</figcaption>
</figure>

But since I broke my mold while trying to unmold it... I had to find rubber bands to get it to hold together. I had none.
So let's tinker a bit with a latex glove !
<figure> <center>
  <img src="./../../img/mod11/chess13.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod11/chess14.jpg" alt="logo text" width="80%" />
  <figcaption>That will do it... I hope</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/chess15.jpg" alt="logo text" width="80%" />
  <figcaption>Pouring epoxy</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/chess16.jpg" alt="logo text" width="80%" />
  <figcaption>Filled mold</figcaption>
</figure>

Now we just have to wait and hope the molds holds together for the curing time.

### The day after... again
Epoxy has cured, time to unmold!

<figure> <center>
  <img src="./../../img/mod11/chess17.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
The result is quite satisfying... But far from perfect.

<figure> <center>
  <img src="./../../img/mod11/chess18.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/chess19.jpg" alt="logo text" width="80%" />
  <figcaption>It will need a bit of post-processing</figcaption>
</figure>

Let's cut the excess and polish the rest with sand-paper.
<figure> <center>
  <img src="./../../img/mod11/chess20.jpg" alt="logo text" width="80%" />
  <figcaption>After polishing</figcaption>
</figure>


### The comparison and end result
Can you tell the difference ?
<figure> <center>
  <img src="./../../img/mod11/chess21.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod11/chess22.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

## Third project: Inception spinning top
Finally, let's make a spinning top!

First, [I found a nice design](https://grabcad.com/library/inception-spinning-top-1), inspired from the Inception on movie.
<figure> <center>
  <img src="./../../img/mod11/inception.jpg" alt="logo text" width="80%" />
  <figcaption>From GrabCad</figcaption>
</figure>
### Positive mold
First step: designing the positive mold in Solidworks so that I can machine it.
To create the mold in Solidworks:

I created a basic rectangle which is bigger than the spinning top.
<figure> <center>
  <img src="./../../img/mod11/sw1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then created an assembly which contained both the "mold rectangle" and my spinning top.

<figure> <center>
  <img src="./../../img/mod11/sw2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I then placed it right in the middle using the centerlines of the top and the rectangle:
<figure> <center>
  <img src="./../../img/mod11/sw3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then I thought about using the cavity feature:
<figure> <center>
  <img src="./../../img/mod11/sw4.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/sw5.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

But no... That's a negative mold... I need a positive ! Let's go back and use the "join" feature.
<figure> <center>
  <img src="./../../img/mod11/sw6.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then I designed some walls around it:
<figure> <center>
  <img src="./../../img/mod11/sw7.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then silicone inputs and exhausts:
<figure> <center>
  <img src="./../../img/mod11/sw8.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Finally, I'll need to make it twice to get the full object and to help both parts of the mold to stay together, I designed some bits (two extrusion and two cuts):
<figure> <center>
  <img src="./../../img/mod11/sw9.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

### Machining
Just like I did in the CNC week, I used Solidworks with HSMWorks and the KineticNC post-processor.

**1. 2D pocket with a 6mm flat mill to get rid of most of the material around the spinning top:
**
<figure> <center>
  <img src="./../../img/mod11/cnc1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/cnc2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/cnc3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


**2. 3D pocket with 6mm flat mill to remove layers on top of the spinning top:
**
<figure> <center>
  <img src="./../../img/mod11/cnc4.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/cnc5.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/cnc6.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

**3. Fine pass with a 3mm flat mill to get in the corner and around the alignment bits:
**
<figure> <center>
  <img src="./../../img/mod11/cnc7.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod11/cnc9.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
**4. Making the 2 holes for the alignment bits:
**
**Note:** for an unknown reason here, the mill went straight between the top of the holes and hit my part (luckily just a very small part of it). It is strange because I took special care for that not to happen and, in the toolpath simulation, it does not happen...

**5. Parallel pass to get a nice finish with a 3mm ball mill:
**<figure> <center>
  <img src="./../../img/mod11/cnc8.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/cnc10.jpg" alt="logo text" width="80%" />
  <figcaption>Left: parallel to do, right: done already</figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod11/cnc11.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

**6. Parallel pass on the exhausts and silicone inputs
**<figure> <center>
  <img src="./../../img/mod11/cnc12.jpg" alt="logo text" width="80%" />
  <figcaption>Note how I changed the angle to make sure I have a nice finish</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/cnc13.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

### Making the negative
Just like for the chess piece, I used Oomoo-30. Simply mixing them 1:1, vacuuming and pouring. I made sure to slightly coat the positive mold with release agent before pouring. It still sticked hard so I had to play with a lot before being able to get it out of the mold once cured.

<figure> <center>
  <img src="./../../img/mod11/mold1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

The result is pretty good though.

<figure> <center>
  <img src="./../../img/mod11/mold2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I did the same thing for the second part, this time with much more release agent. It was indeed easier to remove but there was so many agent that it left some holes and the surface finish is not great.

<figure> <center>
  <img src="./../../img/mod11/mold3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Assembling both parts with rubber bands:
<figure> <center>
  <img src="./../../img/mod11/mold4.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/mold5.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I was very afraid the input holes were too tiny and there would be a lot of air inside the mold, so I played a bit with a syringe to make sure to pop all of them.
After curing, we can open the mold:

<figure> <center>
  <img src="./../../img/mod11/mold6.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
The result is not as bad as I thought and it's actually quite nice.
<figure> <center>
  <img src="./../../img/mod11/mold7.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I still need to cut the excess:
<figure> <center>
  <img src="./../../img/mod11/mold8.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
And polish everything with sand-paper:
<figure> <center>
  <img src="./../../img/mod11/mold9.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Still some bubbles on the top but it's not that bad:
<figure> <center>
  <img src="./../../img/mod11/mold10.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod11/mold11.jpg" alt="logo text" width="80%" />
  <figcaption>End result</figcaption>
</figure>

<video width="650" autoplay loop>
  <source src="./../../img/mod11/spin1.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<br>

<video width="650" autoplay loop>
  <source src="./../../img/mod11/spin2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>


## My design files
:material-download-box: [My Design files](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/ulb/students/maxime-verstraeten/-/raw/master/docs/files/mod11.zip)
