# Bladder phantom

In my project, I need a bladder phantom, i.e. a model of a human bladder on which I can place multiple devices and sensors. I will detail how I made it and what it is capable of.

## Objective

Rubber balloons are often used in the literature to model the human bladder. It is, however, a terrible model.

By making a model in silicone, it is possible to control the mechanical properties of the phantom as well as its shape.

In particular, rubber balloons have an extremely thin wall that is not resembling a real bladder. The mechanical properties like the Young modulus are also not relevant.


<figure> <center>
  <img src="./../../img/finalProject/balloonModel.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Balloon model </figcaption>
</figure>

## Choosing the right materials

The silicone is probably the most obvious choice for its ease of use and its mechanical properties. Moreover, soft biological tissues show a classical visco-elastic behavior. The Ecoflex silicones share the same mechanical properties:

<figure> <center>
  <img src="./../../img/finalProject/visco.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Representative force-stretch curve for
soft biological tissue ; T = force, lambda = stretch</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/visco2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Stress/stretch relationships of 9 Ecoflex00-30 silicone samples under an axial
stretch rate of 1.2/min </figcaption>
</figure>


The Young modulus of the silicone must be chosen to correspond to the modulus of the bladder.

Regarding a real bladder, the modulus is between 4 and 400kPa depending on the article or the reference. In practice, most bladders show a modulus of around 75kPa

It is difficult to find the perfect silicone modulus as it depends on the strain. Only the modulus at a strain of 100% (called E100) is specified in the datasheet. It is also important to have silicone that is easy to work with, i.e. with a sufficient pot life and curing time.
Because of this, the Ecoflex00-50 has been chosen.

<figure> <center>
  <img src="./../../img/finalProject/ecoflex.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Smooth-On Ecoflex datasheet </figcaption>
</figure>

In particular, the pot life is 18 minutes (quite sufficient to have a nice casting with degassing) and the E100 is 82kPa.

## Making the phantom

With the silicone now chosen, it was time to make the phantom.

### Making the mold and casting it
Making the phantom is difficult as it must be hollow.

Initially, I thought about roto casting but for this to work, I had to create such a machine first and I was not confident about the potential results.

The next idea that came to my mind was to make a phantom in 2 parts, each part is made with 2 molds that link to each other. This is making two half-spheres before joining them together.

I created the mold in SolidWorks:
<figure> <center>
  <img src="./../../img/finalProject/mold1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> A half bladder mold</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/mold2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Casting it</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/mold3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

To join them, I used Ecoflex FAST to make a strong adhesion with a very small curing time.

<figure> <center>
  <img src="./../../img/finalProject/mold4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/mold5.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Final result</figcaption>
</figure>


The only problems with this model is that::
1. This joint between the spheres make it more fragile
2. This joint locally changes the mechanical properties.

This also resulted in a lot fixing using Ecoflex FAST but the properties were even more different after each repair.
<figure> <center>
  <img src="./../../img/finalProject/phantomFix.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> After multiple repairs</figcaption>
</figure>


### Mold improvement: water-soluble filament
To make the phantom in a single piece, I chose to use a soluble filament to make an inner mold that I could easily dissolve in water. In used Verbatim BVOH filament. It prints with the same settings as PLA except for the nozzle temperature that must be lowered by 5°C for a total of 205°C.

<figure> <center>
  <img src="./../../img/finalProject/mold6.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Single-casting mold</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/finalProject/pva1.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Inner mold in water-soluble filament</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva2.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva3.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva4.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva5.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>degassing</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva6.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva7.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva8.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Placing it in water</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva9.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>After one hour</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/pva10.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>After 4 hours</figcaption>
</figure>

You can see the water with the dissolved filament pouring outside the phantom.
<video width="700" height="480" autoplay loop>
  <source src="./../../img/finalProject/phantomSoluble.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

This ensures a reliable phantom that can be used for many filling and emptying cycles!

<figure> <center>
  <img src="./../../img/finalProject/mold7.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/moldFinal.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

### Adding muscle fibers

To better represent the muscle fibers in a real bladder and therefore the mechanical behavior, I added some silicone fibers and designed some "fasteners" to hold them in place and be able to easily adjust them.

<figure> <center>
  <img src="./../../img/finalProject/mold8.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Initial "fiber net" idea</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/mold9.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Fibers development</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/finalProject/mold10.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Actual design with a pressure sensor</figcaption>
</figure>


## Final result in the chamber
<video width="700" height="480" autoplay loop>
  <source src="./../../img/finalProject/airFilling.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<video width="700" height="480" autoplay loop>
  <source src="./../../img/finalProject/waterFiling.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

### Possible improvements

It would be nice to be able to create the bladder phantom based on DICOM (medical) imaging from CTscan for example.
The bladder mold could be done in Teflon to be a bit more smooth as well instead of relying on 3D printing.
It would be possible to encapsulate some electronics boards in silicone or parylene, or even use the thermoforming machine.
