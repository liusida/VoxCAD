# VoxCAD

Use QT5 Creator as IDE, instead of Visual Studio.

## Installation

Download QT5 and QT Creator. I downloaded them here: https://www.qt.io/download-qt-installer

Install QT5 and QT Creator. I choose to only install "Qt 5.12.6" -> "Desktop gcc 64-bit" and "Developer and Desinger Tools". They are about 1.86G.

Clone this repository "VoxCAD" and its submodule "Voxelyze": (Anyone know how to do this in one step?)

```bash
git clone git@github.com:liusida/VoxCAD.git
cd VoxCAD
git clone git@github.com:liusida/Voxelyze.git
```

Open QT Creator, open the project by opening the "VoxCAD.pro" file.

Compile and (Debug or Run).


## Notes for steps (Maybe it's only hard for me to use the GUI?)

1. Create a robot.

1.1 "Tools"->"Edit Voxels"; 

1.2 Choose the right "Palette" (Or we should call that "Material"); 

1.3 Use "Pencil", "Rectangle", etc. to draw what you want. (Sometimes there's a bug in Depth so users cannot draw.)

1.4 Use "Layer Back" before drawing another layer.

2. Cancel "Fix All"

2.1 "Analyze"->"Boundary Conditions";

2.2 Choose Boundary Condition BC0(*******), click "Fix None";

2.3 Click "Finished Editing".

3. Run Simulation

3.1 "Analyze"->"Physics Sandbox"

3.2 "timestep (% optimal dt)" should be set to about "0.01"

4. Enable Actuation

4.1 Click one certain "Palette" (or "Material") and select Tab "Physical".

4.2 Change "CTE (1/deg C)" (which means Coefficient of Thermal Expansion, Unit: 1/degrees celsius) to like "0.01"

4.3 In "Physics Sandbox", select Tab "Physics Setting"->Tab "Environment", check "Vary Temperature" and set value to like "5e-05".

4.4 Change "Temp (deg C)" to like "40".

5. Damping

5.1 Set "Ground Damping Ratio (z)" to "0.04" if you feel the robot is too energetic.

Now you can see your robot moving.

## Great videos about physical concepts

Understanding Young's Modulus: 

[![](https://i.ytimg.com/vi/DLE-ieOVFjI/hqdefault.jpg?sqp=-oaymwEZCPYBEIoBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLDVt2H-rw0Bg7acXSBktS2e0DqeZA)](https://www.youtube.com/watch?v=DLE-ieOVFjI)

Understanding Poisson's Ratio: 

[![](https://i.ytimg.com/vi/tuOlM3P7ygA/hqdefault.jpg?sqp=-oaymwEZCPYBEIoBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLBVaNtvEewQxuTZv6eHlH1zacW0mg)](https://www.youtube.com/watch?v=tuOlM3P7ygA)

## Example of Hyperparameters

Hyperparameters from https://github.com/skriegman/2019-RSS

1. Material

    * Elastic Modulus: 10 Million Pa;
    * Poisson Ratio: 0.35;
    * Density: 1 Million Kg/m^3; (Never saw such dense material... but works fine in simulation.)
    * Coefficient of Thermal Expansion (CTE): 0.01 1/degree Celsius;
    * Temp Phase: 0 rad; (What's this?)
    * Static Friction Coefficient: 1;
    * Dynamic Friction Coefficient: 0.5;

2. World

    * Timestep 0.3 % of optimal dt;
    * Ground damp ratio: 0.01 z; (What's this?)
    * Temperature: 39 degree Celsius;
    * Vary Temperature Period: 0.2 second;


## Issue with using Visual Studio Code and CMake

Even with VS Code 1.41, in terminal, if we want to launch any application with GUI, there will be fatal problem. So install VS Code insider 1.42 instead: https://code.visualstudio.com/insiders/ and this issue has been fixed.

