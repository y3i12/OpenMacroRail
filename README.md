OpenMacroRail
=============

Solution to create macro stacked pictures. This project aims to reach the Software + Hardware solution using OpenFrameworks and Arduino.

#Yada, yada, yada, some history, yada yada...
As a hobbiyst photographer I have particular interest on Macro photography. But the real deal macro, that can capture the eye of a fly ocupying the whole picture is a little more complicated do create than taking a single picture. Special lenses combinations are used, resulting on a shallow depth of field. Several pictures are needed to capture the whole depth, and each picture needs to be taken precisely with a controlled motion to fill the image with details.

A macro rail allows you to create those pictures by moving the camera or the subject manually, and automated macro rails do it automatically, moving the camera and taking pictures on all steps.

Here the the complete solution of motion and shooting (eventually in the future, the stacking of the images) in low-profile-DIY-open-source way will be provided, using open soure solutions like Arduino, OpenFrameworks and Fritzing.

I've maded 3 other prototypes of the same project and this will be the cheapest and most practical. Little code, cheap parts (except for your camera) and great results.

#What is already ready ady y?
By the current moment only the protoboard is complete, based on the other projects. The picture shooting triggers are compatible to CameraAxe connection and are isolated from the main circuit, as the stepper driver is also isolated and uses another power source than the Arduino.

The current code only blinks some leds on a modified protoboard - I won't use movable parts to do such tests.

#Solution Flow
The main flow is something like this:
Set the parameters on the OpenFrameworks UI and click "Lets shoot this thing.", the UI through OF communicates to the Arduino using Firmata, shoots the camera and moves it repeatedly until all the slices are all shot.

#Next steps
* Etch and test the PCB;
* Create 3D-Printable parts to the case;

