# 14.

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group Assignment: Send a message between two projects. </li>
    <li> Design, build, and connect wired or wireless node(s) with network or bus addresses</li>
  </ul>
</div>
<div class="dottedLine"></div>

TODO

## Group assignment

## Previous design
During last week, I developped my network featuring three boards (one master, two slaves) that can communicate so I can switch on and off the LEDs on the boards using the Serial USB port with the master.
Initially, I only had one slave and one master and I finally added a second slave:

<figure> <center>
  <img src="./../../img/mod13/3nodes.jpg" alt="logo text" width="80%" />
  <figcaption>The 2 slaves and the master together</figcaption>
</figure>

_Making the LEDs subsequently blink_
<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/blink3Nodes.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<br>

_Commanding the indivual LEDs through the network_
<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/command3Nodes.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>


## This week objective
This week, I intend to develop a Python interface using PyQt to command the LED on each board with this interface.


## My design files
:material-download-box: [My Design files](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/ulb/students/maxime-verstraeten/-/raw/master/docs/files/mod14.zip)
