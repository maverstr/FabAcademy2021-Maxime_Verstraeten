# 5. ...

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group assignment: characterize your lasercutter's focus, power, speed, rate, kerf, joint clearance and types. </li>
    <li> Cut something on the vinylcutter.</li>
    <li>  Design, lasercut and document a parametric construction kit, accounting for the lasercutter kerf whiuch can be assembled in multiple ways.</li>
    <li> Try to include elements which aren't flat.</li>
  </ul>
</div>
TODO
<div class="dottedLine"></div>



To scan things, I downloaded [Autodesk Recap Pro](https://www.autodesk.com/products/recap/overview?plc=RECAP&term=1-YEAR&support=ADVANCED&quantity=1).
 The software is extremely powerful and is capable of generating 3D model based on at least 30 images. These images can be simply taken with a smartphone camera without even needing to be in precise spatial positions or anyting.
 It is unfortunately pricey but a free-trial exists and just like (almost) all Autodesk's products, it's free if you have an .edu mail address.

 Recap will then try to reconstruct the point clouds in 3D and you can then slice or adjust the model before exporting it.

!!!notes
    .edu account have a limited queue so waiting time is between 2-12hours, no need to panick neither to leave your laptop on, as it is processed online ;)


I was first not really conviced by the software capabilities so I took bad photos (no attention to lighting, blur or 3D completeness) of a bottle of beer. Surprisingly, the results were good !

The Edit-> 'Slice and Fill' option allowed to slice the object from the environement and I ended up with this:



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
