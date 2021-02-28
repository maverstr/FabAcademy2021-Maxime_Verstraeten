# 5. 3D scanning and Printing

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group assignment: Test the design rules for your 3D printer(s). </li>
    <li> design and 3D print an object (small, few cm3, limited by printer time)
         that could not be made subtractively. </li>
    <li>  3D scan an object (and optionally print it).</li>
  </ul>
</div>
<div class="dottedLine"></div>

This week is one of the most creative so I intend to make a good use of it in the time that I can allow to it.

## Introduction
So the main difference with 3D printers compared to more classical methods is that it _adds_ material (additive method) rather than _removing_ some (substractive methods).
It has both pros and cons but additive manufacturing allows to create things that are not possible with substractive processes. Moreover, you don't need to care about the complexity of the design itself and how to manufacture it. With 3D-priting, it is possible to have access to the interior of a part while building it so we can create imbricated parts and bodies in a single process. Moreover, though the material can be quite expensive, the waste is limited as you don't remove excess parts (except support).

But it's not all good with 3D-printing. Printers are notoriously known for failing for sometimes unknown reasons, which can be frustrating when doing big parts (and that's why it's best to keep it to small parts, one at a time) that take a while (yes, 3D-printing is **slow** !). Also, the resolution is not as good as substractive processes as it is limited by the nozzle size and the filament used. It is still good enough however in most cases. Finally, not all materials are available so sometimes you have no other choice than to make a mould or use substractive processes.

Multiple types of printers exist: filament, resin and so on... This week I sticked to filament deposition printing but I plan to use resin in the future. We also have an Eden printer (photopolymer jetting technology) at Uni that I used once for a very detailed part but it is extremely expensive so I didn't use it this week :smile:.

## The power of 3D-printing
### Printer characterization and design rules
At the lab we have multiple Prusa I3MK3 and MK3S. With Jason, we started printing multiple test parts and more specifically, we wanted to get a feel of what the different materials and nozzles change.

Our fablab already printed a simple test part but we wanted to do it ourselves and test out more characteristics of the printer.

<figure> <center>
  <img src="./../../img/mod05/testFablab.jpg" alt="Beer" width="80%" />
  <figcaption> Fablab's test part</figcaption>
</figure>


