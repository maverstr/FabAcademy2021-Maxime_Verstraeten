# Week 5



To scan my head and this bottle of beer, I downloaded [Autodesk Recap Pro](https://www.autodesk.com/products/recap/overview?plc=RECAP&term=1-YEAR&support=ADVANCED&quantity=1).
 The software is extremely powerful and is capable of generating 3D model based on at least 30 images. These images can be simply taken with a smartphone camera without even needing to be in precise spatial positions or anyting.
 It is unfortunately pricey but a free-trial exists and just like (almost) all Autodesk's products, it's free if you have an .edu mail address.

 Recap will then try to reconstruct the point clouds in 3D and you can then slice or adjust the model before exporting it.


!!!notes
    edu account have a limited queue so waiting time is between 2-12hours, no need to panick neither to leave your laptop on, as it is processed online ;)


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
