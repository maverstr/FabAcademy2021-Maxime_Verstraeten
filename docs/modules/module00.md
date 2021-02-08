# 0. Principles and practices

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Plan and sketch a final project. </li>
    <li> Describe what it will do and who will use it.</li>
    <li> Read the Fab Charter </li>
  </ul>
</div>

<div class="dottedLine"></div>

This week I tried to establish a sketch of my project. It's quite hard as I don't really know what will be possible and I will probably need to revisit my ideas multiple time during my FabAc journey.


## Intro
Because I'm doing my PhD full-time concurrently with the FabAcademy, I'll try to stay in the scope of my PhD subject.

Currently, I have a barely working silicone bladder phantom that I would like to improve and test several sensors that could be implanted inside.

To do so, I will first need to improve the phantom design and the manufacturing process. I will also need to find new ways to replicate the physiological behavior of the bladder and anchor my novel sensors on my bladder.

I will also need to design the electronics to measure my sensors' outputs and communicate them all to a central node that will be able to process the data to monitor the bladder activity.

I have only a few ideas at the moment but it is extremely likely that things will evolve over time.

## Needs
A "Neurogenic" bladder defines bladder and sphincter dysfunctions related to a neurological disease or a condition such as a spinal cord injury (SCI). Clincal manifestations include detrusor (the main muscle of the bladder) overactivity leading to incontinence and detrusor sphincter dyssynergia which can result in irreversible kidney damage.

<figure> <center>
  <img src="./../../img/mod00/neurogenicBladder.jpg" alt="neurogenic Bladder" width="80%" />
  <figcaption> </figcaption>
</figure>

#### Consequences
A neurogenic bladder has therefore tremendous repercussions on patient's physical and psychological well-being and constitute a financial burden on healthcare systems.

#### Management techniques
To prevent most of these issues, patients rely on uncomfortable bladder management techniques such as clear intermittent catheterization (CIC) which often lead to urinary-tract infections and subsequent renal failure if managed incorrectly or in poor conditions.


#### Bladder monitoring
Being able to monitor and predict bladder contractions as well as rising intravesical pressure would allow patients to adapt their management techniques and increase their quality of life. Moreover, it would be possible to stimulate the afferent nerves in a closed-feedback loop to refrain their urge to urinate. Monitoring bladder activity in SCI patients is therefore today a top research priority.

##Project requirements

### Bladder phantom
The fist step in the development of a medical device is tot test it on a phantom. The state-of-the-art bladder phantom, still today, it a rubber balloon. Needless to say that is not a very good model of the bladder itself.
The first step is therefore to mold a new phantom in silicone. I plan to use 3D-printing to make molds for it. Also, it would be nice if I could segment 3D scan of patient's bladder to enhance my model.

<figure> <center>
  <img src="./../../img/mod00/phantom.jpg" alt="phantom" width="80%" />
  <figcaption> A silicone phantom </figcaption>
</figure>


### Bladder activity simulation
Having a simple silicone phantom will be of no use if it does not represent the bladder activity, especially in the case of a neurogenic Bladder

The main parameters that I aim to simulate:

- Physiological filling: The bladder can naturally fill with a flow rate of about 1-2mL/min and is usually filled with between 50 to 600mL. Most cystometry (procedures where a physician artificially fills the bladder) occur at 50mL/min which is supposed to influence the bladder response. I would like to develop a simple system that can fill my phantom at those physiological rate.

<figure> <center>
  <img src="./../../img/mod00/phantomDrawing.jpg" alt="phantomDrawing" width="80%" />
  <figcaption> Basic scheme of the filling through a solenoid valve and some sensors on the phantom </figcaption>
</figure>


- Pressure: The intravesical pressure is the main symptom we are looking to treat. In particular, contractions lead to sudden increase in pressure that can be detected. Being able top simulate these contractions (a net of contractile wires ?) would be extremely interesting. It could also be simulated by placing the phantom in a hermetic box where the pressure can be externally-controlled.

PIC OF A PRESSURE GRAPH + hermetic box ?

- Deformation: Over time, the bladder deforms as it is made of various visco-elastic fibers. By choosing the right material (silicone : which one ? or other materials) we could reach the same mechanical properties and be able to simulate the bladder deformation.

<figure> <center>
  <img src="./../../img/mod00/bladderDeformation.gif" alt="neurogenic Bladder" width="100%" />
  <figcaption> Deformation of the bladder </figcaption>
</figure>

- Temperature: To be honest this is more for fun as I don't think it will impact my measurements at all but still, it would be nice to have the water filling my phantom at the correct temperature.

### Measurements
The whole goal of making this phantom is to be able to test different sensors.
Based on the section just above, I intent to test:
- A pressure sensor
- A deformation sensor
- A temperature sensor
- Something else ? Maybe simulate the bladder electrical activity and try to place electrode to act as an EMG ?

### Signal amplification and processing
The sensors will obviously need to be powered and to transmit their data to a 'brain'. I will therefore need to use a micro-controller but also several amplifiers and filter if I hope to get nice signals that I can then process to monitor the bladder activity.
Ideally, I would like to transmit most of the data and power wirelessly (through an inductive link ?) as in real-life, the sensors would be implanted inside the patient.

### Anchoring and encapsulation
Those sensors will need to be encapsulated and anchored to my phantom. I will need to find innovative ways to place the sensors on the phantom while trying to respect the surgical constraints.
The sensors but also all the electronics will have to be isolated from the patient.
I'll have to test multiple types of encapsulation (silicone, epoxy, parylene, solid encapsulation, ...) in order to find the one that holds my implant in place the best while also ensuring that no water can slowly reach the electronics and ensure that no part of the encapsulation tends to peel or unstuck itself.