We found another nice [test part](https://www.thingiverse.com/thing:2656594) online that allows to test gaps, bridges, overhangs, angles, walls and so on.
We decided to print this part three times, with no support (otherwise the overhang tests do not make sense).

First with a PLA filament and a 0.4mm nozzle (0.2mm resolution), 10% infill.
For the PLA, we sticked to the recommended temperature (i.e. 210°C extruder, 60°C heating plate).

<figure> <center>
  <img src="./../../img/mod05/designRules1_1.jpg" alt="Beer" width="80%" />
  <figcaption> Printing our first test part</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod05/designRules1.jpg" alt="Beer" width="80%" />
  <figcaption> PLA, 0.4mm nozzle, 10% infill </figcaption>
</figure>

Second, PLA filament, 0.6mm nozzle (0.3mm resolution), 10% infill.
Note that you actually need to specify the nozzle diameter in Prusa's settings.

<figure> <center>
  <img src="./../../img/mod05/prusaNozzleSettings.jpg" alt="Beer" width="80%" />
  <figcaption> Nozzle diameter settings</figcaption>
</figure>

The main difference with a bigger nozzle is the printing time. We went from 4h30 to 3h, a 33% reduction. On the other hand, we lose in resolution and it can especially be seen on the thin walls. We also had trouble with the bottom plate not sticking correctly to the heating plate.

<figure> <center>
  <img src="./../../img/mod05/designRules2_1.jpg" alt="Beer" width="80%" />
  <figcaption> Bottom plate not sticking !</figcaption>
</figure>

TODO

Finally, PETG filament, 0.4mm nozzle (0.2mm resolution.), 10% infill.
PETG is PET with added glycol. It is a more rigid but more brittle material than PLA but harder to print (we had worse results than with PLA, especially due to the bottom layer not sticking correctly to the heating plate). It must be heated at a much higher temperature (260°C extruder and 80°C for the heating plate).
To help the bottom plate to stick, we added a brim but it did not do much in our case. We also tried cleaning the heating plate with acetone which helped a bit as well.

<figure> <center>
  <img src="./../../img/mod05/designRules3_1.jpg" alt="Beer" width="80%" />
  <figcaption> PETG "burns" (black color) in some places... </figcaption>
</figure>

TODO


I later found out this cool settings in recent Prusa slicer releases: the _variable layer height_. It allows to specifically set layer speed and resolution for each layer of the part. Even more interesting, it can adapt the layer settings automatically by pressing the _adaptive_ button. It can also smooth the resulting part.

<figure> <center>
  <img src="./../../img/mod05/prusaHeight.jpg" alt="prusa Height" width="80%" />
  <figcaption> Adaptive results: the greener the higher the resolution </figcaption>
</figure>


We then tested the clearance using Neil's design. Once printed, we had to remove the support with pliers and bit of hand-work, not easy but it worked !

<figure> <center>
  <img src="./../../img/mod05/clearance1.jpg" alt="prusa Height" width="80%" />
  <figcaption> The part is printed with support !</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod05/clearance2.jpg" alt="prusa Height" width="80%" />
  <figcaption> 0.2 and 0.1mm clearance are blocked </figcaption>
</figure>

It's interesting to see that when the gaps gets too small, the support cannot be cleared and so the two parts are linked and blocked together.

### Imbricated parts: Chainmail



### Solving my needs: my bike handlebar tape holder
support vs no support (no need because bridging and small overhand on the end)
### PVA: the soluble filament
PVA is a type of filament that has the property to be soluble in water. That makes it good for two things:

1. Printing support that can be easily removed, even inside the part by just plunging the part in water for a few hours.
2. Make an inner mold for single-cast.

I used it in the past for the latter reason and here is what I obtained.

<figure> <center>
  <img src="./../../img/mod05/twoPiecesMold.jpg" alt="Beer" width="80%" />
  <figcaption> Initial plan: two half hollow spheres</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod05/singlePieceMold.jpg" alt="Beer" width="80%" />
  <figcaption> An outer mold in PLA and an inner mold in PVA </figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod05/PhantomWithSolubleFilament.jpg" alt="Beer" width="80%" />
  <figcaption> Final result: an hollow sphere in silicone done in a single mold </figcaption>
</figure>


## 3D-scanning

To scan things, I downloaded [Autodesk Recap Pro](https://www.autodesk.com/products/recap/overview?plc=RECAP&term=1-YEAR&support=ADVANCED&quantity=1).
 The software is extremely powerful and is capable of generating 3D model based on at least 30 images. These images can be simply taken with a smartphone camera without even needing to be in precise spatial positions or anyting.
 It is unfortunately pricey but a free-trial exists and just like (almost) all Autodesk's products, it's free if you have an .edu mail address.

 Recap will then try to reconstruct the point clouds in 3D and you can then slice or adjust the model before exporting it.

!!!notes
    .edu account have a limited queue so waiting time is between 2-12hours, no need to panick neither to leave your laptop on, as it is processed online ;)


I was first not really conviced by the software capabilities so I took bad photos (no attention to lighting, blur or 3D completeness) of a bottle of beer. Surprisingly, the results were good !

The Edit-> 'Slice and Fill' option allowed to slice the object from the environment and I ended up with this:



<figure> <center>
  <img src="./../../img/mod05/beer.jpg" alt="Beer" width="50%" />
  <figcaption> A belgian beer !</figcaption>
</figure>

I then tried to scan the head of my colleague Adrien. I used a video from my phone, captured at 30fps; 1920x1080 pixels and then used ffmpeg to extract all frames as single .jpg files.

Since Recap is limited to 100 photos per project though, I first had to reduce the number of frames.

Given that I had an initial 20 seconds videos (596 frames exactly), I reduced my video to 5 fps before extracting the frames:

`ffmpeg -i Adrien.mp4 -filter:v fps=5 AdrienLowRate.mp4`

And I ended up with exactly 99 frames:

`ffmpeg -i AdrienLowRate.mp4 thumb%04d.jpg`


<video width="640" height="480" autoplay loop>
  <source src="./../../img/mod05/adrienCompressed.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<center> **Thank you Adrien !** </center>

Well... It failed. I think this may be because some of the pictures did not capture its entire face and maybe the background was too uneven. I'll try again.

I then simply took some pictures of my father's head (about 30 pictures) and it actually worked way better. Now the back of the head was very inaccurate because of the hair but the front of is face is actually quite impressive:

<iframe allowfullscreen webkitallowfullscreen width="640" height="480" frameborder="0" seamless src="https://p3d.in/e/uDB2F"></iframe>

Installation de MeshMixer
Brush smooth to smooth the mesh
edit: make solid to close the gaps behind the face
different options (accurate, fast, sharp edges preservation, ...) and we can update the result
reducing cell size to a minimum gives the best result and preserves the initial slight bumps and such.

meshmixer tutorial to append and mix multiple meshes and objects
https://knowledge.autodesk.com/search-result/caas/screencast/Main/Details/6abcc8c1-536a-4e80-bce4-5391468a774f.html


to move the head: edit -> transform
clicking on the center square for scaling

select (S key) then brush to select and b to slmooth the boundary then x to delete

ctrl shift to select both then combine
double left click to select the whole boundary
edit -> join
then brush to shrink smooth everything
and export to STL
then CuraMaker or PrusaSlicer and it's good to be printed !

## To go further
I would like to use a resin 3D-printer to make other parts and compare the results.
I plan to finish my chess game whenever I got time.
I want to implement OctoPrint on my Uni's printers to be able to print from everywhere in the building and monitor the printing.
Play with the independant layer settings in Prusa to optimize my printing time.
Test infill patterns mechanical anisotropy to make structures that are rigid in a direction and deformable in another one.
