# 6. Computer-Controlled Machining

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group assignment: Do your lab's safety training.
</li>
    <li> Test runout, alignment, speeds, feeds, materials, and toolpaths for your machine.</li>
    <li> Make (design+mill+assemble) something big (~meter-scale) </li>
  </ul>
</div>
<div class="dottedLine"></div>

# Introduction
This week is about making something "big". It started with a lack of interesting idea and I didn't want to make "just" another table or chair...
Got it ! **Let's make an electric guitar** !

# Introduction to the CNC
Before I dive into the extremely complicated design of my guitar, I spent an afternoon with Christophe so that I could get an understanding of how the CNC works and what I can/cannot do with it.

## The CNC itself
The CNC is a computer-controlled machine that generally means is motorized and can move in multiple directions, according to the files that are fed into the program.
In this particular case, when I refer to the CNC, I will refer to the CNC machine that we have at our Fablab: a [HIGH-Z S-1000](https://www.cnc-step.com/cnc-router-1000x600-s-1000t-ballscrew/) that is controlled with the [Kinetic-NC](https://www.cnc-step.com/cnc-software/kinetic-nc-cnc-control-software/) software.

<figure> <center>
  <img src="./../../img/mod07/cnc.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


Using the correct milling bits, it is able to cut through wood, aluminum and some other materials in 2.5D (i.e. 2D with different heights and depths).

## Equipment
We lack a bit of mills at the Fablab so we were limited to using only 6mm and 3mm flat mills (201043 from Hoffman Group).
Mills are usually defined by a few parameters:
- The material they are made of
- Their diameter
- The number of flutes (i.e. the number of sharp edges at the bottom of the mill)
- The surfacing speed (in m/min)
- The feed per tooth (mm)
- The cutting, shoulder and total length

Most of these parameters depend on the material we want to cut and not all mills are adapted to every material.
**It is therefore extremely important to use the reference catalog**.


<figure> <center>
  <img src="./../../img/mod07/catalog1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/catalog2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

_Note that wood is almost never indicated so we take the aluminum parameters. Some mills require coolant but we do not have any at the lab and when working on wood, it must not be used otherwise the wood will be soaked._

We can see that in the case of our 201043 mill with 3mm diameter, we can use a surfacing speed of 170m/min and 0,008mm of feed per tooth. The cutting length is 22mm and the total length 75mm.

The surfacing speed and the diameter will have an impact of the rotation speed (spindle speed), luckily, the CAM software computes this for us. However, our CNC has only present spindle speed settings (9000, 14000, 20000rpm mainly) so we must choose the closest one and adapt the surfacing speed to it.

The Kinetic-NC software is pretty easy to use and has two mains menus: jog and program. The first one allows to move the CNC around manually and zero the machine. The latter is used to load a CAM process and run. We can also slightly adjust the parameters once the program is running (0-150% spindle speed and feed per tooth).

## Safety
A CNC machine can be a dangerous tool. The one at our lab cannot run whenever its doors are open and is automatically stopped whenever a door is opened. Moreover, one must always stay close to it when running in case something goes wrong. Cutting causes a lot of friction and heat and one must be extremely vigilant about it.

Also, it is always better to double-check your CAM process in the CAM software and in Kinetic-NC. An "air pass" is usually recommended at least for the first job on the part to make sure the stock is correctly placed and the zero is correctly set.

A CNC working can be quite loud so ear protections are recommend, especially if you spend your whole weekend in the lab :smile:. Eye protection can be useful especially if the CNC is open, in which case a dust mask can also be proven useful.

## Dust collection
Because CNCing something will create a lot of waste material, it is important to remove them in-between two jobs. I used a cyclone vacuum to remove most of the waste material but it ended up a bit blocked at the end... I then used a classical vacuum cleaner.

## Making a CAM design
To test the CNC possibilities, I designed a small piece in SolidWorks that features sharp and round edges, engraving and enclosed and open holes (through all and blind).

<figure> <center>
  <img src="./../../img/mod07/testPiece.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

That was the easy part. Now time to make the CAM job.
Since I use SolidWorks, I had to install a CAM addon (newer SolidWorks version should have it installed but I didn't for whatever reason). I went with the [Autodesk HSMWorks](https://www.autodesk.com/products/hsmworks/overview?plc=F360&term=1-YEAR&support=ADVANCED&quantity=1) software (free for edu students... How to access it after then ?).

Once installed (and the computer rebooted), a CAM menu appeared on the top ribbon.

<figure> <center>
  <img src="./../../img/mod07/HSMRibbon.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

### Setting up the job
The first step is to create a new job.

<figure> <center>
  <img src="./../../img/mod07/job.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
Inside the job settings, I need to set the coordinates system (selecting edges that will be my X and Y axis and a zero-position for the machine). On our CNC, the X axis is the longer one so I place the X axis along the longest edge.

<figure> <center>
  <img src="./../../img/mod07/WCS.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


Then, I set the dimension of my stock, in this virtual test, I set my stock to be a fixed size box of 300x300x22mm.

<figure> <center>
  <img src="./../../img/mod07/testStock1.jpg" alt="logo text" width="80%" />
  <figcaption>Default fixed size box stock settings</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/testStock2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I could then set my zero-position of the machine to be the either a selected point on my model or another point such as the top left corner of my stock.

<figure> <center>
  <img src="./../../img/mod07/testStock3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

One need to be very careful about the orientation of the axis, in particular the Z one.

### Surfacing the part
The first step is to surface the part. This will create an even surface for the part relative to the machine axis and will ensure that the finish surface is smooth and "new". To avoid surfacing the whole surface of the CNC or the whole stock, I can create a new sketch that will be my surfacing boundaries (Later I found that I could actually surface the model contour, see below).

<figure> <center>
  <img src="./../../img/mod07/testSurfacing.jpg" alt="logo text" width="80%" />
  <figcaption> The square sketch is the boundary for surfacing</figcaption>
</figure>


#### Tool library

I then had to choose the tool that I was going to use for this job. Usually, this step is done once for all projects and the mills are stored in a tool library but for this first time I had to do it now.

<figure> <center>
  <img src="./../../img/mod07/newTool1.jpg" alt="logo text" width="80%" />
  <figcaption> Tool number "1"</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod07/newTool2.jpg" alt="logo text" width="80%" />
  <figcaption> Setting up the diameter </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/newTool3.jpg" alt="logo text" width="80%" />
  <figcaption> Setting up the surfacing speed and feed per tooth as well as the number of flutes </figcaption>
</figure>

I could then set several settings for my surfacing: the contour to surface but also the height (top and bottom), the stepover between each pass and the maximum depth of a pass (usually set to maximum half the diameter of the mill, in this case I used 2.5mm for a 6mm mill).
Here is the result of the surfacing job.

<figure> <center>
  <img src="./../../img/mod07/testSurfacing2.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>

### 2D Pocket
A 2D pocket is a job that allows to cut inside the part to make a hole (a pocket). One must select the contour and either the bottom height or the contour surface to set the depth. It is extremely important to set the "multiple depths" settings to on to preserve the mill.

<figure> <center>
  <img src="./../../img/mod07/2DPocket1.jpg" alt="logo text" width="80%" />
  <figcaption> Selecting the contour </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/2DPocket2.jpg" alt="logo text" width="80%" />
  <figcaption> Setting the height, when going through, you can go a bit lower to make sure you go through the whole part</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/2DPocket3.jpg" alt="logo text" width="80%" />
  <figcaption> Multiple depths !</figcaption>
</figure>

One can set a "stock to leave" if using a big mill to then finish the job with a softer touch and a smaller mill (using the 2D contour job). If only one pass (which I did for my guitar as I had not much time, then set it to off !).


### 2D Adaptive and other
Adaptive clearing means that the program will try to compute the path to reduce the load on the mill. However, this usually result in a longer toolpath but the material undergoes less force and pressure so the finish is usually better. There is no multiple depth settings there.

A lot of the options are also available. In particular, the 2D engraving too but also the 3D jobs that allow to make slopes with the parallel, 3D pocket, 3D adaptive, scallop jobs, ... I used some of them to make my guitar.

### Simulating
The final step before exporting the CAM is to simulate it. This allows to see the time it will take and help detect any issues. I highly recommend to do it.

## Making my guitar !
### Getting inspirations and references
So I started off looking for inspirations and plans... Since I'll have to design it in a CAD software, better to have some good references before starting to work.

<figure> <center>
  <img src="./../../img/mod07/references.jpg" alt="logo text" width="80%" />
  <figcaption> Looking online to find references</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/stratRef.jpg" alt="logo text" width="80%" />
  <figcaption> Something like that</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/stratRef2.jpg" alt="logo text" width="80%" />
  <figcaption> That a beginning but it lacks dimensions</figcaption>
</figure>

I found some plans online but most of them were extremely pricey (we talk about 30-100$ for the plans, ouch)...
Until I foud this [gem](https://www.electricherald.com/diagrams/stratocaster/Stratocaster-Guitar-Plan-01.pdf)

<figure> <center>
  <img src="./../../img/mod07/stratRef3.jpg" alt="logo text" width="80%" />
  <figcaption> Ok I can start working now !</figcaption>
</figure>

### The CAD design
I used Solidworks to design my guitar. I used this nice little tool available in SW to import a .png inside my sketch so that I can "copy" the shape of the guitar and I use the dimensions reference on the plan. The steps are: Tools menu - sketch tools - sketch picture

<figure> <center>
  <img src="./../../img/mod07/plans.jpg" alt="logo text" width="80%" />
  <figcaption> Adding my plan to my sketch workspace</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch1.jpg" alt="logo text" width="80%" />
  <figcaption> I can start drawing now</figcaption>
</figure>

I started with the face "A" (or the top face). I used straight lines but also splines (and adjusting them multiple times), ellipses and sketch fillet. I also took some liberties on the upper part on the shape to make it more "my own".

<figure> <center>
  <img src="./../../img/mod07/sketch2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

until I realized it was not the correct size :smile:. Obviously the png had been resized. So I used Inkscape with the 1:1 template, some SolidWorks measurements and a bit of math to compute the length between the neck and the bottom (344mm). I then scaled my SolidWorks sketch to get this distance.

<figure> <center>
  <img src="./../../img/mod07/sketch3.jpg" alt="logo text" width="80%" />
  <figcaption>575.57mm initial measurement so I need to scale by 577.57/344 = 1/1.678 = 0.595
</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch4.jpg" alt="logo text" width="80%" />
  <figcaption>Sketch scaling</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch5.jpg" alt="logo text" width="80%" />
  <figcaption>575.57mm initial measurement so I need to scale by 577.57/344 = 1/1.678 = 0.595
</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod07/sketch6.jpg" alt="logo text" width="80%" />
  <figcaption>"close enough" but now, if I want to keep using the template, I need to resize it as well
</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch7.jpg" alt="logo text" width="80%" />
  <figcaption> Resized template</figcaption>
</figure>

Let's extrude and boss everything we need. In a tens of minutes of work, the bottom is done !

<figure> <center>
  <img src="./../../img/mod07/sketch8.jpg" alt="logo text" width="80%" />
  <figcaption> Bottom !</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch9.jpg" alt="logo text" width="80%" />
  <figcaption> Time to make the upper part, I added transparency on the white color of the picture sketch to be able to see the extruded part</figcaption>
</figure>

For the top part, all of the holes are different depth so here are the intermediate and final results !

<figure> <center>
  <img src="./../../img/mod07/sketch10.jpg" alt="logo text" width="80%" />
  <figcaption> First holes </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch11.jpg" alt="logo text" width="80%" />
  <figcaption> All holes done </figcaption>
</figure>

I then created a new reference plane to be able to make the slope.
<figure> <center>
  <img src="./../../img/mod07/sketch12.jpg" alt="logo text" width="80%" />
  <figcaption> Reference plane and cut </figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod07/sketch13.jpg" alt="logo text" width="80%" />
  <figcaption> Using the swept cut feature to make a slope cut follow this path </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/sketch14.jpg" alt="logo text" width="80%" />
  <figcaption> Top part finished, with some fillets (not all of them are actually needed)</figcaption>
</figure>

### Making the guitar !

#### Making the stock
My guitar requires 420mmx300mmx44mm. So I needed to make a stock bigger than that with the wood available at the lab. I chose to go with long planks that are 25mm thick and 110mm large. I had to cut them at 450mm and assemble them by 3 then times 2 to make a whole body that was big enough.

<figure> <center>
  <img src="./../../img/mod07/initPlanks.jpg" alt="logo text" width="80%" />
  <figcaption> My initial planks</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/cuttingPlanks.jpg" alt="logo text" width="80%" />
  <figcaption> Placing them on the ground to cut them</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/cut1.jpg" alt="logo text" width="80%" />
  <figcaption> Actually it was easier like this</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/cut2.jpg" alt="logo text" width="80%" />
  <figcaption> 6 small boards </figcaption>
</figure>

Then I had to glue them together. I used wood glue and clamps to hold them in place for 2 hours.
<figure> <center>
  <img src="./../../img/mod07/glue1.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue2.jpg" alt="logo text" width="80%" />
  <figcaption> Glue applied </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue3.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue4.jpg" alt="logo text" width="80%" />
  <figcaption> Clamps</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue5.jpg" alt="logo text" width="80%" />
  <figcaption> Horizontal holder and clamp to prevent wood buckling</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue6.jpg" alt="logo text" width="80%" />
  <figcaption> Final result </figcaption>
</figure>

I then needed to assemble my new board of 3 planks with another one to make a stock 50mm high.

<figure> <center>
  <img src="./../../img/mod07/glue7.jpg" alt="logo text" width="80%" />
  <figcaption> More glue </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue8.jpg" alt="logo text" width="80%" />
  <figcaption> Assemlbing two boards made of 3 planks </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue9.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/glue10.jpg" alt="logo text" width="80%" />
  <figcaption> My new stock !</figcaption>
</figure>

### Placing the stock
I made sure to vacuum clean the spoilerboard and added double-sided tape and screws to hold my stock well in place.
<figure> <center>
  <img src="./../../img/mod07/stock1.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/stock2.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod07/stock3.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod07/stock4.jpg" alt="logo text" width="80%" />
  <figcaption> </figcaption>
</figure>

#### Post-processing the CAM
So the first step before actually being able to mill is to export the GCode for the machine. I had to install the post-processor kinetic-NC. It is available [here](https://cam.autodesk.com/hsmposts?).

Then I tried to postprocess my design and ran into this:
<figure> <center>
  <img src="./../../img/mod07/errorCAM.jpg" alt="logo text" width="80%" />
  <figcaption> Seems like version do not match...</figcaption>
</figure>

Actually it is because the version is too recent compared to the engine used in SolidWorks (or HSMWorks maybe ?). Anyway, I found an older version (43054) that works !
<figure> <center>
  <img src="./../../img/mod07/kineticVersion
.jpg" alt="logo text" width="80%" />
  <figcaption> Seems like versions do not match...</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/surfacingGCode.jpg" alt="logo text" width="80%" />
  <figcaption> Working GCode for surfacing </figcaption>
</figure>

### Tools
Now I'm entering the real tool that I'll use: the might 6mm flat end.

<figure> <center>
  <img src="./../../img/mod07/6mm.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/6mm2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/6mm3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I will be using 14000rpm as it is a bit faster than what is in the datasheet for aluminum.

###Top face: surfacing
Just like I did with the "test" part, I made a new job, added the stock and axis and created a surfacing process. In the job setup I specified that my guitar should be 2mm below the top of my stock so I will need to surface 2mm.
<figure> <center>
  <img src="./../../img/mod07/jobGuitar.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

I processed the GCode and had a look in the Kinetic software to make sure it was all okay.

<figure> <center>
  <img src="./../../img/mod07/jog.jpg" alt="logo text" width="80%" />
  <figcaption>The jog menu</figcaption>
</figure>

I placed my machine at the top left corner of my stock, as defined as the zero in my job setup, and clicked on zero. Then I had to place a piece of paper and lower the mill until it slightly touches it and I adjusted (0.1 and 0.01mm) until it scratches when the paper, before zeroing my machine.

<figure> <center>
  <img src="./../../img/mod07/zero1.jpg" alt="logo text" width="80%" />
  <figcaption>Placing a piece of paper</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/zero2.jpg" alt="logo text" width="80%" />
  <figcaption>It scratches, let's zero the machine</figcaption>
</figure>

Then I loaded the CAM and made sure it was all okay.

<figure> <center>
  <img src="./../../img/mod07/surfacing.jpg" alt="logo text" width="80%" />
  <figcaption>The program menu</figcaption>
</figure>

Since it was the first milling I did, I took time to make an "air milling" and make sure the mill did not go outside the stock boundaries.

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod07/airMilling.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

I can now start the program at the correct height.
<figure> <center>
  <img src="./../../img/mod07/surfacing1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/surfacing2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/doingFacing.jpg" alt="logo text" width="80%" />
  <figcaption>Program running and current line highlighted</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/finishedSurfacing.jpg" alt="logo text" width="80%" />
  <figcaption>Surfacing finished</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod07/cleanedSurfacing.jpg" alt="logo text" width="80%" />
  <figcaption>Once vacuumed</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/surfacingView.jpg" alt="logo text" width="80%" />
  <figcaption>Very nice finish even with the 6mm mill</figcaption>
</figure>


### Top face: 2D pocket
I started with the neck hole/pocket since it is the easier. I did just like for the "test" part above and the result:

<figure> <center>
  <img src="./../../img/mod07/neckPocket.jpg" alt="logo text" width="80%" />
  <figcaption>JNeck finished</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/neckPocket2.jpg" alt="logo text" width="80%" />
  <figcaption>Vacuumed, rough finish</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod07/neckPocket3.jpg" alt="logo text" width="80%" />
  <figcaption>hand-sanded</figcaption>
</figure>

For the central holes, most of them are not of the same depth, however, to avoid making each one at a time, I selected the whole contour and selected the highest face as the bottom height so that everything will be leveled at the highest height.

<figure> <center>
  <img src="./../../img/mod07/faceA1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/faceA2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

An extreme attention must be made to the clearance height to make sure the mill won't jog into the whole wood.
<figure> <center>
  <img src="./../../img/mod07/centralHoles1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/centralHoles2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure


For the bridge part, it goes through the whole part but we'll make a first half in the face A and the other half on face B. Note that since we have surfaced already, the top height is the stock minus 2mm since I surfaced 2mm.
<figure> <center>
  <img src="./../../img/mod07/heightHoles.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/bridge1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/bridge2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

I then did the Jack input hole:
<figure> <center>
  <img src="./../../img/mod07/Jack1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/Jack2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

And finished by making the different depth holes:
<figure> <center>
  <img src="./../../img/mod07/depthSub.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure



###Top face: slope (3D pocket and parallel)
The slope on the top face was a bit harder to setup.
Since the height is not constant, I used a 3D pocket clearing to get a rough surfacing and leave only a maximum difference of 1mm (some cusps exist):

<figure> <center>
  <img src="./../../img/mod07/3DPocket1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/3DPocket2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/slope1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/slope2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/slope3.jpg" alt="logo text" width="80%" />
  <figcaption>After hand-sanding</figcaption>
</figure

The cusps are very visible but this is normal, this step is to reduce the maximum depth to mill in the next step.

I can now use the parallel process to really follow the slope (there is no stepdown settings here !!! so we need to be extra careful) with the tool and since I used the 3D clearing just before, I know I will have between 0 and 1mm of height of wood, so I can go faster!

<figure> <center>
  <img src="./../../img/mod07/slope4.jpg" alt="logo text" width="80%" />
  <figcaption>Parallel process</figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/slope5.jpg" alt="logo text" width="80%" />
  <figcaption>Parallel process</figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/slope6.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

### Top face: outline
I used the 2D contour process to do the outline. I have 44mm to cut so I'll do 20 on this face. However, since wood waste will be stuck in the slot, I'll only make 10mm in one job then clean thoroughly before doing a second job 10mm below.

<figure> <center>
  <img src="./../../img/mod07/outline1.jpg" alt="logo text" width="80%" />
  <figcaption>First job</figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/outline2.jpg" alt="logo text" width="80%" />
  <figcaption>Second job</figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/outline3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/outline4.jpg" alt="logo text" width="80%" />
  <figcaption>The wood is very cheap so the mill broke some when the direction was perpendicular to the fiber direction</figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/outline5.jpg" alt="logo text" width="80%" />
  <figcaption>On other direction the finish is nice</figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/outline6.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

### Top face: Rounded edges
For rounded edges on the Jack input and on the outline, I used the parallel process but using the additional _check surfaces_ option and make sure the _touch_ settings was on. That allowed me to force the tool to follow the curve all along.

<figure> <center>
  <img src="./../../img/mod07/check1.jpg" alt="logo text" width="80%" />
  <figcaption>Selecting the contour</figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/check2.jpg" alt="logo text" width="80%" />
  <figcaption>And the check surfaces (touch enabled)</figcaption>
</figure

The height is set as : from the surface to the surface -5mm.
<figure> <center>
  <img src="./../../img/mod07/check3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure


<figure> <center>
  <img src="./../../img/mod07/check5.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure

<figure> <center>
  <img src="./../../img/mod07/check6.jpg" alt="logo text" width="80%" />
  <figcaption> Rounded Jack input</figcaption>
</figure

I did the same for the outline:
<figure> <center>
  <img src="./../../img/mod07/check7.jpg" alt="logo text" width="80%" />
  <figcaption> Rounded outline</figcaption>
</figure

###Changing side: Drilling holes

## My design files
:material-download-box: [My Design files](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/ulb/students/maxime-verstraeten/-/raw/master/docs/files/mod07.zip)
